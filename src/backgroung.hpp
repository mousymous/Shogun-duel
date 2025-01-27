#include "libraries.hpp"

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

class Background {
public:
    
    /*
        Background Constructor that takes background image path to render
        and assign it to path_to_background in the initializer list

        And takes windoow size in it's second parameter and pass it as an argument to setup_background()
    */
    Background(std::string background_path, const sf::Vector2u &window_size) 
        : path_to_background{background_path}
    {
        setup_background(window_size);
    }

    sf::Sprite get_background() {
        return background_sprite;
    }

private:

    /*
        A function that takes window -> getSize() as it argument to calculate the background images 
        proper width and height (the width and height of the background image should be the same as the window's)
    */ 
    void setup_background(const sf::Vector2u &window_size) {

        logger::LOG_INTO -> info ("Background: Initializing");

        // Load background imagae and handle errors
        if(!background_texture.loadFromFile(path_to_background)) {
            logger::LOG_INTO -> info("Background: Failed to load background");
            exit(EXIT_FAILURE);
        }

        background_sprite.setTexture(background_texture);
        background_sprite.setScale( 
            static_cast<float>(window_size.x) / background_texture.getSize().x,
            static_cast<float>(window_size.y) / background_texture.getSize().y
        );
    }

    sf::String path_to_background;
    sf::Texture background_texture;
    sf::Sprite background_sprite;

};

#endif