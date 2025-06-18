#include "LaBr_cyl_TrackingAction.h"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"

LaBr_cyl_TrackingAction::LaBr_cyl_TrackingAction()  {
}

LaBr_cyl_TrackingAction::~LaBr_cyl_TrackingAction() {}

void LaBr_cyl_TrackingAction::PreUserTrackingAction(const G4Track *track){
std::cout <<"Tracking Action begin....." << std::endl;
}

void LaBr_cyl_TrackingAction::PostUserTrackingAction(const G4Track *track){
std::cout <<"Tracking Action ends....." << std::endl;
}

