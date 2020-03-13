void ComputeHistograms (){
  for (Int_t i = 0; i < 100; i++)
  {
    if (i < 50) h_ene_p[i] = new TH1F (Form ("h_ene_p[%i]", i), Form("imput [%i]", i+1), ene_p_bin, ene_p_low, ene_p_high);
    if (i >= 50) h_ene_p[i] = new TH1F (Form ("h_ene_p[%i]", i), Form("imput [%i]", i+1), ene_p_bin_bwd, ene_p_low, ene_p_high);
    if (i < 50) h_ene_p_step[i] = new TH1F (Form ("h_ene_p_step[%i]", i), Form("imput [%i]", i+1), ene_p_bin, ene_p_low, ene_p_high);
    if (i >= 50) h_ene_p_step[i] = new TH1F (Form ("h_ene_p_step[%i]", i), Form("imput [%i]", i+1), ene_p_bin_bwd, ene_p_low, ene_p_high);
    if (i < 50) h_ene_p_ratio[i] = new TH1F (Form ("h_ene_p_ratio[%i]", i), Form("imput [%i]", i+1), ene_p_bin, ene_p_low, ene_p_high);
    if (i >= 50) h_ene_p_ratio[i] = new TH1F (Form ("h_ene_p_ratio[%i]", i), Form("imput [%i]", i+1), ene_p_bin_bwd, ene_p_low, ene_p_high);
  }
}
// data loop
void ComputeData (){
  for (Long64_t i = 0; i < f_in->GetEntries ()/1; i++)
  //for (Long64_t i = f_in->GetEntries ()/2; i < f_in->GetEntries ()/1; i++)
  //for (Long64_t i = 0; i < f_in->GetEntries ()/2; i++)
  {
    ene_sum_p = 0.;
    det_sum_p = 0;

    f_in->GetEntry (i);
    if (i > 11 && i%((long long) f_in->GetEntries ()/10) == 0) std::cout << " " << (Double_t) (i*100.)/f_in->GetEntries () << "% done" << std::endl;


    for (Int_t j = 0; j < mult_p; j++){ // particles
      if (det_p->at (j) < 50){//FWD
        //if (mult_p != 1) continue;
        if (mult_p == 1) {
          h_ene_p_step[mask_s3[det_p->at (j) - 1] - 1]->Fill (ene_p->at (j)); // single detector energy
          h_ene_p[mask_s3[det_p->at (j) - 1] - 1]->Fill (ene_p->at (j)); // single detector energy
        }
        if (mult_p == 2){
          ene_sum_p+=ene_p->at (j);
          if (ene_p->at (j) > ene_p->at (det_sum_p)) det_sum_p = j;
          if (j == mult_p - 1) // sum energy
          {
            if (TMath::Abs(mask_s3[det_p->at (j)] - mask_s3[det_p->at (j - 1)]) == 1){
              if (ene_sum_p >= 2*Mean_Interval_Project[std::min(mask_s3[det_p->at (j - 1) - 1], mask_s3[det_p->at (j) - 1]) - 1] - 3*Sigma_Interval_Project[std::min(mask_s3[det_p->at (j - 1) - 1], mask_s3[det_p->at (j) - 1]) - 1] && ene_sum_p <= 2*Mean_Interval_Project[std::min(mask_s3[det_p->at (j - 1) - 1], mask_s3[det_p->at (j) - 1]) - 1] + 3*Sigma_Interval_Project[std::min(mask_s3[det_p->at (j - 1) - 1], mask_s3[det_p->at (j) - 1]) - 1]) {
                if (TMath::Sqrt(1./2)*(ene_p->at (j - 1) - ene_p->at (j)) >= Mean_Project[std::min(mask_s3[det_p->at (j - 1) - 1], mask_s3[det_p->at (j) - 1]) - 1] - 3*Sigma_Project[std::min(mask_s3[det_p->at (j - 1) - 1], mask_s3[det_p->at (j) - 1]) - 1] && TMath::Sqrt(1./2)*(ene_p->at (j - 1) - ene_p->at (j)) <= Mean_Project[std::min(mask_s3[det_p->at (j - 1) - 1], mask_s3[det_p->at (j) - 1]) - 1] + 3*Sigma_Project[std::min(mask_s3[det_p->at (j - 1) - 1], mask_s3[det_p->at (j) - 1]) - 1]) {
                  h_ene_p_ratio[mask_s3[det_p->at (det_sum_p) - 1] - 1]->Fill (ene_sum_p);
                  h_ene_p_step[mask_s3[det_p->at (det_sum_p) - 1] -1]->SetBinContent (ene_sum_p*ene_p_bin/(ene_p_high - ene_p_low), h_ene_p_step[mask_s3[det_p->at (det_sum_p) - 1] -1]->GetBinContent (ene_sum_p*ene_p_bin/(ene_p_high - ene_p_low)) + Ratio_project[std::min(mask_s3[det_p->at (j - 1) - 1], mask_s3[det_p->at (j) - 1]) - 1]);
                  h_ene_p[mask_s3[det_p->at (det_sum_p) - 1] -1]->SetBinContent ((ene_sum_p*Slope_m2_fwd[mask_s3[det_p->at (det_sum_p) - 1] - 1] + Offset_m2_fwd[mask_s3[det_p->at (det_sum_p) - 1] - 1])*ene_p_bin/(ene_p_high - ene_p_low), h_ene_p_step[mask_s3[det_p->at (det_sum_p) - 1] -1]->GetBinContent ((ene_sum_p*Slope_m2_fwd[mask_s3[det_p->at (det_sum_p) - 1] - 1] + Offset_m2_fwd[mask_s3[det_p->at (det_sum_p) - 1] - 1])*ene_p_bin/(ene_p_high - ene_p_low)) + Ratio_project[std::min(mask_s3[det_p->at (j - 1) - 1], mask_s3[det_p->at (j) - 1]) - 1]);
                }
                else{
                  h_ene_p[mask_s3[det_p->at (det_sum_p) - 1] - 1]->Fill (ene_sum_p*Slope_m2_fwd[mask_s3[det_p->at (det_sum_p) - 1] - 1] + Offset_m2_fwd[mask_s3[det_p->at (det_sum_p) - 1] - 1]);
                }
              }
              else {
                h_ene_p[mask_s3[det_p->at (det_sum_p) - 1] - 1]->Fill (ene_sum_p*Slope_m2_fwd[mask_s3[det_p->at (det_sum_p) - 1] - 1] + Offset_m2_fwd[mask_s3[det_p->at (det_sum_p) - 1] - 1]);
              }
            }
            if (TMath::Abs(mask_s3[det_p->at (j)] - mask_s3[det_p->at (j - 1)]) != 1) {
              h_ene_p[mask_s3[det_p->at (j) - 1] - 1]->Fill (ene_p->at (j)); // single detector energy
              h_ene_p[mask_s3[det_p->at (j - 1) - 1] - 1]->Fill (ene_p->at (j - 1)); // single detector energy
            }
          }
        }
      }
      else { //BWD
        if (mult_p == 1) {
          h_ene_p[mask_s3[det_p->at (j) - 1] - 1]->Fill (ene_p->at (j)); // single detector energy
        }
        if (mult_p == 2){
          ene_sum_p+=ene_p->at (j);
          if (ene_p->at (j) > ene_p->at (det_sum_p)) det_sum_p = j;
          if (j == mult_p - 1) // sum energy
          {
            if (TMath::Abs(mask_s3[det_p->at (j)] - mask_s3[det_p->at (j - 1)]) == 1){
              h_ene_p[mask_s3[det_p->at (det_sum_p) - 1] - 1]->Fill (ene_sum_p*Slope_m2_bwd[mask_s3[det_p->at (det_sum_p) - 1] - 76] + Offset_m2_bwd[mask_s3[det_p->at (det_sum_p) - 1] - 76]);
            }
            else {
              h_ene_p[mask_s3[det_p->at (j) - 1] - 1]->Fill (ene_p->at (j)); // single detector energy
              h_ene_p[mask_s3[det_p->at (j - 1) - 1] - 1]->Fill (ene_p->at (j - 1)); // single detector energy
            }
          }
        }
      }
    }
  }
}


