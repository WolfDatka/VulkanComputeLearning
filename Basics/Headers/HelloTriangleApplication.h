#ifndef HELLO_TRIANGLE_APPLICATION_H
#define HELLO_TRIANGLE_APPLICATION_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>
#include <string.h>

#include "DebuggerDefinitions.h"

class HelloTriangleApplication {
    public:
        void Run();

    private:
        void InitWindow();
        void InitVulkan();

        bool CheckValidationLayerSupport();

        void CreateInstance();

        void MainLoop();
        void Cleanup();

        GLFWwindow* window;
        VkInstance instance;
};

#endif
