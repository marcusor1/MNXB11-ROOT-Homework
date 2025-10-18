#ifndef __PARTICLE_CLASS_H__
#define __PARTICLE_CLASS_H__
#include <TObject.h>

class particle_class : public TObject
{

public:
    particle_class();               // default constructor
    particle_class(Int_t variable); // some other constructor
    double magnitude() const;       // This is to find the magnitude of p
    virtual ~particle_class();      // destructor
    Double_t px, py, pz;            // These are the private members

private:
    ClassDef(particle_class, 1); // my_class
};
#endif // __PARTICLE_CLASS_H_