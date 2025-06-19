#ifndef LABR3_SLAB_RUNACTION_HH
#define LABR3_SLAB_RUNACTION_HH

class G4Run;

#include "G4UserRunAction.hh"
#include "G4Event.hh"
class LaBr3_Slab_RunAction : public G4UserRunAction {
public:
    LaBr3_Slab_RunAction();
    virtual ~LaBr3_Slab_RunAction();
    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run* run);
};

#endif
