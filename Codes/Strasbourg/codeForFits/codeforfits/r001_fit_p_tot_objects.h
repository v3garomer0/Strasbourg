//Pull Data
unsigned long long event_g, event_p, event_gp;
Int_t mult_g, mult_p, mult_gp;
std::vector <Int_t> *det_g = 0;
std::vector <Int_t> *det_p = 0;
std::vector <Long64_t> *time_g = 0;
std::vector <Long64_t> *time_p = 0;
std::vector <Double_t> *ene_g = 0;
std::vector <Double_t> *ene_p = 0;

TBranch *b_event_g, *b_mult_g, *b_det_g, *b_time_g, *b_ene_g, *b_event_p, *b_mult_p, *b_det_p, *b_time_p, *b_ene_p, *b_event_gp, *b_mult_gp;


TChain *f_in = new TChain ("t_event");


// declare objects to fill data
const Double_t ene_p_low = 0.; // qdc chn
const Double_t ene_p_high = 17.;
const Int_t M = 3;
const Int_t ene_p_bin = (ene_p_high - ene_p_low)*50*M;
const Int_t ene_p_bin_bwd = (ene_p_high - ene_p_low)*50*M*5;

TH1F *h_ene_p[100], *h_ene_p_step[100], *h_ene_p_ratio[100];
TH2F *h_ang_vs_ene_p[2];


TF1 *f_fit_1_fwd[24];
TF1 *f_fit_2_fwd[24];
TF1 *f_fit_3_fwd[24];
TF1 *f_fit_4_fwd[24];
TF1 *f_fit_4_fwd_a[24];
TF1 *f_fit_4_fwd_b[24];
TF1 *f_fit_5_fwd[24];
TF1 *f_fit_6_fwd[24];
TF1 *f_fit_7_fwd[24];
TF1 *f_fit_8_fwd[24];
TF1 *f_fit_789_fwd[24];
TF1 *f_fit_p1_fwd[24];

TF1 *f_fit_1_bwd[24];
TF1 *f_fit_2_bwd[24];
TF1 *f_fit_3_bwd[24];
TF1 *f_fit_4_bwd[24];
TF1 *f_fit_5_bwd[24];
TF1 *f_fit_6_bwd[24];
TF1 *f_fit_7_bwd[24];
TF1 *f_fit_a1p6_bwd[24];
TF1 *f_fit_p89_bwd[24];

const Int_t mask_s3[100] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 9, 12, 11, 24, 23, 22, 21, 20, 19, 18, 17, 15, 16, 13, 14, 25, // S3F (before January 2017) CORRECTED
                            26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
                            51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75,
                            76, 77, 78, 79, 80, 81, 82, 83, 85, 84, 87, 86, 88, 89, 90, 91, 92, 93, 94, 95, 97, 96, 99, 98, 100}; // S3B
Double_t  ene_sum_p; // sum energy
Int_t det_sum_p; // initial detector

//declare objacts to display Data
const Int_t n_can = 5;
TCanvas *c_coinc[n_can];

//declare objects to extract fitparameters
Double_t Amp_fwd_a[3][24], Mean_fwd_a[3][24], Sigma_fwd_a[3][24];
Double_t Amp_fwd_p[8][24], Mean_fwd_p[8][24], Sigma_fwd_p[8][24];

Double_t Amp_fwd_a_err[3][24], Mean_fwd_a_err[3][24], Sigma_fwd_a_err[3][24];
Double_t Amp_fwd_p_err[8][24], Mean_fwd_p_err[8][24], Sigma_fwd_p_err[8][24];

//Declare objects to correct spectrums
Double_t Slope_m2_fwd[24], Offset_m2_fwd[24];//recalibrate chargesharing
Double_t Slope_m2_bwd[24], Offset_m2_bwd[24];//recalibrate chargesharing
Double_t Mean_Interval_Project[23], Sigma_Interval_Project[23];
Double_t Mean_Project[23], Sigma_Project[23], Ratio_project[23];
