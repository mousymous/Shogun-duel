#include "libraries.hpp"

#ifndef RECT_HPP
#define RECT_HPP

class Rect {
public:

    Rect( bool is_rect_visible, sf::Color color, sf::Vector2f rect_position) {
        rect_set_visible(is_rect_visible);
        rect_set_position(rect_position);
        rect_set_color(color);
    }

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

    // Sets rect color
    void rect_set_color(sf::Color color) {
        rect.setFillColor(color);
    }

    // Getter function that returns rect as reference
    sf::RectangleShape & get_rect() {
        return rect;
    }

private:

    // Rect Speed
    float rect_speed;

     // Rect variable
    sf::RectangleShape rect{sf::Vector2f(200, 200)};
};

#endif
