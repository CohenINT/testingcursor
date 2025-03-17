#pragma once

#include "Window.hpp"
#include "VulkanInstance.hpp"
#include "Renderer.hpp"
#include "Triangle.hpp"
#include <vector>
#include <memory>
#include <chrono>

class Engine {
public:
    Engine();
    ~Engine();

    void run();

private:
    void update();
    void spawnTriangle();
    bool checkCollision(const Triangle& t1, const Triangle& t2);
    void handleInput();

    Window window;
    VulkanInstance vulkanInstance;
    Renderer renderer;
    std::vector<Triangle*> triangles;
    Triangle* playerTriangle;
    float moveSpeed = 300.0f;
    float lastFrameTime = 0.0f;
}; 