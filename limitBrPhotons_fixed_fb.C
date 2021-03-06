#include <vector>
#include <iostream>
#include "TStyle.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TGraphAsymmErrors.h"
#include "TAxis.h"
#include "TLine.h"

using namespace std;

#ifndef __CINT__

int main() {

    // Data points for limits
    vector<double> const x{0.5, 1., 1.5, 2., 2.4, 2.7, 3.};

    // limits in fb
    vector<double> const   limitObserved{4.29*231,  3.80*231,  3.44*231,  3.06*231,  2.84*231,  2.72*231,  2.57*231};
    
    vector<double> const   limit2SDown{1.99*231,  1.68*231,  1.48*231,  1.37*231,  1.30*231,  1.25*231,  1.20*231};
    vector<double> const   limit1SDown{2.36*231,  2.01*231,  1.80*231,  1.73*231,  1.64*231,  1.59*231,  1.48*231};
    vector<double> const     limitMean{3.00*231,  2.72*231,  2.47*231,  2.28*231,  2.16*231,  2.06*231,  1.92*231};
    vector<double> const     limit1SUp{4.43*231,  3.93*231,  3.53*231,  3.25*231,  2.99*231,  2.84*231,  2.73*231};
    vector<double> const     limit2SUp{5.90*231,  5.41*231,  4.91*231,  4.55*231,  4.29*231,  4.16*231,  4.05*231};
    
    // Canvas
    TCanvas canvas("canvas", "", 1200, 1200);
    canvas.SetTicks();
    canvas.SetGrid(kFALSE);
    canvas.SetGridy(kFALSE);
    
    // Style
    gStyle->SetStripDecimals(kFALSE);
    
    
    // Graphs with observed and mean expected limits
    TGraph graphObserved(x.size(), x.data(), limitObserved.data());
    graphObserved.SetLineColor(kBlack);
    graphObserved.SetLineWidth(2);
    
    TGraph graphMean(x.size(), x.data(), limitMean.data());
    graphMean.SetLineColor(kBlack);
    graphMean.SetLineStyle(2);
    graphMean.SetLineWidth(2);
    
    
    // Graphs with error bands
    vector<double> err1SUp(x.size()), err1SDown(x.size());
    
    for (unsigned i = 0; i < x.size(); ++i)
    {
        err1SUp.at(i) = limit1SUp.at(i) - limitMean.at(i);
        err1SDown.at(i) = limitMean.at(i) - limit1SDown.at(i);
    }
    
    TGraphAsymmErrors band1S(x.size(), x.data(), limitMean.data(), nullptr, nullptr,
     err1SDown.data(), err1SUp.data());
    band1S.SetFillColor(kGreen);
    
    vector<double> err2SUp(x.size()), err2SDown(x.size());
    
    for (unsigned i = 0; i < x.size(); ++i)
    {
        err2SUp.at(i) = limit2SUp.at(i) - limitMean.at(i);
        err2SDown.at(i) = limitMean.at(i) - limit2SDown.at(i);
    }
    
    TGraphAsymmErrors band2S(x.size(), x.data(), limitMean.data(), nullptr, nullptr,
     err2SDown.data(), err2SUp.data());
    band2S.SetFillColor(kYellow);


    // add reference lines...
    TLine mum1(0.25, 231, 3.25, 231);
    TLine mup1(0.25,  18, 3.25,  18);
    mum1.SetLineWidth(2);
    mum1.SetLineColor(2);
    mup1.SetLineWidth(2);

    // ..and corresponding text on top of them
    TLatex latexm1;
    TLatex latexp1;
    latexm1.SetTextAlign(11);
    latexp1.SetTextAlign(10);
    latexm1.SetTextSize(0.030);
    latexp1.SetTextSize(0.030);

    // Draw graphs
    band2S.Draw("a3");
    band1S.Draw("3");
    graphMean.Draw("l");
    graphObserved.Draw("l same");
    mum1.Draw("same");
    mup1.Draw("same");
    latexm1.DrawLatex(.5,270, "#sigma_{tHq}(C_{t} = -1)");
    latexp1.DrawLatex(.5,30, "#sigma_{tHq}(C_{t} = 1)");
    
    
    
    // Decoration for axes
    band2S.SetTitle(";Br(H#rightarrow#gamma#gamma) / Br_{SM}(H#rightarrow#gamma#gamma);"
     "95% CL limit on #sigma (fb)");
    band2S.GetYaxis()->SetRangeUser(0., 1600.);
    band2S.GetXaxis()->SetTitleOffset(1.3);
    band2S.GetYaxis()->SetTitleOffset(1.5);
    band2S.GetYaxis()->SetLabelSize(0.03);
    band2S.GetXaxis()->SetLabelSize(0.03);
    
    
    // Add a legend
    TLegend legend(0.65, 0.65, 0.85, 0.85);
    legend.SetLineColor(0);
    legend.AddEntry(&graphObserved, " Observed ", "l");
    legend.AddEntry(&graphMean, " Expected ", "l");
    legend.AddEntry(&band1S, " #pm1#sigma exp. ", "f");
    legend.AddEntry(&band2S, " #pm2#sigma exp. ", "f");
    
    legend.Draw();
    
    
    // CMS labels
    //TLatex cmsLabel(0.12, 0.91, "#scale[1.2]{#font[62]{CMS}} #font[52]{Preliminary}");
    TLatex cmsLabel(0.12, 0.91, "#scale[1.2]{#font[62]{CMS}}");
    cmsLabel.SetNDC();
    cmsLabel.SetTextSize(0.04);
    cmsLabel.SetTextAlign(11);
    
    TLatex energyLabel(0.9, 0.91, "#font[42]{19.7 fb^{-1} (8 TeV)}");
    energyLabel.SetNDC();
    energyLabel.SetTextSize(0.04);
    energyLabel.SetTextAlign(31);
    
    cmsLabel.Draw();
    energyLabel.Draw();
    
    
    // Save the figure
    canvas.Print("limitPLOT.pdf");
    canvas.Print("limitPLOT.C");
    cout<<"printed"<<endl;

}

#endif
