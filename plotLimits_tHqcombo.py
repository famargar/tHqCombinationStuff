import ROOT
from ROOT import TCanvas, TLatex, TGraphAsymmErrors, TH1D, TH2D, TLegend

def redrawBorder(pad):
	# this little macro redraws the axis tick marks and the pad border lines.
	pad.Update()
	pad.RedrawAxis()
	l = ROOT.TLine()
	l.DrawLine(pad.GetUxmin(), pad.GetUymax(), pad.GetUxmax(), pad.GetUymax())
	l.DrawLine(pad.GetUxmax(), pad.GetUymin(), pad.GetUxmax(), pad.GetUymax())
	pad.SetTicks(0,1)


ROOT.gROOT.SetBatch(1)
ROOT.gStyle.SetOptStat(0)
ROOT.gStyle.SetLabelOffset(0.005)


c = ROOT.TCanvas("limits","limits",600,600)
c.cd()
c.SetBorderSize(0)
c.SetFillColor(ROOT.kWhite)

# labels = ["\\mu^{#pm}\\mu^{#pm}", "e^{#pm}\\mu^{#pm}", "3 Leptons", "Combination"]
labels = ["#tau_{had}", "e^{#pm}#mu^{#pm}", "3 lep", "#mu^{#pm}#mu^{#pm}", "b #bar{b}", "#gamma#gamma", "Combined"]


#  -- Upper limit VALUES values
#  -- Entry upper limits and error bands
values = []
values.append((6.0, 8.1, 11.4, 16.7, 24.9))    # tautau
values.append((5.4, 7.0, 9.3, 13.5, 18.8))     # em
values.append((5.7, 6.6, 8.6, 12.4, 18.0))     # 3l
values.append((4.7, 6.0, 8.1, 11.8, 16.7))     # mm
values.append((2.80, 3.75, 5.35, 7.72, 10.7))   # bb
values.append((3.43, 3.68, 4.05, 4.20, 5.25))  # gamma gamma
values.append((1.33, 1.63, 2.00, 2.84, 4.15))   # total combination

#  -- Entry observed upper limits
#  --   tt    em    3l   mm   bb   gg  comb
obs = [9.8, 11.4, 11.5, 9.3, 7.6, 4.1, 2.75] 

COLOR1S = ROOT.kSpring-8
COLOR2S = ROOT.kYellow-4
# COLOR1S = 3 ## Higgs default 80's style
# COLOR2S = 5

expt = []
onesig = []
twosig = []
for llo, lo, cent, hi, hhi in values:
	expt.append(cent)
	onesigerr = abs(hi-lo)/2.
	twosigerr = abs(hhi-llo)/2.
	onesigcent = lo  + onesigerr
	twosigcent = llo + twosigerr
	onesig.append((onesigcent, onesigerr))
	twosig.append((twosigcent, twosigerr))

obshists2   = [TH1D("observed2%d"%n, "observed2", len(values), 0, len(values)) for n in range(len(values))]
obshists   = [TH1D("observed%d"%n, "observed", len(values), 0, len(values)) for n in range(len(values))]
exphists   = [TH1D("expected%d"%n, "expected", len(values), 0, len(values)) for n in range(len(values))]
# expecthist = TH1D("expected", "expected", len(values), 0, len(values))
onesighist = TH1D("onesigma", "onesigma", len(values), 0, len(values))
twosighist = TH1D("twosigma", "twosigma", len(values), 0, len(values))

for n in range(len(values)):
	for m in range(len(values)):
		obshists[n].SetBinContent(m+1, 0)
		obshists2[n].SetBinContent(m+1, 0)
		exphists[n].SetBinContent(m+1, 0)

for n in range(len(values)):
	obshists[n].SetBinContent(n+1, obs[n])
	obshists2[n].SetBinContent(n+1, obs[n])
	exphists[n].SetBinContent(n+1, expt[n])
	onesighist.SetBinContent(n+1, onesig[n][0])
	twosighist.SetBinContent(n+1, twosig[n][0])

	onesighist.SetBinError(n+1, onesig[n][1])
	twosighist.SetBinError(n+1, twosig[n][1])

