#include "../../Scripts/libPerso.h"
#include "r001_PolarEne.h"


Double_t Energy (Double_t *var,Double_t *par){
  
  /*  Double_t K = par[0]*par[2]*par[3]/(par[1]*(par[0]+par[1])*TMath::Power(par[4],2));
  Double_t E_kin = 0;
  if (2*par[4]*TMath::Cos(var[0])*TMath::Power(1-TMath::Power(par[4]*TMath::Sin(var[0]),2),1./2) > TMath::Power(par[4]*TMath::Cos(var[0]),2)+(1-TMath::Power(par[4]*TMath::Sin(var[0]),2)))
    {
      E_kin =  K*TMath::Power((par[4]*TMath::Cos(var[0]) - TMath::Power(1-TMath::Power(par[4]*TMath::Sin(var[0]),2),1./2)),2);
    }
   else if (2*par[4]*TMath::Cos(var[0])*TMath::Power(1-TMath::Power(par[4]*TMath::Sin(var[0]),2),1./2) < TMath::Power(par[4]*TMath::Cos(var[0]),2)+(1-TMath::Power(par[4]*TMath::Sin(var[0]),2)))
   {
    E_kin = K*TMath::Power((par[4]*TMath::Cos(var[0]) + TMath::Power(1-TMath::Power(par[4]*TMath::Sin(var[0]),2),1./2)),2);
    }*/
  //std::cout << E_kin;

    double K=par[0]*par[2]*par[3]/(par[1]*(par[0]+par[1])*pow(par[4],2));
  double E_kin = 0;

  if(2*par[4]*cos(var[0])*pow(1-pow(par[4]*sin(var[0]),2),1./2)>pow(par[4]*cos(var[0]),2)+(1-pow(par[4]*sin(var[0]),2)))
    {

      E_kin = K*pow((par[4]*cos(var[0])-pow(1-pow(par[4]*sin(var[0]),2),1./2)),2);
    }

  else if(2*par[4]*cos(var[0])*pow(1-pow(par[4]*sin(var[0]),2),1./2)<pow(par[4]*cos(var[0]),2)+(1-pow(par[4]*sin(var[0]),2)))
    {
    
      E_kin = K*pow((par[4]*cos(var[0])+pow(1-pow(par[4]*sin(var[0]),2),1./2)),2);
    }

  if ((var[0] > theta_min_S3_fwd/180*TMath::Pi() && var[0] < theta_max_S3_fwd/180*TMath::Pi()) || (var[0] > theta_min_S3_bwd/180*TMath::Pi() && var[0] > theta_min_S3_bwd/180*TMath::Pi())){  
    for (int l = 0; l<N; l++) {
      
      if (E_kin >= 7.5) {
	E_kin = E_kin - 1./N*(par[5]/TMath::Abs(cos(var[0])))*a1*pow(E_kin,b1); //power law
      }
      else if (E_kin < 7.5 && E_kin >= 5.5) {
	E_kin = E_kin - 1./N*(par[5]/TMath::Abs(cos(var[0])))*a2*pow(E_kin,b2); //power law
      }
      else if (E_kin < 5.5 && E_kin >= 4.) {
	E_kin = E_kin - 1./N*(par[5]/TMath::Abs(cos(var[0])))*a3*pow(E_kin,b3); //power law
      }
      else if (E_kin < 4. && E_kin >= 2.35) {
	E_kin = E_kin - 1./N*(par[5]/TMath::Abs(cos(var[0])))*a4*pow(E_kin,b4); //power law
      }
      else if (E_kin < 2.35 && E_kin >= 1.35) {
	E_kin = E_kin - 1./N*(par[5]/TMath::Abs(cos(var[0])))*a5*pow(E_kin,b5); //power law
      }
      else{
	E_kin = E_kin - 1./N*(par[5]/TMath::Abs(cos(var[0])))*a6*pow(E_kin,b6); //power law
      }
    }
    // std::cout << " " << E_kin;
    // si dead layer after all aluminium 
    
    for (int l = 0; l<N; l++) {
      
      if (E_kin >= 9.5) {
	E_kin = E_kin - 1./N*(si/TMath::Abs(cos(var[0])))*a1_si*pow(E_kin,b1_si);
      }
      else if (E_kin < 9.5 && E_kin >= 7.5) {
	E_kin = E_kin - 1./N*(si/TMath::Abs(cos(var[0])))*a2_si*pow(E_kin,b2_si);
      }
      else if (E_kin < 7.5 && E_kin >= 5.) {
	E_kin = E_kin - 1./N*(si/TMath::Abs(cos(var[0])))*a3_si*pow(E_kin,b3_si);
      }
      else if (E_kin < 5. && E_kin >= 3.) {
	E_kin = E_kin - 1./N*(si/TMath::Abs(cos(var[0])))*a4_si*pow(E_kin,b4_si);
      }
      else if (E_kin < 3. && E_kin >= 1.3) {
	E_kin = E_kin - 1./N*(si/TMath::Abs(cos(var[0])))*a5_si*pow(E_kin,b5_si);
      }
      else if (E_kin < 1.3 && E_kin >= 0.8) {
	E_kin = E_kin - 1./N*(si/TMath::Abs(cos(var[0])))*a6_si*pow(E_kin,b6_si);
      }
      else {
	E_kin = E_kin - 1./N*(si/TMath::Abs(cos(var[0])))*a7_si*pow(E_kin,b7_si);
      }
    }
  }
    // std::cout << " " << E_kin << std::endl;
    return E_kin;    

}
// par[0] = A1; par[1] = A2; par[2] = A3; par[3] = Ecm; par[4] = gam3; Var[0] = theta lab



