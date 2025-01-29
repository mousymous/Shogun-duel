# Shogun-duel Game-engine 

## A Work-in-Progress Project

- **Developer**: Mousymous<br>
- **Description**: A Work on Progress Project written in C++ that suppose to be a game called Shogun-duel but it became a game engine instead.<br>

## Orginal Design:

- ~~Two Shogun figthing in the middle of the white spot of the battle field, miniture, traditional sword fight~~

## Problem:

- The project became a game engine without realizing it:>

## Dependencies for compilation:

- **Standard C++ Library**<br>
- **Spdlogs**:[https://github.com/gabime/spdlog]<br>
- **SFML**:[https://www.sfml-dev.org/]<br>

# Things to do

1. Add proper descriptive comments to all file<br>
2. Add proper logging<br>

# Notes for Self!<br>

**I wrote this so that I know what to do next, as this project is too big for me to remember it all.**<br>

---

## Logger (`logger.hpp`)<br>

- **Purpose**:<br>
  This header does not contain a class but handles the initialization and error handling for the **SPDLOG** logger.<br>
  The pointer `LOG_INTO` (inside the `logger::` namespace) writes log information to `logs/logs.texture`.<br>

---

## Background_Parralax (`background.hpp`)<br>

- **Purpose**:<br>
   `Background_Parallax` this class is dedicated for setting up parallax effects in the background for 3D visuals<br>

- **Features:**<br>
    - `.parallax_effect()` member simulates the effect according to the keyboard's pressed arrow keys `left` or `right`
    - `Background_Parallax` constractor takes three arguments `background` `midground` `foreground` to set the effect
    -  foreground moves slower than midground and background moves the slowest

- **Notes**:
    - foreground images must be long atleast a width of 1500 it really depends
---

## Window (`window.hpp`)<br>

- **Purpose**:<br>
  This class is not templated but serves as a container. All events and updates are managed within the class object.<br>

- **Things to Change**:<br>
  1. ✅ Add proper comments.(completed)<br>
  2. ✅ Add more logging. (completed)<br>

---

## Spritesheet_Animator(`spritesheet.hpp`)<br>

- **Purpose**:<br>
  This class fetches spritesheets, animates them, and applies them as textures to entities (e.g., `Rect::rect`).<br>


---

## Rect (`rect.hpp`)<br>

- **Purpose**:<br>
  This class serves as a template for creating new entities.<br>
  Note: Entities created by this class have no textures or animations. These are applied using the `Spritesheet Class`.<br>

- **Features**:<br>
  - Utilizes `sf::RectangleShape`, which comes with pre-coded hitbox properties.<br>
  - You can enable or disable visible outline for collision testing 


- **Added**
  1. You can now have a custom color for the rect<br>
  2. it now has a function getter that returns the rect variable as a reference<br>

---

## Entity (entity.hpp)

- **Purpose**: <br>
    `Entity` is a class that can be used to create entities with 2 direction movement in x and -x <br>
     There's two control mechanics which are `arrow_keys()` which uses arrows and `letter_keys()` which uses letters<br>
     and an attack mechanic that works when pressing `Space Bar`<br>

- **Features**:<br>
    - select the movement type you want by passing ` Entity::CONTROL_TYPE::LETTER_KEYS` or ` Entity::CONTROL_TYPE::ARROW_KEYS` in 
      the last argument

- **How to use:**<br>
     1. It takes 7 arguments a Rect, 4 spritesheet class, entity movement speed and control type<br>
     2. With proper arguments you can create a functioning entity<br>

---

## Entity_Database (entitydatabase.hpp)<br>

-- **Purpose**<br>
   `Entity_Database` class ia a database contains created etities and stores it in a vector list<br>

- **Features:**<br>
     1. The storing mechanism is scalable as it use `std::vector` to store entity object<br>
        - The stored entity objects are not a copy but a refrences to existing one<br>
        - To add an entity use `.add_entity()` member.<br>
         > it takes a reference to an entity object as an argument and stores it in `entity_list` vector using `.push_back()`<br>
        - To access an entity use `.get_entity()` member.<br>
        > it takes an index and returns an etity object stored in that location<br>

- **Notes**:<br>

    1. The very first object that has been added has an ID number `0` and scales up as you add entities<br>

    2. It is still not perfect so when adding a entity in the database make sure to leave a comment on which ID it has<br>
      - for example `entity_database.add_entity(object) // ID 0`.<br>

--- 

### Things to do:<br> 

  - Add parallax effect in the background (Restructure the Background Class mechanics)
  - Add Hitbox mechanics
  - Add Health mechanics
  - Don't worry adding a bot opponent for now, just focus on the list above
  - Learn About Shaders too to add cool effects but only do that when the game is finished