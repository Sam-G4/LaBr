#include "LaBr_slab_TrackingAction.h"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"

LaBr_slab_TrackingAction::LaBr_slab_TrackingAction()  {
}

LaBr_slab_TrackingAction::~LaBr_slab_TrackingAction() {}

void LaBr_slab_TrackingAction::PreUserTrackingAction(const G4Track *track){
std::cout <<"Tracking Action begin....." << std::endl;
}

void LaBr_slab_TrackingAction::PostUserTrackingAction(const G4Track *track){
std::cout <<"Tracking Action ends....." << std::endl;
}

