#ifndef LABR_CYL_STEPPINGACTION_HH
#define LABR_CYL_STEPPINGACTION_HH

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class LaBr_cyl_SteppingAction : public G4UserSteppingAction {
public:
    LaBr_cyl_SteppingAction();
    virtual ~LaBr_cyl_SteppingAction();

    virtual void UserSteppingAction(const G4Step*);
   
};

 
    extern G4int nGenerated;
    extern G4int nDetected;

#endif
