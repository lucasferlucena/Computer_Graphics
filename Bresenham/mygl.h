#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <vector>
#include <math.h>      
//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************
float LineSize(int x0, int y0, int x1, int y1){
	return pow((pow((x1 - x0), 2) + pow((y1 - y0), 2.0)), 0.5);
}

std::vector<int> interpolate(std::vector<int> color0, std::vector<int> color1, float tamanhoTotal, float tamanhoParcial)
{	
	std::vector<int> color{0,0,0,0};

	double t = tamanhoParcial/tamanhoTotal;

	color[0] = color0[0]*(1 - t) + color1[0]*t;
	color[1] = color0[1]*(1 - t) + color1[1]*t;
	color[2] = color0[2]*(1 - t) + color1[2]*t;

	
    return color;
}

void PutPixel(int xPosition, int yPosition, std::vector<int> color){
	for(int i = 0; i < 4; i++){
		FBptr[xPosition*4+i + yPosition*4*IMAGE_WIDTH] = color.at(i);
	}
}


void DrawLine(int x0, int y0, int x1, int y1, std::vector<int> color0, std::vector<int> color1) {
	int swap_axis = 0, swap_i_f = 0;
	float line_size = LineSize(x0, y0, x1, y1);

	std::vector<int> color;

	int dx = (x1 - x0);
	int dy = (y1 - y0);

	if(dx * dy < 0) {
		if(x0 > x1) {
			std::swap(x0, x1);
			std::swap(y0, y1);
			swap_i_f = 1;
		}

		dx = std::abs(dx);
		dy = std::abs(dy);
		 
 		if(dy  > dx) {
			std::swap(x0,y0);
			std::swap(x1,y1);
			std::swap(dx,dy);
			swap_axis = 1;
		}

		int x = x0;
		int y = y0;

		int d = 2 * dy - dx;
		int incr_e = 2 * dy;
		int incr_ne = 2 * (dy - dx);

		color = swap_i_f|| swap_i_f && swap_axis ? interpolate(color1, color0, line_size, LineSize(x0, y0, x, y)) : interpolate(color0, color1, line_size, LineSize(x0, y0, x, y));
		swap_axis ? PutPixel(y, x, color) : PutPixel(x, y, color);

		while (!swap_axis && (x < x1) || swap_axis && ( x1 < x)) {
			if (d <= 0) {
				d += incr_e;
				swap_axis ? x-- : x++;
			} else {
				d += incr_ne;
				swap_axis ? x-- : x++;
				swap_axis ? y++ : y--;
			}
			color = swap_i_f|| swap_i_f && swap_axis ? interpolate(color1, color0, line_size, LineSize(x0, y0, x, y)) : interpolate(color0, color1, line_size, LineSize(x0, y0, x, y));
			swap_axis ? PutPixel(y, x, color) : PutPixel(x, y, color);	
		}
	}
	else {
		dx = std::abs(dx);
		dy = std::abs(dy);
		
		if(dy  > dx) {
			std::swap(x0,y0);
			std::swap(x1,y1);
			std::swap(dx,dy);
			swap_axis = 1;
		}

		if(x0 > x1) {
			std::swap(x0, x1);
			std::swap(y0, y1);
			swap_i_f = 1;
		}

		int x = x0;
		int y = y0;

		int d = 2 * dy - dx;
		int incr_e = 2 * dy;
		int incr_ne = 2 * (dy - dx);


		color = swap_i_f ? interpolate(color1, color0, line_size, LineSize(x0, y0, x, y)) : interpolate(color0, color1, line_size, LineSize(x0, y0, x, y));
		swap_axis ? PutPixel(y, x, color) : PutPixel(x, y, color);

		while (x < x1) {
			if (d <= 0) {
				d += incr_e;
				x++;
			} else {
				d += incr_ne;
				x++;
				y++;
			}
			color = swap_i_f ? interpolate(color1, color0, line_size, LineSize(x0, y0, x, y)) : interpolate(color0, color1, line_size, LineSize(x0, y0, x, y));
			swap_axis ? PutPixel(y, x, color) : PutPixel(x, y, color);	
		}
	}
}

void DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, std::vector<int> color0, std::vector<int> color1, std::vector<int> color2){
	DrawLine(x0,y0, x1, y1, color0, color1);
	DrawLine(x1,y1, x2, y2, color1, color2);
	DrawLine(x2, y2, x0, y0, color2, color0);
}


#endif // _MYGL_H_

