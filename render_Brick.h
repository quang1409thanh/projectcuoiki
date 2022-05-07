void render_Brick_Lv1(Brick brick[TOTAL_BRICKSLV1]){
    for (int i = 0; i < 5; i++){
        brick[i].renderB('b');
        }
	for(int i=5;i<10;i++){	
		brick[i].renderB('r');
	}
    for(int i=10;i<15;i++){
        brick[i].renderB('g');
    }
}
void render_Brick_Lv2(Brick brick[TOTAL_BRICKSLV2]){
    for (int i = 0; i < 5; i++){
        brick[i].renderB('b');
        }
	for(int i=5;i<10;i++){	
		brick[i].renderB('o');
	}
}