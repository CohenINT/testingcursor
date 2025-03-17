#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

class Window {
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    bool shouldClose() const;
    void pollEvents() const;
    VkExtent2D getExtent() const;
    GLFWwindow* getWindow() const { return window; }

    // Prevent copying
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

private:
    GLFWwindow* window;
    int width;
    int height;
    std::string title;
}; 