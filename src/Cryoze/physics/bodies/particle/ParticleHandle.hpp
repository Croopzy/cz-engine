#pragma once
#include "src/Cryoze/physics/bodies/point_mass/PointMass.hpp"
#include "src/Cryoze/physics/world/World.hpp"
#include <optional>

class ParticleHandle {
public:
    explicit ParticleHandle(World& world) : world(world) {}

    ParticleHandle& operator = (ParticleID newID) {  // Usage: ParticleHandle myParticle = myWorld.addParticle(...)
        id = newID;
        return *this; // Each Call Returns The ParticleHandle Object
    }

    Particle& operator*() const { return world.getParticle(id.value()); } // Usage: (*myParticle).particleAttribute = ...
    Particle* operator->() const { return &**this; } // Usage:: myParticle->particleAttribute

    ParticleID particleID() const { return id.value(); } // Usage: myWorld.addSpring(myParticleA.particleID(), myParticleB.particleID(), ...)


private:
    World& world;
    std::optional<ParticleID> id;
};