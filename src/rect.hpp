#include "libraries.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Rect_Class {
public:

    Rect_Class( bool is_player_visible, sf::Vector2f player_position, float player_speed) {
        rect_set_visible(is_player_visible);
        rect_set_position(player_position);
        rect_set_speed(player_speed);
    }

    // rect variable
    sf::RectangleShape rect{sf::Vector2f(200, 200)};

    // Sets the rect position
    void rect_set_position(sf::Vector2f player_position) {
        rect.setPosition(sf::Vector2f(player_position));
    }

    // Make Rect Visible
    void rect_set_visible(bool visible) {
        if (visible == false ) {
            rect.setFillColor(sf::Color(0,0,0,0));
        } 
    }

    // Rect Speed set up
    void rect_set_speed(float speed){
        rect_speed = speed;
    };

    // Rect Movement Logic
    void rect_movement_logic() {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            rect.move(rect_speed, 0);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            rect.move(-rect_speed, 0);
        }
    }

private:
    sf::Clock clock;
    float rect_speed;
};

#endif
