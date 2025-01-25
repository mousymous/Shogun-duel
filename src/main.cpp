
#include "libraries.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char ** argv) {
    
    logger::LOG_INTO -> info("Main: Initializing");

    Window_Class main_window;
    Rect_Class samurai( true, sf::Vector2f(500, 300), 1.0f);

    Background_Class mountain_background(main_window.get_window_size());
    main_window.window_init(mountain_background, samurai);
    return EXIT_FAILURE;
}