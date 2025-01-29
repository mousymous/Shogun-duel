#include "libraries.hpp"

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

class Background_Parallax {
public:

    Background_Parallax(std::string background, std::string midground, std::string foreground) {
        logger::LOG_INTO -> info("Background: Initializing");
        load_layer_textures(background_texture, background);
        load_layer_textures(midgroud_texture, midground);
        load_layer_textures(foreground_texture, foreground);

        load_texture_to_layer(background_layer, background_texture);
        load_texture_to_layer(midground_layer, midgroud_texture);
        load_texture_to_layer(foreground_layer, foreground_texture);


    };

    // Experimental parallax effect
    void parallax_effect() {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            background_layer.move(-bspeed, 0);
            midground_layer.move(-mspeed, 0);
            foreground_layer.move(-fspeed, 0);
        }

         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            background_layer.move(bspeed, 0);
            midground_layer.move(mspeed, 0);
            foreground_layer.move(fspeed, 0);
        }
    }

    // Function getters
    sf::Sprite &get_background() {
        return background_layer;
    }

    sf::Sprite &get_midground() {
        return midground_layer;
    }

    sf::Sprite &get_foreground() {
        return foreground_layer;
    }
    
private:
    // Variables to hold textures
    sf::Texture background_texture;
    sf::Texture midgroud_texture;
    sf::Texture foreground_texture;

    // variables to hold sprites of each ground
    sf::Sprite background_layer;
    sf::Sprite midground_layer;
    sf::Sprite foreground_layer;

    // speed of each ground for parallax effect
    float bspeed = 0.1;
    float mspeed = 0.3;
    float fspeed = 0.5;

    // A function that takes a reference to a sf::Texture and loads it's texture with
    // Error handling
    void load_layer_textures(sf::Texture &texture, std::string path) {

        if(!texture.loadFromFile(path)) {
            logger::LOG_INTO -> error("Background: Can't find path");
            exit(EXIT_FAILURE);
        }
    }

    // Assigns the proper texture for each background sprite.
    // Set ground position to 0,0 
    // scales them to 40% less of the actuall size
    void load_texture_to_layer(sf::Sprite &sprite, sf::Texture &texture) {
        sprite.setTexture(texture);
        sprite.setPosition(0, 0);
        sprite.setScale(0.4, 0.4);
    }

};

#endif