#include "LaBr_cyl_RunAction.h"
#include "G4Run.hh"

#include "G4SystemOfUnits.hh"
#include "G4ios.hh"

LaBr_cyl_RunAction::LaBr_cyl_RunAction()  {
}

LaBr_cyl_RunAction::~LaBr_cyl_RunAction() {}

void LaBr_cyl_RunAction::BeginOfRunAction(const G4Run*){

}

extern G4int nGenerated;
extern G4int nDetected;

void LaBr_cyl_RunAction::EndOfRunAction(const G4Run* run){
	G4cout << "\n===== Detector Efficiency Report =====" << G4endl;
    G4cout << "Total events run     : " << run->GetNumberOfEvent() << G4endl;
    G4cout << "Gammas entered LaBr3 : " << nGenerated << G4endl;
    G4cout << "Gammas detected      : " << nDetected << G4endl;

    G4double geomEff = (G4double)nGenerated / run->GetNumberOfEvent();
    G4double absEff  = (G4double)nDetected  / run->GetNumberOfEvent();

    G4cout << "Geometric Efficiency : " << geomEff << G4endl;
    G4cout << "Absolute Efficiency  : " << absEff << G4endl;

}

