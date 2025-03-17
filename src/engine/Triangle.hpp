#pragma once

#include <glm/glm.hpp>
#include <vector>
#include "Vertex.hpp"

class Triangle {
public:
    Triangle(const glm::vec2& position, const glm::vec3& color);
    void update(float deltaTime);
    void setPosition(const glm::vec2& pos);
    glm::vec2 getPosition() const { return position; }
    const std::vector<Vertex>& getVertices() const { return vertices; }
    bool isBlinking() const { return blinkTimer > 0.0f; }
    void startBlinking() { blinkTimer = 1.0f; }
    bool isPlayer() const { return isPlayerTriangle; }
    void setPlayer(bool player) { isPlayerTriangle = player; }
    glm::vec3 getColor() const { return color; }

private:
    void updateVertices();
    glm::vec2 position;
    glm::vec3 color;
    std::vector<Vertex> vertices;
    float fallSpeed = 200.0f;
    float blinkTimer = 0.0f;
    bool isPlayerTriangle = false;
}; 