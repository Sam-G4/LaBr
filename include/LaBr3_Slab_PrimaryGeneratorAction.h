#ifndef LABR3_SLAB_PRIMARYGENERATORACTION_HH
#define LABR3_SLAB_PRIMARYGENERATORACTION_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"

class LaBr3_Slab_PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
    LaBr3_Slab_PrimaryGeneratorAction();
    virtual ~LaBr3_Slab_PrimaryGeneratorAction();

    virtual void GeneratePrimaries(G4Event* anEvent);
public:
    G4ParticleGun *fParticleGun;
};

#endif
