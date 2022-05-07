
void set_Brick_lv1(){
    Brick brick[BRICK_ROWS][BRICK_COLUMNS];
	for (int i = 0; i < BRICK_ROWS; i++)
	{
		for (int j = 0; j < BRICK_COLUMNS; j++)
		{
			brick[i][j] = brick[i][j].setBrick(20 + i * brick[i][j].BRICK_WIDTH, j * brick[i][j].BRICK_HEIGHT, 0, 0, brick[i][j].BRICK_WIDTH, brick[i][j].BRICK_HEIGHT);
		}
	}
}