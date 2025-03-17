#pragma once

#include <glm/glm.hpp>
#include "Vertex.hpp"

class Triangle {
public:
    Triangle(const glm::vec2& pos, const glm::vec3& col);
    void update(float deltaTime);
    std::array<Vertex, 3> getVertices(const glm::vec2& pos, const glm::vec3& color);
    glm::vec2 getPosition() const { return position; }
    glm::vec3 getColor() const { return color; }

private:
    glm::vec2 position;
    glm::vec3 color;
    const float fallSpeed = 200.0f; // Positive speed makes it fall downward in screen coordinates
}; 