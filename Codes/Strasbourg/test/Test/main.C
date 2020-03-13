
#include "main.h"

#include "global.hh"


Int_t display_input (Char_t* nameIn_dI){

  std::cout << "\n <INFO> reading " << nameIn_dI << std::endl;

  std::ifstream input_dI (nameIn_dI);
/*  if (input_dI == NULL);
    {
      std::cout << "\n <ERROR> No input variable file." << std::endl;
      return 0;
    } */

  std::string run_dI, scale_dI, ene_dI;
  input_dI >> run_dI >> scale_dI >> ene_dI;

  eneBeam = std::atof (ene_dI.c_str ());
  
  std::cout << " <INFO>   run = " << std::atoi (run_dI.c_str ()) << std::endl;
  std::cout << " <INFO> scale = " << std::atoi (scale_dI.c_str ()) << std::endl;
  std::cout << " <INFO>   E_b = " << std::setw (5) << eneBeam << " MeV" << std::endl;
  
  return 0;
}


Int_t main (Int_t argc, Char_t* argv[]){

  gStyle->SetOptStat (0);
  
  display_input (argv[1]);



  std::cout << "\n Hello World.\n\n";  
  
  return 0;
}
