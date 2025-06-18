#include "LaBr3_cylinder_DetectorConstruction.h"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "LaBr3_cylinder_SensitiveDetector.h"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"

#include "G4Tubs.hh"
#include "G4Material.hh"
#include "G4Element.hh"
LaBr3_cylinder_DetectorConstruction::LaBr3_cylinder_DetectorConstruction() {}

LaBr3_cylinder_DetectorConstruction::~LaBr3_cylinder_DetectorConstruction() {}


G4VPhysicalVolume* LaBr3_cylinder_DetectorConstruction::Construct() {
    G4NistManager* nist = G4NistManager::Instance();
    G4Material* worldMat = nist->FindOrBuildMaterial("G4_AIR");
    
    //defining material for LaBr3:Ce
/////////////////////////////////////////////////For  now Cerium doping is not considered
    G4Element* La = nist->FindOrBuildElement("La");
    G4Element* Br = nist->FindOrBuildElement("Br");
    /////////G4Element* Ce = nist->FindOrBuildElement("Ce");

    // Define LaBr3:Ce material
    // Assuming Ce doping ~5% atomic fraction (typical range 0.5–5%)
    // Adjust the fractionMass if you want a more accurate model

    G4double density = 5.29 * g/cm3;  // Approximate density of LaBr3:Ce
    G4Material* LaBr3Ce = new G4Material("LaBr3Ce", density, 2);
    LaBr3Ce->AddElement(La, 1);
    LaBr3Ce->AddElement(Br, 3);
    ///////LaBr3Ce->AddElement(Ce, 0.02);  // Small doping amount

    // Note: Geant4 will normalize proportions automatically

    G4Material* detectorMaterial = LaBr3Ce;//////////////////////

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
    LaBr3_cylinder_SensitiveDetector* detector = new LaBr3_cylinder_SensitiveDetector("SensitiveDetector");
    G4SDManager::GetSDMpointer()->AddNewDetector(detector);
    logicLaBr_cyl->SetSensitiveDetector(detector);

    return physWorld;
}
