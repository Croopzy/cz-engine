#pragma once
#include "src/engine/physics/World.hpp"
#include "src/engine/graphics/Camera.hpp"
#include "src/engine/graphics/Renderer.hpp"

class Visualiser {
    public:
        Visualiser(Renderer& renderer);

        // World Draw Functions
        void drawParticles(const World& world, const Camera& camera);
        void drawPlanes(const World& world, const Camera& camera);
        void drawWorld(const World& world, const Camera& camera);
    private:
        Renderer& renderer;
};