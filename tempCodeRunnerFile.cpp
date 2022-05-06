void play();
void lose();
void play(){
    if(x) lose();
}
void lose(){
    if(y) play();
}