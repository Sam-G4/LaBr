#ifndef LABR3_SLAB_USERPHYSICSLIST_HH
#define LABR3_SLAB_USERPHYSICSLIST_HH

#include "G4VUserPhysicsList.hh"

class LaBr3_Slab_UserPhysicsList : public G4VUserPhysicsList {
public:
    LaBr3_Slab_UserPhysicsList();
    virtual ~LaBr3_Slab_UserPhysicsList();
    virtual void ConstructParticle(); 
    virtual void ConstructProcess(); 
};

#endif
