#include "libraries.hpp"

#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity {

    public:
        Entity(Rect& rect, Spritesheet_Animator &right_animation, Spritesheet_Animator &left_animation, Spritesheet_Animator &idle_animation, 
        Spritesheet_Animator &attack_animation, float speed) 
        : entity_rect{rect}, right{right_animation}, left{left_animation}, idle{idle_animation}, attack{attack_animation} ,movement_speed{speed}
        {}

        void movement() {

            bool isMoving = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                entity_rect.get_rect().move(movement_speed, 0);
                right.animate_entity();
                isMoving = true;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                entity_rect.get_rect().move(-movement_speed, 0);
                left.animate_entity();
                isMoving = true;
            } 

             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                entity_rect.get_rect().move(-0.2, 0);
                attack.animate_entity();
                isMoving = true;
            } 
            
            if (!isMoving){
                 idle.animate_entity();
            }
        }

        sf::RectangleShape& get_rect() {
            return entity_rect.get_rect();
        }

    private:
        Rect &entity_rect;
        Spritesheet_Animator &right;
        Spritesheet_Animator &left;
        Spritesheet_Animator &idle;
        Spritesheet_Animator &attack;
        float movement_speed;
};

#endif