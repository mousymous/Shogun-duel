
#include "libraries.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char ** argv) {
    
    logger::LOG_INTO -> info("Main: Initializing");

    Window main_window;
    Background mountain_background( "../resources/background/shogun-duel-background.png",main_window.get_window_size());
    main_window.window_init(mountain_background);
    return EXIT_SUCCESS;
}