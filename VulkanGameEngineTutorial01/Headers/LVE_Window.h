#ifndef LVE_WINDOW_H
#define LVE_WINDOW_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace LVE {
    class LVE_Window {
        public:
            LVE_Window(int w, int h, std::string name);
            ~LVE_Window();

            LVE_Window(const LVE_Window &) = delete;
            LVE_Window &operator=(const LVE_Window &) = delete;

            bool ShouldClose() { return glfwWindowShouldClose(window); }

        private:
            GLFWwindow *window;
            std::string windowName;

            const int WIDTH;
            const int HEIGHT;

            void InitWindow();
    };
}

#endif