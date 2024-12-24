#include "FirstApp.h"

namespace LVE {
    void FirstApp::Run() {
        while (!LVEWindow.ShouldClose()) {
            glfwPollEvents();
        }
    }
}
