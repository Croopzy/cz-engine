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

    PointMass& operator*() const { return world.getParticle(id.value()).linear(); } // Usage: (*myParticle).linearAttribute = ...
    PointMass* operator->() const { return &**this; } // Usage:: myParticle->particleAttribute


private:
    World& world;
    std::optional<ParticleID> id;
};