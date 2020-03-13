Double_t my_func (Double_t *var, Double_t *par){

  return par[0]/var[0] + par[1]; // f(x) = a/x + b
}

Double_t my_gaus (Double_t *var, Double_t *par){

  return par[0]*TMath::Exp (-0.5*TMath::Power ((var[0] - par[1])/par[2], 2));// gaussian function
}

Double_t my_exp (Double_t *var, Double_t *par){

  return TMath::Exp(par[0] + par[1]*var[0]);
}

Double_t my_lin (Double_t *var, Double_t *par){

  return par[0] + par[1]*var[0];
}

Double_t my_resp (Double_t *var, Double_t *par){

  // two gaussian for the signals
  Double_t *set1 = &par[0];
  Double_t *set2 = &par[3];
  Double_t *set3 = &par[6];

    return my_gaus (var, set1) + my_gaus (var, set2) + my_exp (var, set3);
}

Double_t my_resp2 (Double_t *var, Double_t *par){

  // two gaussian for the signals
  Double_t *set1 = &par[0];
  Double_t *set2 = &par[3];
  Double_t *set3 = &par[6];

    return my_gaus (var, set1) + my_gaus (var, set2) + my_lin (var, set3);
}

Double_t my_resp3 (Double_t *var, Double_t *par){

  // two gaussian for the signals
  Double_t *set1 = &par[0];
  Double_t *set2 = &par[3];
  Double_t *set3 = &par[6];
  Double_t *set4 = &par[9];

    return my_gaus (var, set1) + my_gaus (var, set2) + my_gaus (var, set3) + my_exp (var, set4);
}

Double_t my_resp4 (Double_t *var, Double_t *par){

  // two gaussian for the signals
  Double_t *set1 = &par[0];
  Double_t *set2 = &par[3];
  Double_t *set3 = &par[6];
  Double_t *set4 = &par[9];

    return my_gaus (var, set1) + my_gaus (var, set2) + my_gaus (var, set3) + my_lin (var, set4);
}
Double_t my_resp5 (Double_t *var, Double_t *par){

  // two gaussian for the signals
  Double_t *set1 = &par[0];
  Double_t *set2 = &par[3];
  Double_t *set3 = &par[6];
  Double_t *set4 = &par[9];
  Double_t *set5 = &par[12];
  Double_t *set6 = &par[15];

    return my_gaus (var, set1) + my_gaus (var, set2) + my_gaus (var, set3) + my_gaus (var, set4) + my_gaus (var, set5) + my_exp (var, set6);
}

void SetupGraphAppearance(TGraphErrors* graph, Int_t markerStyle, Int_t markerColor, Int_t lineWidth, Int_t lineColor) {
  graph->SetMarkerStyle(markerStyle);
  graph->SetMarkerColor(markerColor);
  graph->SetLineWidth(lineWidth);
  graph->SetLineColor(lineColor);
}

void SetupGraphAppearance(TGraph* graph, Int_t markerStyle, Int_t markerColor, Int_t lineWidth, Int_t lineColor) {
  graph->SetMarkerStyle(markerStyle);
  graph->SetMarkerColor(markerColor);
  graph->SetLineWidth(lineWidth);
  graph->SetLineColor(lineColor);
}
void SetupCanvas(TCanvas* canvas, string name) {
  canvas = new TCanvas(&name[0], "", 700, 500);
  canvas->SetTickx();
  canvas->SetTicky();
}

void SetupCanvas(TCanvas* canvas, string name, Int_t nHorizontal, Int_t nVertical) {
  canvas = new TCanvas(&name[0], "", 700, 500);
  canvas->Draw();
  //canvas->Divide (nHorizontal, nVertical);

}


void SetupHistogram(TH1F* histogram, string name, string title, string xAxisTitle, string yAxisTitle) {
  histogram = new TH1F (&name[0], &title[0], 100, 0, 180);
  histogram->GetYaxis ()->SetRangeUser(0, 0.2);
  histogram->GetXaxis ()->SetTitle(&xAxisTitle[0]);
  histogram->GetYaxis ()->SetTitle(&yAxisTitle[0]);
  histogram->Draw("");
}

void SetupHistogram(TH1F* histogram, string name, string title, string xAxisTitle, string yAxisTitle, Int_t nbin, Int_t xmax, Int_t xmin) {
  histogram = new TH1F (&name[0], &title[0], nbin, xmin, xmax);
  histogram->GetXaxis ()->SetTitle(&xAxisTitle[0]);
  histogram->GetYaxis ()->SetTitle(&yAxisTitle[0]);
  histogram->Draw("");
}

void SetupLegend(TLegend* legend, TGraphErrors* graph, string name, string option) {
  legend = new TLegend(0.45,0.65,0.85,0.85);
  legend->SetLineColor(1);
  legend->AddEntry(graph, &name[0], &option[0]);
  legend->Draw ("SAME");
}

template<typename T, size_t N>
void SetupLegend(TLegend* legend, std::array<T, N> &entries) {
  legend = new TLegend(0.45,0.65,0.85,0.85);
  legend->SetLineColor(1);
  for(T& entry : entries) {
    legend->AddEntry(entry.graph, &entry.name[0], &entry.option[0]);
  }
  legend->Draw ("SAME");
}
