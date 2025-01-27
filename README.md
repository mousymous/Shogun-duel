# Shogun-duel

## A Work-in-Progress Project

- **Developer**: Mousymous<br>
- **Theme**: Silouhette<br>
- **Description**:    A Work on Progress Project written in C++ of two shogun having a duel.<br>

## Design:

- Two Shogun figthing in the middle of the white spot of the battle field, miniture, traditional sword fight

## Dependencies for compilation:

- **Standard C++ Library**<br>
- **Spdlogs**:[https://github.com/gabime/spdlog]<br>
- **SFML**:[https://www.sfml-dev.org/]<br>

# Things to do

1. Add proper descriptive comments to all file<br>
2. Add proper logging<br>

3. Configure Rect Class to make it as a modular template for creating entities<br>
  - Textures will be the job of Texture instead<br>
4. Add Player Class and by using Rect Class and Texture Class create a samurai<br>
  - with proper animation based on movements

# Notes for Self!<br>

I wrote this so that I know what to do next, as this project is too big for me to remember it all.<br>

---<br>

## Logger (`logger.hpp`)<br>

- **Purpose**:<br>
  This header does not contain a class but handles the initialization and error handling for the **SPDLOG** logger.<br>
  The pointer `LOG_INTO` (inside the `logger::` namespace) writes log information to `logs/logs.texture`.<br>

---<br>

## Background (`background.hpp`)<br>

- **Purpose**:<br>
  This class is now modular and templated. It takes the image path as an argument and uses it in the `setup_background()` function.<br>

- **Current Features**:<br>
  - ✅ Getter function for the sprite variables (completed).<br>

- **Notes**:<br>
  Avoid making further changes unless you are adding animations for the background, which is a task for the future.<br>

---<br>

## Window (`window.hpp`)<br>

- **Purpose**:<br>
  This class is not templated but serves as a container. All events and updates are managed within the class object.<br>

- **Things to Change**:<br>
  1. ✅ Add proper comments.(completed)<br>
  2. Add more logging.<br>

---<br>

## Spritesheet_Animator(`texture.hpp`)<br>

- **Purpose**:<br>
  This class fetches spritesheets, animates them, and applies them as textures to entities (e.g., `Rect::rect`).<br>

- **Things to Change**:<br>
  1. Add comments to explain the functionality to avoid forgetting how it works.<br>

---<br>

## Rect (`rect.hpp`)<br>

- **Purpose**:<br>
  This class serves as a template for creating new entities.<br>
  Note: Entities created by this class have no textures or animations. These are applied using the `Texture`.<br>

- **Features**:<br>
  - Utilizes `sf::RectangleShape`, which comes with pre-coded hitbox properties.<br>

- **Things to Change**:<br>
  1. Remove the movement function from the `Rect`.<br>
  2. Encapsulate the `rect` variable and use a getter function to draw it in the window.<br>
  3. Add loggers and comments to the class.<br>

---<br>

## Things to Add<br>

- **Player Class**:<br>
  After fixing `Rect` and making changes to `Texture`, combine the two to create a `Player`.<br>
  - The `Player` should represent the samurai with proper textures and animations based on movement direction.<br>

- **Notes**:<br>
  - Focus on the `Player` first and prioritize its implementation.<br>
  - Do not worry about health bars and hitboxes for now; those can be addressed later.<br>
