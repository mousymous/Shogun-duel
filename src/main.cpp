
#include "libraries.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char ** argv) {
    
    logger::LOG_INTO -> info("Main: Initializing");

    Window main_window;

    Background_Parallax backgrounds(
    "../resources/background/silent-mountain/stars.png", 
    "../resources/background/silent-mountain/mountain.png",
    "../resources/background/silent-mountain/trees.png"
    );

    // Build the samurai
    Rect samurai_rect(false, false, sf::Color::Black, sf::Vector2f(200, 400));
    Spritesheet_Animator samurai_rrun("../resources/samurai/Run.png", 200, 200, 8, 0.12f, samurai_rect.get_rect());
    Spritesheet_Animator samurai_lrun("../resources/samurai/Runleft.png", 200, 200, 8, 0.12f, samurai_rect.get_rect());
    Spritesheet_Animator samurai_idle("../resources/samurai/Idle.png", 200, 200, 8, 0.12f, samurai_rect.get_rect());
    Spritesheet_Animator samurai_attack("../resources/samurai/Attack1.png", 200, 200, 6, 0.12f, samurai_rect.get_rect());

    Entity samurai(samurai_rect, samurai_rrun, samurai_lrun, samurai_idle, samurai_attack, 1.0f, Entity::CONTROL_TYPE::LETTER_KEYS);

    // Create a Data base class and add the samurai entity into the data base
    Entity_Database entity_database;
    entity_database.add_entity(samurai);

    main_window.window_init(backgrounds, entity_database);
    return EXIT_SUCCESS;
}