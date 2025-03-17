#include "engine/Engine.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "Starting Vulkan Engine..." << std::endl;
        Engine engine;
        std::cout << "Engine initialized successfully" << std::endl;
        engine.run();
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        std::cerr << "Press Enter to exit..." << std::endl;
        std::cin.get();
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "Unknown fatal error occurred!" << std::endl;
        std::cerr << "Press Enter to exit..." << std::endl;
        std::cin.get();
        return EXIT_FAILURE;
    }
} 