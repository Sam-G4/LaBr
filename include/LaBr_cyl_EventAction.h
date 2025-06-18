#ifndef LABR_CYL_EVENTACTION_HH
#define LABR_CYL_EVENTACTION_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
class LaBr_cyl_EventAction : public G4UserEventAction {
public:
    LaBr_cyl_EventAction();
    virtual ~LaBr_cyl_EventAction();
    virtual void BeginOfEventAction(const G4Event *event);
    virtual void EndOfEventAction(const G4Event *event);
};

#endif
