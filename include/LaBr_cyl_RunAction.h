#ifndef LABR_CYL_RUNACTION_HH
#define LABR_CYL_RUNACTION_HH

class G4Run;

#include "G4UserRunAction.hh"
#include "G4Event.hh"
class LaBr_cyl_RunAction : public G4UserRunAction {
public:
    LaBr_cyl_RunAction();
    virtual ~LaBr_cyl_RunAction();
    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run* run);
};

#endif
