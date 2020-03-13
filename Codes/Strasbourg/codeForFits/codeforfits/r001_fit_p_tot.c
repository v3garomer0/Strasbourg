
#include "/home/gustavo/Documents/orsayData/libPerso.h"
#include "r001_fit_p_tot_objects.h"
#include "r001_fit_p_tot_outfiles.h"
#include "r001_fit_p_tot_infiles.h"
#include "r001_fit_p_tot_helpers.cpp"
#include "r001_fit_p_tot_compute.cpp"
#include "r001_fit_p_tot_display.cpp"


void r001_fit_p_tot (){

  // check single particle spectra
  // check the angular distributions S3F/S3B
  // check multiplicity patterns per energy and particle cut


  gStyle->SetOptStat (0);
  //gStyle->SetOptStat (1111110);
  gStyle->SetOptFit(1);
  gSystem->Exec ("ls -lrth r010_ene_gp.root");

  // pull data
  ComputeFiles();
  ComputeHistograms();
  ComputeTree();
  ComputeData();

  // plot data
  DisplayFitFwd(); //display fit and extract parameters
  ComputeOutputFwd();
  DisplayFitBwd();//display fit and extract parameters in ofile
  ComputeCloseOFiles();
}
