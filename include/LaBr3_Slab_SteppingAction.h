#ifndef LABR3_SLAB_STEPPINGACTION_HH
#define LABR3_SLAB_STEPPINGACTION_HH

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class LaBr3_Slab_SteppingAction : public G4UserSteppingAction {
public:
    LaBr3_Slab_SteppingAction();
    virtual ~LaBr3_Slab_SteppingAction();

    virtual void UserSteppingAction(const G4Step*);
};

	extern G4int nGenerated;
	extern G4int nDetected;
#endif
