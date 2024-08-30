//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP
#include <SDL_mixer.h>
#include <map>
#include <string>

class AudioManager {
public:
    static AudioManager& getInstance();

    bool loadMusic(const std::string& id, const std::string& filename);
    bool loadSoundEffect(const std::string& id, const std::string& filename);

    void playMusic(const std::string& id);
    void playSoundEffect(const std::string& id);

    void free();

private:
    AudioManager() = default;
    ~AudioManager() = default;
    AudioManager(const AudioManager&) = delete;
    AudioManager& operator=(const AudioManager&) = delete;

    std::map<std::string, Mix_Music*> musicMap;
    std::map<std::string, Mix_Chunk*> soundEffectMap;
};

#endif //AUDIOMANAGER_HPP
