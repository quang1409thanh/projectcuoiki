void Init_Bricklv1(Brick brick[]){
   for (int i = 0; i < 8; i++){
	   		brick[i].setBrick(i*(brick[i].BRICK_WIDTH+1), brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	      }
	for(int i=8;i<16;i++){	
		brick[i].setBrick((i-8)*(brick[i].BRICK_WIDTH+1), 2*(brick[i].BRICK_HEIGHT+1),0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=16;i<24;i++){
		brick[i].setBrick((i-16)*(brick[i].BRICK_WIDTH+1), 3*(brick[i].BRICK_HEIGHT+1),0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=24;i<32;i++){
		brick[i].setBrick((i-24)*(brick[i].BRICK_WIDTH+1), 4*(brick[i].BRICK_HEIGHT+1),0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=32;i<40;i++){
		brick[i].setBrick((i-32)*(brick[i].BRICK_WIDTH+1), 5*(brick[i].BRICK_HEIGHT+1),0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv2(Brick brick[]){
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
