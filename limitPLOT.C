{
//=========Macro generated from canvas: canvas/
//=========  (Mon Aug  3 16:11:33 2015) by ROOT version5.34/23
   TCanvas *canvas = new TCanvas("canvas", "",0,0,1200,1200);
   canvas->SetHighLightColor(2);
   canvas->Range(-0.125,-200,3.625,1800);
   canvas->SetFillColor(0);
   canvas->SetBorderMode(0);
   canvas->SetBorderSize(2);
   canvas->SetTickx(1);
   canvas->SetTicky(1);
   canvas->SetFrameBorderMode(0);
   canvas->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(7);
   grae->SetName("Graph0");
   grae->SetTitle(";Br(H#rightarrow#gamma#gamma) / Br_{SM}(H#rightarrow#gamma#gamma);95% CL limit on #sigma (fb)");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,0.5,693);
   grae->SetPointError(0,0,0,233.31,669.9);
   grae->SetPoint(1,1,628.32);
   grae->SetPointError(1,0,0,240.24,621.39);
   grae->SetPoint(2,1.5,570.57);
   grae->SetPointError(2,0,0,228.69,563.64);
   grae->SetPoint(3,2,526.68);
   grae->SetPointError(3,0,0,210.21,524.37);
   grae->SetPoint(4,2.4,498.96);
   grae->SetPointError(4,0,0,198.66,492.03);
   grae->SetPoint(5,2.7,475.86);
   grae->SetPointError(5,0,0,187.11,485.1);
   grae->SetPoint(6,3,443.52);
   grae->SetPointError(6,0,0,166.32,492.03);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,0.25,3.25);
   Graph_Graph1->SetMinimum(0);
   Graph_Graph1->SetMaximum(1600);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetTitle("Br(H#rightarrow#gamma#gamma) / Br_{SM}(H#rightarrow#gamma#gamma)");
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.03);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleOffset(1.3);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle("95% CL limit on #sigma (fb)");
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.03);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleOffset(1.5);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph1);
   
   grae->Draw("a3");
   
   grae = new TGraphAsymmErrors(7);
   grae->SetName("Graph1");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(ci);
   grae->SetPoint(0,0.5,693);
   grae->SetPointError(0,0,0,147.84,330.33);
   grae->SetPoint(1,1,628.32);
   grae->SetPointError(1,0,0,164.01,279.51);
   grae->SetPoint(2,1.5,570.57);
   grae->SetPointError(2,0,0,154.77,244.86);
   grae->SetPoint(3,2,526.68);
   grae->SetPointError(3,0,0,127.05,224.07);
   grae->SetPoint(4,2.4,498.96);
   grae->SetPointError(4,0,0,120.12,191.73);
   grae->SetPoint(5,2.7,475.86);
   grae->SetPointError(5,0,0,108.57,180.18);
   grae->SetPoint(6,3,443.52);
   grae->SetPointError(6,0,0,101.64,187.11);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Graph",100,0.25,3.25);
   Graph_Graph2->SetMinimum(273.735);
   Graph_Graph2->SetMaximum(1091.475);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph2->SetLineColor(ci);
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph2);
   
   grae->Draw("3");
   
   TGraph *graph = new TGraph(7);
   graph->SetName("Graph2");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineStyle(2);
   graph->SetLineWidth(2);
   graph->SetPoint(0,0.5,693);
   graph->SetPoint(1,1,628.32);
   graph->SetPoint(2,1.5,570.57);
   graph->SetPoint(3,2,526.68);
   graph->SetPoint(4,2.4,498.96);
   graph->SetPoint(5,2.7,475.86);
   graph->SetPoint(6,3,443.52);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,0.25,3.25);
   Graph_Graph1->SetMinimum(418.572);
   Graph_Graph1->SetMaximum(717.948);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   graph->Draw("l");
   
   graph = new TGraph(7);
   graph->SetName("Graph3");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineWidth(2);
   graph->SetPoint(0,0.5,990.99);
   graph->SetPoint(1,1,877.8);
   graph->SetPoint(2,1.5,794.64);
   graph->SetPoint(3,2,706.86);
   graph->SetPoint(4,2.4,656.04);
   graph->SetPoint(5,2.7,628.32);
   graph->SetPoint(6,3,593.67);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Graph",100,0.25,3.25);
   Graph_Graph2->SetMinimum(553.938);
   Graph_Graph2->SetMaximum(1030.722);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph2->SetLineColor(ci);
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph2);
   
   graph->Draw("l ");
   TLine *line = new TLine(0.25,231,3.25,231);
   line->SetLineColor(2);
   line->SetLineWidth(2);
   line->Draw();
   line = new TLine(0.25,18,3.25,18);
   line->SetLineWidth(2);
   line->Draw();
   TLatex *   tex = new TLatex(0.5,270,"#sigma_{tHq}(C_{t} = -1)");
   tex->SetTextSize(0.03);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.5,30,"#sigma_{tHq}(C_{t} = 1)");
   tex->SetTextAlign(10);
   tex->SetTextSize(0.03);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TLegend *leg = new TLegend(0.65,0.65,0.85,0.85,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph3"," Observed ","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph2"," Expected ","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1"," #pm1#sigma exp. ","f");

   ci = TColor::GetColor("#00ff00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph0"," #pm2#sigma exp. ","f");

   ci = TColor::GetColor("#ffff00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
      tex = new TLatex(0.12,0.91,"#scale[1.2]{#font[62]{CMS}}");
tex->SetNDC();
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.9,0.91,"#font[42]{19.7 fb^{-1} (8 TeV)}");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
   canvas->Modified();
   canvas->cd();
   canvas->SetSelected(canvas);
}
