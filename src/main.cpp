
#include "libraries.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char ** argv) {
    
    logger::LOG_INTO -> info("Main: Initializing");

    Window_Class main_window;
    main_window.window_init();
    return EXIT_FAILURE;
}