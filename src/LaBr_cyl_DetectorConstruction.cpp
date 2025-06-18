#include "LaBr_cyl_DetectorConstruction.h"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "LaBr_cyl_SensitiveDetector.h"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"

#include "G4Tubs.hh"
#include "G4Material.hh"
#include "G4Element.hh"
LaBr_cyl_DetectorConstruction::LaBr_cyl_DetectorConstruction() {}

LaBr_cyl_DetectorConstruction::~LaBr_cyl_DetectorConstruction() {}

G4VPhysicalVolume* LaBr_cyl_DetectorConstruction::Construct() {
    G4NistManager* nist = G4NistManager::Instance();
    G4Material* worldMat = nist->FindOrBuildMaterial("G4_AIR");
    
    G4Element* La = nist->FindOrBuildElement("La");
    G4Element* Br = nist->FindOrBuildElement("Br");

     G4double density = 5.29 * g/cm3; 
    G4Material* LaBr3Ce = new G4Material("LaBr3Ce", density, 2);
    LaBr3Ce->AddElement(La, 1);
    LaBr3Ce->AddElement(Br, 3);
    G4Material* detectorMaterial = LaBr3Ce;
    
    //Modify the world volume dimension as required
    G4Box* solidWorld = new G4Box("World", 0.5*m, 0.5*m, 0.5*m);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, worldMat, "World");
    G4VPhysicalVolume* physWorld = new G4PVPlacement(nullptr, G4ThreeVector(), logicWorld, "World", nullptr, false, 0);
    
    //TODO : Create your desired detectors here
      G4double radius = 3.2*cm;
    G4double halfLength = 15.24/2.0*cm;
    
    G4Tubs* solidLaBr_cyl = new G4Tubs("LaBr_cyl", 0., radius, halfLength, 0. , 360. * deg);
    G4LogicalVolume* logicLaBr_cyl = new G4LogicalVolume(solidLaBr_cyl, detectorMaterial, "Logic_cyl");
    
    // Define positions: center + 6 hexagon points around
    std::vector<G4ThreeVector> positions;
    
    // Center crystal
    positions.push_back(G4ThreeVector(0, 0, 14.62* cm));
    G4double spacing = radius * 2;
    
    // Six surrounding crystals in a hex pattern (angles: 0, 60, ..., 300 deg)
	for (int i = 0; i < 6; ++i) {
	    double angle = i * 60.0 * CLHEP::deg;
	    double y = spacing * std::cos(angle);
	    double x = spacing * std::sin(angle);
	    positions.push_back(G4ThreeVector(x, y, 14.62 *cm));
	   
	}
	
	// Place all 7 crystals
	for (size_t i = 0; i < positions.size(); ++i) {
    new G4PVPlacement(0, positions[i], logicLaBr_cyl, "PhyLaBr_cyl", logicWorld, false, i, true);
    }
    

    // Logic to Attach sensitive detector to a logical volume
    LaBr_cyl_SensitiveDetector* detector = new LaBr_cyl_SensitiveDetector("SensitiveDetector");
    G4SDManager::GetSDMpointer()->AddNewDetector(detector);
    logicLaBr_cyl->SetSensitiveDetector(detector);

    return physWorld;
}
