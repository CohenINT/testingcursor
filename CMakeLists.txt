cmake_minimum_required(VERSION 3.15)
project(VulkanEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Vulkan package
find_package(Vulkan REQUIRED)
if(NOT Vulkan_FOUND)
    message(FATAL_ERROR "Vulkan SDK not found. Please install the Vulkan SDK from https://vulkan.lunarg.com/sdk/home#windows")
endif()

# Configure GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(third_party/glfw)

# Add source files
set(SOURCES
    src/main.cpp
    src/engine/Engine.cpp
    src/engine/Engine.hpp
    src/engine/VulkanInstance.cpp
    src/engine/VulkanInstance.hpp
    src/engine/Renderer.cpp
    src/engine/Renderer.hpp
    src/engine/Window.cpp
    src/engine/Window.hpp
    src/engine/Triangle.cpp
    src/engine/Triangle.hpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    Vulkan::Vulkan
    glfw
)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/glfw/include
    ${Vulkan_INCLUDE_DIRS}
) 