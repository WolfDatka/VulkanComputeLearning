#include "Main.h"

int main(int argc, char const *argv[]) {
    LVE::FirstApp app{};

    try {
        app.Run();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
