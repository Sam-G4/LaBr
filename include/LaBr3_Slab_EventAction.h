#ifndef LABR3_SLAB_EVENTACTION_HH
#define LABR3_SLAB_EVENTACTION_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
class LaBr3_Slab_EventAction : public G4UserEventAction {
public:
    LaBr3_Slab_EventAction();
    virtual ~LaBr3_Slab_EventAction();
    virtual void BeginOfEventAction(const G4Event *event);
    virtual void EndOfEventAction(const G4Event *event);
};

#endif
