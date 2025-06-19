#include "LaBr3_Slab_SteppingAction.h"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"

#include <set>
LaBr3_Slab_SteppingAction::LaBr3_Slab_SteppingAction() {}

LaBr3_Slab_SteppingAction::~LaBr3_Slab_SteppingAction() {}

G4int nGenerated = 0;
G4int nDetected = 0;

void LaBr3_Slab_SteppingAction::UserSteppingAction(const G4Step* step) {
    G4Track* track = step->GetTrack();
    G4int trackID = track->GetTrackID();
   
    G4String particleName = track->GetDefinition()->GetParticleName();
    G4String volumeName = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName();    
    
    // DEBUG: print it
//    G4cout << "Step in: " << volumeName << G4endl;
// Count total gammas entering detector (only once per track)
    if (particleName == "gamma" &&
        step->GetPreStepPoint()->GetStepStatus() == fGeomBoundary &&
        volumeName == "PhyLaBr_slab")
    {
        nGenerated++;
    }
/*
    // Count only if energy deposited inside LaBr
    G4double edep = step->GetTotalEnergyDeposit();
    if (edep > 0. &&
        volumeName == "PhyLaBr_slab")
    {
    	 if (detectedTrackIDs.find(trackID) == detectedTrackIDs.end()) {
        detectedTrackIDs.insert(trackID);
        nDetected++;
       //G4cout << "edep: " << edep << G4endl;
       }
    }*/
}
