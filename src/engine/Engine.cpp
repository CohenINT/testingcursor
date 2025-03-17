#include "Engine.hpp"
#include <random>
#include <iostream>

Engine::Engine() 
    : window(800, 600, "Vulkan Engine"),
      vulkanInstance(window.getWindow()),
      renderer(vulkanInstance, window),
      lastFrameTime(0.0f) {
    
    // Create player triangle
    playerTriangle = new Triangle(glm::vec2(400.0f, 500.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    playerTriangle->setPlayer(true);
    triangles.push_back(playerTriangle);
}

Engine::~Engine() {
    for (auto triangle : triangles) {
        delete triangle;
    }
}

void Engine::run() {
    while (!window.shouldClose()) {
        window.pollEvents();
        update();
        renderer.render(triangles);
    }
}

void Engine::update() {
    float currentTime = static_cast<float>(glfwGetTime());
    float deltaTime = currentTime - lastFrameTime;
    lastFrameTime = currentTime;

    handleInput();
    spawnTriangle();

    // Update all triangles except player
    for (size_t i = 1; i < triangles.size(); ++i) {
        triangles[i]->update(deltaTime);
    }

    // Check collisions
    for (size_t i = 1; i < triangles.size(); ++i) {
        if (checkCollision(*playerTriangle, *triangles[i])) {
            triangles[i]->startBlinking();
        }
    }

    // Remove triangles that have fallen off screen
    auto it = triangles.begin() + 1; // Skip player triangle
    while (it != triangles.end()) {
        if ((*it)->getPosition().y > 650.0f) {
            delete *it;
            it = triangles.erase(it);
        } else {
            ++it;
        }
    }
}

void Engine::handleInput() {
    if (!playerTriangle) return;

    float moveAmount = moveSpeed * (1.0f / 60.0f); // Assuming 60 FPS
    glm::vec2 newPos = playerTriangle->getPosition();
    
    if (glfwGetKey(window.getWindow(), GLFW_KEY_LEFT) == GLFW_PRESS) {
        newPos.x -= moveAmount;
    }
    if (glfwGetKey(window.getWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS) {
        newPos.x += moveAmount;
    }

    // Keep player within screen bounds
    newPos.x = std::max(50.0f, std::min(750.0f, newPos.x));
    
    // Update player position
    playerTriangle->setPosition(newPos);
}

void Engine::spawnTriangle() {
    static float spawnTimer = 0.0f;
    static const float SPAWN_INTERVAL = 2.0f;
    float currentTime = static_cast<float>(glfwGetTime());
    
    if (currentTime - spawnTimer >= SPAWN_INTERVAL) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> xDist(50.0f, 750.0f);
        
        glm::vec2 position(xDist(gen), 50.0f);
        glm::vec3 color(0.772577f, 0.577346f, 0.733947f);
        
        triangles.push_back(new Triangle(position, color));
        spawnTimer = currentTime;
    }
}

bool Engine::checkCollision(const Triangle& t1, const Triangle& t2) {
    // Simple circle-based collision detection
    const float radius = 50.0f; // Increased radius to match triangle size
    glm::vec2 pos1 = t1.getPosition();
    glm::vec2 pos2 = t2.getPosition();
    
    float dx = pos1.x - pos2.x;
    float dy = pos1.y - pos2.y;
    float distance = std::sqrt(dx * dx + dy * dy);
    
    return distance < radius * 2;
} 