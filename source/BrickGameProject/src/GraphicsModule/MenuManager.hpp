//
// Created by Nguyễn Quang Thành on 8/28/2024.
//

#ifndef MENUMANAGER_HPP
#define MENUMANAGER_HPP

#include <SDL.h>
#include <vector>
#include "LButton.h"
#include <iostream>
class MenuManager
{
public:
    // Screen dimension constants
    const int SCREEN_WIDTH = 400;
    const int SCREEN_HEIGHT = 600;

    static MenuManager &getInstance()
    {
        static MenuManager instance;
        return instance;
    }

    void loadButtons(SDL_Renderer *renderer)
    {
        // Clear any existing buttons to avoid duplicates
        gButtons.clear();

        // Load all buttons
        addButton("about_button", "D:/project/INT2215/projectcuoiki/source/Data/img/buttons/aboutbutton.png", renderer, SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2, SCREEN_HEIGHT - 70 - 2 * BUTTON_HEIGHT - 2 * BUTTON_HEIGHT / 8);
        // addButton("play_button", "D:/project/INT2215/projectcuoiki/source/Data/img/buttons/playbutton.png", renderer, SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2, SCREEN_HEIGHT - 70 - 3 * BUTTON_HEIGHT - 3 * BUTTON_HEIGHT / 8);
        // addButton("exit_button", "D:/project/INT2215/projectcuoiki/source/Data/img/buttons/exitbutton.png", renderer, SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2, SCREEN_HEIGHT - 70);
        // addButton("sound_button", "D:/project/INT2215/projectcuoiki/source/Data/img/buttons/soundbutton.png", renderer, SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2, SCREEN_HEIGHT - 70 - BUTTON_HEIGHT - BUTTON_HEIGHT / 8);
        // addButton("resume_button", "D:/project/INT2215/projectcuoiki/source/Data/img/buttons/resumebutton.png", renderer, SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2, SCREEN_HEIGHT - 70 - 2 * BUTTON_HEIGHT - 2 * BUTTON_HEIGHT / 8);
        // addButton("restart_button", "D:/project/INT2215/projectcuoiki/source/Data/img/buttons/restartbutton.png", renderer, SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2, SCREEN_HEIGHT - 70 - BUTTON_HEIGHT - BUTTON_HEIGHT / 8);
        // addButton("main_menu_button", "D:/project/INT2215/projectcuoiki/source/Data/img/buttons/mainmenubutton.png", renderer, SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2, SCREEN_HEIGHT - 70 - 2 * BUTTON_HEIGHT - 2 * BUTTON_HEIGHT / 8);

        // Add any other buttons if necessary...
    }

    void renderButtons(SDL_Renderer *renderer)
    {
        for (auto &button : gButtons)
        {
            button.render(renderer);
        }
    }

    void handleEvents(SDL_Event *e)
    {
        for (auto &button : gButtons)
        {
            button.handleEvent(e);
        }
    }

private:
    MenuManager() {}
    ~MenuManager() { cleanup(); }

    void addButton(const std::string &id, const std::string &path, SDL_Renderer *renderer, int x, int y)
    {
        LButton button;
        if (button.loadFromFile(path, renderer))
        {
            button.setPosition(x, y);
            gButtons.push_back(button);
        }
        else
        {
            std::cerr << "Failed to load button texture: " << path << std::endl;
        }
    }

    void cleanup()
    {
        gButtons.clear(); // Free vector resources
    }

    std::vector<LButton> gButtons; // Vector containing all buttons
};

#endif // MENUMANAGER_HPP
