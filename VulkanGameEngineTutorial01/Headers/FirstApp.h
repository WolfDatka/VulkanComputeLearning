#ifndef FIRST_APP_H
#define FIRST_APP_H

#include "LVE_Window.h"

namespace LVE {
    class FirstApp {
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

            void Run();

        private:
            LVE_Window LVEWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
    };
}



#endif