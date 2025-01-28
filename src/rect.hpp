#include "libraries.hpp"

#ifndef RECT_HPP
#define RECT_HPP

class Rect {
public:

    Rect( bool rect_visible, bool rect_outline ,sf::Color color, sf::Vector2f rect_position) {
        rect_set_visible(rect_visible);
        rect_set_outline(rect_outline);
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

    // Sets rect outline visibility
    void rect_set_outline(bool outline) {
        if (outline == true) {
            rect.setOutlineThickness(1.0f);
            rect.setOutlineColor(sf::Color::Red);
        }
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
