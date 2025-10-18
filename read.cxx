#include "my_class.h"
#include <TFile.h>
#include <TTree.h>
#include <TH2F.h> // for histogram

void read()
{
    TFile *f = TFile::Open("tree_file.root"); // opens the root file
    auto tree = (TTree *)f->Get("tree");      // This gets teh tree from f

    particle_class *p = nullptr;            // this initializes the object
    tree->SetBranchAddress("particle", &p); // sets the branch adress

    Int_t N = tree->GetEntries();                                          // this does so it loops over the whole tree
    TH2F *h2 = new TH2F("h2", "px vs py", 100, -0.1, 0.1, 100, -0.1, 0.1); // creates the 2d histogram

    for (Int_t i = 0; i < N; ++i)
    {
        tree->GetEntry(i);
        h2->Fill(p->px, p->py); // This fills the histogram
    }
    TCanvas *c1 = new TCanvas("c1", "px vs py", 800, 600);
    h2->Draw("COLZ");    // does colour coded squares for the bin count
    c1->WaitPrimitive(); // Does so teh canvas doesnt delete instantly

    TCanvas *c2 = new TCanvas("c2", "px*py vs pz", 800, 600);
    // Below draws the scatter plot, the criterion is that magnitude of p is greater than 0.02
    tree->Draw("px*py:pz", "sqrt(px*px + py*py + pz*pz) > 0.02");
    c2->WaitPrimitive();
}