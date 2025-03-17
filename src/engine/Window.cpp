#include "Window.hpp"
#include <stdexcept>

Window::Window(int w, int h, const std::string& t) : width{w}, height{h}, title{t} {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window!");
    }
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void Window::pollEvents() const {
    glfwPollEvents();
}

VkExtent2D Window::getExtent() const {
    return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)};
} 