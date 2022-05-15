void Init_Bricklv1(Brick brick[]){
   for (int i = 0; i < 7; i++){
	   		brick[i].setBrick(i*(brick[i].BRICK_WIDTH+1)+21, 0*brick[i].BRICK_HEIGHT+60,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	      }
	for(int i=7;i<14;i++){	
		brick[i].setBrick((i-7)*(brick[i].BRICK_WIDTH+1)+21, 1*(brick[i].BRICK_HEIGHT+1)+60,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=14;i<21;i++){
		brick[i].setBrick((i-14)*(brick[i].BRICK_WIDTH+1)+21, 2*(brick[i].BRICK_HEIGHT+1)+60,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=21;i<28;i++){
		brick[i].setBrick((i-21)*(brick[i].BRICK_WIDTH+1)+21, 3*(brick[i].BRICK_HEIGHT+1)+60,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=28;i<35;i++){
		brick[i].setBrick((i-28)*(brick[i].BRICK_WIDTH+1)+21, 4*(brick[i].BRICK_HEIGHT+1)+60,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=35;i<40;i++){
		brick[i].setBrick((i-35)*(brick[i].BRICK_WIDTH+1)+21, 5*(brick[i].BRICK_HEIGHT+1)+60,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv2(Brick brick[]){
    for (int i = 0; i < 7; i++){
		brick[i].setBrick(i*(brick[i].BRICK_WIDTH+1)+21, 0*brick[i].BRICK_HEIGHT+60,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	    }
	for(int i=7;i<14;i++){	
		brick[i].setBrick((i-7)*(brick[i].BRICK_WIDTH+1)+21,1*(brick[i].BRICK_HEIGHT+1)+60,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=14;i<21;i++){
		brick[i].setBrick((i-14)*(brick[i].BRICK_WIDTH+1)+21,2*(brick[i].BRICK_HEIGHT+1)+60,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=21;i<28;i++){
		brick[i].setBrick((i-21)*(brick[i].BRICK_WIDTH+1)+21,3*(brick[i].BRICK_HEIGHT+1)+60,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=28;i<35;i++){
		brick[i].setBrick((i-28)*(brick[i].BRICK_WIDTH+1)+21,4*(brick[i].BRICK_HEIGHT+1)+60,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv3(Brick brick[]){
    for (int i = 0; i < 7; i++){
		brick[i].setBrick(i*brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	    }
	for(int i=7;i<14;i++){	
		brick[i].setBrick((i-7)*brick[i].BRICK_WIDTH+25,2*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=14;i<20;i++){
		brick[i].setBrick((i-14)*brick[i].BRICK_WIDTH+40,3*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=20;i<25;i++){
		brick[i].setBrick((i-20)*brick[i].BRICK_WIDTH+65,4*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=25;i<30;i++){
		brick[i].setBrick((i-25)*brick[i].BRICK_WIDTH+90,5*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv4(Brick brick[]){
    for (int i = 0; i < 7; i++){
		brick[i].setBrick(i*brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	    }
	for(int i=7;i<14;i++){	
		brick[i].setBrick((i-7)*brick[i].BRICK_WIDTH+25,2*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=14;i<20;i++){
		brick[i].setBrick((i-14)*brick[i].BRICK_WIDTH+40,3*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=20;i<25;i++){
		brick[i].setBrick((i-20)*brick[i].BRICK_WIDTH+65,4*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=25;i<30;i++){
		brick[i].setBrick((i-25)*brick[i].BRICK_WIDTH+90,5*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv5(Brick brick[]){
    for (int i = 0; i < 7; i++){
		brick[i].setBrick(i*brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	    }
	for(int i=7;i<14;i++){	
		brick[i].setBrick((i-7)*brick[i].BRICK_WIDTH+25,2*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=14;i<20;i++){
		brick[i].setBrick((i-14)*brick[i].BRICK_WIDTH+40,3*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=20;i<25;i++){
		brick[i].setBrick((i-20)*brick[i].BRICK_WIDTH+65,4*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=25;i<30;i++){
		brick[i].setBrick((i-25)*brick[i].BRICK_WIDTH+90,5*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv6(Brick brick[]){
    for (int i = 0; i < 7; i++){
		brick[i].setBrick(i*brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	    }
	for(int i=7;i<14;i++){	
		brick[i].setBrick((i-7)*brick[i].BRICK_WIDTH+25,2*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=14;i<20;i++){
		brick[i].setBrick((i-14)*brick[i].BRICK_WIDTH+40,3*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=20;i<25;i++){
		brick[i].setBrick((i-20)*brick[i].BRICK_WIDTH+65,4*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=25;i<30;i++){
		brick[i].setBrick((i-25)*brick[i].BRICK_WIDTH+90,5*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv7(Brick brick[]){
    for (int i = 0; i < 7; i++){
		brick[i].setBrick(i*brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	    }
	for(int i=7;i<14;i++){	
		brick[i].setBrick((i-7)*brick[i].BRICK_WIDTH+25,2*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=14;i<20;i++){
		brick[i].setBrick((i-14)*brick[i].BRICK_WIDTH+40,3*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=20;i<25;i++){
		brick[i].setBrick((i-20)*brick[i].BRICK_WIDTH+65,4*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=25;i<30;i++){
		brick[i].setBrick((i-25)*brick[i].BRICK_WIDTH+90,5*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv8(Brick brick[]){
    for (int i = 0; i < 7; i++){
		brick[i].setBrick(i*brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	    }
	for(int i=7;i<14;i++){	
		brick[i].setBrick((i-7)*brick[i].BRICK_WIDTH+25,2*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=14;i<20;i++){
		brick[i].setBrick((i-14)*brick[i].BRICK_WIDTH+40,3*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=20;i<25;i++){
		brick[i].setBrick((i-20)*brick[i].BRICK_WIDTH+65,4*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=25;i<30;i++){
		brick[i].setBrick((i-25)*brick[i].BRICK_WIDTH+90,5*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv9(Brick brick[]){
    for (int i = 0; i < 7; i++){
		brick[i].setBrick(i*brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	    }
	for(int i=7;i<14;i++){	
		brick[i].setBrick((i-7)*brick[i].BRICK_WIDTH+25,2*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=14;i<20;i++){
		brick[i].setBrick((i-14)*brick[i].BRICK_WIDTH+40,3*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=20;i<25;i++){
		brick[i].setBrick((i-20)*brick[i].BRICK_WIDTH+65,4*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=25;i<30;i++){
		brick[i].setBrick((i-25)*brick[i].BRICK_WIDTH+90,5*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv10(Brick brick[]){
    for (int i = 0; i < 7; i++){
		brick[i].setBrick(i*brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	    }
	for(int i=7;i<14;i++){	
		brick[i].setBrick((i-7)*brick[i].BRICK_WIDTH+25,2*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=14;i<20;i++){
		brick[i].setBrick((i-14)*brick[i].BRICK_WIDTH+40,3*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=20;i<25;i++){
		brick[i].setBrick((i-20)*brick[i].BRICK_WIDTH+65,4*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=25;i<30;i++){
		brick[i].setBrick((i-25)*brick[i].BRICK_WIDTH+90,5*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv11(Brick brick[]){
    for (int i = 0; i < 7; i++){
		brick[i].setBrick(i*brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	    }
	for(int i=7;i<14;i++){	
		brick[i].setBrick((i-7)*brick[i].BRICK_WIDTH+25,2*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=14;i<20;i++){
		brick[i].setBrick((i-14)*brick[i].BRICK_WIDTH+40,3*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=20;i<25;i++){
		brick[i].setBrick((i-20)*brick[i].BRICK_WIDTH+65,4*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=25;i<30;i++){
		brick[i].setBrick((i-25)*brick[i].BRICK_WIDTH+90,5*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv12(Brick brick[]){
    for (int i = 0; i < 7; i++){
		brick[i].setBrick(i*brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	    }
	for(int i=7;i<14;i++){	
		brick[i].setBrick((i-7)*brick[i].BRICK_WIDTH+25,2*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=14;i<20;i++){
		brick[i].setBrick((i-14)*brick[i].BRICK_WIDTH+40,3*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=20;i<25;i++){
		brick[i].setBrick((i-20)*brick[i].BRICK_WIDTH+65,4*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=25;i<30;i++){
		brick[i].setBrick((i-25)*brick[i].BRICK_WIDTH+90,5*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv13(Brick brick[]){
    for (int i = 0; i < 7; i++){
		brick[i].setBrick(i*brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	    }
	for(int i=7;i<14;i++){	
		brick[i].setBrick((i-7)*brick[i].BRICK_WIDTH+25,2*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=14;i<20;i++){
		brick[i].setBrick((i-14)*brick[i].BRICK_WIDTH+40,3*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=20;i<25;i++){
		brick[i].setBrick((i-20)*brick[i].BRICK_WIDTH+65,4*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=25;i<30;i++){
		brick[i].setBrick((i-25)*brick[i].BRICK_WIDTH+90,5*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv14(Brick brick[]){
    for (int i = 0; i < 7; i++){
		brick[i].setBrick(i*brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	    }
	for(int i=7;i<14;i++){	
		brick[i].setBrick((i-7)*brick[i].BRICK_WIDTH+25,2*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=14;i<20;i++){
		brick[i].setBrick((i-14)*brick[i].BRICK_WIDTH+40,3*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=20;i<25;i++){
		brick[i].setBrick((i-20)*brick[i].BRICK_WIDTH+65,4*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=25;i<30;i++){
		brick[i].setBrick((i-25)*brick[i].BRICK_WIDTH+90,5*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv15(Brick brick[]){
    for (int i = 0; i < 7; i++){
		brick[i].setBrick(i*brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	    }
	for(int i=7;i<14;i++){	
		brick[i].setBrick((i-7)*brick[i].BRICK_WIDTH+25,2*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=14;i<20;i++){
		brick[i].setBrick((i-14)*brick[i].BRICK_WIDTH+40,3*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=20;i<25;i++){
		brick[i].setBrick((i-20)*brick[i].BRICK_WIDTH+65,4*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
	for(int i=25;i<30;i++){
		brick[i].setBrick((i-25)*brick[i].BRICK_WIDTH+90,5*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH,brick[i].BRICK_HEIGHT);
	}
}

// từ lv3 đến lv15 dành ra 1 buổi đề ngồi cài đặt brick
