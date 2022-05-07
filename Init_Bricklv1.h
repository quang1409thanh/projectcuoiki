void Init_Bricklv1(Brick brick[TOTAL_BRICKSLV1]){
   for (int i = 0; i < 5; i++){
	   		brick[i].setBrick(i*brick[i].BRICK_WIDTH, i*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	      }
	for(int i=5;i<10;i++){	
		brick[i].setBrick((i-5)*brick[i].BRICK_WIDTH, (i-5)*brick[i].BRICK_HEIGHT+40,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	for(int i=10;i<15;i++){
		brick[i].setBrick((i-10)*brick[i].BRICK_WIDTH, (i-10)*brick[i].BRICK_HEIGHT+80,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
}
void Init_Bricklv2(Brick brick[TOTAL_BRICKSLV2]){
   for (int i = 0; i < 5; i++){
	   		brick[i].setBrick(i*brick[i].BRICK_WIDTH, i*brick[i].BRICK_HEIGHT,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	      }
	for(int i=5;i<10;i++){	
		brick[i].setBrick((i-5)*brick[i].BRICK_WIDTH+25, (i-5)*brick[i].BRICK_HEIGHT+60,0,0,brick[i].BRICK_WIDTH, brick[i].BRICK_HEIGHT);
	}
	
}

