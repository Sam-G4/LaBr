#include "LaBr3_Slab_TrackingAction.h"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"

LaBr3_Slab_TrackingAction::LaBr3_Slab_TrackingAction()  {
}

LaBr3_Slab_TrackingAction::~LaBr3_Slab_TrackingAction() {}

void LaBr3_Slab_TrackingAction::PreUserTrackingAction(const G4Track *track){
std::cout <<"Tracking Action begin....." << std::endl;
}

void LaBr3_Slab_TrackingAction::PostUserTrackingAction(const G4Track *track){
std::cout <<"Tracking Action ends....." << std::endl;
}

