#include "LVE_Window.h"

namespace LVE {
    LVE_Window::LVE_Window(int w, int h, std::string name):
    WIDTH{w}, HEIGHT{h}, windowName{name} {
        InitWindow();
    }

    LVE_Window::LVE_Window::~LVE_Window() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void LVE_Window::LVE_Window::InitWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(WIDTH, HEIGHT, windowName.c_str(), nullptr, nullptr);
    }
}
