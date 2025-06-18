#ifndef LABR_CYL_PRIMARYGENERATORACTION_HH
#define LABR_CYL_PRIMARYGENERATORACTION_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"

class LaBr_cyl_PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
    LaBr_cyl_PrimaryGeneratorAction();
    virtual ~LaBr_cyl_PrimaryGeneratorAction();

    virtual void GeneratePrimaries(G4Event* anEvent);
public:
    G4ParticleGun *fParticleGun;
};

#endif
