#include<iostream>
#include"loadhighscore.h"
using namespace std;
int main(){
    cout<<loadhighscore()<<endl;
    sethighscore(100);
    cout<<loadhighscore()<<endl;
}