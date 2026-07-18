#pragma once
#include "src/engine/physics/World.hpp"
#include "src/engine/graphics/Camera.hpp"
#include "src/engine/graphics/Renderer.hpp"

class Visualiser {
    public:
        Visualiser(Renderer& renderer);

        // World Draw Functions
        bool planeCollision(const World& world, const Particle& body, const World::PlaneCollider& plane, const Camera& camera);
        void drawPlanes(const World& world, const Camera& camera);
        void drawParticles(const World& world, const Camera& camera);
        void drawSprings(const World& world, const Camera& camera);
        void drawWorld(const World& world, const Camera& camera);
    private:
        Renderer& renderer;
        std::vector<std::vector<Vector>> trails; // Dynamic Array of Persistent Trail Points (Indexed by Particle Index)
        void recordTrail(const World& world, const Particle& body, const Vector& position); // Record New Trail Point
        void drawTrail(const World& world, const Particle& body, const Camera& camera); // Draw All of Particle's Trail Points
};