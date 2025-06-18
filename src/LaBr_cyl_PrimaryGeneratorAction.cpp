#include "LaBr_cyl_PrimaryGeneratorAction.h"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"

//#include "G4Gamma.hh" 
#include "G4RandomTools.hh"
LaBr_cyl_PrimaryGeneratorAction::LaBr_cyl_PrimaryGeneratorAction() {
    G4int n_particle = 1;
    fParticleGun = new G4ParticleGun(n_particle);

    //Default we have setup geantino particles
    G4ParticleDefinition* particle = G4ParticleTable::GetParticleTable()->FindParticle("gamma");
    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticlePosition(G4ThreeVector(0., 0., 0.));
    //fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0., 0., 1.));
    fParticleGun->SetParticleEnergy(0.662 * MeV);
    
    
    // TODO : Add your desired particles
}

LaBr_cyl_PrimaryGeneratorAction::~LaBr_cyl_PrimaryGeneratorAction() {
    delete fParticleGun;
}


void LaBr_cyl_PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {

    
    //TODO :  Logic to change the particle position for each event
    
    fParticleGun->SetParticleMomentumDirection(G4RandomDirection());
	   
    fParticleGun->GeneratePrimaryVertex(anEvent);
}
