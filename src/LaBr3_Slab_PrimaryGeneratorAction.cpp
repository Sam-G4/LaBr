#include "LaBr3_Slab_PrimaryGeneratorAction.h"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4SystemOfUnits.hh"

#include "G4Gamma.hh" 
#include "G4RandomTools.hh"
LaBr3_Slab_PrimaryGeneratorAction::LaBr3_Slab_PrimaryGeneratorAction() {
    G4int n_particle = 1;
    fParticleGun = new G4ParticleGun(n_particle);

    //Default we have setup geantino particles
    G4ParticleDefinition* particle = G4ParticleTable::GetParticleTable()->FindParticle("gamma");
    fParticleGun->SetParticleDefinition(particle);
    //fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0., 0., 1.));
    fParticleGun->SetParticleEnergy(0.662 * MeV);
    fParticleGun->SetParticlePosition(G4ThreeVector(0., 0., 0.));
    
    // TODO : Add your desired particles
}

LaBr3_Slab_PrimaryGeneratorAction::~LaBr3_Slab_PrimaryGeneratorAction() {
    delete fParticleGun;
}


void LaBr3_Slab_PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {

    
    //TODO :  Logic to change the particle position for each event
   
	G4ThreeVector randomDir = G4RandomDirection();
    fParticleGun->SetParticleMomentumDirection(randomDir);  
    fParticleGun->GeneratePrimaryVertex(anEvent);
}
