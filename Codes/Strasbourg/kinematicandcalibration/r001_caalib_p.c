#include "../../Scripts/libPerso.h"

Double_t my_lin (Double_t *var, Double_t *par)
{
  return par[0] + par[1]*var[0];
}



void r001_caalib_p (){

  gStyle->SetOptStat (0);

  //inFiles.
  //fwd
  std::ifstream Ikin("Mean_kin_fwd.dat");
  std::ifstream Ifit_fwd_a0("Mean_a0_fwd.dat");
  std::ifstream Ifit_fwd_a1("Mean_a1_fwd.dat");
  std::ifstream Ifit_fwd_a2("Mean_a2_fwd.dat");
  std::ifstream Ifit_fwd_p2("Mean_p2_fwd.dat");
  std::ifstream Ifit_fwd_a3("Mean_a3_fwd.dat");
  std::ifstream Ifit_fwd_p45("Mean_p45_fwd.dat");
  std::ifstream Ifit_fwd_p6_a1("Mean_p6_a1_fwd.dat");
  std::ifstream Ifit_fwd_err_a0("Mean_a0_fwd_err.dat");
  std::ifstream Ifit_fwd_err_a1("Mean_a1_fwd_err.dat");
  std::ifstream Ifit_fwd_err_a2("Mean_a2_fwd_err.dat");
  std::ifstream Ifit_fwd_err_p2("Mean_p2_fwd_err.dat");
  std::ifstream Ifit_fwd_err_a3("Mean_a3_fwd_err.dat");
  std::ifstream Ifit_fwd_err_p45("Mean_p45_fwd_err.dat");
  std::ifstream Ifit_fwd_err_p6_a1("Mean_p6_a1_fwd_err.dat");
  //bwd
  std::ifstream Ikin_bwd("Mean_kin_bwd.dat");
  std::ifstream Ifit_bwd_p0("Mean_p0_bwd.dat");
  std::ifstream Ifit_bwd_p1("Mean_p1_bwd.dat");
  std::ifstream Ifit_bwd_a0("Mean_a0_bwd.dat");
  std::ifstream Ifit_bwd_p2("Mean_p2_bwd.dat");
  std::ifstream Ifit_bwd_p3("Mean_p3_bwd.dat");
  std::ifstream Ifit_bwd_p7("Mean_p7_bwd.dat");

  std::ifstream Ifit_bwd_err_p0("Mean_p0_bwd_err.dat");
  std::ifstream Ifit_bwd_err_p1("Mean_p1_bwd_err.dat");
  std::ifstream Ifit_bwd_err_a0("Mean_a0_bwd_err.dat");
  std::ifstream Ifit_bwd_err_p2("Mean_p2_bwd_err.dat");
  std::ifstream Ifit_bwd_err_p3("Mean_p3_bwd_err.dat");
  std::ifstream Ifit_bwd_err_p7("Mean_p7_bwd_err.dat");

  //alpha kin
  std::ifstream Ikin_fwd_a("Mean_kin_fwd_a.dat");
  std::ifstream Ikin_bwd_a("Mean_kin_bwd_a.dat");

  //outfiles
  std::ofstream Ocalib("calib_par_p.dat");
  std::ofstream Ocalib_bwd("calib_par_p_bwd.dat");

  //array definitions
  Double_t Ang_fwd[11][24];
  Int_t nbr[24];
  Double_t Ene_fwd_kin[11][24];
  Double_t Ene_p_fwd_a0[24], Ene_p_fwd_a1[24], Ene_p_fwd_a2[24], Ene_p_fwd_p2[24], Ene_p_fwd_a3[24];
  Double_t Ene_p_fwd_err_a0[24], Ene_p_fwd_err_a1[24], Ene_p_fwd_err_a2[24], Ene_p_fwd_err_a3[24];

  Double_t Ene_bwd_kin[11][24];
  Double_t Ene_p_bwd_p0[24], Ene_p_bwd_p1[24], Ene_p_bwd_p2[24], Ene_p_bwd_p3[24], Ene_p_bwd_p7[24];
  Double_t Ene_p_bwd_err_p0[24], Ene_p_bwd_err_p1[24], Ene_p_bwd_err_p2[24], Ene_p_bwd_err_p3[24], Ene_p_bwd_err_p7[24];
  Double_t Ene_p_bwd_a0[24], Ene_p_bwd_a1[24];
  Double_t Ene_p_bwd_err_a0[24], Ene_p_bwd_err_a1[24];
  Double_t Ang_bwd[11][24];
  Double_t Ene_bwd_kin_a[11][24];
  Double_t Ene_fwd_kin_a[11][24];

  TGraphErrors *g_cal[24];
  TGraphErrors *g_cal_bwd[24];
  //TGraph *g_cal[24];

  for (Int_t j = 0; j < 11; j++)
    {
      for (Int_t i = 0; i < 24; i++)
	{
	  Ikin >> Ang_fwd[j][i] >> Ene_fwd_kin[j][i];
	  Ikin_bwd >> Ang_bwd[j][i] >> Ene_bwd_kin[j][i];
	  Ikin_fwd_a >> Ang_fwd[j][i] >> Ene_fwd_kin_a[j][i];
	  Ikin_bwd_a >> Ang_bwd[j][i] >> Ene_bwd_kin_a[j][i];
	}
    }

  for (Int_t i = 0; i < 24; i++)
    {
      Ifit_fwd_a0 >> nbr[i] >> Ene_p_fwd_a0[i];
      Ifit_fwd_a1 >> nbr[i] >> Ene_p_fwd_a1[i];
      Ifit_fwd_a2 >> nbr[i] >> Ene_p_fwd_a2[i];
      Ifit_fwd_a3 >> nbr[i] >> Ene_p_fwd_a3[i];

      Ifit_fwd_err_a0 >> nbr[i] >> Ene_p_fwd_err_a0[i];
      Ifit_fwd_err_a1 >> nbr[i] >> Ene_p_fwd_err_a1[i];
      Ifit_fwd_err_a2 >> nbr[i] >> Ene_p_fwd_err_a2[i];
      Ifit_fwd_err_a3 >> nbr[i] >> Ene_p_fwd_err_a3[i];
      // std::cout << Ene_p_fwd_p2[i] << " " << Ene_p_fwd_p3[i] << std::endl;

      Ifit_bwd_p0 >> nbr[i] >> Ene_p_bwd_p0[i];
      Ifit_bwd_p1 >> nbr[i] >> Ene_p_bwd_p1[i];
      Ifit_bwd_a0 >> nbr[i] >> Ene_p_bwd_a0[i];
      Ifit_bwd_p2 >> nbr[i] >> Ene_p_bwd_p2[i];
      Ifit_bwd_p3 >> nbr[i] >> Ene_p_bwd_p3[i];
      Ifit_bwd_p7 >> nbr[i] >> Ene_p_bwd_p7[i];
      Ifit_bwd_err_p0 >> nbr[i] >> Ene_p_bwd_err_p0[i];
      Ifit_bwd_err_p1 >> nbr[i] >> Ene_p_bwd_err_p1[i];
      Ifit_bwd_err_a0 >> nbr[i] >> Ene_p_bwd_err_a0[i];
      Ifit_bwd_err_p2 >> nbr[i] >> Ene_p_bwd_err_p2[i];
      Ifit_bwd_err_p3 >> nbr[i] >> Ene_p_bwd_err_p3[i];
      Ifit_bwd_err_p7 >> nbr[i] >> Ene_p_bwd_err_p7[i];
      // std::cout << Ene_p_bwd_p2[i] << " " << Ene_p_bwd_p3[i] << std::endl;
    }
  Int_t n_points = 3;
  Double_t Datacalib[24][n_points];
  Double_t Datacalib_err[24][n_points];
  Double_t Kincalib[24][n_points];
  Double_t Kincalib_err[24][n_points];

  Int_t n_points_bwd = 4;
  Double_t Datacalib_bwd[24][n_points_bwd];
  Double_t Datacalib_err_bwd[24][n_points_bwd];
  Double_t Kincalib_bwd[24][n_points_bwd];
  Double_t Kincalib_err_bwd[24][n_points_bwd];

  for (Int_t i = 0; i < 24; i++)
    {
      Datacalib[i][0] = Ene_p_fwd_a0[i];
      Datacalib[i][1] = Ene_p_fwd_a1[i];
      Datacalib[i][2] = Ene_p_fwd_a2[i];
      Datacalib_err[i][0] = Ene_p_fwd_err_a0[i];
      Datacalib_err[i][1] = Ene_p_fwd_err_a1[i];
      Datacalib_err[i][3] = Ene_p_fwd_err_a2[i];
      // std::cout <<  Datacalib[i][2] << " " <<  Datacalib[i][3] << std::endl;

      Datacalib_bwd[i][0] = Ene_p_bwd_p0[i];
      Datacalib_bwd[i][1] = Ene_p_bwd_p1[i];
      Datacalib_bwd[i][2] = Ene_p_bwd_a0[i];
      // Datacalib_bwd[i][2] = Ene_p_bwd_p2[i];
      Datacalib_bwd[i][3] = Ene_p_bwd_p3[i];
      Datacalib_bwd[i][4] = Ene_p_bwd_p7[i];
      Datacalib_err_bwd[i][0] = Ene_p_bwd_err_p0[i];
      Datacalib_err_bwd[i][1] = Ene_p_bwd_err_p1[i];
      Datacalib_err_bwd[i][2] = Ene_p_bwd_err_a0[i];
      //Datacalib_err_bwd[i][2] = Ene_p_bwd_err_p2[i];
      Datacalib_err_bwd[i][3] = Ene_p_bwd_err_p3[i];
      Datacalib_err_bwd[i][4] = Ene_p_bwd_err_p7[i];
      // std::cout <<  Datacalib[i][2] << " " <<  Datacalib[i][3] << std::endl;
    }

  for (Int_t i = 0; i < 24; i++)
    {

      Kincalib[i][0] = Ene_fwd_kin_a[0][i];
      Kincalib[i][1] = Ene_fwd_kin_a[1][i];
      Kincalib[i][2] = Ene_fwd_kin_a[2][i];

      for (Int_t j = 0; j < n_points_bwd; j++)  Kincalib_err[i][j] = 0.01;

      Kincalib_bwd[i][0] = Ene_bwd_kin[0][i];
      Kincalib_bwd[i][1] = Ene_bwd_kin[1][i];
      Kincalib_bwd[i][2] = Ene_bwd_kin_a[0][i];
      // Kincalib_bwd[i][2] = Ene_bwd_kin[2][i];
      Kincalib_bwd[i][3] = Ene_bwd_kin[3][i];
      Kincalib_bwd[i][4] = Ene_bwd_kin[7][i];

      for (Int_t j = 0; j < n_points_bwd; j++)    Kincalib_err_bwd[i][j] = 0.01;


    }

  for (Int_t i = 0; i < 24; i++)
    {
      g_cal[i] = new TGraphErrors(n_points, Datacalib[i], Kincalib[i], Datacalib_err[i], Kincalib_err[i]);
      // g_cal[i] = new TGraph(n_points, Datacalib[i], Kincalib[i]);
      g_cal_bwd[i] = new TGraphErrors(n_points_bwd, Datacalib_bwd[i], Kincalib_bwd[i], Datacalib_err_bwd[i], Kincalib_err_bwd[i]);
   }

  TF1 *f_fit[24];
  TF1 *f_fit_bwd[24];

  //out array
  Double_t slope[24];
  Double_t offset[24];
  Double_t slope_bwd[24];
  Double_t offset_bwd[24];
  TCanvas *C = new TCanvas("C", "", 700,500);
  C->Divide(5,5);
  for (Int_t i = 0; i < 24; i++)
    {
      C->cd (i+1);
      g_cal[i]->SetMarkerStyle (3);
      g_cal[i]->Draw("AP");
      f_fit[i] = new TF1 (Form("f_fit[%i]",i), my_lin, 5, 15, 2);
      f_fit[i]->SetParameters(0, 1);
      g_cal[i]->Fit(f_fit[i], "R");
      f_fit[i]->Draw("SAME");
      offset[i] = f_fit[i]->GetParameter(0);
      slope[i] = f_fit[i]->GetParameter(1);
      Ocalib << offset[i] << " " << slope[i] << std::endl;

    }

  TCanvas *C2 = new TCanvas ("C2", "2", 700,500);
  C2->Divide(5,5);
  for (Int_t i = 0; i < 24; i++)
    {
      C2->cd (i+1);
      g_cal_bwd[i]->SetMarkerStyle (3);
      g_cal_bwd[i]->Draw("AP");
      f_fit_bwd[i] = new TF1 (Form("f_fit_bwd[%i]",i), my_lin, 0, 6, 2);
      f_fit_bwd[i]->SetParameters(0, 1);
      g_cal_bwd[i]->Fit(f_fit_bwd[i], "R");
      f_fit_bwd[i]->Draw("SAME");
      offset_bwd[i] = f_fit_bwd[i]->GetParameter(0);
      slope_bwd[i] = f_fit_bwd[i]->GetParameter(1);
      Ocalib_bwd << offset_bwd[i] << " " << slope_bwd[i] << std::endl;
    }
    Ocalib_bwd.close();
    Ocalib.close();
}