for n in range(len(values)):
	obshists2[n].SetLineColor(ROOT.kBlack)
	obshists2[n].SetLineWidth(2)
	obshists2[n].SetLineStyle(1)
	obshists[n].SetLineColor(ROOT.kBlack)
	obshists[n].SetLineWidth(2)
	obshists[n].SetLineStyle(1)
	obshists[n].SetMarkerColor(ROOT.kBlack)
	obshists[n].SetMarkerStyle(20)
	obshists[n].SetMarkerSize(1.5)

	exphists[n].SetLineColor(ROOT.kBlack)
	exphists[n].SetLineStyle(2)
	exphists[n].SetLineWidth(2)

onesighist.SetMarkerColor(COLOR1S)
onesighist.SetFillColor(COLOR1S)
onesighist.SetFillStyle(1001)
twosighist.SetMarkerColor(COLOR2S)
twosighist.SetFillColor(COLOR2S)
twosighist.SetFillStyle(1001)

hlab = TH2D("hlab","",len(values),0,len(values),35,0,35)
hlab.GetYaxis().SetTitle("95% CL limit on #sigma/#sigma_{Ct=-1}")
hlab.GetYaxis().SetTitleOffset(1.15)
hlab.GetXaxis().SetLabelSize(0.05)
hlab.GetXaxis().SetTitleSize(0.04)
hlab.GetXaxis().SetTitleOffset(1.15)
hlab.GetXaxis().SetBinLabel(1,labels[0])
hlab.GetXaxis().SetBinLabel(2,labels[1])
hlab.GetXaxis().SetBinLabel(3,labels[2])
hlab.GetXaxis().SetBinLabel(4,labels[3])
hlab.GetXaxis().SetBinLabel(5,labels[4])
hlab.GetXaxis().SetBinLabel(6,labels[5])
hlab.GetXaxis().SetBinLabel(7,labels[6])
hlab.Draw("")

twosighist.Draw("E2 SAME")
onesighist.Draw("E2 SAME")

for n in range(len(values)):
	exphists[n].Draw("HIST ][ SAME")
	obshists2[n].Draw("HIST ][ SAME")
	obshists[n].Draw("P ][ SAME")

#  -- Standard legend
leg = TLegend(0.56,0.56,0.94,0.73)
leg.AddEntry(obshists[0]," Observed","pl")
leg.AddEntry(exphists[0]," Expected","l")
leg.AddEntry(onesighist," #pm 1#sigma exp.","f")
leg.AddEntry(twosighist," #pm 2#sigma exp.","f")
leg.SetBorderSize(0)
leg.SetFillColor(ROOT.kWhite)
leg.SetTextAlign(13)
leg.SetTextFont(42)
leg.SetTextSize(0.03)

#  -- Draw
# line = ROOT.TLine(0,1,4,1)
# line.SetLineColor(ROOT.kRed)
# line.SetLineWidth(2)
# line.Draw("same")

#  -- Draw labels and legend
tlatex = TLatex()
tlatex.SetNDC()

tlatex.SetTextSize(22)

tlatex.SetTextAlign(11)
tlatex.SetTextFont(63)
tlatex.DrawLatex(0.12,       0.91, "CMS")
tlatex.SetTextFont(53)
#tlatex.DrawLatex(0.12+0.085, 0.91, "Preliminary")


tlatex.SetTextFont(43)
tlatex.SetTextAlign(31)
tlatex.DrawLatex(0.90,       0.91, "19.7 fb^{-1} (8 TeV)")

tlatex.SetTextFont(43)
tlatex.SetTextSize(20)
tlatex.SetTextAlign(0)
tlatex.DrawLatex(0.57, 0.85,  "pp #rightarrow tHq")
tlatex.DrawLatex(0.57, 0.805, "t #rightarrow bl#nu")
tlatex.DrawLatex(0.57, 0.75,  "C_{t}=-1, m_{H}=125 GeV")


leg.Draw("same")
redrawBorder(ROOT.gPad)

c.SaveAs("tHqComboLimits_all.pdf")
c.SaveAs("tHqComboLimits_all.png")
