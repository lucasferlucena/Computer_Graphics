#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	std::vector<int> red = {255,0,0,0};
	std::vector<int> green = {0,255,0,0};
	std::vector<int>  blue = {0,0,255,0};
	std::vector<int> white = {255,255,255,0};

	int x = 0, y = 0;
/*
	for(int k = 0; k < IMAGE_WIDTH*IMAGE_HEIGHT-1; k++){
		if(x < IMAGE_WIDTH){
			if(x%6 == 0 && y%6 == 0){
				if(x < IMAGE_WIDTH/2 && y < IMAGE_HEIGHT/2)
					PutPixel(x,y,red);
				if(x >= IMAGE_WIDTH/2 && y < IMAGE_HEIGHT/2)
					PutPixel(x,y,blue);
				if(x < IMAGE_WIDTH/2 && y >= IMAGE_HEIGHT/2)
					PutPixel(x,y,green);
				if(x >= IMAGE_WIDTH/2 && y >= IMAGE_HEIGHT/2)
					PutPixel(x,y,white);
			}
			x++;
		}
		else{
			x = 0;
			y++;
		}
	}*/

	int x0 = 0;
	while(x0 <= 512){	

		DrawLine(0 + x0, 0, 512 - x0, 512, red, blue);
		DrawLine(0, 0 + x0, 512, 512 - x0, red, blue);
		//DrawLine(512 - x0, 512,0 + x0, 0, red, blue);
		//DrawLine(512, 512 - x0, 0, 0 + x0, green, blue);

		x0 += 32;
	}

	//DrawTriangle(256, 100, 400, 300, 112, 300, red, blue, green);
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}