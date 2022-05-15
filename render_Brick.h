void render_Brick_Lv1(Brick brick[]){
    for (int i = 0; i < 7; i++){
        brick[i].renderB('b');
        }
	for(int i=7;i<14;i++){	
		brick[i].renderB('r');
	}
    for(int i=14;i<21;i++){
        brick[i].renderB('g');
    }
    for(int i=21;i<28;i++){
        brick[i].renderB('i');
    }
    for(int i=28;i<34;i++){
        brick[i].renderB('d');
    }
    for(int i=34;i<40;i++){
        brick[i].renderB('o');
    }

}
void render_Brick_Lv2(Brick brick[]){
    for (int i = 0; i < 7; i++){
		brick[i].renderB('b');
	    }
	for(int i=7;i<14;i++){	
		brick[i].renderB('r');
	}
	for(int i=14;i<21;i++){
		brick[i].renderB('g');
	}
	for(int i=21;i<28;i++){
		brick[i].renderB('i');
	}
	for(int i=28;i<35;i++){
		brick[i].renderB('d');
	}
}