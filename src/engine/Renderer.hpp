#pragma once

#include "VulkanInstance.hpp"
#include "Window.hpp"
#include "Triangle.hpp"
#include "Vertex.hpp"
#include <vector>
#include <vulkan/vulkan.h>

class Renderer {
public:
    Renderer(VulkanInstance& vulkan, Window& win);
    ~Renderer();

    void render(const std::vector<Triangle*>& triangles);
    void waitIdle() { vkDeviceWaitIdle(vulkanInstance.getDevice()); }

private:
    void createRenderPass();
    void createGraphicsPipeline();
    void createFramebuffers();
    void createCommandBuffers();
    void createVertexBuffer();
    void createSyncObjects();
    void updateVertexBuffer();
    void updateTriangles(const std::vector<Triangle*>& triangles);
    VkShaderModule createShaderModule(const std::vector<char>& code);
    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
    void drawFrame();

    VulkanInstance& vulkanInstance;
    Window& window;
    VkRenderPass renderPass;
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;
    std::vector<VkFramebuffer> swapChainFramebuffers;
    std::vector<VkCommandBuffer> commandBuffers;
    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    std::vector<Vertex> vertices;
    VkSemaphore imageAvailableSemaphore;
    VkSemaphore renderFinishedSemaphore;
    VkFence inFlightFence;
}; 