void ComputeOutputFwd (){
  for (Int_t i = 0; i < 8; i++)
  {
    OMean_fwd_p << i << " ";
    OAmp_fwd_p << i << " ";
    OSigma_fwd_p << i << " ";
    for (Int_t j = 0; j < 24; j++)
    {
      OMean_fwd_p << Mean_fwd_p[i][j] << " ";
      OAmp_fwd_p << Amp_fwd_p[i][j] << " ";
      OSigma_fwd_p << Sigma_fwd_p[i][j] << " ";
    }
    OMean_fwd_p << std::endl;
    OAmp_fwd_p << std::endl;
    OSigma_fwd_p << std::endl;

    if (i < 3){
      OMean_fwd_a << i << " ";
      OAmp_fwd_a << i << " ";
      OSigma_fwd_a << i << " ";
      for (Int_t j = 0; j < 24; j++)
      {
        OMean_fwd_a << Mean_fwd_a[i][j] << " ";
        OAmp_fwd_a << Amp_fwd_a[i][j] << " ";
        OSigma_fwd_a << Sigma_fwd_a[i][j] << " ";
      }
      OMean_fwd_a << std::endl;
      OAmp_fwd_a << std::endl;
      OSigma_fwd_a << std::endl;
    }
  }

  for (Int_t i = 0; i < 8; i++)
  {
    OMean_fwd_p_err << i << " ";
    OAmp_fwd_p_err << i << " ";
    OSigma_fwd_p_err << i << " ";
    for (Int_t j = 0; j < 24; j++)
    {
      OMean_fwd_p_err << Mean_fwd_p_err[i][j] << " ";
      OAmp_fwd_p_err << Amp_fwd_p_err[i][j] << " ";
      OSigma_fwd_p_err << Sigma_fwd_p_err[i][j] << " ";
    }
    OMean_fwd_p_err << std::endl;
    OAmp_fwd_p_err << std::endl;
    OSigma_fwd_p_err << std::endl;

    if (i < 3){
      OMean_fwd_a_err << i << " ";
      OAmp_fwd_a_err << i << " ";
      OSigma_fwd_a_err << i << " ";
      for (Int_t j = 0; j < 24; j++)
      {
        OMean_fwd_a_err << Mean_fwd_a_err[i][j] << " ";
        OAmp_fwd_a_err << Amp_fwd_a_err[i][j] << " ";
        OSigma_fwd_a_err << Sigma_fwd_a_err[i][j] << " ";
      }
      OMean_fwd_a_err << std::endl;
      OAmp_fwd_a_err << std::endl;
      OSigma_fwd_a_err << std::endl;
    }
  }
}

