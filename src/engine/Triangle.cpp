#include "Triangle.hpp"

Triangle::Triangle(const glm::vec2& pos, const glm::vec3& col) : position(pos), color(col) {}

void Triangle::update(float deltaTime) {
    position.y += fallSpeed * deltaTime; // Positive fallSpeed makes it fall downward
}

std::array<Vertex, 3> Triangle::getVertices(const glm::vec2& pos, const glm::vec3& color) {
    // Make triangles larger (50 pixels)
    return {
        Vertex{{pos.x - 25.0f, pos.y + 25.0f}, color},
        Vertex{{pos.x + 25.0f, pos.y + 25.0f}, color},
        Vertex{{pos.x, pos.y - 25.0f}, color}
    };
} 