#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;
#include "var_common.h"
#include "setup_Sound.h"
#include"LTexture.h"
#include"var_texture.h"
#include"LTimer.h"
#include"LButton.h"
#include"LButton2.h"
#include"LButton1.h"
#include"Brick.h"
#include"Paddle.h"
#include"Dot.h"
#include"fun_common.h"
#include"play1.h"

class TheGame{

    int status;
    std::string status_next;
    public:
    TheGame(){
    // Initialize the game
    this->status=MAIN_MENU;
    this->status_next="menu";
    }
    int get_Char(){
        return this->status;
    }
    
    void update_Status_Game(){
        if(this->status_next=="playlv1"){
            if(this->status==MAIN_MENU){
                this->status=GAME_PLAY;
            }
            if(this->status==LOSE){
                this->status=GAME_PLAY;
            }
            if(this->status==GAME_PLAY){
                this->status=GAME_PLAY;
                // trường hợp đặc biệt reset lại game cần để ý chỗ này
            }
            if(this->status==WIN){
                this->status=GAME_PLAY;
            }
            if(this->status==PAUSE){
                this->status=GAME_PLAY;
            }
            return;
        }
        if(this->status_next=="playlv2"){
            if(this->status==GAME_PLAY){
                this->status=GAME_PLAY2;
            }
            return;
        }
        if(this->status_next=="pause1"){
            if(this->status==GAME_PLAY){
                this->status=PAUSE;
            }
            if(this->status==GAME_PLAY2){
                this->status=PAUSE;
            }
            return;
        }
        
        if(this->status_next=="about"){
            if(this->status==MAIN_MENU){
                this->status=ABOUT;
            }
            return;
        }
        if(this->status_next=="sound"){
            if(this->status==MAIN_MENU){
                this->status=SOUND;
            }
            return;
        }
        if(this->status_next=="quit"){
            if(this->status==MAIN_MENU||this->status==GAME_PLAY2||this->status==GAME_PLAY||this->status==ABOUT||this->status==SOUND||this->status==WIN||this->status==LOSE||this->status==PAUSE){
                this->status=EXIT;
            }
        }
        if(this->status_next=="menu"){
            if(this->status==ABOUT){
                this->status=MAIN_MENU;
            }
            if(this->status==SOUND){
                this->status=MAIN_MENU;
            }
            if(this->status==GAME_PLAY){
                this->status=MAIN_MENU;
            }
            if(this->status==LOSE){
                this->status=MAIN_MENU;
            }
            if(this->status==WIN){
                this->status=MAIN_MENU;
            }
            if(this->status==PAUSE){
                this->status=MAIN_MENU;
            }

            return;
        }
        if(this->status_next=="lose"){
            if(this->status==GAME_PLAY){
                this->status=LOSE;
            }
            if(this->status==GAME_PLAY2){
                this->status=LOSE;
            }
            return;
        }
        if(this->status_next=="win"){
            if(this->status==GAME_PLAY2){
                this->status=WIN;
            }
        }
    }
    void render_Game(){
        switch(this->status){
            case MAIN_MENU:
            {
                this->status_next=main_menu();
                break;
            }
            // chỗ này để chạy level thôi :v
            case GAME_PLAY:
            {
                this->status_next=playlv5();
                break;
            }
            case ABOUT:
            {
                this->status_next=about();
                break;
            }
            case SOUND:
            {
                this->status_next=sound();
                break;
            }
            case LOSE :
            {
                this->status_next=lose();
                break;
            }
            case GAME_PLAY2 :
            {
                this->status_next=playlv2();
                break;
            }
            case WIN :
            {
                this->status_next=win();
                break;
            }

        }
    }
};
TheGame game;