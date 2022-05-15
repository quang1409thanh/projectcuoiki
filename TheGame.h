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
            if(this->status==MAIN_MENU||this->status==GAME_PLAY||this->status==ABOUT||this->status==SOUND||this->status==WIN||this->status==LOSE){
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
            return;
        }
        if(this->status_next=="lose"){
            if(this->status==GAME_PLAY){
                this->status=LOSE;
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
            case GAME_PLAY:
            {
                this->status_next=playlv1();
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
        }
    }
};
TheGame game;