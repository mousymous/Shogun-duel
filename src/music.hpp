#include  "libraries.hpp"

#ifndef MUSIC_HPP
#define MUSIC_HPP

class Music {
public:
    Music(std::string path_to_music) {
        setup_music(path_to_music);
    };

    sf::Music & background_music() {
        return bmusic;
    }
private:
    sf::Music bmusic;

     void setup_music(const std::string music) {
        if(!bmusic.openFromFile(music)) {
            logger::LOG_INTO -> info("Music: Failed to load music from path");
            exit(EXIT_FAILURE);
        }
    }

};

#endif