Double_t Energy_alpha (Double_t *var,Double_t *par){
  
  /*  Double_t K = par[0]*par[2]*par[3]/(par[1]*(par[0]+par[1])*TMath::Power(par[4],2));
  Double_t E_kin = 0;
  if (2*par[4]*TMath::Cos(var[0])*TMath::Power(1-TMath::Power(par[4]*TMath::Sin(var[0]),2),1./2) > TMath::Power(par[4]*TMath::Cos(var[0]),2)+(1-TMath::Power(par[4]*TMath::Sin(var[0]),2)))
    {
      E_kin =  K*TMath::Power((par[4]*TMath::Cos(var[0]) - TMath::Power(1-TMath::Power(par[4]*TMath::Sin(var[0]),2),1./2)),2);
    }
   else if (2*par[4]*TMath::Cos(var[0])*TMath::Power(1-TMath::Power(par[4]*TMath::Sin(var[0]),2),1./2) < TMath::Power(par[4]*TMath::Cos(var[0]),2)+(1-TMath::Power(par[4]*TMath::Sin(var[0]),2)))
   {
    E_kin = K*TMath::Power((par[4]*TMath::Cos(var[0]) + TMath::Power(1-TMath::Power(par[4]*TMath::Sin(var[0]),2),1./2)),2);
    }*/
  //std::cout << E_kin;
  double K=par[0]*par[2]*par[3]/(par[1]*(par[0]+par[1])*pow(par[4],2));
  double E_kin = 0;

  if(2*par[4]*cos(var[0])*pow(1-pow(par[4]*sin(var[0]),2),1./2)>pow(par[4]*cos(var[0]),2)+(1-pow(par[4]*sin(var[0]),2)))
    {

      E_kin = K*pow((par[4]*cos(var[0])-pow(1-pow(par[4]*sin(var[0]),2),1./2)),2);
    }

  else if(2*par[4]*cos(var[0])*pow(1-pow(par[4]*sin(var[0]),2),1./2)<pow(par[4]*cos(var[0]),2)+(1-pow(par[4]*sin(var[0]),2)))
    {
    
      E_kin = K*pow((par[4]*cos(var[0])+pow(1-pow(par[4]*sin(var[0]),2),1./2)),2);
    }

    if ((var[0] > theta_min_S3_fwd/180*TMath::Pi() && var[0] < theta_max_S3_fwd/180*TMath::Pi()) || (var[0] > theta_min_S3_bwd/180*TMath::Pi() && var[0] > theta_min_S3_bwd/180*TMath::Pi())){
      
      for (int l = 0; l<N; l++) {
	if (E_kin >=12.8) {	
	  E_kin = E_kin - 1./N*(par[5]/TMath::Abs(cos(var[0])))*a1_a*pow(E_kin,b1_a); //power law
	}
	else if (E_kin <12.8 && E_kin>=9.8) { 
	  E_kin = E_kin - 1./N*(par[5]/TMath::Abs(cos(var[0])))*a2_a*pow(E_kin,b2_a); //power law
	}
	else if (E_kin <9.8 && E_kin>=7.5) { 
	  E_kin = E_kin - 1./N*(par[5]/TMath::Abs(cos(var[0])))*a3_a*pow(E_kin,b3_a); //power law
	}
	else if (E_kin <7.5 && E_kin>=5.9) { 
	  E_kin = E_kin - 1./N*(par[5]/TMath::Abs(cos(var[0])))*a4_a*pow(E_kin,b4_a); //power law
	}
	else if (E_kin <5.9 && E_kin>=4.9) { 
	  E_kin = E_kin - 1./N*(par[5]/TMath::Abs(cos(var[0])))*a5_a*pow(E_kin,b5_a); //power law
	}
	else if (E_kin <4.9 && E_kin>=3.7) { 
	  E_kin = E_kin - 1./N*(par[5]/TMath::Abs(cos(var[0])))*a6_a*pow(E_kin,b6_a); //power law
	}
	else if (E_kin <3.7 && E_kin>=2.8) { 
	  E_kin = E_kin - 1./N*(par[5]/TMath::Abs(cos(var[0])))*a7_a*pow(E_kin,b7_a); //power law
	}
	else if (E_kin <2.8 && E_kin>=2) { 
	  E_kin = E_kin - 1./N*(par[5]/TMath::Abs(cos(var[0])))*a8_a*pow(E_kin,b8_a); //power law
	}
	else { 
	  E_kin = E_kin - 1./N*(par[5]/TMath::Abs(cos(var[0])))*(a9_a*pow(E_kin,2)+b9_a*E_kin+c9_a); //2nd order polynomial law
	}
      }
      
      
      
// si dead layer after all aluminium 

      for (int l = 0; l<N; l++) {
	if (E_kin >= 12.5) {
	  E_kin = E_kin - 1./N*(si/TMath::Abs(cos(var[0])))*a1_si_a*pow(E_kin,b1_si_a);
	}
	else if (E_kin < 12.5 && E_kin >= 10) {
	  E_kin = E_kin - 1./N*(si/TMath::Abs(cos(var[0])))*a2_si_a*pow(E_kin,b2_si_a);
	}
	else if (E_kin < 10 && E_kin >= 7) {
	  E_kin = E_kin - 1./N*(si/TMath::Abs(cos(var[0])))*a3_si_a*pow(E_kin,b4_si_a);
	}
	else if (E_kin < 7 && E_kin >= 5) {
	  E_kin = E_kin - 1./N*(si/TMath::Abs(cos(var[0])))*a4_si_a*pow(E_kin,b4_si_a);
	}    
	else if (E_kin < 5 && E_kin >= 3.5) {      
	  E_kin = E_kin - 1./N*(si/TMath::Abs(cos(var[0])))*a5_si_a*pow(E_kin,b5_si_a);     
	}
	else if (E_kin < 3.5 && E_kin >= 2.5) {
	  E_kin = E_kin - 1./N*(si/TMath::Abs(cos(var[0])))*a6_si_a*pow(E_kin,b6_si_a);
	}
	else if (E_kin < 2.5 && E_kin >= 1.5) {    
	  E_kin = E_kin - 1./N*(si/TMath::Abs(cos(var[0])))*a7_si_a*pow(E_kin,b7_si_a);
	}
	else {
	  E_kin = E_kin - 1./N*(si/TMath::Abs(cos(var[0])))*a8_si_a*pow(E_kin,b8_si_a);
	}
      }
    }
    return E_kin;
}
    // par[0] = A1; par[1] = A2; par[2] = A3; par[3] = Ecm; par[4] = gam3; Var[0] = theta lab




