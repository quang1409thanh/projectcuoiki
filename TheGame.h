class TheGame{
public:
    Status status;
    TheGame(Status _status= ABOUT){
        // Initialize the game
        this->status=_status;
    }
    void getStatusGame(){
        if(gButton[GAME_PLAY].getStatus()==BUTTON_SPRITE_MOUSE_UP){
            this->status=GAME_PLAY ;
            std::cout<<status<<std::endl;
        }
        if(gButton[ABOUT].getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
            this->status=ABOUT;
            std::cout<<status<<std::endl;
        }
        else if(gButton[SOUND].getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
            this->status=SOUND;
            std::cout<<status<<std::endl;
        }
        else if(gButton[RESTART].getStatus()==BUTTON_SPRITE_MOUSE_DOWN||gButton1_Back.getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
            this->status=MAIN_MENU;
            std::cout<<status<<std::endl;
        } 
        else if(gButton[EXIT].getStatus()==BUTTON_SPRITE_MOUSE_DOWN){
            this->status=EXIT;
            std::cout<<status<<std::endl;
        }
    }
    void render(){
        switch (status)
        {
        // case MAIN_MENU:{
        //     main_menu();
        //     break; 
        // }
        case ABOUT:{
            about();
            break;
        }
        case GAME_PLAY:{
            playlv1();
            break;
        }
        
        case SOUND:{
            sound();
            break;
        }
        }
    }
};
TheGame game;