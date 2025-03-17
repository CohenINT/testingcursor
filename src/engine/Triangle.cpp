#include "Triangle.hpp"
#include <glm/glm.hpp>

Triangle::Triangle(const glm::vec2& position, const glm::vec3& color)
    : position(position), color(color) {
    updateVertices();
}

void Triangle::update(float deltaTime) {
    if (!isPlayerTriangle) {
        position.y += fallSpeed * deltaTime;
        updateVertices(); // Only update vertices if position changed
    }
    
    if (blinkTimer > 0.0f) {
        blinkTimer -= deltaTime;
        // Blink between red and original color
        if (static_cast<int>(blinkTimer * 10) % 2 == 0) {
            this->color = glm::vec3(1.0f, 0.0f, 0.0f); // Red
        } else {
            this->color = glm::vec3(0.772577f, 0.577346f, 0.733947f); // Original color
        }
        updateVertices(); // Update vertices when color changes
    }
}

void Triangle::setPosition(const glm::vec2& pos) {
    if (pos != position) { // Only update if position actually changed
        position = pos;
        updateVertices();
    }
}

void Triangle::updateVertices() {
    vertices.clear();
    // Equilateral triangle with size 50
    const float size = 50.0f;
    const float height = size * std::sqrt(3.0f) / 2.0f;
    
    vertices.push_back({{position.x, position.y - height/2}, color}); // Top
    vertices.push_back({{position.x - size/2, position.y + height/2}, color}); // Bottom left
    vertices.push_back({{position.x + size/2, position.y + height/2}, color}); // Bottom right
} 