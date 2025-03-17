#include "Engine.hpp"
#include <random>
#include <iostream>

Engine::Engine() 
    : window(800, 600, "Vulkan Engine"),
      vulkanInstance(window.getWindow()),
      renderer(vulkanInstance, window),
      lastFrameTime(std::chrono::steady_clock::now()) {}

Engine::~Engine() {}

void Engine::run() {
    while (!window.shouldClose()) {
        window.pollEvents();
        update();
        renderer.render(triangles);
    }
}

void Engine::update() {
    auto currentTime = std::chrono::steady_clock::now();
    float deltaTime = std::chrono::duration<float>(currentTime - lastFrameTime).count();
    lastFrameTime = currentTime;

    // Update triangle spawn timer
    triangleSpawnTimer += deltaTime;
    if (triangleSpawnTimer >= TRIANGLE_SPAWN_INTERVAL) {
        spawnTriangle();
        std::cout << "Spawned new triangle. Total triangles: " << triangles.size() << std::endl;
        triangleSpawnTimer = 0.0f;
    }

    // Update triangle positions
    for (auto& triangle : triangles) {
        triangle.update(deltaTime);
    }

    // Remove triangles that have fallen off the screen
    size_t oldSize = triangles.size();
    triangles.erase(
        std::remove_if(triangles.begin(), triangles.end(),
            [](const Triangle& t) { return t.getPosition().y > 650.0f; }), // Remove when below screen
        triangles.end()
    );
    if (triangles.size() != oldSize) {
        std::cout << "Removed " << (oldSize - triangles.size()) << " triangles. Remaining: " << triangles.size() << std::endl;
    }
}

void Engine::spawnTriangle() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<float> xDist(50.0f, 750.0f); // Spawn across window width
    static std::uniform_real_distribution<float> colorDist(0.5f, 1.0f); // Brighter colors

    glm::vec2 position(xDist(gen), 50.0f); // Spawn near top of window
    glm::vec3 color(colorDist(gen), colorDist(gen), colorDist(gen));
    triangles.emplace_back(position, color);
    std::cout << "Spawned triangle at position: (" << position.x << ", " << position.y 
              << ") with color: (" << color.r << ", " << color.g << ", " << color.b << ")" << std::endl;
} 