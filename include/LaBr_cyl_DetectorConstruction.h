#ifndef LABR_CYL_DETECTORCONSTRUCTION_HH
#define LABR_CYL_DETECTORCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"

class LaBr_cyl_DetectorConstruction : public G4VUserDetectorConstruction {
public:
    LaBr_cyl_DetectorConstruction();
    virtual ~LaBr_cyl_DetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
};

#endif
