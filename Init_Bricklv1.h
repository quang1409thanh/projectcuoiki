#include "load_Point.h"

void Init_Bricklv1(Brick brick[]){
	vector<Point> lv1=load_Vector("Data/data_txt/lv1.txt");
   	for (int i = 0; i < TOTAL_BRICKSLV1; i++){
	   		brick[i].setBrick(lv1[i].x,lv1[i].y,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	      }
}
void Init_Bricklv2(Brick brick[]){
	vector<Point> lv2=load_Vector("Data/data_txt/lv2.txt");
   	for (int i = 0; i < TOTAL_BRICKSLV2; i++){
		brick[i].setBrick(lv2[i].x,lv2[i].y,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv3(Brick brick[]){
	vector<Point> lv3=load_Vector("Data/data_txt/lv3.txt");
   	for (int i = 0; i < TOTAL_BRICKSLV3; i++){
		brick[i].setBrick(lv3[i].x,lv3[i].y,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv4(Brick brick[]){
	vector<Point> lv4=load_Vector("Data/data_txt/lv4.txt");
   	for (int i = 0; i < TOTAL_BRICKSLV4; i++){
		brick[i].setBrick(lv4[i].x,lv4[i].y,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv5(Brick brick[]){
	vector<Point> lv5=load_Vector("Data/data_txt/lv5.txt");
   	for (int i = 0; i < TOTAL_BRICKSLV5; i++){
		brick[i].setBrick(lv5[i].x,lv5[i].y,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
}