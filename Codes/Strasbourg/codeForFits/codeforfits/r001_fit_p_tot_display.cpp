void DisplayFitFwd (){
  c_coinc[4] = new TCanvas("c_coinc[4]", "", 700, 500);
  c_coinc[4]->Draw("");
  c_coinc[4]->Divide (5,5);// order S3F
  for (Int_t pad = 0; pad < 24; pad++)
  {
    c_coinc[4]->cd (pad + 1)->SetTickx ();
    c_coinc[4]->cd (pad + 1)->SetTicky ();
    if (pad == 0)
    {
      Double_t fit_low_1 = 13.6;
      Double_t fit_high_1 = 14.;
      f_fit_1_fwd[pad] = new TF1 (Form ("f_fit_1_fwd[%i]", pad), my_gaus, fit_low_1, fit_high_1, 3);
      f_fit_1_fwd[pad]->SetParameters(425./M, 13.8, 0.1);
      f_fit_1_fwd[pad]->SetParLimits(2, 0, 1000);
      h_ene_p[pad]->Fit (f_fit_1_fwd[pad], "R");
      f_fit_1_fwd[pad]->SetLineColor(2);
      Double_t fit_low_2 = 11.6;
      Double_t fit_high_2 = 12.;
      f_fit_2_fwd[pad] = new TF1 (Form ("f_fit_2_fwd[%i]", pad), my_gaus, fit_low_2, fit_high_2, 3);
      f_fit_2_fwd[pad]->SetParameters(240./M, 11.8, 0.1);
      f_fit_2_fwd[pad]->SetParLimits(2, 0, 1000);
      h_ene_p[pad]->Fit (f_fit_2_fwd[pad], "R");
      f_fit_2_fwd[pad]->SetLineColor(2);

      Double_t fit_low_3 = 8.4;
      Double_t fit_high_3 = 8.8;
      f_fit_3_fwd[pad] = new TF1 (Form ("f_fit_3_fwd[%i]", pad), my_gaus, fit_low_3, fit_high_3, 3);
      f_fit_3_fwd[pad]->SetParameters(85./M, 8.6, 0.1);
      f_fit_3_fwd[pad]->SetParLimits(2, 0, 1000);
      h_ene_p[pad]->Fit (f_fit_3_fwd[pad], "R");
      f_fit_3_fwd[pad]->SetLineColor(2);

      Double_t fit_low_4 = 7.;
      Double_t fit_high_4 = 7.8;
      f_fit_4_fwd[pad] = new TF1 (Form ("f_fit_4_fwd[%i]", pad), my_resp, fit_low_4, fit_high_4, 8);
      f_fit_4_fwd[pad]->SetParameters(275./M, 7.2, 0.1, 160./M, 7.6, 0.1, 6, -5);
      f_fit_4_fwd[pad]->SetParLimits(2, 0, 1000);
      f_fit_4_fwd[pad]->SetParLimits(5, 0, 1000);
      //f_fit_4_fwd[pad]->SetParLimits(6, 40, 60);
      //f_fit_4_fwd[pad]->SetParLimits(7, 40./12, 60./12);
      h_ene_p[pad]->Fit (f_fit_4_fwd[pad], "R");
      f_fit_4_fwd[pad]->SetLineColor(2);

      /*Double_t fit_low_4_a = 7.;
      Double_t fit_high_4_a = 7.4;
      f_fit_4_fwd_a[pad] = new TF1 (Form ("f_fit_4_fwd_a[%i]", pad), my_gaus, fit_low_4_a, fit_high_4_a, 3);
      f_fit_4_fwd_a[pad]->SetParameters(275./M, 7.2, 0.1);
      h_ene_p[Map_fwd[pad]]->Fit (f_fit_4_fwd_a[pad], "R");
      f_fit_4_fwd_a[pad]->SetLineColor(2);

      Double_t fit_low_4_b = 7.5;
      Double_t fit_high_4_b = 7.7;
      f_fit_4_fwd_b[pad] = new TF1 (Form ("f_fit_4_fwd_b[%i]", pad), my_gaus, fit_low_4_b, fit_high_4_b, 3);
      f_fit_4_fwd_b[pad]->SetParameters(160./M, 7.6, 0.1);
      h_ene_p[Map_fwd[pad]]->Fit (f_fit_4_fwd_b[pad], "R");
      f_fit_4_fwd_b[pad]->SetLineColor(2);*/

      Double_t fit_low_5 = 6.3;
      Double_t fit_high_5 = 7;
      f_fit_5_fwd[pad] = new TF1 (Form ("f_fit_5_fwd[%i]", pad), my_resp, fit_low_5, fit_high_5, 8);
      f_fit_5_fwd[pad]->SetParameters(370./M, 6.55, 0.1, 300./M, 6.85, 0.1, 6, -5);
      f_fit_5_fwd[pad]->SetParLimits(2, 0, 1000);
      f_fit_5_fwd[pad]->SetParLimits(5, 0, 1000);
      //f_fit_5_fwd[pad]->SetParLimits(6, 40, 60);
      //f_fit_5_fwd[pad]->SetParLimits(7, 40./12, 60./12);
      h_ene_p[pad]->Fit (f_fit_5_fwd[pad], "R");
      f_fit_5_fwd[pad]->SetLineColor(2);

      Double_t fit_low_789 =5.;
      Double_t fit_high_789 = 6.;
      f_fit_789_fwd[pad] = new TF1 (Form ("f_fit_789_fwd[%i]", pad), my_resp2, fit_low_789, fit_high_789, 8);
      f_fit_789_fwd[pad]->SetParameters(150, 5.35, 0.1, 200, 5.6, 0.075, 50, -50./12);
      f_fit_789_fwd[pad]->SetParLimits(2, 0, 1000);
      f_fit_789_fwd[pad]->SetParLimits(5, 0, 1000);
      //f_fit_789_fwd[pad]->SetParLimits(6, 40, 60);
      //f_fit_789_fwd[pad]->SetParLimits(7, 40./12, 60./12);
      h_ene_p[pad]->Fit (f_fit_789_fwd[pad], "R");
      f_fit_789_fwd[pad]->SetLineColor(2);
    }

    else
    {
      f_fit_1_fwd[pad] = new TF1 (Form ("f_fit_1_fwd[%i]", pad), my_gaus, f_fit_1_fwd[pad - 1]->GetParameter(1) - 0.50, f_fit_1_fwd[pad - 1]->GetParameter(1) + 0.50, 3);
      f_fit_1_fwd[pad]->SetParameters(f_fit_1_fwd[pad - 1]->GetParameter(0), f_fit_1_fwd[pad - 1]->GetParameter(1), f_fit_1_fwd[pad - 1]->GetParameter(2));
      f_fit_1_fwd[pad]->SetParLimits(2, 0, 1000);
      h_ene_p[pad]->Fit (f_fit_1_fwd[pad], "R");
      f_fit_1_fwd[pad]->SetLineColor(2);

      f_fit_2_fwd[pad] = new TF1 (Form ("f_fit_2_fwd[%i]", pad), my_gaus, f_fit_2_fwd[pad - 1]->GetParameter(1) - 0.50, f_fit_2_fwd[pad - 1]->GetParameter(1) + 0.50, 3);
      f_fit_2_fwd[pad]->SetParameters(f_fit_2_fwd[pad - 1]->GetParameter(0), f_fit_2_fwd[pad - 1]->GetParameter(1), f_fit_2_fwd[pad - 1]->GetParameter(2));
      f_fit_2_fwd[pad]->SetParLimits(2, 0, 1000);
      h_ene_p[pad]->Fit (f_fit_2_fwd[pad], "R");
      f_fit_2_fwd[pad]->SetLineColor(2);
      if (pad < 15){
        //if (pad < 15){
        f_fit_3_fwd[pad] = new TF1 (Form ("f_fit_3_fwd[%i]", pad), my_gaus, f_fit_3_fwd[pad - 1]->GetParameter(1) - 0.35, f_fit_3_fwd[pad - 1]->GetParameter(1) + 0.25, 3);
        f_fit_3_fwd[pad]->SetParameters(f_fit_3_fwd[pad - 1]->GetParameter(0), f_fit_3_fwd[pad - 1]->GetParameter(1), f_fit_3_fwd[pad - 1]->GetParameter(2));
        f_fit_3_fwd[pad]->SetParLimits(2, 0, 1000);
        h_ene_p[pad]->Fit (f_fit_3_fwd[pad], "R");
        f_fit_3_fwd[pad]->SetLineColor(2);
        // }
        /* else if (pad == 15){
        f_fit_3_fwd[pad] = new TF1 (Form ("f_fit_3_fwd[%i]", pad), my_resp2, 7.35, f_fit_3_fwd[pad - 1]->GetParameter(1) + 0.25, 8);
        f_fit_3_fwd[pad]->SetParameters(60, 7.355, 0.15, f_fit_3_fwd[pad - 1]->GetParameter(0), f_fit_3_fwd[pad - 1]->GetParameter(1), f_fit_3_fwd[pad - 1]->GetParameter(2));
        h_ene_p[pad]->Fit (f_fit_3_fwd[pad], "R");
        f_fit_3_fwd[pad]->SetLineColor(2);
      }
      else if (pad > 15){
      f_fit_3_fwd[pad] = new TF1 (Form ("f_fit_3_fwd[%i]", pad), my_resp2, f_fit_3_fwd[pad - 1]->GetParameter(1) - 0.35, f_fit_3_fwd[pad - 1]->GetParameter(4) + 0.25, 8);
      f_fit_3_fwd[pad]->SetParameters(f_fit_3_fwd[pad - 1]->GetParameter(0), f_fit_3_fwd[pad - 1]->GetParameter(1), f_fit_3_fwd[pad - 1]->GetParameter(2), f_fit_3_fwd[pad - 1]->GetParameter(3), f_fit_3_fwd[pad - 1]->GetParameter(4), f_fit_3_fwd[pad - 1]->GetParameter(5));
      h_ene_p[pad]->Fit (f_fit_3_fwd[pad], "R");
      f_fit_3_fwd[pad]->SetLineColor(2);
    }*/
  }

  if (pad < 22){
    if (pad < 15){
      f_fit_4_fwd[pad] = new TF1 (Form ("f_fit_4_fwd[%i]", pad), my_resp, f_fit_4_fwd[pad - 1]->GetParameter(1) - 0.15, f_fit_4_fwd[pad - 1]->GetParameter(4) + 0.18, 8);
      f_fit_4_fwd[pad]->SetParameters(f_fit_4_fwd[pad - 1]->GetParameter(0), f_fit_4_fwd[pad - 1]->GetParameter(1), f_fit_4_fwd[pad - 1]->GetParameter(2), f_fit_4_fwd[pad - 1]->GetParameter(3), f_fit_4_fwd[pad - 1]->GetParameter(4), f_fit_4_fwd[pad - 1]->GetParameter(5), f_fit_4_fwd[pad - 1]->GetParameter(6), f_fit_4_fwd[pad - 1]->GetParameter(7));
      f_fit_4_fwd[pad]->SetParLimits(2, 0, 1000);
      f_fit_4_fwd[pad]->SetParLimits(5, 0, 1000);
      //f_fit_4_fwd[pad]->SetParLimits(6, 40, 60);
      //f_fit_4_fwd[pad]->SetParLimits(7, 40./12, 60./12);
      h_ene_p[pad]->Fit (f_fit_4_fwd[pad], "R");
      f_fit_4_fwd[pad]->SetLineColor(2);
    }
    else if (pad == 15){
      f_fit_4_fwd[pad] = new TF1 (Form ("f_fit_4_fwd[%i]", pad), my_resp3, f_fit_4_fwd[pad - 1]->GetParameter(1) - 0.15, 8.3, 11);
      f_fit_4_fwd[pad]->SetParameters(f_fit_4_fwd[pad - 1]->GetParameter(0), f_fit_4_fwd[pad - 1]->GetParameter(1), f_fit_4_fwd[pad - 1]->GetParameter(2), f_fit_4_fwd[pad - 1]->GetParameter(3), f_fit_4_fwd[pad - 1]->GetParameter(4), f_fit_4_fwd[pad - 1]->GetParameter(5), 45, 7.9, 0.1, f_fit_4_fwd[pad - 1]->GetParameter(6), f_fit_4_fwd[pad - 1]->GetParameter(7));
      f_fit_4_fwd[pad]->SetParLimits(2, 0, 1000);
      f_fit_4_fwd[pad]->SetParLimits(5, 0, 1000);
      f_fit_4_fwd[pad]->SetParLimits(8, 0, 1000);
      //f_fit_4_fwd[pad]->SetParLimits(6, 40, 60);
      //f_fit_4_fwd[pad]->SetParLimits(7, 40./12, 60./12);
      h_ene_p[pad]->Fit (f_fit_4_fwd[pad], "R");
      f_fit_4_fwd[pad]->SetLineColor(2);
    }
    else if (pad > 15){
      f_fit_4_fwd[pad] = new TF1 (Form ("f_fit_4_fwd[%i]", pad), my_resp3, f_fit_4_fwd[pad - 1]->GetParameter(1) - 0.15, f_fit_4_fwd[pad - 1]->GetParameter(7) + 0.18, 11);
      f_fit_4_fwd[pad]->SetParameters(f_fit_4_fwd[pad - 1]->GetParameter(0), f_fit_4_fwd[pad - 1]->GetParameter(1), f_fit_4_fwd[pad - 1]->GetParameter(2), f_fit_4_fwd[pad - 1]->GetParameter(3), f_fit_4_fwd[pad - 1]->GetParameter(4), f_fit_4_fwd[pad - 1]->GetParameter(5), f_fit_4_fwd[pad - 1]->GetParameter(6), f_fit_4_fwd[pad - 1]->GetParameter(7), f_fit_4_fwd[pad - 1]->GetParameter(8), f_fit_4_fwd[pad - 1]->GetParameter(9), f_fit_4_fwd[pad - 1]->GetParameter(10));
      f_fit_4_fwd[pad]->SetParLimits(2, 0, 1000);
      f_fit_4_fwd[pad]->SetParLimits(5, 0, 1000);
      f_fit_4_fwd[pad]->SetParLimits(8, 0, 1000);
      //f_fit_4_fwd[pad]->SetParLimits(6, 40, 60);
      //f_fit_4_fwd[pad]->SetParLimits(7, 40./12, 60./12);
      h_ene_p[pad]->Fit (f_fit_4_fwd[pad], "R");
      f_fit_4_fwd[pad]->SetLineColor(2);
    }
  }
  /* if (pad == 12)
  {
  f_fit_4_fwd_a[pad] = new TF1 (Form ("f_fit_4_fwd_a[%i]", pad), my_gaus, 7.3, 7.5, 3);
  f_fit_4_fwd_a[pad]->SetParameters(60, 7.38, 0.05);
  h_ene_p[Map_fwd[pad]]->Fit (f_fit_4_fwd_a[pad], "R");
  f_fit_4_fwd_a[pad]->SetLineColor(2);
}
else
{
f_fit_4_fwd_a[pad] = new TF1 (Form ("f_fit_4_fwd_a[%i]", pad), my_gaus, f_fit_4_fwd_a[pad - 1]->GetParameter(1) - 0.15, f_fit_4_fwd_a[pad - 1]->GetParameter(1) + 0.15, 3);
f_fit_4_fwd_a[pad]->SetParameters(f_fit_4_fwd_a[pad - 1]->GetParameter(0), f_fit_4_fwd_a[pad - 1]->GetParameter(1), f_fit_4_fwd_a[pad - 1]->GetParameter(2));
h_ene_p[Map_fwd[pad]]->Fit (f_fit_4_fwd_a[pad], "R");
f_fit_4_fwd_a[pad]->SetLineColor(2);
}
f_fit_4_fwd_b[pad] = new TF1 (Form ("f_fit_4_fwd_b[%i]", pad), my_gaus, f_fit_4_fwd_b[pad - 1]->GetParameter(1) - 0.15, f_fit_4_fwd_b[pad - 1]->GetParameter(1) + 0.15, 3);
f_fit_4_fwd_b[pad]->SetParameters(f_fit_4_fwd_b[pad - 1]->GetParameter(0), f_fit_4_fwd_b[pad - 1]->GetParameter(1), f_fit_4_fwd_b[pad - 1]->GetParameter(2));
h_ene_p[Map_fwd[pad]]->Fit (f_fit_4_fwd_b[pad], "R");
f_fit_4_fwd_b[pad]->SetLineColor(2);*/

if (pad < 11){
  f_fit_5_fwd[pad] = new TF1 (Form ("f_fit_5_fwd[%i]", pad), my_resp, f_fit_5_fwd[pad - 1]->GetParameter(1) - 0.3, f_fit_5_fwd[pad - 1]->GetParameter(4) + 0.15, 8);
  f_fit_5_fwd[pad]->SetParameters(f_fit_5_fwd[pad - 1]->GetParameter(0), f_fit_5_fwd[pad - 1]->GetParameter(1), f_fit_5_fwd[pad - 1]->GetParameter(2), f_fit_5_fwd[pad - 1]->GetParameter(3), f_fit_5_fwd[pad - 1]->GetParameter(4), f_fit_5_fwd[pad - 1]->GetParameter(5), f_fit_5_fwd[pad - 1]->GetParameter(6), f_fit_5_fwd[pad - 1]->GetParameter(7));
  f_fit_5_fwd[pad]->SetParLimits(2, 0, 1000);
  f_fit_5_fwd[pad]->SetParLimits(5, 0, 1000);
  //f_fit_5_fwd[pad]->SetParLimits(6, 40, 60);
  //f_fit_5_fwd[pad]->SetParLimits(7, 40./12, 60./12);
  h_ene_p[pad]->Fit (f_fit_5_fwd[pad], "R");
  f_fit_5_fwd[pad]->SetLineColor(2);
}
else if (pad == 11) {
  f_fit_5_fwd[pad] = new TF1 (Form ("f_fit_5_fwd[%i]", pad), my_resp3, f_fit_5_fwd[pad - 1]->GetParameter(1) - 0.3, f_fit_5_fwd[pad - 1]->GetParameter(4) + 0.15, 11);
  f_fit_5_fwd[pad]->SetParameters(f_fit_5_fwd[pad - 1]->GetParameter(0), f_fit_5_fwd[pad - 1]->GetParameter(1), f_fit_5_fwd[pad - 1]->GetParameter(2), 120, 6.3, 0.1, f_fit_5_fwd[pad - 1]->GetParameter(3), f_fit_5_fwd[pad - 1]->GetParameter(4), f_fit_5_fwd[pad - 1]->GetParameter(5), f_fit_5_fwd[pad - 1]->GetParameter(6), f_fit_5_fwd[pad - 1]->GetParameter(7));
  f_fit_5_fwd[pad]->SetParLimits(4, 6.25, 6.40);
  f_fit_5_fwd[pad]->SetParLimits(5, 0.01, 0.1);
  //f_fit_5_fwd[pad]->SetParLimits(7, 40./12, 60./12);
  h_ene_p[pad]->Fit (f_fit_5_fwd[pad], "R");
  f_fit_5_fwd[pad]->SetLineColor(2);
}

else if (pad > 11 && pad < 18){
  f_fit_5_fwd[pad] = new TF1 (Form ("f_fit_5_fwd[%i]", pad), my_resp3, f_fit_5_fwd[pad - 1]->GetParameter(1) - 0.3, f_fit_5_fwd[pad - 1]->GetParameter(7) + 0.1, 11);
  f_fit_5_fwd[pad]->SetParameters(f_fit_5_fwd[pad - 1]->GetParameter(0), f_fit_5_fwd[pad - 1]->GetParameter(1), f_fit_5_fwd[pad - 1]->GetParameter(2), f_fit_5_fwd[pad - 1]->GetParameter(3), f_fit_5_fwd[pad - 1]->GetParameter(4), f_fit_5_fwd[pad - 1]->GetParameter(5), f_fit_5_fwd[pad - 1]->GetParameter(6), f_fit_5_fwd[pad - 1]->GetParameter(7), f_fit_5_fwd[pad - 1]->GetParameter(8), f_fit_5_fwd[pad - 1]->GetParameter(9), f_fit_5_fwd[pad - 1]->GetParameter(10));
  f_fit_5_fwd[pad]->SetParLimits(2, 0, 1000);
  f_fit_5_fwd[pad]->SetParLimits(5, 0, 1000);
  f_fit_5_fwd[pad]->SetParLimits(8, 0, 1000);
  //f_fit_5_fwd[pad]->SetParLimits(6, 40, 60);
  //f_fit_5_fwd[pad]->SetParLimits(7, 40./12, 60./12);
  h_ene_p[pad]->Fit (f_fit_5_fwd[pad], "R");
  f_fit_5_fwd[pad]->SetLineColor(2);
}
else if (pad == 18){
  f_fit_5_fwd[pad] = new TF1 (Form ("f_fit_5_fwd[%i]", pad), my_resp, f_fit_5_fwd[pad - 1]->GetParameter(4) - 0.15, f_fit_5_fwd[pad - 1]->GetParameter(7) + 0.1, 8);
  f_fit_5_fwd[pad]->SetParameters( f_fit_5_fwd[pad - 1]->GetParameter(3), f_fit_5_fwd[pad - 1]->GetParameter(4), f_fit_5_fwd[pad - 1]->GetParameter(5), f_fit_5_fwd[pad - 1]->GetParameter(6), f_fit_5_fwd[pad - 1]->GetParameter(7), f_fit_5_fwd[pad - 1]->GetParameter(8), f_fit_5_fwd[pad - 1]->GetParameter(9), f_fit_5_fwd[pad - 1]->GetParameter(10));
  f_fit_5_fwd[pad]->SetParLimits(2, 0, 1000);
  f_fit_5_fwd[pad]->SetParLimits(5, 0, 1000);
  //f_fit_5_fwd[pad]->SetParLimits(6, 40, 60);
  //f_fit_5_fwd[pad]->SetParLimits(7, 40./12, 60./12);
  h_ene_p[pad]->Fit (f_fit_5_fwd[pad], "R");
  f_fit_5_fwd[pad]->SetLineColor(2);
}
else if (pad > 18 && pad < 22){
  f_fit_5_fwd[pad] = new TF1 (Form ("f_fit_5_fwd[%i]", pad), my_resp, f_fit_5_fwd[pad - 1]->GetParameter(1) - 0.15, f_fit_5_fwd[pad - 1]->GetParameter(4) + 0.1, 8);
  f_fit_5_fwd[pad]->SetParameters( f_fit_5_fwd[pad - 1]->GetParameter(0), f_fit_5_fwd[pad - 1]->GetParameter(1), f_fit_5_fwd[pad - 1]->GetParameter(2), f_fit_5_fwd[pad - 1]->GetParameter(3), f_fit_5_fwd[pad - 1]->GetParameter(4), f_fit_5_fwd[pad - 1]->GetParameter(5), f_fit_5_fwd[pad - 1]->GetParameter(6), f_fit_5_fwd[pad - 1]->GetParameter(7));
  f_fit_5_fwd[pad]->SetParLimits(2, 0, 1000);
  //f_fit_5_fwd[pad]->SetParLimits(6, 40, 60);
  f_fit_5_fwd[pad]->SetParLimits(5, 0, 1000);
  //f_fit_5_fwd[pad]->SetParLimits(7, 40./12, 60./12);
  h_ene_p[pad]->Fit (f_fit_5_fwd[pad], "R");
  f_fit_5_fwd[pad]->SetLineColor(2);
}
else if (pad == 22) {
  f_fit_5_fwd[pad] = new TF1 (Form ("f_fit_5_fwd[%i]", pad), my_resp5, 5.95, 7.8, 17);
  f_fit_5_fwd[pad]->SetParameter(15, f_fit_5_fwd[pad - 1]->GetParameter(6));
  f_fit_5_fwd[pad]->SetParameter(16, f_fit_5_fwd[pad - 1]->GetParameter(7));
  f_fit_5_fwd[pad]->SetParameter(0, 80);
  f_fit_5_fwd[pad]->SetParameter(1, 6.15);
  f_fit_5_fwd[pad]->SetParLimits(1, 6.05, 6.25);
  f_fit_5_fwd[pad]->SetParameter(2, 0.1);
  f_fit_5_fwd[pad]->SetParLimits(2, 0.01, 0.1);
  f_fit_5_fwd[pad]->SetParameter(3, 210);
  f_fit_5_fwd[pad]->SetParameter(4, 6.45);
  f_fit_5_fwd[pad]->SetParLimits(4, 6.35, 6.55);
  f_fit_5_fwd[pad]->SetParameter(5, 0.1);
  f_fit_5_fwd[pad]->SetParLimits(5, 0.01, 0.1);
  f_fit_5_fwd[pad]->SetParameter(6, 120);
  f_fit_5_fwd[pad]->SetParameter(7, 6.75);
  f_fit_5_fwd[pad]->SetParLimits(7, 6.65, 6.85);
  f_fit_5_fwd[pad]->SetParameter(8, 0.1);
  f_fit_5_fwd[pad]->SetParLimits(8, 0.01, 0.1);
  f_fit_5_fwd[pad]->SetParameter(9, 85);
  f_fit_5_fwd[pad]->SetParameter(10, 7.15);
  f_fit_5_fwd[pad]->SetParLimits(10, 7.05, 7.25);
  f_fit_5_fwd[pad]->SetParameter(11, 0.1);
  f_fit_5_fwd[pad]->SetParLimits(11, 0.01, 0.2);
  f_fit_5_fwd[pad]->SetParameter(12, 75);
  f_fit_5_fwd[pad]->SetParameter(13, 7.5);
  f_fit_5_fwd[pad]->SetParLimits(13, 7.40, 7.60);
  f_fit_5_fwd[pad]->SetParameter(14, 0.1);
  f_fit_5_fwd[pad]->SetParLimits(14, 0.01, 0.2);
  //f_fit_5_fwd[pad]->SetParLimits(6, 40, 60);
  //f_fit_5_fwd[pad]->SetParLimits(7, 40./12, 60./12);
  f_fit_5_fwd[pad]->SetParLimits(2, 0, 1000);
  f_fit_5_fwd[pad]->SetParLimits(5, 0, 1000);
  f_fit_5_fwd[pad]->SetParLimits(8, 0, 1000);
  f_fit_5_fwd[pad]->SetParLimits(11, 0, 1000);
  f_fit_5_fwd[pad]->SetParLimits(14, 0, 1000);
  h_ene_p[pad]->Fit (f_fit_5_fwd[pad], "R");
  f_fit_5_fwd[pad]->SetLineColor(2);
}
else {
  f_fit_5_fwd[pad] = new TF1 (Form ("f_fit_5_fwd[%i]", pad), my_resp5, 5.95, 7.8, 17);
  f_fit_5_fwd[pad]->SetParameter(15, f_fit_5_fwd[pad - 1]->GetParameter(15));
  f_fit_5_fwd[pad]->SetParameter(16, f_fit_5_fwd[pad - 1]->GetParameter(16));
  f_fit_5_fwd[pad]->SetParameter(0, f_fit_5_fwd[pad - 1]->GetParameter(0));
  f_fit_5_fwd[pad]->SetParameter(1, f_fit_5_fwd[pad - 1]->GetParameter(1));
  f_fit_5_fwd[pad]->SetParameter(2, f_fit_5_fwd[pad - 1]->GetParameter(2));
  f_fit_5_fwd[pad]->SetParameter(3, f_fit_5_fwd[pad - 1]->GetParameter(3));
  f_fit_5_fwd[pad]->SetParameter(4, f_fit_5_fwd[pad - 1]->GetParameter(4));
  f_fit_5_fwd[pad]->SetParameter(5, f_fit_5_fwd[pad - 1]->GetParameter(5));
  f_fit_5_fwd[pad]->SetParameter(6, f_fit_5_fwd[pad - 1]->GetParameter(6));
  f_fit_5_fwd[pad]->SetParameter(7, f_fit_5_fwd[pad - 1]->GetParameter(7));
  f_fit_5_fwd[pad]->SetParameter(8, f_fit_5_fwd[pad - 1]->GetParameter(8));
  f_fit_5_fwd[pad]->SetParameter(9, f_fit_5_fwd[pad - 1]->GetParameter(9));
  f_fit_5_fwd[pad]->SetParameter(10, f_fit_5_fwd[pad - 1]->GetParameter(10));
  f_fit_5_fwd[pad]->SetParameter(11, f_fit_5_fwd[pad - 1]->GetParameter(11));
  f_fit_5_fwd[pad]->SetParameter(12, f_fit_5_fwd[pad - 1]->GetParameter(12));
  f_fit_5_fwd[pad]->SetParameter(13, f_fit_5_fwd[pad - 1]->GetParameter(13));
  f_fit_5_fwd[pad]->SetParameter(14, f_fit_5_fwd[pad - 1]->GetParameter(14));
  //f_fit_5_fwd[pad]->SetParLimits(6, 40, 60);
  //f_fit_5_fwd[pad]->SetParLimits(7, 40./12, 60./12);
  h_ene_p[pad]->Fit (f_fit_5_fwd[pad], "R");
  f_fit_5_fwd[pad]->SetLineColor(2);
}

if (pad < 18){
  f_fit_789_fwd[pad] = new TF1 (Form ("f_fit_789_fwd[%i]", pad), my_resp2, f_fit_789_fwd[pad - 1]->GetParameter(1) - 0.3, f_fit_789_fwd[pad - 1]->GetParameter(4) + 0.15, 8);
  f_fit_789_fwd[pad]->SetParameters(f_fit_789_fwd[pad - 1]->GetParameter(0), f_fit_789_fwd[pad - 1]->GetParameter(1), f_fit_789_fwd[pad - 1]->GetParameter(2), f_fit_789_fwd[pad - 1]->GetParameter(3), f_fit_789_fwd[pad - 1]->GetParameter(4), f_fit_789_fwd[pad - 1]->GetParameter(5), f_fit_789_fwd[pad - 1]->GetParameter(6), f_fit_789_fwd[pad - 1]->GetParameter(7));
  //f_fit_789_fwd[pad]->SetParLimits(6, 40, 60);
  //f_fit_789_fwd[pad]->SetParLimits(7, 40./12, 60./12);
  h_ene_p[pad]->Fit (f_fit_789_fwd[pad], "R");
  f_fit_789_fwd[pad]->SetLineColor(2);
}

else if (pad == 18){
  f_fit_789_fwd[pad] = new TF1 (Form ("f_fit_789_fwd[%i]", pad), my_resp4, f_fit_789_fwd[pad - 1]->GetParameter(1) - 0.3, 5.95, 11);
  f_fit_789_fwd[pad]->SetParameters(f_fit_789_fwd[pad - 1]->GetParameter(0), f_fit_789_fwd[pad - 1]->GetParameter(1), f_fit_789_fwd[pad - 1]->GetParameter(2), f_fit_789_fwd[pad - 1]->GetParameter(3), f_fit_789_fwd[pad - 1]->GetParameter(4), f_fit_789_fwd[pad - 1]->GetParameter(5), 150, 5.7, 0.1, f_fit_789_fwd[pad - 1]->GetParameter(6), f_fit_789_fwd[pad - 1]->GetParameter(7));
  //f_fit_789_fwd[pad]->SetParLimits(6, 40, 60);
  //f_fit_789_fwd[pad]->SetParLimits(7, 40./12, 60./12);
  h_ene_p[pad]->Fit (f_fit_789_fwd[pad], "R");
  f_fit_789_fwd[pad]->SetLineColor(2);
}

else{
  f_fit_789_fwd[pad] = new TF1 (Form ("f_fit_789_fwd[%i]", pad), my_resp4, f_fit_789_fwd[pad - 1]->GetParameter(1) - 0.3, f_fit_789_fwd[pad - 1]->GetParameter(7) + 0.15, 11);
  f_fit_789_fwd[pad]->SetParameters(f_fit_789_fwd[pad - 1]->GetParameter(0), f_fit_789_fwd[pad - 1]->GetParameter(1), f_fit_789_fwd[pad - 1]->GetParameter(2), f_fit_789_fwd[pad - 1]->GetParameter(3), f_fit_789_fwd[pad - 1]->GetParameter(4), f_fit_789_fwd[pad - 1]->GetParameter(5), f_fit_789_fwd[pad - 1]->GetParameter(6), f_fit_789_fwd[pad - 1]->GetParameter(7), f_fit_789_fwd[pad - 1]->GetParameter(8), f_fit_789_fwd[pad - 1]->GetParameter(9), f_fit_789_fwd[pad - 1]->GetParameter(10));
  //f_fit_789_fwd[pad]->SetParLimits(6, 40, 60);
  //f_fit_789_fwd[pad]->SetParLimits(7, 40./12, 60./12);
  h_ene_p[pad]->Fit (f_fit_789_fwd[pad], "R");
  f_fit_789_fwd[pad]->SetLineColor(2);
}

if (pad == 20){
  Double_t fit_low_p1 = 8.82;
  Double_t fit_high_p1 = 9.1;
  f_fit_p1_fwd[pad] = new TF1 (Form ("f_fit_p1_fwd[%i]", pad), my_gaus, fit_low_p1, fit_high_p1, 3);
  f_fit_p1_fwd[pad]->SetParameters(15., 8.95, 0.1);
  f_fit_p1_fwd[pad]->SetParLimits(2, 0, 1000);
  h_ene_p[pad]->Fit (f_fit_p1_fwd[pad], "R");
  f_fit_p1_fwd[pad]->SetLineColor(2);
}
else if (pad > 20){
  f_fit_p1_fwd[pad] = new TF1 (Form ("f_fit_p1_fwd[%i]", pad), my_gaus, f_fit_p1_fwd[pad - 1]->GetParameter(1) - 0.25, f_fit_p1_fwd[pad - 1]->GetParameter(1) + 0.25, 3);
  f_fit_p1_fwd[pad]->SetParameters(f_fit_p1_fwd[pad - 1]->GetParameter(0), f_fit_p1_fwd[pad - 1]->GetParameter(1), f_fit_p1_fwd[pad - 1]->GetParameter(2));
  h_ene_p[pad]->Fit (f_fit_p1_fwd[pad], "R");
  f_fit_p1_fwd[pad]->SetLineColor(2);
}
}
h_ene_p[pad]->GetXaxis ()->SetRangeUser (2., 15.);
h_ene_p[pad]->GetYaxis ()->SetRangeUser (0., 400.);
//if (pad > 10 && pad < 22) h_ene_p[pad]->GetXaxis ()->SetRangeUser (4.5, 8.);
// else if (pad >= 22) h_ene_p[pad]->GetXaxis ()->SetRangeUser (2, 10.);
h_ene_p[pad]->Draw ();
f_fit_1_fwd[pad]->Draw ("SAME");
f_fit_2_fwd[pad]->Draw ("SAME");
if (pad < 15)  f_fit_3_fwd[pad]->Draw ("SAME");
if (pad < 22)  f_fit_4_fwd[pad]->Draw ("SAME");
// f_fit_4_fwd_a[pad]->Draw ("SAME");
//f_fit_4_fwd_b[pad]->Draw ("SAME");
f_fit_5_fwd[pad]->Draw ("SAME");
f_fit_789_fwd[pad]->Draw ("SAME");


//***********************Extract Parameters*****************************************************************//

for (Int_t i = 0; i < 8; i++)
{
  Amp_fwd_p[i][pad] = -1;
  Mean_fwd_p[i][pad] = -1;
  Sigma_fwd_p[i][pad] = -1;
  if (i > 2) continue;
  Amp_fwd_a[i][pad] = -1;
  Mean_fwd_a[i][pad] = -1;
  Sigma_fwd_a[i][pad] = -1;
}

Amp_fwd_a[0][pad] = f_fit_1_fwd[pad]->GetParameter(0);
Mean_fwd_a[0][pad] = f_fit_1_fwd[pad]->GetParameter(1);
Sigma_fwd_a[0][pad] = f_fit_1_fwd[pad]->GetParameter(2)*ene_p_bin/(ene_p_high - ene_p_low);

Amp_fwd_a[1][pad] = f_fit_2_fwd[pad]->GetParameter(0);
Mean_fwd_a[1][pad] = f_fit_2_fwd[pad]->GetParameter(1);
Sigma_fwd_a[1][pad] = f_fit_2_fwd[pad]->GetParameter(2)*ene_p_bin/(ene_p_high - ene_p_low);

if (pad < 15){
  Amp_fwd_a[2][pad] = f_fit_3_fwd[pad]->GetParameter(0);
  Mean_fwd_a[2][pad] = f_fit_3_fwd[pad]->GetParameter(1);
  Sigma_fwd_a[2][pad] = f_fit_3_fwd[pad]->GetParameter(2)*ene_p_bin/(ene_p_high - ene_p_low);
}
else if (pad >= 15 && pad < 22){
  Amp_fwd_a[2][pad] = f_fit_4_fwd[pad]->GetParameter(6);
  Mean_fwd_a[2][pad] = f_fit_4_fwd[pad]->GetParameter(7);
  Sigma_fwd_a[2][pad] = f_fit_4_fwd[pad]->GetParameter(8)*ene_p_bin/(ene_p_high - ene_p_low);
}
else if (pad >= 22){
  Amp_fwd_a[2][pad] = f_fit_5_fwd[pad]->GetParameter(12);
  Mean_fwd_a[2][pad] = f_fit_5_fwd[pad]->GetParameter(13);
  Sigma_fwd_a[2][pad] = f_fit_5_fwd[pad]->GetParameter(14)*ene_p_bin/(ene_p_high - ene_p_low);
}

if (pad >= 20){
  Amp_fwd_p[1][pad] = f_fit_p1_fwd[pad]->GetParameter(0);
  Mean_fwd_p[1][pad] = f_fit_p1_fwd[pad]->GetParameter(1);
  Sigma_fwd_p[1][pad] = f_fit_p1_fwd[pad]->GetParameter(2)*ene_p_bin/(ene_p_high - ene_p_low);
}

if (pad >= 11 && pad <= 20){
  Amp_fwd_p[2][pad] = f_fit_4_fwd[pad]->GetParameter(3);
  Mean_fwd_p[2][pad] = f_fit_4_fwd[pad]->GetParameter(4);
  Sigma_fwd_p[2][pad] = f_fit_4_fwd[pad]->GetParameter(5)*ene_p_bin/(ene_p_high - ene_p_low);
}
else if (pad > 21){
  Amp_fwd_p[2][pad] = f_fit_5_fwd[pad]->GetParameter(9);
  Mean_fwd_p[2][pad] = f_fit_5_fwd[pad]->GetParameter(10);
  Sigma_fwd_p[2][pad] = f_fit_5_fwd[pad]->GetParameter(11)*ene_p_bin/(ene_p_high - ene_p_low);
}

if (pad <= 9){
  Amp_fwd_p[3][pad] = f_fit_4_fwd[pad]->GetParameter(3);
  Mean_fwd_p[3][pad] = f_fit_4_fwd[pad]->GetParameter(4);
  Sigma_fwd_p[3][pad] = f_fit_4_fwd[pad]->GetParameter(5)*ene_p_bin/(ene_p_high - ene_p_low);

  if (pad == 0 || pad == 3){
    Amp_fwd_p[3][pad] = -1;
    Mean_fwd_p[3][pad] =-1;
    Sigma_fwd_p[3][pad] = -1;
  }
}

if (pad > 10 && pad < 18){
  Amp_fwd_p[6][pad] = f_fit_5_fwd[pad]->GetParameter(3);
  Mean_fwd_p[6][pad] = f_fit_5_fwd[pad]->GetParameter(4);
  Sigma_fwd_p[6][pad] = f_fit_5_fwd[pad]->GetParameter(5)*ene_p_bin/(ene_p_high - ene_p_low);
}
else if (pad >= 18){
  Amp_fwd_p[6][pad] = f_fit_5_fwd[pad]->GetParameter(0);
  Mean_fwd_p[6][pad] = f_fit_5_fwd[pad]->GetParameter(1);
  Sigma_fwd_p[6][pad] = f_fit_5_fwd[pad]->GetParameter(2)*ene_p_bin/(ene_p_high - ene_p_low);
}

if (pad < 18){
  Amp_fwd_p[7][pad] = f_fit_789_fwd[pad]->GetParameter(3);
  Mean_fwd_p[7][pad] = f_fit_789_fwd[pad]->GetParameter(4);
  Sigma_fwd_p[7][pad] = f_fit_789_fwd[pad]->GetParameter(5)*ene_p_bin/(ene_p_high - ene_p_low);
}

if (Amp_fwd_p[1][pad] == -1) Amp_fwd_p[1][pad] = 0;
if (Amp_fwd_p[0][pad] == -1) Amp_fwd_p[0][pad] = 0;
if (Mean_fwd_p[1][pad] == -1) Mean_fwd_p[1][pad] = 0;
if (Mean_fwd_p[0][pad] == -1) Mean_fwd_p[0][pad] = 0;
if (Sigma_fwd_p[1][pad] == -1) Sigma_fwd_p[1][pad] = 0;
if (Sigma_fwd_p[0][pad] == -1) Sigma_fwd_p[0][pad] = 0;

//*********errors

for (Int_t i = 0; i < 8; i++)
{
  Amp_fwd_p_err[i][pad] = -1;
  Mean_fwd_p_err[i][pad] = -1;
  Sigma_fwd_p_err[i][pad] = -1;
  if (i > 2) continue;
  Amp_fwd_a_err[i][pad] = -1;
  Mean_fwd_a_err[i][pad] = -1;
  Sigma_fwd_a_err[i][pad] = -1;
}

Amp_fwd_a_err[0][pad] = f_fit_2_fwd[pad]->GetParError(0);
Mean_fwd_a_err[0][pad] = f_fit_2_fwd[pad]->GetParError(1);
Sigma_fwd_a_err[0][pad] = f_fit_2_fwd[pad]->GetParError(2)*ene_p_bin/(ene_p_high - ene_p_low);

Amp_fwd_a_err[1][pad] = f_fit_2_fwd[pad]->GetParError(0);
Mean_fwd_a_err[1][pad] = f_fit_2_fwd[pad]->GetParError(1);
Sigma_fwd_a_err[1][pad] = f_fit_2_fwd[pad]->GetParError(2)*ene_p_bin/(ene_p_high - ene_p_low);

if (pad < 15){
  Amp_fwd_a_err[2][pad] = f_fit_3_fwd[pad]->GetParError(0);
  Mean_fwd_a_err[2][pad] = f_fit_3_fwd[pad]->GetParError(1);
  Sigma_fwd_a_err[2][pad] = f_fit_3_fwd[pad]->GetParError(2)*ene_p_bin/(ene_p_high - ene_p_low);
}
else if (pad >= 15 && pad < 22){
  Amp_fwd_a_err[2][pad] = f_fit_4_fwd[pad]->GetParError(6);
  Mean_fwd_a_err[2][pad] = f_fit_4_fwd[pad]->GetParError(7);
  Sigma_fwd_a_err[2][pad] = f_fit_4_fwd[pad]->GetParError(8)*ene_p_bin/(ene_p_high - ene_p_low);
}
else if (pad >= 22){
  Amp_fwd_a_err[2][pad] = f_fit_5_fwd[pad]->GetParError(12);
  Mean_fwd_a_err[2][pad] = f_fit_5_fwd[pad]->GetParError(13);
  Sigma_fwd_a_err[2][pad] = f_fit_5_fwd[pad]->GetParError(14)*ene_p_bin/(ene_p_high - ene_p_low);
}

if (pad >= 20){
  Amp_fwd_p_err[1][pad] = f_fit_p1_fwd[pad]->GetParError(0);
  Mean_fwd_p_err[1][pad] = f_fit_p1_fwd[pad]->GetParError(1);
  Sigma_fwd_p_err[1][pad] = f_fit_p1_fwd[pad]->GetParError(2)*ene_p_bin/(ene_p_high - ene_p_low);
}

if (pad >= 11 && pad <= 20){
  Amp_fwd_p_err[2][pad] = f_fit_4_fwd[pad]->GetParError(3);
  Mean_fwd_p_err[2][pad] = f_fit_4_fwd[pad]->GetParError(4);
  Sigma_fwd_p_err[2][pad] = f_fit_4_fwd[pad]->GetParError(5)*ene_p_bin/(ene_p_high - ene_p_low);
}
else if (pad > 21){
  Amp_fwd_p_err[2][pad] = f_fit_5_fwd[pad]->GetParError(9);
  Mean_fwd_p_err[2][pad] = f_fit_5_fwd[pad]->GetParError(10);
  Sigma_fwd_p_err[2][pad] = f_fit_5_fwd[pad]->GetParError(11)*ene_p_bin/(ene_p_high - ene_p_low);
}

if (pad <= 9){
  Amp_fwd_p_err[3][pad] = f_fit_4_fwd[pad]->GetParError(3);
  Mean_fwd_p_err[3][pad] = f_fit_4_fwd[pad]->GetParError(4);
  Sigma_fwd_p_err[3][pad] = f_fit_4_fwd[pad]->GetParError(5)*ene_p_bin/(ene_p_high - ene_p_low);

  if (pad == 0 || pad == 3){
    Amp_fwd_p_err[3][pad] = -1;
    Mean_fwd_p_err[3][pad] =-1;
    Sigma_fwd_p_err[3][pad] = -1;
  }
}

if (pad > 10 && pad < 18){
  Amp_fwd_p_err[6][pad] = f_fit_5_fwd[pad]->GetParError(3);
  Mean_fwd_p_err[6][pad] = f_fit_5_fwd[pad]->GetParError(4);
  Sigma_fwd_p_err[6][pad] = f_fit_5_fwd[pad]->GetParError(5)*ene_p_bin/(ene_p_high - ene_p_low);
}
else if (pad >= 18){
  Amp_fwd_p_err[6][pad] = f_fit_5_fwd[pad]->GetParError(0);
  Mean_fwd_p_err[6][pad] = f_fit_5_fwd[pad]->GetParError(1);
  Sigma_fwd_p_err[6][pad] = f_fit_5_fwd[pad]->GetParError(2)*ene_p_bin/(ene_p_high - ene_p_low);
}

if (pad < 18){
  Amp_fwd_p_err[7][pad] = f_fit_789_fwd[pad]->GetParError(3);
  Mean_fwd_p_err[7][pad] = f_fit_789_fwd[pad]->GetParError(4);
  Sigma_fwd_p_err[7][pad] = f_fit_789_fwd[pad]->GetParError(5)*ene_p_bin/(ene_p_high - ene_p_low);
}

if (Amp_fwd_p_err[1][pad] == -1) Amp_fwd_p_err[1][pad] = 0;
if (Amp_fwd_p_err[0][pad] == -1) Amp_fwd_p_err[0][pad] = 0;
if (Mean_fwd_p_err[1][pad] == -1) Mean_fwd_p_err[1][pad] = 0;
if (Mean_fwd_p_err[0][pad] == -1) Mean_fwd_p_err[0][pad] = 0;
if (Sigma_fwd_p_err[1][pad] == -1) Sigma_fwd_p_err[1][pad] = 0;
if (Sigma_fwd_p_err[0][pad] == -1) Sigma_fwd_p_err[0][pad] = 0;

}
}
void DisplayFitBwd (){
  c_coinc[2] = new TCanvas("c_coinc[2]", "", 700, 500);
  c_coinc[2]->Draw("");
  c_coinc[2]->Divide (5, 5); // S3B
  Double_t sigma = 0.02;
  for (Int_t pad = 0; pad < 24; pad++)
  {
    c_coinc[2]->cd (pad + 1)->SetTickx ();
    c_coinc[2]->cd (pad + 1)->SetTicky ();
    //      c_coinc[2]->cd (pad + 1)->SetLogy ();
    h_ene_p[pad + 75]->GetXaxis ()->SetRangeUser (0., 2.5);
    h_ene_p[pad + 75]->GetYaxis ()->SetRangeUser (0., 300.);
    h_ene_p[pad + 75]->Draw ();
    if (pad == 0)  // fit Back
    {
      Double_t fit_low_1_b = 1.74;
      Double_t fit_high_1_b = 1.80;
      f_fit_1_bwd[pad] = new TF1 (Form ("f_fit_1_bwd[%i]", pad), my_gaus, fit_low_1_b, fit_high_1_b, 3);
      f_fit_1_bwd[pad]->SetParameters(710, 1.77, sigma);
      f_fit_1_bwd[pad]->SetParLimits(2, 0, 1000);
      h_ene_p[pad + 75]->Fit (f_fit_1_bwd[pad], "R");
      f_fit_1_bwd[pad]->SetLineColor(2);

      Double_t fit_low_2_b = 1.62;
      Double_t fit_high_2_b = 1.68;
      f_fit_2_bwd[pad] = new TF1 (Form ("f_fit_2_bwd[%i]", pad), my_gaus, fit_low_2_b, fit_high_2_b, 3);
      f_fit_2_bwd[pad]->SetParameters(575, 1.65, sigma);
      f_fit_2_bwd[pad]->SetParLimits(2, 0, 1000);
      h_ene_p[pad + 75]->Fit (f_fit_2_bwd[pad], "R");
      f_fit_2_bwd[pad]->SetLineColor(2);

      Double_t fit_low_3_b = 1.26;
      Double_t fit_high_3_b = 1.38;
      f_fit_3_bwd[pad] = new TF1 (Form ("f_fit_3_bwd[%i]", pad), my_resp2, fit_low_3_b, fit_high_3_b, 8);
      f_fit_3_bwd[pad]->SetParameters(50, 1.30, sigma, 220, 1.36, sigma, 20, -1);
      f_fit_3_bwd[pad]->SetParLimits(2, 0, 1000);
      f_fit_3_bwd[pad]->SetParLimits(5, 0, 1000);
      h_ene_p[pad + 75]->Fit (f_fit_3_bwd[pad], "R");
      f_fit_3_bwd[pad]->SetLineColor(2);

      Double_t fit_low_4_b = 1.19;
      Double_t fit_high_4_b = 1.24;
      f_fit_4_bwd[pad] = new TF1 (Form ("f_fit_4_bwd[%i]", pad), my_gaus, fit_low_4_b, fit_high_4_b, 3);
      f_fit_4_bwd[pad]->SetParameters(50, 1.22, sigma);
      f_fit_4_bwd[pad]->SetParLimits(2, 0, 1000);
      h_ene_p[pad + 75]->Fit (f_fit_4_bwd[pad], "R");
      f_fit_4_bwd[pad]->SetLineColor(2);

      Double_t fit_low_5_b = 1.11;
      Double_t fit_high_5_b = 1.16;
      f_fit_5_bwd[pad] = new TF1 (Form ("f_fit_5_bwd[%i]", pad), my_gaus, fit_low_5_b, fit_high_5_b, 3);
      f_fit_5_bwd[pad]->SetParameters(380, 1.13, sigma);
      f_fit_5_bwd[pad]->SetParLimits(2, 0, 1000);
      h_ene_p[pad + 75]->Fit (f_fit_5_bwd[pad], "R");
      f_fit_5_bwd[pad]->SetLineColor(2);

      Double_t fit_low_6_b = 1.05;
      Double_t fit_high_6_b = 1.08;
      f_fit_6_bwd[pad] = new TF1 (Form ("f_fit_6_bwd[%i]", pad), my_gaus, fit_low_6_b, fit_high_6_b, 3);
      f_fit_6_bwd[pad]->SetParameters(380, 1.13, sigma);
      h_ene_p[pad + 75]->Fit (f_fit_6_bwd[pad], "R");
      f_fit_6_bwd[pad]->SetLineColor(2);

      /* Double_t fit_low_7_b = .78;
      Double_t fit_high_7_b = .82;
      f_fit_7_bwd[pad] = new TF1 (Form ("f_fit_7_bwd[%i]", pad), my_gaus, fit_low_7_b, fit_high_7_b, 3);
      f_fit_7_bwd[pad]->SetParameters(900, .80, sigma);
      f_fit_7_bwd[pad]->SetParLimits(2, 0, 1000);
      h_ene_p[Map_bwd[pad]]->Fit (f_fit_7_bwd[pad], "R");
      f_fit_7_bwd[pad]->SetLineColor(2);*/

      Double_t fit_low_a1p6_b = 0.9;
      Double_t fit_high_a1p6_b = 1.03;
      f_fit_a1p6_bwd[pad] = new TF1 (Form ("f_fit_a1p6_bwd[%i]", pad), my_resp2, fit_low_a1p6_b, fit_high_a1p6_b, 8);
      f_fit_a1p6_bwd[pad]->SetParameters(150, .98, sigma, 150, 1, sigma, 150, -100);
      f_fit_a1p6_bwd[pad]->SetParLimits(2, 0, 0.1);
      f_fit_a1p6_bwd[pad]->SetParLimits(6, 120, 180);
      f_fit_a1p6_bwd[pad]->SetParLimits(7, -120, -80);
      h_ene_p[pad + 75]->Fit (f_fit_a1p6_bwd[pad], "R");
      f_fit_a1p6_bwd[pad]->SetLineColor(2);

      Double_t fit_low_p89_b = .7;
      Double_t fit_high_p89_b = .84;
      f_fit_p89_bwd[pad] = new TF1 (Form ("f_fit_p89_bwd[%i]", pad), my_resp2, fit_low_p89_b, fit_high_p89_b, 8);
      f_fit_p89_bwd[pad]->SetParameters(500, .745, sigma, 900, 0.80, sigma, 200, -150);
      f_fit_p89_bwd[pad]->SetParLimits(2, 0, 1000);
      f_fit_p89_bwd[pad]->SetParLimits(5, 0, 1000);
      h_ene_p[pad + 75]->Fit (f_fit_p89_bwd[pad], "R");
      f_fit_p89_bwd[pad]->SetLineColor(2);
    }


    else
    {
      f_fit_1_bwd[pad] = new TF1 (Form ("f_fit_1_bwd[%i]", pad), my_gaus, f_fit_1_bwd[pad - 1]->GetParameter(1) - 1.5*sigma, f_fit_1_bwd[pad - 1]->GetParameter(1) + 1.5*sigma, 3);
      f_fit_1_bwd[pad]->SetParameters(f_fit_1_bwd[pad - 1]->GetParameter(0), f_fit_1_bwd[pad - 1]->GetParameter(1), f_fit_1_bwd[pad - 1]->GetParameter(2));
      h_ene_p[pad + 75]->Fit (f_fit_1_bwd[pad], "R");
      f_fit_1_bwd[pad]->SetLineColor(2);

      f_fit_2_bwd[pad] = new TF1 (Form ("f_fit_2_bwd[%i]", pad), my_gaus, f_fit_2_bwd[pad - 1]->GetParameter(1) - 1.5*sigma, f_fit_2_bwd[pad - 1]->GetParameter(1) + 1.5*sigma, 3);
      f_fit_2_bwd[pad]->SetParameters(f_fit_2_bwd[pad - 1]->GetParameter(0), f_fit_2_bwd[pad - 1]->GetParameter(1), f_fit_2_bwd[pad - 1]->GetParameter(2));
      h_ene_p[pad + 75]->Fit (f_fit_2_bwd[pad], "R");
      f_fit_2_bwd[pad]->SetLineColor(2);

      /* f_fit_3_bwd[pad + ] = new TF1 (Form ("f_fit_3_bwd[%i]", pad + ), my_resp2, f_fit_3_bwd[pad +  - 1]->GetParameter(1) - 1.5*sigma, f_fit_3_bwd[pad +  - 1]->GetParameter(4) + 1.5*sigma, 8);
      f_fit_3_bwd[pad + ]->SetParameters(f_fit_3_bwd[pad +  - 1]->GetParameter(0), f_fit_3_bwd[pad +  - 1]->GetParameter(1), f_fit_3_bwd[pad +  - 1]->GetParameter(2), f_fit_3_bwd[pad +  - 1]->GetParameter(3), f_fit_3_bwd[pad +  - 1]->GetParameter(4), f_fit_3_bwd[pad +  - 1]->GetParameter(5), f_fit_3_bwd[pad +  - 1]->GetParameter(6), f_fit_3_bwd[pad +  - 1]->GetParameter(7));
      h_ene_p[Map_bwd[pad + ]]->Fit (f_fit_3_bwd[pad + ], "R");
      f_fit_3_bwd[pad + ]->SetLineColor(2);*/
      if (pad == 1)
      {
        f_fit_3_bwd[pad] = new TF1 (Form ("f_fit_3_bwd[%i]", pad), my_gaus, f_fit_3_bwd[pad - 1]->GetParameter(4) - 1.5*sigma, f_fit_3_bwd[pad - 1]->GetParameter(4) + 1.5*sigma, 3);
        f_fit_3_bwd[pad]->SetParameters(f_fit_3_bwd[pad  - 1]->GetParameter(3), f_fit_3_bwd[pad - 1]->GetParameter(4), f_fit_3_bwd[pad - 1]->GetParameter(5));
        h_ene_p[pad + 75]->Fit (f_fit_3_bwd[pad], "R");
        f_fit_3_bwd[pad]->SetLineColor(2);
      }

      else
      {
        f_fit_3_bwd[pad] = new TF1 (Form ("f_fit_3_bwd[%i]", pad), my_gaus, f_fit_3_bwd[pad - 1]->GetParameter(1) - 1.5*sigma, f_fit_3_bwd[pad - 1]->GetParameter(1) + 1.5*sigma, 3);
        f_fit_3_bwd[pad]->SetParameters(f_fit_3_bwd[pad - 1]->GetParameter(0), f_fit_3_bwd[pad - 1]->GetParameter(1), f_fit_3_bwd[pad - 1]->GetParameter(2));
        h_ene_p[pad + 75]->Fit (f_fit_3_bwd[pad], "R");
        f_fit_3_bwd[pad]->SetLineColor(2);
      }

      f_fit_4_bwd[pad] = new TF1 (Form ("f_fit_4_bwd[%i]", pad), my_gaus, f_fit_4_bwd[pad - 1]->GetParameter(1) - 1.5*sigma, f_fit_4_bwd[pad - 1]->GetParameter(1) + 1.5*sigma, 3);
      f_fit_4_bwd[pad]->SetParameters(f_fit_4_bwd[pad - 1]->GetParameter(0), f_fit_4_bwd[pad - 1]->GetParameter(1), f_fit_4_bwd[pad - 1]->GetParameter(2));
      h_ene_p[pad + 75]->Fit (f_fit_4_bwd[pad], "R");
      f_fit_4_bwd[pad]->SetLineColor(2);

      f_fit_5_bwd[pad] = new TF1 (Form ("f_fit_5_bwd[%i]", pad), my_gaus, f_fit_5_bwd[pad - 1]->GetParameter(1) - 1.5*sigma, f_fit_5_bwd[pad - 1]->GetParameter(1) + 1.5*sigma, 3);
      f_fit_5_bwd[pad]->SetParameters(f_fit_5_bwd[pad - 1]->GetParameter(0), f_fit_5_bwd[pad - 1]->GetParameter(1), f_fit_5_bwd[pad - 1]->GetParameter(2));
      h_ene_p[pad + 75]->Fit (f_fit_5_bwd[pad], "R");
      f_fit_5_bwd[pad]->SetLineColor(2);

      f_fit_6_bwd[pad] = new TF1 (Form ("f_fit_6_bwd[%i]", pad), my_gaus, f_fit_6_bwd[pad +  - 1]->GetParameter(1) - 1.*sigma, f_fit_6_bwd[pad +  - 1]->GetParameter(1) + 1.2*sigma, 3);
      f_fit_6_bwd[pad]->SetParameters(f_fit_6_bwd[pad - 1]->GetParameter(0), f_fit_6_bwd[pad - 1]->GetParameter(1), f_fit_6_bwd[pad - 1]->GetParameter(2));
      f_fit_6_bwd[pad]->SetParLimits(2, 0., 0.1);
      h_ene_p[pad + 75]->Fit (f_fit_6_bwd[pad], "R");
      f_fit_6_bwd[pad]->SetLineColor(2);

      /* f_fit_7_bwd[pad] = new TF1 (Form ("f_fit_7_bwd[%i]", pad), my_gaus, f_fit_7_bwd[pad - 1]->GetParameter(1) - 1.*sigma, f_fit_7_bwd[pad - 1]->GetParameter(1) + 1.2*sigma, 3);
      f_fit_7_bwd[pad]->SetParameters(f_fit_7_bwd[pad - 1]->GetParameter(0), f_fit_7_bwd[pad - 1]->GetParameter(1), f_fit_7_bwd[pad - 1]->GetParameter(2));
      h_ene_p[Map_bwd[pad]]->Fit (f_fit_7_bwd[pad], "R");
      f_fit_7_bwd[pad]->SetLineColor(2);*/

      if (pad == 1){
        Double_t fit_low_a1p6_b = 0.9;
        Double_t fit_high_a1p6_b = 1.03;
        f_fit_a1p6_bwd[pad] = new TF1 (Form ("f_fit_a1p6_bwd[%i]", pad), my_resp2, fit_low_a1p6_b, fit_high_a1p6_b, 8);
        f_fit_a1p6_bwd[pad]->SetParameters(150, .98, sigma, 150, 1, sigma, 150, -100);
        f_fit_a1p6_bwd[pad]->SetParLimits(2, 0, .1);
        f_fit_a1p6_bwd[pad]->SetParLimits(6, 120, 180);
        f_fit_a1p6_bwd[pad]->SetParLimits(7, -101, -105);
        h_ene_p[pad + 75]->Fit (f_fit_a1p6_bwd[pad], "R");
        f_fit_a1p6_bwd[pad]->SetLineColor(2);
      }
      else if(pad > 1 && pad < 4) {
        f_fit_a1p6_bwd[pad] = new TF1 (Form ("f_fit_a1p6_bwd[%i]", pad), my_resp2, f_fit_a1p6_bwd[pad - 1]->GetParameter(1) - 1.5*sigma, f_fit_a1p6_bwd[pad - 1]->GetParameter(4) + 1.5*sigma, 8);
        f_fit_a1p6_bwd[pad]->SetParameters(f_fit_a1p6_bwd[pad - 1]->GetParameter(0), f_fit_a1p6_bwd[pad - 1]->GetParameter(1), f_fit_a1p6_bwd[pad - 1]->GetParameter(2), f_fit_a1p6_bwd[pad - 1]->GetParameter(3), f_fit_a1p6_bwd[pad - 1]->GetParameter(4), f_fit_a1p6_bwd[pad - 1]->GetParameter(5), f_fit_a1p6_bwd[pad - 1]->GetParameter(6), f_fit_a1p6_bwd[pad - 1]->GetParameter(7));
        f_fit_a1p6_bwd[pad]->SetParLimits(7, -101, -105);
        f_fit_a1p6_bwd[pad]->SetParLimits(2, 0, .1);
        f_fit_a1p6_bwd[pad]->SetParLimits(5, 0, .1);
        f_fit_a1p6_bwd[pad]->SetParLimits(1, 0.9, 1.1);
        h_ene_p[pad + 75]->Fit (f_fit_a1p6_bwd[pad], "R");
        f_fit_a1p6_bwd[pad]->SetLineColor(2);
      }

      else if(pad >= 4) {
        f_fit_a1p6_bwd[pad] = new TF1 (Form ("f_fit_a1p6_bwd[%i]", pad), my_gaus, f_fit_a1p6_bwd[pad - 1]->GetParameter(1) - 1.5*sigma, f_fit_a1p6_bwd[pad - 1]->GetParameter(1) + 1.5*sigma, 3);
        f_fit_a1p6_bwd[pad]->SetParameters(f_fit_a1p6_bwd[pad - 1]->GetParameter(0), f_fit_a1p6_bwd[pad - 1]->GetParameter(1), f_fit_a1p6_bwd[pad - 1]->GetParameter(2));
        f_fit_a1p6_bwd[pad]->SetParLimits(2, 0, .1);
        f_fit_a1p6_bwd[pad]->SetParLimits(1, 0.9, 1.);
        h_ene_p[pad + 75]->Fit (f_fit_a1p6_bwd[pad], "R");
        f_fit_a1p6_bwd[pad]->SetLineColor(2);
      }

      f_fit_p89_bwd[pad] = new TF1 (Form ("f_fit_p89_bwd[%i]", pad), my_resp2, f_fit_p89_bwd[pad - 1]->GetParameter(1) - 3.0*sigma, f_fit_p89_bwd[pad - 1]->GetParameter(4) + 1.6*sigma, 8);
      f_fit_p89_bwd[pad]->SetParameters(f_fit_p89_bwd[pad - 1]->GetParameter(0), f_fit_p89_bwd[pad - 1]->GetParameter(1), f_fit_p89_bwd[pad - 1]->GetParameter(2), f_fit_p89_bwd[pad - 1]->GetParameter(3), f_fit_p89_bwd[pad - 1]->GetParameter(4), f_fit_p89_bwd[pad - 1]->GetParameter(5), f_fit_p89_bwd[pad - 1]->GetParameter(6), f_fit_p89_bwd[pad - 1]->GetParameter(7));
      //f_fit_p89_bwd[pad]->SetParLimits(7, -101, -105);
      f_fit_p89_bwd[pad]->SetParLimits(2, 0, .1);
      //f_fit_p89_bwd[pad]->SetParLimits(1, 0.9, 1.1);
      h_ene_p[pad + 75]->Fit (f_fit_p89_bwd[pad], "R");
      f_fit_p89_bwd[pad]->SetLineColor(2);
    }

    f_fit_1_bwd[pad]->Draw("SAME");
    f_fit_2_bwd[pad]->Draw("SAME");
    f_fit_3_bwd[pad]->Draw("SAME");
    f_fit_4_bwd[pad]->Draw("SAME");
    f_fit_5_bwd[pad]->Draw("SAME");
    f_fit_6_bwd[pad]->Draw("SAME");
    //f_fit_7_bwd[pad]->Draw("SAME");
    f_fit_a1p6_bwd[pad]->Draw("SAME");
    f_fit_p89_bwd[pad]->Draw("SAME");

    OMean_p0_bwd << pad << " " << f_fit_1_bwd[pad]->GetParameter(1) << std::endl;
    OMean_p1_bwd << pad << " " << f_fit_2_bwd[pad]->GetParameter(1) << std::endl;
    if (pad <= 1 ) OMean_a0_bwd << pad << " " << -1 << std::endl;
    else OMean_a0_bwd << pad << " " << f_fit_3_bwd[pad]->GetParameter(1) << std::endl;
    OMean_p2_bwd << pad << " " << f_fit_4_bwd[pad]->GetParameter(1) << std::endl;
    OMean_p3_bwd << pad << " " << f_fit_5_bwd[pad]->GetParameter(1) << std::endl;
    OMean_p45_bwd << pad << " " << f_fit_6_bwd[pad]->GetParameter(1) << std::endl;
    OMean_p7_bwd << pad << " " << f_fit_p89_bwd[pad]->GetParameter(4) << std::endl;
    OMean_p89_bwd << pad << " " << f_fit_p89_bwd[pad]->GetParameter(1) << std::endl;

    OMean_p0_bwd_err << pad << " " << f_fit_1_bwd[pad]->GetParError(1) << std::endl;
    OMean_p1_bwd_err << pad << " " << f_fit_2_bwd[pad]->GetParError(1) << std::endl;
    if (pad == 0) OMean_a0_bwd_err << pad << " " << f_fit_3_bwd[pad]->GetParError(4) << std::endl;
    else OMean_a0_bwd_err << pad << " " << f_fit_3_bwd[pad]->GetParError(1) << std::endl;
    OMean_p2_bwd_err << pad << " " << f_fit_4_bwd[pad]->GetParError(1) << std::endl;
    OMean_p3_bwd_err << pad << " " << f_fit_5_bwd[pad]->GetParError(1) << std::endl;
    OMean_p45_bwd_err << pad << " " << f_fit_6_bwd[pad]->GetParError(1) << std::endl;
    //OMean_p7_bwd_err << pad << " " << f_fit_7_bwd[pad]->GetParError(1) << std::endl;
    OMean_p7_bwd_err << pad << " " << f_fit_p89_bwd[pad]->GetParError(4) << std::endl;
    OMean_p89_bwd_err << pad << " " << f_fit_p89_bwd[pad]->GetParError(1) << std::endl;

    /*
    OSigma_p0_bwd << pad << " " << f_fit_1_bwd[pad]->GetParameter(2) << std::endl;
    OSigma_p1_bwd << pad << " " << f_fit_2_bwd[pad]->GetParameter(2) << std::endl;
    if (pad == 0) OSigma_a0_bwd << pad << " " << f_fit_3_bwd[pad]->GetParameter(5) << std::endl;
    else OSigma_a0_bwd << pad << " " << f_fit_3_bwd[pad]->GetParameter(2) << std::endl;
    OSigma_p2_bwd << pad << " " << f_fit_4_bwd[pad]->GetParameter(2) << std::endl;
    OSigma_p3_bwd << pad << " " << f_fit_5_bwd[pad]->GetParameter(2) << std::endl;
    OSigma_p45_bwd << pad << " " << f_fit_6_bwd[pad]->GetParameter(2) << std::endl;
    OSigma_p7_bwd << pad << " " << f_fit_7_bwd[pad]->GetParameter(2) << std::endl;
    */
    OSigma_p0_bwd << pad << " " << f_fit_1_bwd[pad]->GetParameter(2)*ene_p_bin_bwd/(ene_p_high - ene_p_low) << std::endl;
    OSigma_p1_bwd << pad << " " << f_fit_2_bwd[pad]->GetParameter(2)*ene_p_bin_bwd/(ene_p_high - ene_p_low) << std::endl;
    if (pad <= 1) OSigma_a0_bwd << pad << " " << -1 << std::endl;
    else OSigma_a0_bwd << pad << " " << f_fit_3_bwd[pad]->GetParameter(2)*ene_p_bin_bwd/(ene_p_high - ene_p_low) << std::endl;
    OSigma_p2_bwd << pad << " " << f_fit_4_bwd[pad]->GetParameter(2)*ene_p_bin_bwd/(ene_p_high - ene_p_low) << std::endl;
    OSigma_p3_bwd << pad << " " << f_fit_5_bwd[pad]->GetParameter(2)*ene_p_bin_bwd/(ene_p_high - ene_p_low) << std::endl;
    OSigma_p45_bwd << pad << " " << f_fit_6_bwd[pad]->GetParameter(2)*ene_p_bin_bwd/(ene_p_high - ene_p_low) << std::endl;
    OSigma_p7_bwd << pad << " " << f_fit_p89_bwd[pad]->GetParameter(5)*ene_p_bin_bwd/(ene_p_high - ene_p_low) << std::endl;
    OSigma_p89_bwd << pad << " " << f_fit_p89_bwd[pad]->GetParameter(2)*ene_p_bin_bwd/(ene_p_high - ene_p_low) << std::endl;

    OSigma_p0_bwd_err << pad << " " << f_fit_1_bwd[pad]->GetParError(2)*ene_p_bin_bwd/(ene_p_high - ene_p_low) << std::endl;
    OSigma_p1_bwd_err << pad << " " << f_fit_2_bwd[pad]->GetParError(2)*ene_p_bin_bwd/(ene_p_high - ene_p_low) << std::endl;
    if (pad == 0) OSigma_a0_bwd_err << pad << " " << f_fit_3_bwd[pad]->GetParError(5)*ene_p_bin_bwd/(ene_p_high - ene_p_low) << std::endl;
    else OSigma_a0_bwd_err << pad << " " << f_fit_3_bwd[pad]->GetParError(2)*ene_p_bin_bwd/(ene_p_high - ene_p_low) << std::endl;
    OSigma_p2_bwd_err << pad << " " << f_fit_4_bwd[pad]->GetParError(2)*ene_p_bin_bwd/(ene_p_high - ene_p_low) << std::endl;
    OSigma_p3_bwd_err << pad << " " << f_fit_5_bwd[pad]->GetParError(2)*ene_p_bin_bwd/(ene_p_high - ene_p_low) << std::endl;
    OSigma_p45_bwd_err << pad << " " << f_fit_6_bwd[pad]->GetParError(2)*ene_p_bin_bwd/(ene_p_high - ene_p_low) << std::endl;
    OSigma_p7_bwd_err << pad << " " << f_fit_p89_bwd[pad]->GetParError(5)*ene_p_bin_bwd/(ene_p_high - ene_p_low) << std::endl;
    OSigma_p89_bwd_err << pad << " " << f_fit_p89_bwd[pad]->GetParError(2)*ene_p_bin_bwd/(ene_p_high - ene_p_low) << std::endl;

    OAmp_p0_bwd << pad << " " << f_fit_1_bwd[pad]->GetParameter(0) << std::endl;
    OAmp_p1_bwd << pad << " " << f_fit_2_bwd[pad]->GetParameter(0) << std::endl;
    if (pad == 0) OAmp_a0_bwd << pad << " " << f_fit_3_bwd[pad]->GetParameter(3) << std::endl;
    else OAmp_a0_bwd << pad << " " << f_fit_3_bwd[pad]->GetParameter(0) << std::endl;
    OAmp_p2_bwd << pad << " " << f_fit_4_bwd[pad]->GetParameter(0) << std::endl;
    OAmp_p3_bwd << pad << " " << f_fit_5_bwd[pad]->GetParameter(0) << std::endl;
    OAmp_p45_bwd << pad << " " << f_fit_6_bwd[pad]->GetParameter(0) << std::endl;
    OAmp_p7_bwd << pad << " " << f_fit_p89_bwd[pad]->GetParameter(3) << std::endl;
    OAmp_p89_bwd << pad << " " << f_fit_p89_bwd[pad]->GetParameter(0) << std::endl;

    OAmp_p0_bwd_err << pad << " " << f_fit_1_bwd[pad]->GetParError(0) << std::endl;
    OAmp_p1_bwd_err << pad << " " << f_fit_2_bwd[pad]->GetParError(0) << std::endl;
    if (pad == 0) OAmp_a0_bwd_err << pad << " " << f_fit_3_bwd[pad]->GetParError(3) << std::endl;
    else OAmp_a0_bwd_err << pad << " " << f_fit_3_bwd[pad]->GetParError(0) << std::endl;
    OAmp_p2_bwd_err << pad << " " << f_fit_4_bwd[pad]->GetParError(0) << std::endl;
    OAmp_p3_bwd_err << pad << " " << f_fit_5_bwd[pad]->GetParError(0) << std::endl;
    OAmp_p45_bwd_err << pad << " " << f_fit_6_bwd[pad]->GetParError(0) << std::endl;
    OAmp_p7_bwd_err << pad << " " << f_fit_p89_bwd[pad]->GetParError(3) << std::endl;
    OAmp_p89_bwd_err << pad << " " << f_fit_p89_bwd[pad]->GetParError(0) << std::endl;

    if (pad < 4) OInt_p6a1 << pad << " " << TMath::Sqrt(2*TMath::Pi())*(f_fit_a1p6_bwd[pad]->GetParameter(0)*f_fit_a1p6_bwd[pad]->GetParameter(2)*ene_p_bin/(ene_p_high - ene_p_low) + f_fit_a1p6_bwd[pad]->GetParameter(3)*f_fit_a1p6_bwd[pad]->GetParameter(5)*ene_p_bin/(ene_p_high - ene_p_low)) << std::endl;
    else OInt_p6a1 << pad << " " << TMath::Sqrt(2*TMath::Pi())*(f_fit_a1p6_bwd[pad]->GetParameter(0)*f_fit_a1p6_bwd[pad]->GetParameter(2)*ene_p_bin/(ene_p_high - ene_p_low)) << std::endl;

    if (pad < 4) OInt_p6a1_err << pad << " " << TMath::Sqrt(TMath::Pi ()*2*TMath::Power(f_fit_a1p6_bwd[pad]->GetParError(2)*f_fit_a1p6_bwd[pad]->GetParameter(0),2) + TMath::Pi ()*2*TMath::Power(f_fit_a1p6_bwd[pad]->GetParError(0)*f_fit_a1p6_bwd[pad]->GetParameter(2),2) + TMath::Pi ()*2*TMath::Power(f_fit_a1p6_bwd[pad]->GetParError(5)*f_fit_a1p6_bwd[pad]->GetParameter(3),2) + TMath::Pi ()*2*TMath::Power(f_fit_a1p6_bwd[pad]->GetParError(3)*f_fit_a1p6_bwd[pad]->GetParameter(5),2)) << std::endl;
    else OInt_p6a1_err << pad << " " << TMath::Sqrt(TMath::Pi ()*2*TMath::Power(f_fit_a1p6_bwd[pad]->GetParError(2)*f_fit_a1p6_bwd[pad]->GetParameter(0),2) + TMath::Pi ()*2*TMath::Power(f_fit_a1p6_bwd[pad]->GetParError(0)*f_fit_a1p6_bwd[pad]->GetParameter(2),2)) << std::endl;

    OMean_a1p6_bwd << pad << " " << f_fit_a1p6_bwd[pad]->GetParameter(1) << std::endl;
    OMean_a1p6_bwd_err << pad << " " << f_fit_a1p6_bwd[pad]->GetParError(1) << std::endl;

  }
}
