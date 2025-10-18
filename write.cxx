#include "my_class.h"
#include <TFile.h>
#include <TTree.h>
#include <TRandom.h>
#include <iostream>

void write()
{

    particle_class *p = new particle_class(); // Initializes the object p to as a pointer to a particle_class object

    gRandom->SetSeed(0);                              // Does so 'Random' number is same everytime I run it
    auto f = new TFile("tree_file.root", "RECREATE"); // Creates the root file
    auto tree = new TTree("tree", "particle tree");   // This creates the TTree

    tree->Branch("particle", &p); // This makes the branch

    Int_t nEvents = 1000000;            // This sets the number of events
    for (Int_t i = 0; i < nEvents; ++i) // This loop fills p with random data
    {
        p->px = gRandom->Gaus(0, .02);
        p->py = gRandom->Gaus(0, .02);
        p->pz = gRandom->Gaus(0, .02);

        double mag = p->magnitude();
        std::cout << "Event " << i << ": |p| = " << mag << std::endl;

        tree->Fill();
    }

    f->Write();
    f->Close();
    delete p;
    delete f; // makes sure that there is no memory leak
}
