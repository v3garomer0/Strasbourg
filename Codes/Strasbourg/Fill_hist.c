#include "../Scripts/libPerso.h"


void Fill_hist (){

  gStyle->SetOptStat (0);
  //gStyle->SetOptStat (1111110);
  gStyle->SetOptFit(1);
  gSystem->Exec ("ls -lrth ~/STELLA/Data/r001/r001_ene_gp.root");

  const Double_t ene_p_low = 0.; // qdc chn
  const Double_t ene_p_high = 17.;
  const Int_t M = 3;
  const Int_t ene_p_bin = (ene_p_high - ene_p_low)*50*M;
  const Int_t ene_p_bin_bwd = (ene_p_high - ene_p_low)*50*M*5;

  TH1F *h_ene_p[100];

  for (Int_t i = 0; i < 100; i++)
  {
    if (i < 50) h_ene_p[i] = new TH1F (Form ("h_ene_p[%i]", i), Form("imput [%i]", i+1), ene_p_bin, ene_p_low, ene_p_high);
    if (i >= 50) h_ene_p[i] = new TH1F (Form ("h_ene_p[%i]", i), Form("imput [%i]", i+1), ene_p_bin_bwd, ene_p_low, ene_p_high);
  }
  unsigned long long event_g, event_p, event_gp;
  Int_t mult_g, mult_p, mult_gp;
  std::vector <Int_t> *det_g = 0;
  std::vector <Int_t> *det_p = 0;
  std::vector <Long64_t> *time_g = 0;
  std::vector <Long64_t> *time_p = 0;
  std::vector <Double_t> *ene_g = 0;
  std::vector <Double_t> *ene_p = 0;

  TChain *f_in = new TChain ("t_event");
  TBranch *b_event_g, *b_mult_g, *b_det_g, *b_time_g, *b_ene_g, *b_event_p, *b_mult_p, *b_det_p, *b_time_p, *b_ene_p, *b_event_gp, *b_mult_gp;
  f_in->Add ("~/STELLA/Data/r001/r001_ene_gp.root"); // no downscaling
  f_in->SetBranchAddress ("event_g", &event_g, &b_event_g);
  f_in->SetBranchAddress ("mult_g", &mult_g, &b_mult_g);
  f_in->SetBranchAddress ("det_g", &det_g, &b_det_g);
  f_in->SetBranchAddress ("time_g", &time_g, &b_time_g);
  f_in->SetBranchAddress ("ene_g", &ene_g, &b_ene_g);
  f_in->SetBranchAddress ("event_p", &event_p, &b_event_p);
  f_in->SetBranchAddress ("mult_p", &mult_p, &b_mult_p);
  f_in->SetBranchAddress ("det_p", &det_p, &b_det_p);
  f_in->SetBranchAddress ("time_p", &time_p, &b_time_p);
  f_in->SetBranchAddress ("ene_p", &ene_p, &b_ene_p);
  f_in->SetBranchAddress ("event_gp", &event_gp, &b_event_gp);
  f_in->SetBranchAddress ("mult_gp", &mult_gp, &b_mult_gp);

  const Int_t mask_s3[100] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 9, 12, 11, 24, 23, 22, 21, 20, 19, 18, 17, 15, 16, 13, 14, 25, // S3F (before January 2017) CORRECTED
                              26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
                              51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75,
                              76, 77, 78, 79, 80, 81, 82, 83, 85, 84, 87, 86, 88, 89, 90, 91, 92, 93, 94, 95, 97, 96, 99, 98, 100}; // S3B
  Double_t  ene_sum_p; // sum energy
  Int_t det_sum_p; // initial detector

  // data loop
  for (Long64_t i = 0; i < f_in->GetEntries ()/1; i++){
    ene_sum_p = 0.;
    det_sum_p = 0;

    f_in->GetEntry (i);
    if (i > 11 && i%((long long) f_in->GetEntries ()/10) == 0) std::cout << " " << (Double_t) (i*100.)/f_in->GetEntries () << "% done" << std::endl;

    for (Int_t j = 0; j < mult_p; j++){ // particles
      //if (mult_p != 1) continue;
      if (mult_p == 1) {
        h_ene_p[mask_s3[det_p->at (j) - 1] - 1]->Fill (ene_p->at (j)); // single detector energy
      }
      if (mult_p == 2){
        ene_sum_p+=ene_p->at (j);
        if (ene_p->at (j) > ene_p->at (det_sum_p)) det_sum_p = j;
        h_ene_p[mask_s3[det_p->at (det_sum_p) - 1] - 1]->Fill (ene_sum_p);
      }    
    }
  }


  TCanvas *C_fwd = new TCanvas ("C_fwd", "", 700, 500);
  C_fwd->Divide(5,5);
  for (Int_t i = 0; i < 24; i++){
    C_fwd->cd (i + 1)->SetTickx();
    C_fwd->cd (i + 1)->SetTicky();
    h_ene_p[i]->GetYaxis ()->SetRangeUser(0, 500);
    h_ene_p[i]->Draw();
  }

  TCanvas *C_bwd = new TCanvas ("C_bwd", "", 700, 500);
  C_bwd->Divide(5,5);
  for (Int_t i = 0; i < 24; i++){
    C_bwd->cd (i + 1)->SetTickx();
    C_bwd->cd (i + 1)->SetTicky();
    h_ene_p[i + 75]->GetYaxis ()->SetRangeUser(0, 500);
    h_ene_p[i + 75]->Draw();
  }

  TCanvas *C = new TCanvas ("C", "", 700, 500);
  C->cd ()->SetTickx();
  C->cd ()->SetTicky();
  h_ene_p[0]->Draw();
}