void ComputeCloseOFiles (){
  OMean_fwd_p.close ();
  OMean_fwd_a.close ();
  OSigma_fwd_p.close ();
  OSigma_fwd_a.close ();
  OAmp_fwd_p.close ();
  OAmp_fwd_a.close ();

  OMean_fwd_p_err.close ();
  OMean_fwd_a_err.close ();
  OSigma_fwd_p_err.close ();
  OSigma_fwd_a_err.close ();
  OAmp_fwd_p_err.close ();
  OAmp_fwd_a_err.close ();

  OMean_p0_bwd.close ();
  OMean_p1_bwd.close ();
  OMean_a0_bwd.close ();
  OMean_p2_bwd.close ();
  OMean_p3_bwd.close ();
  OMean_p45_bwd.close ();
  OMean_p7_bwd.close ();
  OMean_p89_bwd.close ();


  OMean_p0_bwd_err.close ();
  OMean_p1_bwd_err.close ();
  OMean_a0_bwd_err.close ();
  OMean_p2_bwd_err.close ();
  OMean_p3_bwd_err.close ();
  OMean_p45_bwd_err.close ();
  OMean_p7_bwd_err.close ();
  OMean_p89_bwd_err.close ();

  OAmp_p0_bwd.close ();
  OAmp_p1_bwd.close ();
  OAmp_a0_bwd.close ();
  OAmp_p2_bwd.close ();
  OAmp_p3_bwd.close ();
  OAmp_p45_bwd.close ();
  OAmp_p7_bwd.close ();
  OAmp_p89_bwd.close ();

  OSigma_p0_bwd_err.close ();
  OSigma_p1_bwd_err.close ();
  OSigma_a0_bwd_err.close ();
  OSigma_p2_bwd_err.close ();
  OSigma_p3_bwd_err.close ();
  OSigma_p45_bwd_err.close ();
  OSigma_p7_bwd_err.close ();
  OSigma_p89_bwd_err.close ();

  OSigma_p0_bwd.close ();
  OSigma_p1_bwd.close ();
  OSigma_a0_bwd.close ();
  OSigma_p2_bwd.close ();
  OSigma_p3_bwd.close ();
  OSigma_p45_bwd.close ();
  OSigma_p7_bwd.close ();
  OSigma_p89_bwd.close ();

  OAmp_p0_bwd_err.close ();
  OAmp_p1_bwd_err.close ();
  OAmp_a0_bwd_err.close ();
  OAmp_p2_bwd_err.close ();
  OAmp_p3_bwd_err.close ();
  OAmp_p45_bwd_err.close ();
  OAmp_p7_bwd_err.close ();
  OAmp_p89_bwd_err.close ();
}

void ComputeTree (){
  f_in->Add ("r010_ene_gp.root"); // no downscaling
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
}

void ComputeFiles (){
  for (Int_t i = 0; i < 24; i++){
    IFileCalib >> Slope_m2_fwd[i] >> Offset_m2_fwd[i];
    IFileCalibBwd >> Slope_m2_bwd[i] >> Offset_m2_bwd[i];
    if (i < 23) {
      IFileProject >> Mean_Project[i] >> Sigma_Project[i] >> Ratio_project[i];
      IFileIntervalProject >> Mean_Interval_Project[i] >> Sigma_Interval_Project[i];
    }
  }
  IFileProject.close ();
  IFileIntervalProject.close ();
  IFileCalib.close ();
  IFileCalibBwd.close ();
}
