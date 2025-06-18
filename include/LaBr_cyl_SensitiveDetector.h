#ifndef LABR_CYL_SENSITIVEDETECTOR_HH
#define LABR_CYL_SENSITIVEDETECTOR_HH

#include "G4VSensitiveDetector.hh"

class LaBr_cyl_SensitiveDetector : public G4VSensitiveDetector {
public:
    LaBr_cyl_SensitiveDetector(const G4String& name);
    virtual ~LaBr_cyl_SensitiveDetector();

    virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history);
};

#endif
