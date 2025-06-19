#include "LaBr3_Slab_RunAction.h"
#include "G4Run.hh"
#include "G4AnalysisManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

LaBr3_Slab_RunAction::LaBr3_Slab_RunAction()  {
}

LaBr3_Slab_RunAction::~LaBr3_Slab_RunAction() {}

void LaBr3_Slab_RunAction::BeginOfRunAction(const G4Run*){

	G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
  	analysisManager->OpenFile("output_LaBr_Slab.root");
  	G4cout << "Opened output_LaBr_Slab.root for writing analysis data." << G4endl;
	
	for(G4int i =0; i<9; i++){
  	analysisManager->CreateH1("Edep_"+std::to_string(i+1) ,"EDep__Individual" + std::to_string(i+1), 1000, 0, 1.2*MeV);
  	}
  	
  	analysisManager->CreateH2("X-Y_plot", "Interaction area plot", 50, -200., 200, 50, -200., 200.);
  	analysisManager->CreateH1("Edep_cumulative", "Total energy deposited in all 14 BGO", 1000, 0., 1.2 *MeV); 
  	analysisManager->CreateH1("LaBr3-Counts","Counts distribution in Up BGOs", 9, 0, 9);
  	
}

extern G4int nGenerated;
//extern G4int nDetected;
extern G4int nEntered;
extern G4int nAbs;

void LaBr3_Slab_RunAction::EndOfRunAction(const G4Run* run){

    G4cout << "\n===== Detector Efficiency Report =====" << G4endl;
    G4cout << "Total events run     : " << run->GetNumberOfEvent() << G4endl;
    G4cout << "Gammas entered LaBr3 : " << nGenerated << G4endl;
    G4cout << "Gammas detected      : " << nAbs << G4endl;
    G4cout << "Gammas Entered from SD: " << nEntered <<G4endl;

    G4double geomEff = (G4double)nGenerated / run->GetNumberOfEvent();
    G4double absEff  = (G4double)nAbs  / run->GetNumberOfEvent();

    G4cout << "Geometric Efficiency : " << geomEff << G4endl;
    G4cout << "Absolute Efficiency  : " << absEff << G4endl;
    
    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
  	analysisManager->Write();
	analysisManager->CloseFile();
	G4cout << "Analysis data written and file closed." << G4endl;


}

