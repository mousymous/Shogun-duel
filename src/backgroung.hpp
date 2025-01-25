#include "libraries.hpp"

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

class Background_Class {
public:
    
    // Background Constructor to thats fetchs widnow size and pass it as an argument to setup_background()
    Background_Class(const sf::Vector2u &window_size) {
        setup_background(window_size);
    }

    sf::Texture background_texture;
    sf::Sprite background_sprite;

private:

    sf::String path_to_background {"../resources/background/shogun-duel-background.png"};

    // Background Set up function that takes window -> getSize() sa arguments
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

};

#endif