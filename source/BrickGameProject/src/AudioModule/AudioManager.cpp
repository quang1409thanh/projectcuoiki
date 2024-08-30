//
// Created by Nguyễn Quang Thành on 8/28/2024.
//
// AudioManager.cpp
#include "AudioManager.hpp"
#include <iostream>

// Singleton instance
AudioManager& AudioManager::getInstance() {
    static AudioManager instance;
    return instance;
}

bool AudioManager::loadMusic(const std::string& id, const std::string& filename) {
    Mix_Music* music = Mix_LoadMUS(filename.c_str());
    if (music == nullptr) {
        std::cerr << "Failed to load music: " << Mix_GetError() << std::endl;
        return false;
    }
    musicMap[id] = music;
    return true;
}

bool AudioManager::loadSoundEffect(const std::string& id, const std::string& filename) {
    Mix_Chunk* chunk = Mix_LoadWAV(filename.c_str());
    if (chunk == nullptr) {
        std::cerr << "Failed to load sound effect: " << Mix_GetError() << std::endl;
        return false;
    }
    soundEffectMap[id] = chunk;
    return true;
}

void AudioManager::playMusic(const std::string& id) {
    Mix_Music* music = musicMap[id];
    if (music != nullptr) {
        Mix_PlayMusic(music, -1); // -1: Loop the music indefinitely
    }
}

void AudioManager::playSoundEffect(const std::string& id) {
    Mix_Chunk* chunk = soundEffectMap[id];
    if (chunk != nullptr) {
        Mix_PlayChannel(-1, chunk, 0); // -1: Use first available channel
    }
}

void AudioManager::stopMusic() {
    Mix_HaltMusic();
}

void AudioManager::pauseMusic() {
    Mix_PauseMusic();
}

void AudioManager::resumeMusic() {
    Mix_ResumeMusic();
}

void AudioManager::free() {
    for (auto& pair : musicMap) {
        Mix_FreeMusic(pair.second);
    }
    musicMap.clear();

    for (auto& pair : soundEffectMap) {
        Mix_FreeChunk(pair.second);
    }
    soundEffectMap.clear();
}
