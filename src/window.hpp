#include "libraries.hpp"

#ifndef WINDOWS_HPP
#define WINDOWS_HPP

class Window_Class {

public:

    /* 
        Class Constructor that initialize the window_attribute structure (which contains the member of windows width, height and title)
        And the window smart pointer in the initialazation list
    */
    Window_Class() : 
        window_attribute(), 
        window{std::make_unique<sf::RenderWindow>(sf::VideoMode(window_attribute.WINDOW_WIDTH, window_attribute.WINDOW_HEIGHT), window_attribute.WINDOW_TITLE)}
    {}

    // Initialize the winodw canvas
    void window_init(Background_Class &mountain_background) {
        logger::LOG_INTO -> info("Window: Initializing");

        // Sets window FPS to 60
        window -> setFramerateLimit(60);

        // Window Loop
        while (window -> isOpen()) {

            // A loop that checks Events
            sf::Event event;
            while(window -> pollEvent(event)) {
                // Checks if window close button has been pressed to close
                if(event.type == sf::Event::Closed) {

                    logger::LOG_INTO -> info("Window: Close button has been pressed");
                    window -> close();
                }
            }

            // A Section to render sprites and other behavior events
            window -> clear();
            window -> draw(mountain_background.get_background());
            window -> display();
        }

        window -> close();
    }

    /*
        Function getter that returns window size and pass it 
        as an argument to Background_Class::setup_background(); 
    */
    const sf::Vector2u get_window_size() {
        return window -> getSize();
    }

private:
    struct Window_Attribute {
        std::int32_t WINDOW_WIDTH {900};
        std::int32_t WINDOW_HEIGHT {600};
        std::string WINDOW_TITLE {"SHOGUN DUEL"};
    } window_attribute;

    /*
        This variable holds a smart pointer of type sf::RenderWindow.
        I used a unique pointer so that it only points to one sf::RenderWindow variable to avoid duplicating a copy of the window itself
        and that it is properly destroyed when out of scope.
    */
    std::unique_ptr<sf::RenderWindow> window;
};

#endif