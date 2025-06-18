#ifndef LABR_CYL_USERPHYSICSLIST_HH
#define LABR_CYL_USERPHYSICSLIST_HH

#include "G4VUserPhysicsList.hh"

class LaBr_cyl_UserPhysicsList : public G4VUserPhysicsList {
public:
    LaBr_cyl_UserPhysicsList();
    virtual ~LaBr_cyl_UserPhysicsList();
    virtual void ConstructParticle(); 
    virtual void ConstructProcess(); 
};

#endif
