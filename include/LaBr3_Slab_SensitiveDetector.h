#ifndef LABR3_SLAB_SENSITIVEDETECTOR_HH
#define LABR3_SLAB_SENSITIVEDETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "LaBr3_Slab_SensitiveDetector_Hit.h"
#include "globals.hh"

class G4Step;
class G4TouchableHistory;


class LaBr3_Slab_SensitiveDetector : public G4VSensitiveDetector {
public:
    LaBr3_Slab_SensitiveDetector(const G4String& name);
    virtual ~LaBr3_Slab_SensitiveDetector();

    virtual void Initialize(G4HCofThisEvent* hce) override;
    virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history) override;
    virtual void EndOfEvent(G4HCofThisEvent* hce) override;    

private:
    LaBr_Slab_HitsCollection* fHitsCollection;

	
};

	extern G4int nEntered;
	extern G4int nAbs;

#endif
