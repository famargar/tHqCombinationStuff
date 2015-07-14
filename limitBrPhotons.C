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

const int flag = 1;

int main() {

    // Data points for limits
    vector<double> const x{0.5, 1., 1.5, 2., 2.4, 2.7, 3.};

//    if(flag == 0){
	// Data points for limits
	
	// limits as a function of mu
	vector<double> const limitObserved{4.29,  3.80,  3.36,  3.03,  2.75,  2.53,  2.35};
	
	vector<double> const   limit2SDown{1.99,  1.68,  1.40,  1.37,  1.33,  1.33,  1.30};
	vector<double> const   limit1SDown{2.36,  1.97,  1.80,  1.67,  1.63,  1.55,  1.50};
	vector<double> const     limitMean{3.00,  2.68,  2.44,  2.20,  2.00,  1.93,  1.77};
	vector<double> const     limit1SUp{4.43,  3.98,  3.44,  3.10,  2.84,  2.65,  2.47};
	vector<double> const     limit2SUp{5.90,  5.48,  5.01,  4.60,  4.15,  3.80,  3.60};
//    }
  
	/*
    else{
	// limits in fb
        vector<double> const   limitObserved{4.29*231,  3.80*231,  3.36*231,  3.03*231,  2.75*231,  2.53*231,  2.35};
	    
        vector<double> const   limitfb2SDown{1.99*231,  1.68*231,  1.40*231,  1.37*231,  1.33*231,  1.33*231,  1.30};
        vector<double> const   limitfb1SDown{2.36*231,  1.97*231,  1.80*231,  1.67*231,  1.63*231,  1.55*231,  1.50};
        vector<double> const     limitfbMean{3.00*231,  2.68*231,  2.44*231,  2.20*231,  2.00*231,  1.93*231,  1.77};
        vector<double> const     limitfb1SUp{4.43*231,  3.98*231,  3.44*231,  3.10*231,  2.84*231,  2.65*231,  2.47};
        vector<double> const     limitfb2SUp{5.90*231,  5.48*231,  5.01*231,  4.60*231,  4.15*231,  3.80*231,  3.60};
	    
    }
	*/
    
    // Canvas
    TCanvas canvas("canvas", "", 1200, 1000);
    canvas.SetTicks();
    canvas.SetGrid();
    
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


    // add reference line
    TLine mu(0.25, 1, 3.25, 1);


    // Draw graphs
    band2S.Draw("a3");
    band1S.Draw("3");
    graphMean.Draw("l");
    graphObserved.Draw("l same");
    mu.Draw("same");
    
    
    // Decoration for axes
    band2S.SetTitle(";Br(H#rightarrow#gamma#gamma) / Br_{SM}(H#rightarrow#gamma#gamma);"
     "95% CL_{s} limit on #sigma / #sigma_{y_{t} = -1}");
    band2S.GetYaxis()->SetRangeUser(0., 7.);
    band2S.GetXaxis()->SetTitleOffset(1.3);
    
    
    // Add a legend
    TLegend legend(0.65, 0.65, 0.85, 0.85);
    
    legend.AddEntry(&graphObserved, " Observed ", "l");
    legend.AddEntry(&graphMean, " Expected ", "l");
    legend.AddEntry(&band1S, " #pm1#sigma exp. ", "f");
    legend.AddEntry(&band2S, " #pm2#sigma exp. ", "f");
    
    legend.Draw();
    
    
    // CMS labels
    TLatex cmsLabel(0.12, 0.91, "#scale[1.2]{#font[62]{CMS}} #font[52]{Preliminary}");
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
    canvas.Print("limitBrPhotons.pdf");
    cout<<"printed"<<endl;

}

#endif
