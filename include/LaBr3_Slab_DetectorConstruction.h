#ifndef LABR3_SLAB_DETECTORCONSTRUCTION_HH
#define LABR3_SLAB_DETECTORCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"

class LaBr3_Slab_DetectorConstruction : public G4VUserDetectorConstruction {
public:
    LaBr3_Slab_DetectorConstruction();
    virtual ~LaBr3_Slab_DetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
};

#endif
