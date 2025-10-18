#include "my_class.h"
#include <cmath>
ClassImp(particle_class)

    // default constructor - ROOT needs the default one where everything is set to 0
    particle_class::particle_class() : px(0), py(0), pz(0) // This initializes all members to be 0
// initialize all members to null
{
}
// another constructor
particle_class::particle_class(Int_t variable) : px(variable), py(variable), pz(variable)
{
}

double particle_class::magnitude() const
{
    return std::sqrt(px * px + py * py + pz * pz);
}
// destructor
particle_class::~particle_class()
{
    // right now I’m empty
}