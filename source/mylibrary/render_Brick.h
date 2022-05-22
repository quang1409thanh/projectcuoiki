#include"load_Color.h"

void render_Brick_Lv1(Brick brick[]){
	vector<char> color1=load_Color("source/Data/data_txt/lev1C.txt");
	for(int i=0;i<TOTAL_BRICKSLV1;i++){
		brick[i].renderB(color1[i]);
	}
}
void render_Brick_Lv2(Brick brick[]){
	vector<char> color2=load_Color("source/Data/data_txt/lev2C.txt");
	for(int i=0;i<TOTAL_BRICKSLV2;i++){
		brick[i].renderB(color2[i]);
	}
}
void render_Brick_Lv3(Brick brick[]){
	vector<char> color3=load_Color("source/Data/data_txt/lev3C.txt");
	for(int i=0;i<TOTAL_BRICKSLV3;i++){
		brick[i].renderB(color3[i]);
	}
}
void render_Brick_Lv4(Brick brick[]){
	vector<char> color4=load_Color("source/Data/data_txt/lev4C.txt");
	for(int i=0;i<TOTAL_BRICKSLV4;i++){
		brick[i].renderB(color4[i]);
	}
}
void render_Brick_Lv5(Brick brick[]){
	vector<char> color5=load_Color("source/Data/data_txt/lev5C.txt");
	for(int i=0;i<TOTAL_BRICKSLV5;i++){
		brick[i].renderB(color5[i]);
	}
}