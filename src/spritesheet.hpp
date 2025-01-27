#include "libraries.hpp"

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

class Spritesheet_Animator {
public:
    
    /* 
        A constructor that takes texture_path, texture_width, texture_height, frame_number
        duration, a reference to a rect object and initializes them to their
        respective variables
    */
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
        entity_rect{rect}
    {

        // Loads the Spritesheet into the referenced rect and handle errors
        if(!entity_texture.loadFromFile(path_to_texture)) {
            logger::LOG_INTO -> error("Texture: Load failure can't find texture");
            exit(EXIT_FAILURE);
        }

        logger::LOG_INTO -> info("Texture: Load success");

        // Initializes the referenced rect it's texture
        entity_rect.setTexture(&entity_texture);
        entity_rect.setTextureRect(sf::IntRect(0, 0, width, height));
    };

    /*
        This function animates using a verticalspritesheet.
        The 'if(clock.getElapsed().asSeconds() >= frame_duration)' checks how many
        seconds has passed and then executes if the seconds has passed is greater or equal to
        the 'frame_duration'
    */
    void animate_entity() {

        if(clock.getElapsedTime().asSeconds() >= frame_duration) {
            // Explanation 1.0
            current_frame = (current_frame + 1) % number_of_frames;

            // Explanation 2.0
            entity_rect.setTextureRect(sf::IntRect((current_frame * width), 0, width, height));

            // Explanation 3.0
            clock.restart();
        }
    }


private:

    std::string path_to_texture;        // Stores the spritesheet path
    std::int32_t width;                 // Stores the spritesheet width
    std::int32_t height;                // Stores the spritesheet height
    std::int32_t number_of_frames;      // Stores the maximum number of frames in the spritesheet
    float frame_duration;               // Stores the frame's duration

    std::int32_t current_frame{0};
    sf::Clock clock;                 

    sf::Texture entity_texture;         // Texture variable that will contain the spritesheet image 
    sf::RectangleShape &entity_rect;         // A Reference to a Rect Class object

};

#endif


/*
Explanation 1.0:

        "current_frame = (current_frame + 1) % number_of_frames;"

        This line sums 1 on current_frame and gets it's reminder after dividing it 
        by the maximum frame and assign that value to current_frame.

        Everytime the current frame is less than the maximum 
        frame the reminder will be the same as the current frame.

        but if the current frame has the same value as the maximum frame the reminder would be zero.

Explanation 2.0:

        "entity.setTextureRect(sf::IntRect((current_frame * width), 0, width, height));"

        This statement changes the rendered portion of the spritesheet to the next frame
        of the referenced Rect object

// Explanation 3.0
        
        "clock.restart()"

        Resets the clock
*/