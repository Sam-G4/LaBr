#include "LaBr3_Slab_DetectorConstruction.h"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "LaBr3_Slab_SensitiveDetector.h"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"
LaBr3_Slab_DetectorConstruction::LaBr3_Slab_DetectorConstruction() {}

LaBr3_Slab_DetectorConstruction::~LaBr3_Slab_DetectorConstruction() {}

G4VPhysicalVolume* LaBr3_Slab_DetectorConstruction::Construct() {
    G4NistManager* nist = G4NistManager::Instance();
    G4Material* worldMat = nist->FindOrBuildMaterial("G4_AIR");
    
    //Defining material
    G4double density = 5.29 * g/cm3; 
    G4Element* La = nist->FindOrBuildElement("La");
    G4Element* Br = nist->FindOrBuildElement("Br");
    
    G4Material* LaBr3Ce = new G4Material("LaBr3Ce", density, 2);
    LaBr3Ce->AddElement(La, 1);
    LaBr3Ce->AddElement(Br, 3);
    G4Material* detectorMaterial = LaBr3Ce;

    //Modify the world volume dimension as required
    G4Box* solidWorld = new G4Box("World", 0.5*m, 0.5*m, 0.5*m);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, worldMat, "World");
    G4VPhysicalVolume* physWorld = new G4PVPlacement(nullptr, G4ThreeVector(), logicWorld, "World", nullptr, false, 0);
    
    //TODO : Create your desired detectors here
    	G4double halfX = 5.08/ 2.0;
	G4double halfY = 5.08/ 2.0;
	G4double halfZ = 15.24/ 2.0;
	
	G4Box* solidLaBr_slab = new G4Box("LaBr_Solid", halfX * cm, halfY * cm, halfZ* cm);
	G4LogicalVolume* logicLaBr_slab = new G4LogicalVolume(solidLaBr_slab, detectorMaterial, "LaBr_Logic");
	
	G4double spacing = 5.08*cm; // spacing between centers = detector width
	//G4int numPerRow = 3;

G4int copyNo = 0;
for (int i = -1; i < 2; ++i) {
    for (int j = -1; j < 2; ++j) {
        // Centered around (0,0), so offset is needed
        G4double x = i * spacing;
        G4double y = j * spacing;
        G4double z = 14.62 * cm; // All in same Z-plane

        new G4PVPlacement(
            0,  // no rotation
            G4ThreeVector(x, y, z),
            logicLaBr_slab,      // same logical volume
            "PhyLaBr_slab",     // name
            logicWorld,         // mother volume
            false,              // no boolean operation
            copyNo++,           // copy number
            true);              // check for overlaps
    }
}
    

    // Logic to Attach sensitive detector to a logical volume
    LaBr3_Slab_SensitiveDetector* detector = new LaBr3_Slab_SensitiveDetector("SensitiveDetector");
    G4SDManager::GetSDMpointer()->AddNewDetector(detector);
    logicLaBr_slab->SetSensitiveDetector(detector);

    return physWorld;
}
