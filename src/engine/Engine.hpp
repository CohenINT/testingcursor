#pragma once

#include "Window.hpp"
#include "VulkanInstance.hpp"
#include "Renderer.hpp"
#include "Triangle.hpp"
#include <vector>
#include <chrono>

class Engine {
public:
    Engine();
    ~Engine();

    void run();

private:
    void update();
    void spawnTriangle();

    Window window;
    VulkanInstance vulkanInstance;
    Renderer renderer;
    std::vector<Triangle> triangles;
    std::chrono::steady_clock::time_point lastFrameTime;
    float triangleSpawnTimer = 0.0f;
    const float TRIANGLE_SPAWN_INTERVAL = 5.0f; // seconds
}; 