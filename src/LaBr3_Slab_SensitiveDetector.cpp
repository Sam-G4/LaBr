#include "LaBr3_Slab_SensitiveDetector.h"
#include "LaBr3_Slab_SensitiveDetector_Hit.h"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"

#include "G4AnalysisManager.hh"
#include "G4UnitsTable.hh"
#include "G4HCofThisEvent.hh"
#include "G4SDManager.hh"
#include "G4AnalysisManager.hh"
#include "Randomize.hh"


G4int nEntered = 0;
G4int nAbs = 0;

LaBr3_Slab_SensitiveDetector::LaBr3_Slab_SensitiveDetector(const G4String& name) : G4VSensitiveDetector(name), fHitsCollection(nullptr) {
	//Define the hit collection name (used in EventAction)
	   collectionName.insert("LaBr_slab_HitsCollection");  // Register name with SD manager

}

LaBr3_Slab_SensitiveDetector::~LaBr3_Slab_SensitiveDetector() {}

// Initialize at start of event
void LaBr3_Slab_SensitiveDetector::Initialize(G4HCofThisEvent* hce)
{
    fHitsCollection = new LaBr_Slab_HitsCollection(SensitiveDetectorName, collectionName[0]);

    static G4int hcID = -1;
    if (hcID < 0) {
        hcID = G4SDManager::GetSDMpointer()->GetCollectionID(fHitsCollection);
    }
    hce->AddHitsCollection(hcID, fHitsCollection);
    
}

//called every time a step is made
G4bool LaBr3_Slab_SensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory*) {

     //G4cout << "[DEBUG] Entering ProcessHits!" << G4endl;
     G4double edep = step->GetTotalEnergyDeposit();
    if (edep == 0.) return false;	
    
    // Create a new hit
    LaBr3_Slab_SensitiveDetector_Hit* hit = new LaBr3_Slab_SensitiveDetector_Hit();
    
    //Get position of step
    G4StepPoint* prePoint = step->GetPreStepPoint();
    G4ThreeVector pos = prePoint->GetPosition();
    
    
    G4Track* track = step->GetTrack();
    G4int trackid = track->GetTrackID();
    
    hit->SetEdep(edep);
    hit->SetPosition(pos);
    hit->SetTrackID(trackid);
    hit->SetDetectorID(prePoint->GetTouchableHandle()->GetCopyNumber());
     //hit->Print();
    
   // Add to collection
    fHitsCollection->insert(hit);
    
    return true;
}

//called at end of event
void LaBr3_Slab_SensitiveDetector::EndOfEvent(G4HCofThisEvent*) 
{

std::set<G4int> detectedTrackIDs;

G4int nHits = fHitsCollection->entries();
    //std::cout << "=======================================" << std::endl;
   // std::cout << "No. of Hits : " << nHits << std::endl;
    
    G4double edepByDetector[10] = {0.};
    G4double totalEdep = 0.0;
    auto analysisManager = G4AnalysisManager::Instance();
    
    for (G4int i = 0; i < nHits; ++i) {
    LaBr3_Slab_SensitiveDetector_Hit* hit = (*fHitsCollection)[i];
    	G4double edep = hit->GetEdep();
        G4ThreeVector pos = hit->GetPosition();
        G4int id = hit->GetDetectorID();
        G4int trackID = hit->GetTrackID();
        
        if (edep > 0){
        
        totalEdep += edep;
        edepByDetector[id] += edep;
        
         if (detectedTrackIDs.find(trackID) == detectedTrackIDs.end()) {
            nAbs++;
            detectedTrackIDs.insert(trackID);
            }
        
        }
   
   	G4double x_pos = pos.x();
        G4double y_pos = pos.y();

        analysisManager->FillH2(0,x_pos, y_pos); //x-y_Plot
}

//G4cout << "Total Energy Deposited: " << G4BestUnit(totalEdep, "Energy") << G4endl;
	
	for (G4int id = 0; id < 9; ++id) {
	
		if (edepByDetector[id] > 0.) {
		G4double resolution = 0.10;
            G4double sigma = resolution * edepByDetector[id] / 2.35;
            G4double smearedEdep = G4RandGauss::shoot(edepByDetector[id], sigma);
	analysisManager->FillH1(id,smearedEdep );
	analysisManager->FillH1(10, id);
		}
	}
	
	if (totalEdep > 0.){
	G4double resolution = 0.10;  // 10% resolution (adjust as needed)
	G4double sigma = resolution * totalEdep/ 2.35;
	G4double smearedEdep = G4RandGauss::shoot(totalEdep, sigma);
	analysisManager->FillH1(9, smearedEdep);
	}
	
}
	
