
#include "libraries.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char ** argv) {
    
    logger::LOG_INTO -> info("Main: Initializing");

    Window main_window;
    Background mountain_background( "../resources/background/shogun-duel-background_v2.png",main_window.get_window_size());


    // Structuring the samurai with Rect, Spritesheet and Entity classes!
    Rect samurai_rect(false, false, sf::Color::Black, sf::Vector2f(100, 350));
    Spritesheet_Animator samurai_right_run("../resources/samurai/Run.png", 200, 200, 8, 0.10f, samurai_rect.get_rect());
    Spritesheet_Animator samurai_left_run("../resources/samurai/Runleft.png", 200, 200, 8, 0.10f, samurai_rect.get_rect());
    Spritesheet_Animator samurai_idle("../resources/samurai/Idle.png", 200, 200, 8, 0.10f, samurai_rect.get_rect());
    Spritesheet_Animator samurai_attack("../resources/samurai/Attack1.png", 200, 200, 6, 0.10f, samurai_rect.get_rect());
    Entity samurai(samurai_rect, samurai_right_run, samurai_left_run, samurai_idle, samurai_attack, 2.5f);

    // Initializes the window
    main_window.window_init(mountain_background, samurai);
    return EXIT_SUCCESS;
}