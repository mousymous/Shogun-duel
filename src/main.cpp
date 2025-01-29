
#include "libraries.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char ** argv) {
    
    logger::LOG_INTO -> info("Main: Initializing");

    Window main_window;

    Background_Parallax backgrounds(
    "../resources/background/silent-mountain/stars.png", 
    "../resources/background/silent-mountain/mountain.png",
    "../resources/background/silent-mountain/trees.png"
    );

    // Create a Data base class and add the samurai entity into the data base
    Entity_Database entity_database;

    main_window.window_init(backgrounds, entity_database);
    return EXIT_SUCCESS;
}