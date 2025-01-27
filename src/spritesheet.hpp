#include "libraries.hpp"

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

class Spritesheet_Animator {
public:
    Spritesheet_Animator(
        std::string texture_path,
        std::int32_t texture_width,
        std::int32_t texture_height,
        std::int32_t frame_numbers,
        float duration,
        sf::RectangleShape &rect
    ) :
        path_to_texture {texture_path},
        width{texture_width},
        height{texture_height},
        number_of_frames{frame_numbers},
        frame_duration{duration},
        entity{rect}
    {

        if(!entity_texture.loadFromFile(path_to_texture)) {
            logger::LOG_INTO -> error("Texture: Load failure can't find texture");
            exit(EXIT_FAILURE);
        }

        logger::LOG_INTO -> info("Texture: Load success");
        entity.setTexture(&entity_texture);
        entity.setTextureRect(sf::IntRect(0, 0, width, height));
    };

    // Function for animating
    void animate_entity() {

        if(clock.getElapsedTime().asSeconds() >= frame_duration) {
            current_frame = (current_frame + 1) % number_of_frames;
            entity.setTextureRect(sf::IntRect((current_frame * width), 0, width, height));
            clock.restart();
        }
    }


private:

    std::string path_to_texture;
    std::int32_t width;
    std::int32_t height;
    std::int32_t number_of_frames;
    float frame_duration;

    std::int32_t current_frame{0};
    sf::Clock clock;

    sf::Texture entity_texture;
    sf::RectangleShape &entity;

};

#endif
