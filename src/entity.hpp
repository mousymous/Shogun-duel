#include "libraries.hpp"

#ifndef ENTITY_HPP
#define ENTITY_HPP

// Entity class represents a character or object in the game that has animations and can move
class Entity {

    public:

        // Control Types for the entity
        enum class CONTROL_TYPE {
            ARROW_KEYS, LETTER_KEYS
        };


        // Checks the user input type and handles entity movement mechanics
        void movement() {

            if(control_type == CONTROL_TYPE::ARROW_KEYS) {
                arrow_keys();
            }

            if (control_type == CONTROL_TYPE::LETTER_KEYS) {
                letter_keys();
            }

        }

        // Getter for the entity's rectangle (used to draw the entity)
        sf::RectangleShape& get_rect() {
            return entity_rect.get_rect();
        }

        // Constructor initializes the entity with a rectangle (position and size) and animations
        // for different states (right, left, idle, and attack) along with the movement speed and control type

        Entity(Rect& rect, Spritesheet_Animator &right_animation, Spritesheet_Animator &left_animation, Spritesheet_Animator &idle_animation, 
        Spritesheet_Animator &attack_animation, float speed, CONTROL_TYPE type) 
        : entity_rect{rect}, right{right_animation}, left{left_animation}, idle{idle_animation}, attack{attack_animation} ,movement_speed{speed}, control_type{type}
        {}

    private:
        CONTROL_TYPE control_type;

        Rect &entity_rect;  // Reference to the rectangle representing the entity's position and size
        Spritesheet_Animator &right;  // Reference to the right movement animation
        Spritesheet_Animator &left;   // Reference to the left movement animation
        Spritesheet_Animator &idle;   // Reference to the idle animation
        Spritesheet_Animator &attack; // Reference to the attack animation
        float movement_speed;  // Speed at which the entity moves


        // Controls for letter keys and handles appropriate animations
        void letter_keys() {

            bool isMoving = false;  // Flag to track if the entity is moving
        
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                entity_rect.get_rect().move(movement_speed, 0);  // Move the entity right
                right.animate_entity(); // Play the right movement animation
                isMoving = true;    // set isMoving to true
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                entity_rect.get_rect().move(-movement_speed, 0);
                left.animate_entity();
                isMoving = true;
            } 

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                attack.animate_entity();
                isMoving = true;
            } 
            
        // This one is a special if statement  so that it animates the idle animation when no
        // movement key is pressed
            else if (!isMoving){
                 idle.animate_entity();
            }
        }

         // Controls for arrow keys and handles appropriate animations
        void arrow_keys() {

            bool isMoving = false; 
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                entity_rect.get_rect().move(movement_speed, 0);  // Move the entity right
                right.animate_entity(); // Play the right movement animation
                isMoving = true;    // set isMoving to true
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                entity_rect.get_rect().move(-movement_speed, 0);
                left.animate_entity();
                isMoving = true;
            } 

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                attack.animate_entity();
                isMoving = true;
            } 
            
            else if (!isMoving){
                 idle.animate_entity();
            }
        }
};

#endif