all:
	g++ -Isource\src\SDL2\include\SDL2 \
	    -Isource\src\SDL2_img\include\SDL2 \
	    -Isource\src\SDL2_ttf\include\SDL2 \
	    -Isource\src\SDL2_mixer\include\SDL2 \
	    -Lsource\src\SDL2\lib \
	    -Lsource\src\SDL2_img\lib \
	    -Lsource\src\SDL2_ttf\lib \
	    -Lsource\src\SDL2_mixer\lib \
	    -o main \
	    source\BrickGameProject\src\Entities\Paddle\Paddle.cpp \
	    source\BrickGameProject\src\GraphicsModule\LTexture.cpp \
	    source\BrickGameProject\src\GraphicsModule\GraphicsManager.cpp \
	    source\BrickGameProject\src\GraphicsModule\main.cpp \
	    -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
