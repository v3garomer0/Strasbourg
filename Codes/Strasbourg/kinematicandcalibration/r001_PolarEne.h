  //stopping power parameters
  //Al
  Double_t alu_density = 2.7; // g/cm3
  Double_t thick_fwd = 10 + 0.1; // µm   CHANGE THICKNESS OF FOIL HERE
  Double_t thick_bwd = 0.8 + 0.1; // µm   added alu dead layer in silicon detectors according to Tuff thesis
  Double_t alu_fwd = thick_fwd*pow(10,-4)*alu_density; //thickness in g/cm2
  Double_t alu_bwd = thick_bwd*pow(10,-4)*alu_density; //thickness in g/cm2 (rather surface density)
// power law for energy loss of proton in alu from 1.1 to 15 MeV range
  // the law is E_loss = a*(E_proton)^(b)  in MeV.cm2/g so
  // Delta_E = thickness*E_loss and E_meas = E_proton - delta_E
  //except for 1.1 to 2 -> polynomial 2nd order

  Double_t a6 = 171.7649857; //0.8 to 1.35 MeV
  Double_t b6 = -0.6180668;

  Double_t a5 = 174.608207; // 1.35 to 2.35 MeV
  Double_t b5 = -0.6731153;

  Double_t a4 = 180.826916; // 2.35 to 4 MeV
  Double_t b4 = -0.714861;

  Double_t a3 = 184.577826565; // 4 to 5.5 MeV
  Double_t b3 = -0.730959;

  Double_t a2 = 191.22; // 5.5 to 7.5 MeV
  Double_t b2 = -0.751669;

  Double_t a1 = 195.76893592; // 7.5 to 10 MeV
  Double_t b1 = -0.763213525;

  //Si
  Double_t si_density = 2.329; // g/cm3
  Double_t thick_si = 0.5; // µm   same fwd and bwd according to Tuff thesis
  Double_t si = thick_si*pow(10,-4)*si_density; //thickness in g/cm2

  double a7_si = 180.0021557; //0.8 to 0.5 MeV
  double b7_si = -0.517836;

  double a6_si = 175.269; //0.8 to 1.3 MeV
  double b6_si = -0.62242;

  double a5_si = 178.973525; // 1.3 to 3 MeV
  double b5_si = -0.682159;

  double a4_si = 186.793941; // 3 to 5 MeV
  double b4_si = -0.7231;

  double a3_si = 193.736956; // 5 to 7.5 MeV
  double b3_si = -0.74609;

  double a2_si = 199.028157; // 7.5 to 9.5 MeV
  double b2_si = -0.7597;

  double a1_si = 202.220141; // 9.5 to 11 MeV
  double b1_si = -0.766856;


//Alpha energy loss in al and si
double a9_a = 27.8030303; //1.1 to 2 MeV
double b9_a = -326.6075757576;
double c9_a = 1527.3412121212;

double a8_a = 1349.07285; //2 to 2.8 MeV
double b8_a = -0.448489;

double a7_a = 1474.69408107; //2.8 to 3.7 MeV
double b7_a = -0.53273324;

double a6_a = 1672.35226723; //3.7 to 4.9 MeV
double b6_a = -0.63033348;

double a5_a = 1766.45444027; // 4.9 to 5.9 MeV
double b5_a = -0.66558456;

double a4_a = 1824.2919473; // 5.9 to 7.5 MeV
double b4_a = -0.6833843;

double a3_a = 1890.5511761; // 7.5 to 9.8 MeV
double b3_a = -0.7009390;

double a2_a = 1961.7222252; // 9.8 to 12.8 MeV
double b2_a = -0.71707839;

double a1_a = 2011.9297231; // 12.8 to 15 MeV
double b1_a = -0.72702125;

//***************************************************************************************************************************


// power law for energy loss of alpha in si from 1.1 to 15 MeV range

  // the law is E_loss = a*(E_alpha)^(b)  in MeV.cm2/g so
  // Delta_E = thickness*E_loss and E_meas = E_alpha - delta_E

double a8_si_a = 1305.263; //1.1 to 1.5 MeV
double b8_si_a = -0.3134;

double a7_si_a = 1361.289351; //1.5 to 2.5 MeV
double b7_si_a = -0.52441;

