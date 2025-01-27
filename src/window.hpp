#include "libraries.hpp"

#ifndef WINDOWS_HPP
#define WINDOWS_HPP

class Window_Class {

public:

    // Class Constructor that initialize the window_attribute structure and the window in the initialazation list
    Window_Class() : window_attribute(), 
    window{std::make_unique<sf::RenderWindow>(sf::VideoMode(window_attribute.WINDOW_WIDTH, window_attribute.WINDOW_HEIGHT), window_attribute.WINDOW_TITLE)}
    {}

    // Initialize the winodw canvas
    void window_init(Background_Class &mountain_background) {
        logger::LOG_INTO -> info("Window: Initializing");

        // Window Setup
        window -> setFramerateLimit(60);

        // Window Loop
        while (window -> isOpen()) {

            sf::Event event;
            while(window -> pollEvent(event)) {
                // Checks if window close button has been pressed to close
                if(event.type == sf::Event::Closed) {
                    window -> close();
                }
            }

            // Render Sprites here under window -> clear();
            window -> clear();
            window -> draw(mountain_background.get_background());
            window -> display();
        }

        window -> close();
    }

    // Function to fetch the window size to deliver to Background_Class::setup_background();
    const sf::Vector2u get_window_size() {
        return window -> getSize();
    }

private:
    struct Window_Attribute {
        std::int32_t WINDOW_WIDTH {900};
        std::int32_t WINDOW_HEIGHT {600};
        std::string WINDOW_TITLE {"SHOGUN DUEL"};
    } window_attribute;

    std::unique_ptr<sf::RenderWindow> window;
};

#endif