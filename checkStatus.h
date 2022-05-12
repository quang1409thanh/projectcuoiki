void checkStatus(){
    if(gButtonPlay.getStatus()==BUTTON_SPRITE_MOUSE_UP){
        std::cout<<"GAME_PLAY"<<std::endl;
    }
    else if(gButtonAbout.getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
        std::cout<<"About"<<std::endl;
    }
    else if(gButtonSound.getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
        std::cout<<"Sound"<<std::endl;
    }
}