void kinematic (){

  gStyle->SetOptStat (0);

  //outfile

  std::ofstream Omean("Mean_kin_fwd.dat");
  std::ofstream Omean_b("Mean_kin_bwd.dat");
  std::ofstream Omean_a("Mean_kin_fwd_a.dat");
  std::ofstream Omean_b_a("Mean_kin_bwd_a.dat");

  //****************************************Computing kinematic****************************************

  //----------------Proton-------------------



  //filling values
  //proton
  E_inf = 10.30; //(MeV) beam energy
  v_inf = TMath::Sqrt (2*E_inf/(12*931.5));
  A12 = A1*A2/(A1+A2);
  mu = A12*m;
  Ecm = TMath::Power (v_inf,2)*mu/2;
  Q_fus = m*(A1 + A2 - A3 - A4);

  for(int i=0;i<11;i++){
    Q_eff[i] = Q_fus - Eex[i];
    std::cout << Q_eff[i] << std::endl;
    gam3[i] = sqrt(A1*A3/(A2*A4)*(Ecm/(Ecm+Q_eff[i])));
  }
  //alpha
  Q_fus_a = m*(A1 + A2 - A3_a - A4_a);
  for(int i=0;i<5;i++){
    Q_eff_a[i] = Q_fus_a - Eex_a[i];
    std::cout << Q_eff_a[i] << std::endl;
    gam3_a[i] = sqrt(A1*A3_a/(A2*A4_a)*(Ecm/(Ecm+Q_eff_a[i])));
  }


  //*******************2D Hist ang vs ene *************************
  

  
  for (Int_t i = 0; i <= n_ch_s3; i++)
    {
      bin_s3f[i] = TMath::ATan ((offs_s3 + r_i_s3 + i*d_s3)/z_s3f);
      bin_s3b[n_ch_s3 - i] = TMath::Pi () + TMath::ATan ((offs_s3 + r_i_s3 + i*d_s3)/z_s3b);// swapp direction
      std::cout << bin_s3f[i] << std::endl;
    } 

  TF1 *f_EneVsAng_fwd_p[11];
  TF1 *f_EneVsAng_bwd_p[11];
  TF1 *f_EneVsAng_fwd_a[5];
  TF1 *f_EneVsAng_bwd_a[5];
  //Proton
  
  for (Int_t i = 0; i < 11; i++)
    {
      f_EneVsAng_fwd_p[i] = new TF1(Form("f_EneVsAng_fwd_p[%i]",i), Energy, theta_min_S3_fwd/180*TMath::Pi(), theta_max_S3_fwd/180*TMath::Pi(), 6); //  par[0] = A1; par[1] = A2; par[2] = A3; par[3] = Ecm; par[4] = gam3; Var[0] = theta lab
      f_EneVsAng_fwd_p[i]->SetParameters (A1, A2, A3, Ecm, gam3[i], alu_fwd);
      f_EneVsAng_bwd_p[i] = new TF1(Form("f_EneVsAng_bwd_p[%i]",i), Energy, theta_min_S3_bwd/180*TMath::Pi(), theta_max_S3_bwd/180*TMath::Pi(), 6); //  par[0] = A1; par[1] = A2; par[2] = A3; par[3] = Ecm; par[4] = gam3; Var[0] = theta lab
      f_EneVsAng_bwd_p[i]->SetParameters (A1, A2, A3, Ecm, gam3[i], alu_bwd);
    }

  //Alpha
  
  for (Int_t i = 0; i < 5; i++)
    {
      f_EneVsAng_fwd_a[i] = new TF1(Form("f_EneVsAng_fwd_p[%i]",i), Energy_alpha, theta_min_S3_fwd/180*TMath::Pi(), theta_max_S3_fwd/180*TMath::Pi(), 6); //  par[0] = A1; par[1] = A2; par[2] = A3; par[3] = Ecm; par[4] = gam3; Var[0] = theta lab
      f_EneVsAng_fwd_a[i]->SetParameters (A1, A2, A3_a, Ecm, gam3_a[i], alu_fwd);
      f_EneVsAng_bwd_a[i] = new TF1(Form("f_EneVsAng_bwd_p[%i]",i), Energy_alpha, theta_min_S3_bwd/180*TMath::Pi(), theta_max_S3_bwd/180*TMath::Pi(), 6); //  par[0] = A1; par[1] = A2; par[2] = A3; par[3] = Ecm; par[4] = gam3; Var[0] = theta lab
      f_EneVsAng_bwd_a[i]->SetParameters (A1, A2, A3_a, Ecm, gam3_a[i], alu_bwd);
    }

  TGraph *g_AngVsEne_fwd_p[11];
  TGraph *g_AngVsEne_bwd_p[11];
  
  Double_t Ang_fwd[1000];
  Double_t Ang_bwd[1000];
  Double_t Ene_fwd_p[11][1000];
  Double_t Ene_bwd_p[11][1000];

  Double_t Ang_fwd_fit[24], Ene_fwd_fit[11][24];
  Double_t Ang_bwd_fit[24], Ene_bwd_fit[11][24];
  
  for (Int_t i = 0; i < 24; i++)
    {
      Ang_fwd_fit[i] = (bin_s3f[i+1] - bin_s3f[i])/2 + bin_s3f[i];
      Ang_bwd_fit[i] = (bin_s3b[i+1] - bin_s3b[i])/2 + bin_s3b[i];
      // Ang_fwd_fit[i] = bin_s3f[i];
      // Ang_bwd_fit[i] = bin_s3b[i];
    }
  
  for ( Int_t j = 0; j < 11; j++)
    {
      for (Int_t k = 0; k < 24; k++)
	{
	  Ene_fwd_fit[j][k] = f_EneVsAng_fwd_p[j]->Eval(Ang_fwd_fit[k]);
	  Ene_bwd_fit[j][k] = f_EneVsAng_bwd_p[j]->Eval(Ang_bwd_fit[k]);
	  Omean << Ang_fwd_fit[k] << " " << Ene_fwd_fit[j][k] << std::endl;
	  Omean_b << Ang_bwd_fit[k] << " " << Ene_bwd_fit[j][k] << std::endl;
	}

      for (Int_t i = 0; i < 200; i++)
	{
	  Ang_fwd[i] = theta_min_S3_fwd*TMath::Pi ()/180 + (theta_max_S3_fwd - theta_min_S3_fwd)*TMath::Pi ()/(180*200)*i;
	  Ang_bwd[i] = theta_min_S3_bwd*TMath::Pi ()/180 + (theta_max_S3_bwd - theta_min_S3_bwd)*TMath::Pi ()/(180*200)*i;
	  Ene_fwd_p[j][i] = f_EneVsAng_fwd_p[j]->Eval(Ang_fwd[i]);
	  // std::cout << "\n";
	  Ene_bwd_p[j][i] = f_EneVsAng_bwd_p[j]->Eval(Ang_bwd[i]);
	}
      // std::cout << "\n";
      // std::cout << "\n";
      g_AngVsEne_fwd_p[j] = new TGraph (200, Ene_fwd_p[j], Ang_fwd);
      g_AngVsEne_bwd_p[j] = new TGraph (200, Ene_bwd_p[j], Ang_bwd);
   }

  //alpha
  TGraph *g_AngVsEne_fwd_a[5];
  TGraph *g_AngVsEne_bwd_a[5];
  

  Double_t Ene_fwd_a[5][1000];
  Double_t Ene_bwd_a[5][1000];

  Double_t Ene_fwd_fit_a[5][24];
  Double_t Ene_bwd_fit_a[5][24];
  

  for ( Int_t j = 0; j < 5; j++)
    {
      for (Int_t k = 0; k < 24; k++)
	{
	  Ene_fwd_fit_a[j][k] = f_EneVsAng_fwd_a[j]->Eval(Ang_fwd_fit[k]);
	  Ene_bwd_fit_a[j][k] = f_EneVsAng_bwd_a[j]->Eval(Ang_bwd_fit[k]);
	  Omean_a << Ang_fwd_fit[k] << " " << Ene_fwd_fit_a[j][k] << std::endl;
	  Omean_b_a << Ang_bwd_fit[k] << " " << Ene_bwd_fit_a[j][k] << std::endl;
	}

      for (Int_t i = 0; i < 200; i++)
	{
	  Ene_fwd_a[j][i] = f_EneVsAng_fwd_a[j]->Eval(Ang_fwd[i]);
	  // std::cout << "\n";
	  Ene_bwd_a[j][i] = f_EneVsAng_bwd_a[j]->Eval(Ang_bwd[i]);
	}
      // std::cout << "\n";
      // std::cout << "\n";
      g_AngVsEne_fwd_a[j] = new TGraph (1000, Ene_fwd_a[j], Ang_fwd);
      g_AngVsEne_bwd_a[j] = new TGraph (1000, Ene_bwd_a[j], Ang_bwd);
   }




   TCanvas *C_f = new TCanvas ("C_f", "C_f", 700, 500);
   C_f->Draw();
   C_f->Divide (4,3);
   C_f->cd (1);
   g_AngVsEne_fwd_p[0]->SetLineColor(2);
   g_AngVsEne_fwd_p[0]->SetMarkerColor(2);
   g_AngVsEne_fwd_p[0]->Draw("AP");
   for (Int_t i = 1; i < 11; i++)
    {
      C_f->cd (i+1);
      g_AngVsEne_fwd_p[i]->SetLineColor(2);
      g_AngVsEne_fwd_p[i]->SetMarkerColor(2);
      g_AngVsEne_fwd_p[i]->Draw("AP");
    }

   TCanvas *C_f2 = new TCanvas ("C_f2", "C_f2", 700, 500);
   C_f2->Draw();
   C_f2->Divide (4,3);
   C_f2->cd (1);
   g_AngVsEne_fwd_a[0]->SetLineColor(4);
   g_AngVsEne_fwd_a[0]->SetMarkerColor(4);
   g_AngVsEne_fwd_a[0]->Draw("AP");
   for (Int_t i = 1; i < 5; i++)
    {
      C_f2->cd (i+1);
      g_AngVsEne_fwd_a[i]->SetLineColor(4);
      g_AngVsEne_fwd_a[i]->SetMarkerColor(4);
      g_AngVsEne_fwd_a[i]->Draw("AP");
    }
   
  Omean.close();
  Omean_b.close();
  Omean_b_a.close();
  Omean_a.close();
}
  
