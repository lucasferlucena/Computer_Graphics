#include "main.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/norm.hpp>

using namespace glm;
using namespace std;

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	vector<int> color[4] = {
							{255,0,0,0},
							{0,255,0,0},
							{0,0,255,0},
							{255,255,255,0}
};
	std::vector<int> red = {255,0,0,0};
	std::vector<int> green = {0,255,0,0};
	std::vector<int>  blue = {0,0,255,0};
	std::vector<int> white = {255,255,255,0};
	
	//vertices do quadrado

    vec4 v_obj[8];
    v_obj[0] = vec4(-1, -1, -1, 1);
    v_obj[1] = vec4(-1, -1,  1, 1);
    v_obj[2] = vec4( 1, -1, -1, 1);
    v_obj[3] = vec4( 1, -1,  1, 1);
    v_obj[4] = vec4(-1,  1, -1, 1);
    v_obj[5] = vec4(-1,  1,  1, 1);
    v_obj[6] = vec4( 1,  1, -1, 1);
    v_obj[7] = vec4( 1,  1,  1, 1);

    //arestas do quaadrado
    int aresta[12][2] = {
    {1,0},    {2,0},    {1,3},    {2,3},    //base
    {4,5},    {4,6},    {7,5},    {7,6},    //topo
    {4,0},    {1,5},    {2,6},    {7,3}     //verticais
    };

    //matriz model
    mat4 Model = mat4(1);

    //parametros da camera
    vec3 camera_pos      =  vec3(1.3,2.1,2.5);  
    vec3 camera_lookat   =  vec3(0,0,0);
    vec3 camera_up       =  vec3(0,1,0);
    
    //sistema ortogonal
    vec3 camera_dir     = camera_lookat - camera_pos;
   
    vec3 z_camera       = -(camera_dir)/l2Norm(camera_dir);
    vec3 x_camera       = cross(camera_up, z_camera)/l2Norm(cross(camera_up, z_camera));
    vec3 y_camera       = cross(z_camera, x_camera);

    //Construção matriz view
    float f_Bt[16]=
    {
      x_camera[0], x_camera[1], x_camera[2], 0,
      y_camera[0], y_camera[1], y_camera[2], 0,
      z_camera[0], z_camera[1], z_camera[2], 0,
      0,0,0,1
    };

    float f_T[16]=
    {
      1, 0, 0, -camera_pos[0],
      0, 1, 0, -camera_pos[1],
      0, 0, 1, -camera_pos[2],
      0, 0, 0, 1
    };

    mat4 Bt = make_mat4(f_Bt);
    mat4 T  = make_mat4(f_T);
    mat4 View = T*Bt;

    //Matriz Projeção
    float d = 1;
    float f_Proj[16] = 
    {
        1,0,0,0,
        0,1,0,0,
        0,0,1,d,
        0,0,-1/d,0
    };

    mat4 Projection = make_mat4(f_Proj);

    //Matriz ModelViewProjection
    mat4 ModelViewProjection = Model*View*Projection;

    vec4 v_clip[8];

    for(int i = 0; i < 8; i++){
        v_clip[i] = v_obj[i]*ModelViewProjection;
    }

    //Homogenização
    vec4 v_canonic[8];

    for(int i = 0; i < 8; i++){
        v_canonic[i] = v_clip[i]/v_clip[i][3];
    }

    //Conversao para o espaço de tela
    float f_s1[16] = {1, 0, 0, 0,
                      0,-1, 0 ,0,
                      0, 0, 1, 0,
                      0, 0, 0, 1};
    mat4 S1 = make_mat4(f_s1);

    float f_trans[16] = {1, 0, 0, 1,
                         0, 1, 0 ,1,
                         0, 0, 1, 0,
                         0, 0, 0, 1};
    mat4 Translation = make_mat4(f_trans);

    float f_s2[16] = {(IMAGE_WIDTH-1)/2, 0, 0, 0,
                       0,(IMAGE_HEIGHT-1)/2, 0 ,0,
                       0, 0, 1, 0,
                       0, 0, 0, 1};
    mat4 S2 = make_mat4(f_s2);

    mat4 ViewPort = S1*Translation*S2;

    vec4 v_screen[8];

    for(int i = 0; i < 8; i++){
        v_screen[i] = v_canonic[i]*ViewPort;
    }

	int i_v_screen[8][2]={
		{(int)v_screen[0][0],(int)v_screen[0][1]},
		{(int)v_screen[1][0],(int)v_screen[1][1]},
		{(int)v_screen[2][0],(int)v_screen[2][1]},
		{(int)v_screen[3][0],(int)v_screen[3][1]},
		{(int)v_screen[4][0],(int)v_screen[4][1]},
		{(int)v_screen[5][0],(int)v_screen[5][1]},
		{(int)v_screen[6][0],(int)v_screen[6][1]},
		{(int)v_screen[7][0],(int)v_screen[7][1]}
	};

	for(int i = 0; i < 12; i ++){
		DrawLine(i_v_screen[aresta[i][0]][0],i_v_screen[aresta[i][0]][1],i_v_screen[aresta[i][1]][0],i_v_screen[aresta[i][1]][1],red, blue);
	}
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