double a6_si_a = 1497.2076761; //2.5 to 3.5 MeV
double b6_si_a = -0.62242;

double a5_si_a = 1706.723733; // 3.5 to 5 MeV
double b5_si_a = -0.630125;

double a4_si_a = 1817.25965; // 5 to 7 MeV
double b4_si_a = -0.669928;

double a3_si_a = 1911.1161; // 7 to 10 MeV
double b3_si_a = -0.69588;

double a2_si_a = 1990.501841; // 10 to 12 MeV
double b2_si_a = -0.7137736;

double a1_si_a = 2048.867961; // 12 to 15 MeV
double b1_si_a = -0.725248;

  Int_t N = 10000;
const Double_t A1 = 12., A2 = 12., A3 = 1.007825, A4 = 22.989770, m = 931.5;//uma->MeV
const Double_t  A3_a = 4.002603, A4_a = 19.992440;//uma->MeV
const Double_t  A2_d = 2.014101777, A3_d = 1.007825, A4_d = 13.0033548378;//uma->MeV

  Double_t v_inf, v3, vlab;
Double_t E3, E3bis, E_inf = 10.75, Ecm = E_inf/2, Q_fus, A12, mu;
//Double_t E3, E3bis, E_inf = 10.67, Ecm = E_inf/2, Q_fus, A12, A12_d, mu_d, mu, Ecm_d;
//Double_t E3, E3bis, E_inf = 5.6, Ecm = E_inf/2, Q_fus, A12, mu;
  Double_t E3_a, E3bis_a, Q_fus_a;
  Double_t E3_d, E3bis_d, Q_fus_d;
  Double_t Eex[11] = {0.0, 0.43999, 2.076011, 2.390732, 2.63985,
		    2.703500, 2.982060, 3.67760, 3.848069, 3.914239, 4.42964};//excitation energies (gamma)
Double_t Eex_a[8] = {0.0, 1.633674, 4.2477, 4.96651, 5.6214, 5.7877, 6.725, 7.004};
Double_t Eex_d[8] = {0.0, 3.089443, 3.684507, 3.853807, 6.864, 7.492, 7.547, 7.686};
  Double_t gam3[11], Q_eff[11];
  Double_t gam3_a[11], Q_eff_a[11];
  Double_t gam3_d[11], Q_eff_d[11];
  Double_t r_int_S3 = 11;//Detector caracteristics (mm)
  Double_t r_ext_S3 = 35;
  Double_t d_S3_fwd = 60; //distance from targed
  Double_t d_S3_bwd = 56;

  Double_t theta_min_S3_fwd = atan(r_int_S3/d_S3_fwd)*180/M_PI;
  Double_t theta_max_S3_fwd = atan(r_ext_S3/d_S3_fwd)*180/M_PI;

  Double_t theta_min_S3_bwd = 180 - atan(r_ext_S3/d_S3_bwd)*180/M_PI;
  Double_t theta_max_S3_bwd = 180 - atan(r_int_S3/d_S3_bwd)*180/M_PI;  // Set binwidth
  const Double_t z_s3f = 6.0; // cm; z position
  const Double_t z_s1b = -3.1;
  const Double_t z_s3b = -5.6;
  const Double_t r_i_s1 = 4.8/2.; // active area radii
  const Double_t r_a_s1 = 9.6/2.;
  const Double_t r_i_s3 = 2.3/2.;
  const Double_t r_a_s3 = 7.0/2.;
  const Double_t d_s1 = 0.1505; // cm, strip pitch
  const Double_t d_s3 = 0.0886;
  const Double_t offs_s1 = -0.004; // cm, center sensitive area from strip pitch in active area from the manual
// const Double_t offs_s3 = 0.1368;// without resistive junction
  const Double_t offs_s3 = 0.0218;//with resistive junction
  const Double_t d_s3_iso = 0.0100; // cm,
  const Int_t n_ch_s3 = 24;
  Double_t bin_s3f[n_ch_s3 + 1], bin_s3b[n_ch_s3 + 1];
  Double_t bin_s3f1[n_ch_s3], bin_s3b1[n_ch_s3], bin_s3f2[n_ch_s3], bin_s3b2[n_ch_s3], bin_s3f3[n_ch_s3], bin_s3b3[n_ch_s3], bin_s3f4[n_ch_s3], bin_s3b4[n_ch_s3];
