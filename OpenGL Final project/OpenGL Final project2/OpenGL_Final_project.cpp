#include<GL/glew.h>
#include <GL/glut.h>
#include"glm.h"
#include <stdlib.h>
#include <stdio.h>
#include<math.h>

#include <mmsystem.h>  //音效用
#pragma comment(lib, "Winmm.lib")

#define STB_IMAGE_IMPLEMENTATION
#include "SOIL.h"
/****************************
Final

******************************/
#define jumpv0 4
#define gravity 0.098*jumpv0
#define up 0
#define down 1
#define pi 3.14159
#define move 0.5
#define Map_Max -1720   //地圖最大值
#define Role_Time 50		//人物跌倒的時間
#define Drop_Time 50		//人物墜落的時間
#define Hrudle_Time 120    //柵欄倒下再站起來的時間
#define Hurdle_Number 146  //柵欄的數量
#define Drop_Number 21  //掉落陷阱的數量
#define accerlatenum 60
#define animetionnum 2
#define energyv0 0.2
#define endfloordepth 20 
#define hurdelx 10.8
#define hurdely 5.6
#define hurdelz 5
#define stonex 10
#define stoney 10
#define stonez 10
#define stonetexwide 3
#define endboxw 35
#define floorhigh -4.8
#define stonenum 80
#define mode4positiony -300
#define shakeL pi
#define shakeM 5
#define anglestart 40

float accerlatemap[accerlatenum][3] =
{ { 0.0,floorhigh,-260 },{ 0.0,floorhigh,-320 },{ 5.0,floorhigh,-360 },{ 5.0,floorhigh,-410 }
,{ 25.0,floorhigh,-450 },{ -25.0,floorhigh,-450 }
,{ -10.0,floorhigh,-480 },{ 10.0,floorhigh,-480 }
,{ -25.0,floorhigh,-520 },{ -20.0,floorhigh,-520 },{ 20.0,floorhigh,-520 },{ 25.0,floorhigh,-520 }
,{ -25.0,floorhigh,-970 },{ -20.0,floorhigh,-970 },{ -15.0,floorhigh,-970 },{ -10.0,floorhigh,-970 }
,{ 25.0,floorhigh,-970 },{ 20.0,floorhigh,-970 },{ 15.0,floorhigh,-970 },{ 10.0,floorhigh,-970 }    // 20
,{ 25.0,floorhigh,-1050 },{ 20.0,floorhigh,-1050 },{ 15.0,floorhigh,-1050 },{ 10.0,floorhigh,-1050 }
,{ -25.0,floorhigh,-1050 },{ -20.0,floorhigh,-1050 },{ -15.0,floorhigh,-1050 },{ -10.0,floorhigh,-1050 }
,{ 0.0,floorhigh,-970 },{ 0.0,floorhigh,-1050 },{ -5.0,floorhigh,-1050 },{ 5.0,floorhigh,-1050 }
,{ 0.0,floorhigh,-970 },{ 5.0,floorhigh,-970 },{ -5.0,floorhigh,-970 },{ 0.0,floorhigh,-1090 }
,{ 25.0,floorhigh,-1140 },{ 20.0,floorhigh,-1140 },{ 15.0,floorhigh,-1140 },{ 10.0,floorhigh,-1140 }  //40
,{ -25.0,floorhigh,-1140 },{ -20.0,floorhigh,-1140 },{ -15.0,floorhigh,-1140 },{ -10.0,floorhigh,-1140 } 
,{ 10,floorhigh,-1250 },{ 15.0,floorhigh,-1250 },{ 20.0,floorhigh,-1250 },{ 25.0,floorhigh,-1250 }
,{ 10,floorhigh,-1360 },{ 15.0,floorhigh,-1360 },{ 20.0,floorhigh,-1360 },{ 25.0,floorhigh,-1360 }
,{ 10,floorhigh,-1470 },{ 15.0,floorhigh,-1470 },{ 20.0,floorhigh,-1470 },{ 25.0,floorhigh,-1470 }
,{ -10,floorhigh,-1470 },{ -15.0,floorhigh,-1470 },{ -20.0,floorhigh,-1470 },{ -25.0,floorhigh,-1470 } //60
};


float stonemap[stonenum][3] =
{ 
 { 0.0,30,-90.0 },{ 0.0,30,-100 },{ 0.0,30,-110 } ,{ 0.0,0.0,-75.0 }
,{ 0.0,0.0,-125.0 },{ 0.0,0.0,-135.0 },{ 0.0,0.0,-145.0 },{ 0.0,0.0,-165.0 }
,{ 0.0,20,-190 },{ 0.0,20,-210 },{ 0.0,0.0,-220 },{ 0.0,0.0,-230 }
,{ 0.0,0.0,-260 },{ 0.0,0.0,-300 },{ 5.0,0.0,-340 },{ 5,0.0,-380 }
,{ 5.0,0.0,-400 },{ 0.0,0.0,-460 },{ -10.0,0.0,-490 },{ 10.0,0.0,-490 }
,{ 15,0.0,-510 },{ -15,0.0,-510 },{ -20,0.0,-540 },{ 20.0,0.0,-540 }
,{ -15,0.0,-570 },{ 15,0.0,-570 },{ 0.0,0.0,-600 },{ 0.0,0.0,-610 }
,{ 0.0,0.0,-620 },{ 15,0.0,-640 },{ 15,0.0,-650 },{ -15,0.0,-650 }
,{ -15,0.0,-660 },{ 0.0,0.0,-680 },{ 0.0,0.0,-690 },{ 0.0,0.0,-700 }

,{ -7.0,20,-720 },{ -8.0,20,-730 },{ -15,0.0,-750 },{ 0.0,0.0,-760 }   //--------->40
,{ -15,0.0,-810 },{ 0.0,0.0,-820 }
,{ 0.0,0.0,-830 },{ 0.0,0.0,-840 },{ -20,0.0,-880 },{ -20,0.0,-890 }
,{ -20,0.0,-880 },{ -20,0.0,-890 },{ -20,0.0,-900 },{ -20,0.0,-910 }
,{ 17.5,20.0,-1260 },{ 17.5,20,-1370 }
,{ 17.5,20.0,-1180.0 },{ 17.5,20.0,-1190 },{ 17.5,20.0,-1200 },{ 17.5,20,-1210 }
,{ 17.5,20.0,-1290.0 },{ 17.5,20.0,-1300.0 },{ 17.5,20.0,-1310 },{ 17.5,20,-1320 }  // 60
,{ 17.5,20.0,-1400 },{ 17.5,20.0,-1410 },{ 17.5,20.0,-1420 },{ 17.5,20,-1430 }   
,{ 17.5,0.0,-990 },{ 17.5,0.0,-1000 },{ 17.5,0.0,-1010 },{ 17.5,0,-1020 }
,{ -17.5,0.0,-990 },{ -17.5,0.0,-1000 },{ -17.5,0.0,-1010 },{ -17.5,0,-1020 }
,{ 17.5,0.0,-1070 },{ 17.5,0.0,-1080 },{ 17.5,0.0,-1090 },{ 17.5,0,-1100 }
,{ -17.5,0.0,-1070 },{ -17.5,0.0,-1080 },{ -17.5,0.0,-1090 },{ -17.5,0,-1100 }   //80
};


float doorposition[3] = { 0.0,0.0,Map_Max };
float doorpositionR[3] = { -10.0,0.0,Map_Max };
float doorpositionL[3] = { 10.0,0.0,Map_Max };
int keystates[256] = { up };
GLint list_id, rock_id;
GLint fogMode;
GLuint Hurdel_list;  // 柵欄的list
int drop_index;   // 掉進哪一個岩漿坑

int select = 0;  //選單中正在選第幾個
int mode = 0;
//  mode =  (0 = 主畫面 ) 
//          ( 11 = 教學part1 最後會開始遊戲 )   (12 = 教學part2)  ...  (16 = 教學結束 準備進入遊戲的畫面) 
//          ( 21 = 教學part1 最後會回主選單 )   (22 = 教學part2)   ... 
//          ( 3 = gameing )  ( 31 = game中 按下選單 一切會暫停並跳出選單 ) (35=角色進門)
//          ( 4 = gameending )

float DROP = 0;
// load 
int width, height, nrChannels;
int drop_down = 0;
int open = 1;
unsigned char *data;

unsigned int texture;
int m = 0;

struct obj {
	bool isappear = true;
	float x, y, z;
	float MaxX, MaxY, MaxZ;
	float MinX, MinY, MinZ;
	float length, width, hight; //長寬高

};

struct obj role;
struct obj Wall;
struct obj door;
struct obj Hurdle[Hurdle_Number];
struct obj Drop[Drop_Number];
struct obj accerlate[accerlatenum];
struct obj stone[stonenum];
int CHARACTER_ACTION = 0, jumpcnt = 0, CHARACTET_BURST = 0, burstcnt = 0, animetion = 0, animetiontimecnt = 0, endtimecnt = 0;
int stonecnt = 0;
bool fullscreen = false;
bool charactetismoving = false, jumpmusicisopen = false;
float X = 0, Y = 0, Z = 0;
float angleRL = 0, angleTD = anglestart, rolefaceangle = 0, shaketimecnt = 0.0;
float shake = 0.0;
float cameradistant = 15.0;
int Hurdle_down[Hurdle_Number] = { 0 };
int role_down = 0;
GLuint texName, runway_id, wall_id, wall2_id, green_id, iava_id, index_id[7], doorleft_id, doorright_id, endwall_id, runner, menu_id, accerlate_id
, stoneframe_id, stonevol_id, stone_id, colormap_id, flash_id, summon_id, night_id, midlighting_id;
GLuint gudako[3] = { 0 ,0,0 }, astorufo[5] = { 0,0,0,0,0 };
GLfloat energy = 20.0, accerlate_spin = 0.0, stonespin = 0.0, flashspin = 0, summonspin = 0.0, summonscale = 0.0, summonmidlightscale = 0.0;


void index_material()
{
	GLfloat floor_ambient[] = { 0.5,0.5,0.5,0.5 };
	GLfloat floor_diffuse[] = { 1.0, 1.0, 1.0 ,1.0 };
	GLfloat floor_specular[] = { 1.0,1.0,1.0 ,0.5 };
	GLfloat floor_high_shininess[] = { 10 };
	GLfloat floor_emission[] = { 0.9, 0.9, 0.9, 0.5 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, floor_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, floor_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, floor_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, floor_high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, floor_emission);
}
void lava_material()
{
	GLfloat floor_ambient[] = { 0.5,0.5,0.5,0.5 };
	GLfloat floor_diffuse[] = { 1.0, 1.0, 1.0 ,1.0 };
	GLfloat floor_specular[] = { 1.0,0.3,0.3 ,0.5 };
	GLfloat floor_high_shininess[] = { 10 };
	GLfloat floor_emission[] = { 0.9, 0.3, 0.3, 0.5 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, floor_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, floor_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, floor_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, floor_high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, floor_emission);
}
void accerlate_material()
{
	GLfloat ambient[] = { 0.5,0.5,0.8,0.5 };
	GLfloat diffuse[] = { 0.0, 0.0, 1.0 ,1.0 };
	GLfloat specular[] = { 0.3,0.3,0.8 ,0.5 };
	GLfloat high_shininess[] = { 10 };
	GLfloat emission[] = { 0.4, 0.4, 0.8, 0.8 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
}
void floor_material()
{
	GLfloat floor_ambient[] = { 0.8,0.8,0.8,1.0 };
	GLfloat floor_diffuse[] = { 0.6, 0.6, 0.6 ,1.0 };
	GLfloat floor_specular[] = { 0.2,0.2,0.2 ,0.8 };
	GLfloat floor_high_shininess[] = { 100 };
	GLfloat floor_emission[] = { 0.5, 0.5, 0.5, 0.5 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, floor_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, floor_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, floor_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, floor_high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, floor_emission);
}
void role_material()
{
	GLfloat floor_emission[] = { 0.1, 0.1, 0.1, 1.0 };
	glMaterialfv(GL_FRONT, GL_EMISSION, floor_emission);
}
void hud_material()
{
	GLfloat floor_ambient[] = { 1.0,1.0,1.0,1.0 };
	GLfloat floor_diffuse[] = { 1.0, 1.0, 1.0 ,1.0 };
	GLfloat floor_specular[] = { 1.0,0.3,0.3 ,0.5 };
	GLfloat floor_high_shininess[] = { 10 };
	GLfloat floor_emission[] = { 0.6, 0.3, 0.3, 0.5 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, floor_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, floor_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, floor_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, floor_high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, floor_emission);
}
void frame_material()
{
	GLfloat ambient[] = { 1.0,1.0,1.0,1.0 };
	GLfloat diffuse[] = { 0.0,0.0,0.0,1.0 };
	GLfloat specular[] = { 1.0,1.0,1.0,1.0 };
	GLfloat high_shininess[] = { 10 };
	GLfloat emission[] = { 0.0,0.0,0.0,1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
}
void loadingtex()
{
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/runway.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &runway_id);
		glBindTexture(GL_TEXTURE_2D, runway_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/wall1.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &wall_id);
		glBindTexture(GL_TEXTURE_2D, wall_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}


	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/green.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &green_id);
		glBindTexture(GL_TEXTURE_2D, green_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}

	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/ENERGY.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &texName);
		glBindTexture(GL_TEXTURE_2D, texName);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}

	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/accerlate.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &accerlate_id);
		glBindTexture(GL_TEXTURE_2D, accerlate_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/lava.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &iava_id);
		glBindTexture(GL_TEXTURE_2D, iava_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}

	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/index.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &(index_id[0]));
		glBindTexture(GL_TEXTURE_2D, (index_id[0]));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/tour.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &(index_id[1]));
		glBindTexture(GL_TEXTURE_2D, (index_id[1]));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}

	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/tour2.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &(index_id[2]));
		glBindTexture(GL_TEXTURE_2D, (index_id[2]));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/tour3.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &(index_id[3]));
		glBindTexture(GL_TEXTURE_2D, (index_id[3]));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/tour4.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &(index_id[4]));
		glBindTexture(GL_TEXTURE_2D, (index_id[4]));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/tour5.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &(index_id[5]));
		glBindTexture(GL_TEXTURE_2D, (index_id[5]));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/tour_end.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &(index_id[6]));
		glBindTexture(GL_TEXTURE_2D, (index_id[6]));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/e.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &runner);
		glBindTexture(GL_TEXTURE_2D, runner);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/menu.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &menu_id);
		glBindTexture(GL_TEXTURE_2D, menu_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/doorright.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &doorright_id);
		glBindTexture(GL_TEXTURE_2D, doorright_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/doorleft.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &doorleft_id);
		glBindTexture(GL_TEXTURE_2D, doorleft_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/wall2.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &endwall_id);
		glBindTexture(GL_TEXTURE_2D, endwall_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/frame.png", &width, &height, 0, SOIL_LOAD_RGBA);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &stoneframe_id);
		glBindTexture(GL_TEXTURE_2D, stoneframe_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/colorall.png", &width, &height, 0, SOIL_LOAD_RGBA);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &stonevol_id);
		glBindTexture(GL_TEXTURE_2D, stonevol_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/Saintquartz.png", &width, &height, 0, SOIL_LOAD_RGBA);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &stone_id);
		glBindTexture(GL_TEXTURE_2D, stone_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/colormap.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &colormap_id);
		glBindTexture(GL_TEXTURE_2D, colormap_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/flash.png", &width, &height, 0, SOIL_LOAD_RGBA);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &flash_id);
		glBindTexture(GL_TEXTURE_2D, flash_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/summon.png", &width, &height, 0, SOIL_LOAD_RGBA);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &summon_id);
		glBindTexture(GL_TEXTURE_2D, summon_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/fgonight.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &night_id);
		glBindTexture(GL_TEXTURE_2D, night_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/wall2.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &wall2_id);
		glBindTexture(GL_TEXTURE_2D, wall2_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/midlighting.png", &width, &height, 0, SOIL_LOAD_RGBA);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &midlighting_id);
		glBindTexture(GL_TEXTURE_2D, midlighting_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/astorufo/astorufo0.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &astorufo[0]);
		glBindTexture(GL_TEXTURE_2D, astorufo[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/astorufo/astorufo1.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &astorufo[1]);
		glBindTexture(GL_TEXTURE_2D, astorufo[1]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/astorufo/astorufo2.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &astorufo[2]);
		glBindTexture(GL_TEXTURE_2D, astorufo[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/astorufo/astorufo3.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &astorufo[3]);
		glBindTexture(GL_TEXTURE_2D, astorufo[3]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	{
		int width, height;
		unsigned char* image =
			SOIL_load_image("res/tex/astorufo/astorufo4.png", &width, &height, 0, SOIL_LOAD_RGB);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &astorufo[4]);
		glBindTexture(GL_TEXTURE_2D, astorufo[4]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
}
void loading()
{
	{
		GLMmodel *glm_model;
		glm_model = glmReadOBJ("res/model/gudakoactionRS.obj");
		glmUnitize(glm_model);
		glmScale(glm_model, 5.0);
		glmFacetNormals(glm_model);
		glmVertexNormals(glm_model, 90);
		gudako[1] = glmList(glm_model, GLM_SMOOTH | GLM_MATERIAL);
		glmDelete(glm_model);
	}
	{
		GLMmodel *glm_model;
		glm_model = glmReadOBJ("res/model/gudakoactionLS.obj");
		glmUnitize(glm_model);
		glmScale(glm_model, 5.0);
		glmFacetNormals(glm_model);
		glmVertexNormals(glm_model, 90);
		gudako[0] = glmList(glm_model, GLM_SMOOTH | GLM_MATERIAL);
		glmDelete(glm_model);
	}
	{
		GLMmodel *glm_model;
		glm_model = glmReadOBJ("res/model/gudakohandsup.obj");
		glmUnitize(glm_model);
		glmScale(glm_model, 5.0);
		glmFacetNormals(glm_model);
		glmVertexNormals(glm_model, 90);
		gudako[2] = glmList(glm_model, GL_SMOOTH | GLM_MATERIAL);
		glmDelete(glm_model);
	}
}

void set_box(obj &a, float maxx, float minx, float maxy, float miny, float maxz, float minz) {
	a.MaxX = maxx;
	a.MinX = minx;
	a.MaxY = maxy;
	a.MinY = miny;
	a.MaxZ = maxz;
	a.MinZ = minz;

}
void set_xyz(obj &a, float x, float y, float z, float l, float w, float h) { //xyz長寬高

	a.x = x;
	a.y = y;
	a.z = z;
	//順便把box設好
	a.length = l;
	a.width = w;
	a.hight = h;
	set_box(a, a.x + (l / 2), a.x - (l / 2), a.y + (w / 2), a.y - (w / 2), a.z + (h / 2), a.z - (h / 2));

}
void set_Hurdel() {
	GLfloat floor_ambient[] = { 1.0,1.0,1.0,1.0 };
	GLfloat floor_ambient2[] = { 1.0,0.0,0.0,1.0 };
	GLfloat floor_diffuse[] = { 0.6, 0.6, 0.5 ,1.0 };
	GLfloat floor_specular[] = { 0.2,0.2,0.2 ,0.8 };
	GLfloat floor_high_shininess[] = { 100 };
	GLfloat floor_emission[] = { 0.2, 0.2, 0.2, 0.2 };
	GLfloat floor_emission2[] = { 0.6, 0.1, 0.1, 0.2 };
	int j = 0;
	for (int i = 0; i < 10; i++) {

		set_xyz(Hurdle[i], -22.5 + ((5.2)*(i % 10)), 2, (-20), hurdelx, hurdely, hurdelz);  //設定柵欄位置 & 長寬高  (包含設置box)
	}
	for (int i = 10; i < 20; i++) {

		set_xyz(Hurdle[i], -22.5 + ((5.2)*(i % 10)), 2, (-30), hurdelx, hurdely, hurdelz);  //設定柵欄位置 & 長寬高  (包含設置box)
	}
	for (int i = 20; i < 30; i++) {

		set_xyz(Hurdle[i], -22.5 + ((5.2)*(i % 10)), 2, (-40), hurdelx, hurdely, hurdelz);  //設定柵欄位置 & 長寬高  (包含設置box)
	}
	for (int i = 30; i < 40; i++) {

		set_xyz(Hurdle[i], -22.5 + ((5.2)*(i % 10)), 2, (-60), hurdelx, hurdely, hurdelz);  //設定柵欄位置 & 長寬高  (包含設置box)
	}
	for (int i = 40; i < 50; i++) {

		set_xyz(Hurdle[i], -22.5 + ((5.2)*(i % 10)), 2, (-90), hurdelx, hurdely, hurdelz);  //設定柵欄位置 & 長寬高  (包含設置box)
	}
	for (int i = 50; i < 60; i++) {

		set_xyz(Hurdle[i], -22.5 + ((5.2)*(i % 10)), 2, (-100), hurdelx, hurdely, hurdelz);  //設定柵欄位置 & 長寬高  (包含設置box)
	}
	for (int i = 60; i < 70; i++) {

		set_xyz(Hurdle[i], -22.5 + ((5.2)*(i % 10)), 2, (-110), hurdelx, hurdely, hurdelz);  //設定柵欄位置 & 長寬高  (包含設置box)
	}
	for (int i = 70; i < 80; i++) {

		set_xyz(Hurdle[i], -22.5 + ((5.2)*(i % 10)), 2, (-130), hurdelx, hurdely, hurdelz);  //設定柵欄位置 & 長寬高  (包含設置box)
	}
	for (int i = 80; i < 90; i++) {

		set_xyz(Hurdle[i], -22.5 + ((5.2)*(i % 10)), 2, (-150), hurdelx, hurdely, hurdelz);  //設定柵欄位置 & 長寬高  (包含設置box)
	}
	for (int i = 90; i < 100; i++) {

		set_xyz(Hurdle[i], -22.5 + ((5.2)*(i % 10)), 2, (-170), hurdelx, hurdely, hurdelz);  //設定柵欄位置 & 長寬高  (包含設置box)
	}
	for (int i = 100; i < 110; i++) {

		set_xyz(Hurdle[i], -22.5 + ((5.2)*(i % 10)), 2, (-190), hurdelx, hurdely, hurdelz);  //設定柵欄位置 & 長寬高  (包含設置box)
	}
	for (int i = 110; i < 120; i++) {

		set_xyz(Hurdle[i], -22.5 + ((5.2)*(i % 10)), 2, (-200), hurdelx, hurdely, hurdelz);  //設定柵欄位置 & 長寬高  (包含設置box)
	}
	for (int i = 120; i < 130; i++) {

		set_xyz(Hurdle[i], -22.5 + ((5.2)*(i % 10)), 2, (-210), hurdelx, hurdely, hurdelz);  //設定柵欄位置 & 長寬高  (包含設置box)
	}
	for (int i = 130, j = 2; i < 136; i++, j++) {

		set_xyz(Hurdle[i], -22.5 + ((5.2)*(j % 10)), 2, (-440), hurdelx, hurdely, hurdelz);
	}
	for (int i = 136, j = 0; i < 139; i++, j++) {

		set_xyz(Hurdle[i], -22.5 + ((5.2)*(j % 10)), 2, (-490), hurdelx, hurdely, hurdelz);
	}
	for (int i = 139, j = 7; i < 142; i++, j++) {

		set_xyz(Hurdle[i], -22.5 + ((5.2)*(j % 10)), 2, (-490), hurdelx, hurdely, hurdelz);
	}
	for (int i = 142, j = 3; i < 146; i++, j++) {

		set_xyz(Hurdle[i], -22.5 + ((5.2)*(j % 10)), 2, (-520), hurdelx, hurdely, hurdelz);
	}
	Hurdel_list = glGenLists(1);
	glNewList(Hurdel_list, GL_COMPILE);
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, floor_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, floor_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, floor_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, floor_high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, floor_emission);
	glTranslatef(0, 1.5, 0);  // 中橫桿
	glColor3f(1, 1, 1);
	glScalef(4, 0.5, 0.5);
	glutSolidCube(1.0);
	glutWireCube(1.0);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(2.25, 0, 0);  // 右桿 
	glColor3f(1, 1, 1);
	glScalef(0.5, 5, 0.5);
	glutSolidCube(1.0);
	glutWireCube(1.0);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-2.25, 0, 0);  // 左桿 
	glColor3f(1, 1, 1);
	glScalef(0.5, 5, 0.5);
	glutSolidCube(1.0);
	glutWireCube(1.0);
	glPopMatrix();



	glPushMatrix();

	glMaterialfv(GL_FRONT, GL_AMBIENT, floor_ambient2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, floor_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, floor_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, floor_high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, floor_emission2);
	glTranslatef(0, 2.75, 0);  // 最高的橫桿 
	glColor3f(1, 1, 0);
	glScalef(5, 0.5, 0.5);
	glutSolidCube(1.0);
	glutWireCube(1.0);
	glPopMatrix();

	glEndList();
}
void set_lava() {
	set_xyz(Drop[0], -15, 0, (-330), 20, 5.3, 170);  //設定柵欄位置 & 長寬高  (包含設置box)
	set_xyz(Drop[1], -2.5, 0, (-385), 5, 5.3, 60);
	set_xyz(Drop[2], 5, 0, (-285), 5, 5.3, 80);
	set_xyz(Drop[3], 17.5, 0, (-330), 20, 5.3, 170);

	set_xyz(Drop[4], -17.5, 0, (-615), 20, 5.3, 40);
	set_xyz(Drop[5], 0, 0, (-645), 15, 5.3, 40);
	set_xyz(Drop[6], 17.5, 0, (-610), 20, 5.3, 30);
	set_xyz(Drop[7], -17.5, 0, (-705), 20, 5.3, 60);
	set_xyz(Drop[8], 0, 0, (-755), 15, 5.3, 80);
	set_xyz(Drop[9], 20, 0, (-755), 15, 5.3, 190);
	set_xyz(Drop[10], -20, 0, (-820), 15, 5.3, 80);
	set_xyz(Drop[11], 0, 0, (-900), 15, 5.3, 90);
	set_xyz(Drop[12], -20, 0, (-935), 15, 5.3, 20);
	set_xyz(Drop[13], 20, 0, (-925), 15, 5.3, 40);
	set_xyz(Drop[14], -10, 0, (-860), 5, 5.3, 170);
	set_xyz(Drop[15], 10, 0, (-800), 5, 5.3, 290);
	set_xyz(Drop[16], 0, 0, (-1190), 50, 5.3, 50);
	set_xyz(Drop[17], 15, 0, (-1290), 20, 5.3, 50);
	set_xyz(Drop[18], 15, 0, (-1300), 20, 5.3, 50);
	set_xyz(Drop[19], 15, 0, (-1410), 20, 5.3, 50);
	set_xyz(Drop[20], -10, 0, (-1330), 30, 5.3, 230);
}

void restart()
{
	for (int i = 0; i < stonenum; i++)
	{
		stone[i].isappear = true;
	}
	role.x = 0.0;
	role.y = 0.0;
	role.z = 0.0;
	angleRL = 0;
	angleTD = anglestart;
	rolefaceangle = 0;
	flashspin = 0;
	doorpositionL[0] = 10;
	doorpositionR[0] = -10;
	open = 1;
	CHARACTER_ACTION = 0;
	CHARACTET_BURST = 0;
	charactetismoving = false;
	cameradistant = 15.0;
	jumpcnt = 0, burstcnt = 0, animetion = 0, animetiontimecnt = 0, endtimecnt = 0;
	summonspin = 0.0, summonscale = 0.0;  select = 0;  m = 0, stonecnt = 0; shaketimecnt = 0.0;
}

void init(void)
{



	loadingtex();


	//
	set_xyz(role, 0.5, 0, 0, 0, 0, 0);  //設定角色起始位置
	set_Hurdel();
	for (int i = 0; i < accerlatenum; i++)
	{
		set_xyz(accerlate[i], accerlatemap[i][0], accerlatemap[i][1], accerlatemap[i][2], 9.0, 20.0, 10.0);
	}
	for (int i = 0; i < stonenum; i++)
	{
		set_xyz(stone[i], stonemap[i][0], stonemap[i][1], stonemap[i][2], stonex, stoney, stonez);
	}
	set_lava();
	set_box(Wall, 24.5, -24.5, 90, 0.5, 9.5, Map_Max + 5.0);
	set_xyz(door, doorposition[0], doorposition[1], doorposition[2], 90, 90, endfloordepth);




	glShadeModel(GL_SMOOTH);
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat local_view[] = { 0.0 };

	glClearColor(0.5, 0.5, 0.5, 0.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_FOG);
	{
		GLfloat fogColor[4] = { 0.5, 0.5, 0.5, 1.0 };

		fogMode = GL_LINEAR;
		glFogi(GL_FOG_MODE, fogMode);
		glFogfv(GL_FOG_COLOR, fogColor);
		glFogf(GL_FOG_DENSITY, 0.3);
		glHint(GL_FOG_HINT, GL_DONT_CARE);
		glFogf(GL_FOG_START, 70.0);
		glFogf(GL_FOG_END, 100.0);
	}
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
}



void wall(void) {




	//地板
	floor_material();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, runway_id);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-25, -5, 10.0);
	glTexCoord2f(0.0, Map_Max / 100); glVertex3f(-25, -5, Map_Max);
	glTexCoord2f(1.0, Map_Max / 100); glVertex3f(25, -5, Map_Max);
	glTexCoord2f(1.0, 0.0); glVertex3f(25, -5, 10.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//天花板
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall2_id);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-45, 60, 10.0);
	glTexCoord2f(0.0, Map_Max / 100); glVertex3f(-45, 60, Map_Max);
	glTexCoord2f(1.0, Map_Max / 100); glVertex3f(45, 60, Map_Max);
	glTexCoord2f(1.0, 0.0); glVertex3f(45, 60, 10.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//右牆
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall_id);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(45, -5, Map_Max);
	glTexCoord2f(0.0, 1.0); glVertex3f(45, 60, Map_Max);
	glTexCoord2f(Map_Max / 40.0, 1.0); glVertex3f(45, 60, 40.0);
	glTexCoord2f(Map_Max / 40.0, 0.0); glVertex3f(45, -5, 40.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//左牆
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall_id);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-45, -5, Map_Max);
	glTexCoord2f(0.0, 1.0); glVertex3f(-45, 60, Map_Max);
	glTexCoord2f(Map_Max / 40, 1.0); glVertex3f(-45, 60, 40.0);
	glTexCoord2f(Map_Max / 40, 0.0); glVertex3f(-45, -5, 40.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//左草
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, green_id);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-45, -5, 10.0);
	glTexCoord2f(0.0, Map_Max / 10); glVertex3f(-45, -5, Map_Max);
	glTexCoord2f(1.0, Map_Max / 10); glVertex3f(-25, -5, Map_Max);
	glTexCoord2f(1.0, 0.0); glVertex3f(-25, -5, 10.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);


	//右草
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, green_id);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(45, -5, 10.0);
	glTexCoord2f(0.0, Map_Max / 10); glVertex3f(45, -5, Map_Max);
	glTexCoord2f(1.0, Map_Max / 10); glVertex3f(25, -5, Map_Max);
	glTexCoord2f(1.0, 0.0); glVertex3f(25, -5, 10.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);


	//前草
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, green_id);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-45, -5, 40.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-45, -5, 10.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(45, -5, 10.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(45, -5, 40.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//尾牆
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, endwall_id);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-45, -5, Map_Max);
	glTexCoord2f(0.0, 1.0); glVertex3f(-45, 60, Map_Max);
	glTexCoord2f(2.0, 1.0); glVertex3f(45, 60, Map_Max);
	glTexCoord2f(2.0, 0.0); glVertex3f(45, -5, Map_Max);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_MULTISAMPLE_ARB);
	//門r
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, doorright_id);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0); glVertex3f(doorpositionR[0] - 10, doorpositionR[1] - 5, doorpositionR[2] + 0.2);
	glTexCoord2f(1.0, 0.0); glVertex3f(doorpositionR[0] - 10, doorpositionR[1] + 30, doorpositionR[2] + 0.2);
	glTexCoord2f(0.0, 0.0); glVertex3f(doorpositionR[0] + 10, doorpositionR[1] + 30, doorpositionR[2] + 0.2);
	glTexCoord2f(0.0, 1.0); glVertex3f(doorpositionR[0] + 10, doorpositionR[1] - 5, doorpositionR[2] + 0.2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//門l
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, doorleft_id);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0); glVertex3f(doorpositionL[0] - 10, doorpositionL[1] - 5, doorpositionL[2] + 0.2);
	glTexCoord2f(1.0, 0.0); glVertex3f(doorpositionL[0] - 10, doorpositionL[1] + 30, doorpositionL[2] + 0.2);
	glTexCoord2f(0.0, 0.0); glVertex3f(doorpositionL[0] + 10, doorpositionL[1] + 30, doorpositionL[2] + 0.2);
	glTexCoord2f(0.0, 1.0); glVertex3f(doorpositionL[0] + 10, doorpositionL[1] - 5, doorpositionL[2] + 0.2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_MULTISAMPLE_ARB);
	//門內
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, colormap_id);
	glBegin(GL_QUADS);
	glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] - 20, doorposition[1] - 5, doorposition[2] + 0.1);
	glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] - 20, doorposition[1] + 30, doorposition[2] + 0.1);
	glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] + 20, doorposition[1] + 30, doorposition[2] + 0.1);
	glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] + 20, doorposition[1] - 5, doorposition[2] + 0.1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	{//五面盒
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, colormap_id);
		glBegin(GL_QUADS); //down
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] - 50, doorposition[1] - 5.0, doorposition[2] - 0.01);
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] - 50, doorposition[1] - 5.0, doorposition[2] - 50);
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] + 50, doorposition[1] - 5.0, doorposition[2] - 50);
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] + 50, doorposition[1] - 5.0, doorposition[2] - 0.01);
		glEnd();
		glBegin(GL_QUADS);//front
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] - 50, doorposition[1] - 5.0, doorposition[2] - 50);
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] - 50, doorposition[1] + 90, doorposition[2] - 50);
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] + 50, doorposition[1] + 90, doorposition[2] - 50);
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] + 50, doorposition[1] - 5.0, doorposition[2] - 50);
		glEnd();
		glBegin(GL_QUADS); //top
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] - 50, doorposition[1] + 90, doorposition[2] - 0.01);
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] - 50, doorposition[1] + 90, doorposition[2] - 50);
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] + 50, doorposition[1] + 90, doorposition[2] - 50);
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] + 50, doorposition[1] + 90, doorposition[2] - 0.01);
		glEnd();
		glBegin(GL_QUADS); //right
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] + 50, doorposition[1] - 5.0, doorposition[2] - 50);
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] + 50, doorposition[1] + 90, doorposition[2] - 50);
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] + 50, doorposition[1] + 90, doorposition[2] - 0.01);
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] + 50, doorposition[1] - 5.0, doorposition[2] - 0.01);
		glEnd();
		glBegin(GL_QUADS); //left
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] - 50, doorposition[1] - 5.0, doorposition[2] - 50);
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] - 50, doorposition[1] + 90, doorposition[2] - 50);
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] - 50, doorposition[1] + 90, doorposition[2] - 0.01);
		glTexCoord2f(0.09, 0.09); glVertex3f(doorposition[0] - 50, doorposition[1] - 5.0, doorposition[2] - 0.01);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}


}
void wallend()
{
	floor_material();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, night_id);
	glBegin(GL_QUADS); //down
	glTexCoord2f(0.2, 0.2); glVertex3f(-endboxw, -endboxw, endboxw);
	glTexCoord2f(0.2, 0.8); glVertex3f(-endboxw, -endboxw, -endboxw);
	glTexCoord2f(0.8, 0.8); glVertex3f(endboxw, -endboxw, -endboxw);
	glTexCoord2f(0.8, 0.2); glVertex3f(endboxw, -endboxw, endboxw);
	glEnd();
	glBegin(GL_QUADS);//front
	glTexCoord2f(0.2, 0.2); glVertex3f(-endboxw, -endboxw, -endboxw);
	glTexCoord2f(0.2, 0.8); glVertex3f(-endboxw, endboxw, -endboxw);
	glTexCoord2f(0.8, 0.8); glVertex3f(endboxw, endboxw, -endboxw);
	glTexCoord2f(0.8, 0.2); glVertex3f(endboxw, -endboxw, -endboxw);
	glEnd();
	glBegin(GL_QUADS); //top
	glTexCoord2f(0.2, 0.2); glVertex3f(-endboxw, endboxw, endboxw);
	glTexCoord2f(0.2, 0.8); glVertex3f(-endboxw, endboxw, -endboxw);
	glTexCoord2f(0.8, 0.8); glVertex3f(endboxw, endboxw, -endboxw);
	glTexCoord2f(0.8, 0.2); glVertex3f(endboxw, endboxw, endboxw);
	glEnd();
	glBegin(GL_QUADS); //right
	glTexCoord2f(0.2, 0.2); glVertex3f(endboxw, -endboxw, -endboxw);
	glTexCoord2f(0.2, 0.8); glVertex3f(endboxw, endboxw, -endboxw);
	glTexCoord2f(0.8, 0.8); glVertex3f(endboxw, endboxw, endboxw);
	glTexCoord2f(0.8, 0.2); glVertex3f(endboxw, -endboxw, endboxw);
	glEnd();
	glBegin(GL_QUADS); //left
	glTexCoord2f(0.2, 0.2); glVertex3f(-endboxw, -endboxw, -endboxw);
	glTexCoord2f(0.2, 0.8); glVertex3f(-endboxw, endboxw, -endboxw);
	glTexCoord2f(0.8, 0.8); glVertex3f(-endboxw, endboxw, endboxw);
	glTexCoord2f(0.8, 0.2); glVertex3f(-endboxw, -endboxw, endboxw);
	glEnd();
	glBegin(GL_QUADS);//front
	glTexCoord2f(0.2, 0.2); glVertex3f(-endboxw, -endboxw, endboxw);
	glTexCoord2f(0.2, 0.8); glVertex3f(-endboxw, endboxw, endboxw);
	glTexCoord2f(0.8, 0.8); glVertex3f(endboxw, endboxw, endboxw);
	glTexCoord2f(0.8, 0.2); glVertex3f(endboxw, -endboxw, endboxw);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void flash()
{
	glPushMatrix();
	glDepthFunc(GL_ALWAYS);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);//flash
	glBindTexture(GL_TEXTURE_2D, flash_id);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-flashspin, -flashspin - 5.0, Map_Max - 10.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-flashspin, flashspin - 5.0, Map_Max - 10.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(flashspin, flashspin - 5.0, Map_Max - 10.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(flashspin, -flashspin - 5.0, Map_Max - 10.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glDepthFunc(GL_LESS);
	glPopMatrix();
}
void summoning()
{
	glPushMatrix();
	hud_material();
	glTranslated(role.x, 0.0, role.z - 7.5);
	glRotated(summonspin, 0.0, 1.0, 0.0);
	glTranslated(-role.x, 0.0, -role.z);
	glDepthFunc(GL_ALWAYS);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);//summon
	glBindTexture(GL_TEXTURE_2D, summon_id);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(role.x - summonscale, -4, role.z - summonscale);
	glTexCoord2f(0.0, 1.0); glVertex3f(role.x - summonscale, -4, role.z + summonscale);
	glTexCoord2f(1.0, 1.0); glVertex3f(role.x + summonscale, -4, role.z + summonscale);
	glTexCoord2f(1.0, 0.0); glVertex3f(role.x + summonscale, -4, role.z - summonscale);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glDepthFunc(GL_LESS);
	glPopMatrix();

	glPushMatrix();
	glTranslated(role.x, 0.0, role.z - 5.0);
	glRotated(angleRL / 2, 0.0, -1.0, 0.0);
	glTranslated(-role.x, 0.0, -role.z);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);//summonmidlight
	glBindTexture(GL_TEXTURE_2D, midlighting_id);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(role.x - summonscale * 2, -4, role.z - 5);
	glTexCoord2f(0.0, 1.0); glVertex3f(role.x - summonscale * 2, summonmidlightscale - 4, role.z - 5);
	glTexCoord2f(1.0, 1.0); glVertex3f(role.x + summonscale * 2, summonmidlightscale - 4, role.z - 5);
	glTexCoord2f(1.0, 0.0); glVertex3f(role.x + summonscale * 2, -4, role.z - 5);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glPopMatrix();

	//flash
	glPushMatrix();

	glTranslated(role.x, role.y, role.z);
	glRotated(angleRL * 2, 0.0, -1.0, 0.0);
	glTranslated(0.0, 0.0, (cameradistant - 5.0));

	glDepthFunc(GL_ALWAYS);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);//flash
	glBindTexture(GL_TEXTURE_2D, flash_id);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-flashspin + 5, -flashspin - 10.0, -30);
	glTexCoord2f(0.0, 1.0); glVertex3f(-flashspin + 5, flashspin - 10.0, -30);
	glTexCoord2f(1.0, 1.0); glVertex3f(flashspin + 5, flashspin - 10.0, -30);
	glTexCoord2f(1.0, 0.0); glVertex3f(flashspin + 5, -flashspin - 10.0, -30);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glDepthFunc(GL_LESS);
	glPopMatrix();


}
void summoned()
{
	hud_material();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, astorufo[animetion]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0); glVertex3f(-2.0, -1.0, 4.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, 1.0, 4.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(2.0, 1.0, 4.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(2.0, -1.0, 4.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
bool  col(obj &a, obj b, int open) {
	int t = 0;

	if (open) {  //有開啟
				 // 牆壁的碰撞  (必須待在物體內)

		if (a.x > b.MaxX) {
			a.x = b.MaxX;
			t = 1;
		}
		if (a.x < b.MinX) {
			a.x = b.MinX;
			t = 1;
		}

		if (a.y > b.MaxY) {
			a.y = b.MaxY;
			t = 1;
		}
		if (a.y < b.MinY) {
			a.y = b.MinY;
			t = 1;
			if (CHARACTER_ACTION == 2)
			{
				jumpcnt = 0;
				CHARACTER_ACTION = 0;
			}
		}

		if (a.z > b.MaxZ) {
			a.z = b.MaxZ;
			t = 1;
		}
		if (a.z < b.MinZ) {
			a.z = b.MinZ;
			t = 1;
		}
	}
	if (t) { return true; }

	return false; // 沒碰到

}
void drop(int i) {
	drop_down = Drop_Time;
	drop_index = i;


}
bool  obj_col(obj &a, obj b) {
	// 物體的碰撞  (必須待在物體外)
	int t = 0;
	if (a.x < b.MaxX  && a.x>b.MinX && a.z < b.MaxZ && a.z > b.MinZ && a.y<b.MaxY && a.y> b.MinY) {

		t = 1;
	}

	if (t) { return true; }

	return false; // 沒碰到

}

void keyoperation(void)
{

	if (mode == 3) {  //遊戲模式
		if (role_down == 0 && drop_down == 0) {  //沒跌倒才能動
			if ((keystates['W'] == down) || (keystates['w'] == down))
			{
				charactetismoving = true;
				rolefaceangle = 0;
				role.z -= move;
				glutPostRedisplay();
			}
			if ((keystates['A'] == down) || (keystates['a'] == down))
			{
				charactetismoving = true;
				rolefaceangle = 270;
				role.x -= move;
				glutPostRedisplay();
			}
			if ((keystates['S'] == down) || (keystates['s'] == down))
			{
				charactetismoving = true;
				rolefaceangle = 180;
				role.z += move;
				glutPostRedisplay();
			}

			if ((keystates['D'] == down) || (keystates['d'] == down))
			{
				charactetismoving = true;
				rolefaceangle = 90;
				role.x += move;
				glutPostRedisplay();
			}
			if ((keystates['P'] == down) || (keystates['p'] == down))
			{
				if (energy >= 1)
				{
					energy -= energyv0;
				}
				else if (energy > 0.1) {

					energy -= energyv0 / 3 * 2;
				}
				else {
					PlaySound(TEXT("res/sound/down1.wav"), NULL, SND_ASYNC);
					if (m == 0) { role_down = Role_Time; }

				}
				if ((keystates['W'] == down) || (keystates['w'] == down))
				{
					charactetismoving = true;
					role.z -= move;
					glutPostRedisplay();
				}
				if ((keystates['A'] == down) || (keystates['a'] == down))
				{
					charactetismoving = true;
					role.x -= move;
					glutPostRedisplay();
				}
				if ((keystates['S'] == down) || (keystates['s'] == down))
				{
					charactetismoving = true;
					role.z += move;
					glutPostRedisplay();
				}

				if ((keystates['D'] == down) || (keystates['d'] == down))
				{
					charactetismoving = true;
					role.x += move;
					glutPostRedisplay();
				}
			}
			if (m == 1)
			{
				/*if ((keystates['I'] == down) || (keystates['i'] == down))
				{
				if (angleTD >= 10)
				angleTD -= 2;
				glutPostRedisplay();
				}
				if ((keystates['K'] == down) || (keystates['k'] == down))
				{
				if (angleTD <= 85)
				angleTD += 2;
				glutPostRedisplay();
				}
				if ((keystates['J'] == down) || (keystates['j'] == down))
				{
				angleRL -= 2;
				if (angleRL <= 360)
				angleRL += 360;
				glutPostRedisplay();
				}

				if ((keystates['L'] == down) || (keystates['l'] == down))
				{
				angleRL += 2;
				if (angleRL >= 360)
				angleRL -= 360;
				glutPostRedisplay();
				}*/
			}
			if ((keystates['1'] == down) || (keystates['1'] == down))
			{
				restart();				
				glutPostRedisplay();
			}
			if ((keystates[32] == down))  //空白
			{
				if (CHARACTER_ACTION == 0)
				{
					CHARACTER_ACTION++;
					jumpcnt = 0;
				}
			}




		}
		col(role, Wall, open);
		for (int i = 0; i < Hurdle_Number; i++) {
			if (Hurdle_down[i] == 0 && obj_col(role, Hurdle[i])) {
				if (m == 0) { role_down = Role_Time; }
				Hurdle_down[i] = Hrudle_Time;
				PlaySound(TEXT("res/sound/down1.wav"), NULL, SND_ASYNC);
			}

		}
		for (int i = 0; i < accerlatenum; i++) {
			if (obj_col(role, accerlate[i]))
				if (CHARACTET_BURST == 0)
				{
					CHARACTET_BURST = 1;
					burstcnt = 0;
				}
		}
		for (int i = 0; i < stonenum; i++) {
			if (obj_col(role, stone[i]) && stone[i].isappear == true)
			{
				if (jumpmusicisopen)
					PlaySound(TEXT("res/sound/Item.wav"), NULL, SND_ASYNC);
				if (stonecnt <= 30)
					stonecnt++;
				stone[i].isappear = false;
			}
		}
		for (int i = 0; i < Drop_Number; i++) {
			if (drop_down == 0 && obj_col(role, Drop[i]) && m == 0) {
				PlaySound(TEXT("res/sound/lava.wav"), NULL, SND_ASYNC);
				open = 0;
				drop(i);  //drop (i)表示掉進index 為 i的岩漿之中

			}
		}
		if (obj_col(role, door))
		{
			if (stonecnt >= 30)
			{
				role.x = 0.0;
				mode = 35;
				open = 0;
			}
			else
			{
				restart();
			}

		}
		if (keystates['W'] == up && keystates['w'] == up
			&& keystates['A'] == up && keystates['a'] == up
			&& keystates['S'] == up && keystates['s'] == up
			&& keystates['D'] == up && keystates['d'] == up)
			charactetismoving = false;

	}// mode3  遊戲模式結尾


}

void HUD()
{
	if (mode == 3)
	{
		glPushMatrix();
		glTranslated(-0.0, 5, 0.0);
		hud_material();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texName);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);  glVertex3f(-8.0, -0.2, 0.0);
		glTexCoord2f(0.0, 1.0);  glVertex3f(-8.0, 0.2, 0.0);
		glTexCoord2f(1.0, 1.0);  glVertex3f(energy / 2 - 8.0, 0.2, 0.0);
		glTexCoord2f(1.0, 0.0);  glVertex3f(energy / 2 - 8.0, -0.2, 0.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		glTranslated(6, 4.0, 0.0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, stonevol_id);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);  glVertex3f(-1, stonecnt / 15.0 - 1, 0.0);     //   stonecnt/ 30 * 8 -4;
		glTexCoord2f(0.0, 1.0);  glVertex3f(-1, -1, 0.0);
		glTexCoord2f(1.0, 1.0);  glVertex3f(1, -1, 0.0);
		glTexCoord2f(1.0, 0.0);  glVertex3f(1, stonecnt / 15.0 - 1, 0.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();


		glDepthFunc(GL_ALWAYS);
		glPushMatrix();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glTranslated(6, 4.0, 0.0);
		frame_material();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, stoneframe_id);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);  glVertex3f(-2.5, 1.75, 0.0);
		glTexCoord2f(0.0, 1.0);  glVertex3f(-2.5, -1.75, 0.0);
		glTexCoord2f(1.0, 1.0);  glVertex3f(2.5, -1.75, 0.0);
		glTexCoord2f(1.0, 0.0);  glVertex3f(2.5, 1.75, 0.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);
		glPopMatrix();
		glDepthFunc(GL_LESS);
	}
	else if (mode == 31)
	{  //暫停中


		glPushMatrix();
		index_material();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, menu_id);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 1.0); glVertex3f(-6, -4, -0.1);
		glTexCoord2f(0.0, 0.0); glVertex3f(-6, +5.4, -0.1);
		glTexCoord2f(1.0, 0.0); glVertex3f(6, +5.4, -0.1);
		glTexCoord2f(1.0, 1.0); glVertex3f(6, -4, -0.1);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();


		glPushMatrix();//指示物
		glTranslated(-4 + (select*(-0.9)), 1 + (select*(-3)), 0);
		index_material();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, runner);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 1.0); glVertex3f(-0.5, 0, 0.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 1, 0.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(0.5, 1, 0.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(0.5, 0, 0.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

	}
}

void display(void)
{

	GLfloat position[] = { 0.0, 30.0, 20.5, 0.0 };


	if (mode == 0) {
		keyoperation();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(0, 0, 15, 0, 0, 0, 0.0, 1.0, 0);



		glPushMatrix();//主畫面
		index_material();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, (index_id[0]));
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 1.0); glVertex3f(-96, -60, -35);
		glTexCoord2f(0.0, 0.0); glVertex3f(-96, 60, -35);
		glTexCoord2f(1.0, 0.0); glVertex3f(96, 60, -35);
		glTexCoord2f(1.0, 1.0); glVertex3f(96, -60, -35);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();//指示物
		glTranslated(-43, -7 + (select*(-20)) - select, 0);
		index_material();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, runner);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 1.0); glVertex3f(-5, -5, -34.9);
		glTexCoord2f(0.0, 0.0); glVertex3f(-5, 5, -34.9);
		glTexCoord2f(1.0, 0.0); glVertex3f(5, 5, -34.9);
		glTexCoord2f(1.0, 1.0); glVertex3f(5, -5, -34.9);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glutSwapBuffers();
	}
	else if (mode > 10 && mode< 30) {

		keyoperation();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(0, 0, 15, 0, 0, 0, 0.0, 1.0, 0);

		glPushMatrix();//燈
		glLightfv(GL_LIGHT0, GL_POSITION, position);
		glPopMatrix();


		glPushMatrix();//畫面
		index_material();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, (index_id[(mode % 10)]));
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 1.0); glVertex3f(-96, -60, -35);
		glTexCoord2f(0.0, 0.0); glVertex3f(-96, 60, -35);
		glTexCoord2f(1.0, 0.0); glVertex3f(96, 60, -35);
		glTexCoord2f(1.0, 1.0); glVertex3f(96, -60, -35);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();


		if (mode == 16) {

			glPushMatrix();//指示物
			glTranslated(-33 + (select*(-8)), -5 + (select*(-30)), 0);
			index_material();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, runner);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 1.0); glVertex3f(-5, -5, -34.9);
			glTexCoord2f(0.0, 0.0); glVertex3f(-5, 5, -34.9);
			glTexCoord2f(1.0, 0.0); glVertex3f(5, 5, -34.9);
			glTexCoord2f(1.0, 1.0); glVertex3f(5, -5, -34.9);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();


		}


		glutSwapBuffers();


	}
	else if (mode == 3 || mode == 31 || mode == 35) {

		keyoperation();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(role.x, role.y, role.z + cameradistant, role.x, role.y, role.z, 0.0, 1.0, 0);

		GLfloat lamp_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
		GLfloat lamp_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat lamp_position[] = { role.x, role.y + 20.0 ,role.z, 0.5 };
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lamp_ambient);
		glLightfv(GL_LIGHT0, GL_POSITION, lamp_position);
		glEnable(GL_LIGHT1);



		glTranslatef(role.x, role.y, role.z);
		glRotated(angleTD + shake, 1.0, 0.0, 0.0);
		glRotated(angleRL, 0.0, 1.0, 0.0);
		glTranslated(-role.x, -role.y, -role.z);



		wall();


		for (int i = 0; i < accerlatenum; i++)
		{
			glPushMatrix();
			//accerlate_material();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, accerlate_id);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0 + accerlate_spin, 0.0); glVertex3f(accerlatemap[i][0] - 2.5, accerlatemap[i][1], accerlatemap[i][2] - 2.5);
			glTexCoord2f(0.0 + accerlate_spin, 1.0); glVertex3f(accerlatemap[i][0] + 2.5, accerlatemap[i][1], accerlatemap[i][2] - 2.5);
			glTexCoord2f(1.0 + accerlate_spin, 1.0); glVertex3f(accerlatemap[i][0] + 2.5, accerlatemap[i][1], accerlatemap[i][2] + 2.5);
			glTexCoord2f(1.0 + accerlate_spin, 0.0); glVertex3f(accerlatemap[i][0] - 2.5, accerlatemap[i][1], accerlatemap[i][2] + 2.5);
			glEnd();
			glDisable(GL_TEXTURE_2D);

			glPopMatrix();
		}






		glPushMatrix();
		//移動



		glPushMatrix();  //角色
		glTranslatef(role.x, role.y - DROP, role.z);
		role_material();
		glTranslatef(0.0, -0.7, 0.0);
		glRotated(rolefaceangle, 0.0, -1.0, 0.0);
		glRotated(180, 0.0, -1.0, 0.0);
		glRotated(90, 1.0, 0.0, 0.0);
		if (role_down == 0) { glRotated(-90, 1.0, 0.0, 0.0); }  //如果角色沒跌倒 是站著的
		glCallList(gudako[animetion]);
		glPopMatrix();


		for (int i = 0; i < Hurdle_Number; i++)
		{
			glPushMatrix();  //跨欄
			glTranslatef((Hurdle[i]).x, (Hurdle[i]).y, (Hurdle[i]).z);



			glTranslatef(0.0, -2, 0.0);
			if (Hurdle_down[i] != 0) {
				glTranslatef(0.0, -2.5, 0.0);
				glRotated(90, -1.0, 0.0, 0.0);
				glTranslatef(0.0, 2.5, 0.0);
			}  // 柵欄倒下來

			glCallList(Hurdel_list);

			glPopMatrix();
		}


		for (int i = 0; i < Drop_Number; i++)
		{
			//掉落
			glPushMatrix();
			lava_material();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, iava_id);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f((Drop[i]).MinX, -4.9, (Drop[i]).MinZ);
			glTexCoord2f(0.0,(Drop[i].MaxZ- Drop[i].MinZ)/20); glVertex3f((Drop[i]).MinX, -4.9, (Drop[i]).MaxZ);
			glTexCoord2f(1.0, (Drop[i].MaxZ - Drop[i].MinZ) / 20); glVertex3f((Drop[i]).MaxX, -4.9, (Drop[i]).MaxZ);
			glTexCoord2f(1.0, 0.0); glVertex3f((Drop[i]).MaxX, -4.9, (Drop[i]).MinZ);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
		}
		for (int i = stonenum - 1; i >= 0; i--)
		{
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			if (stone[i].isappear == true)
			{
				glPushMatrix();
				glTranslated(stonemap[i][0], stonemap[i][1], stonemap[i][2]);
				glRotated(stonespin, 0.0, 1.0, 0.0);
				glTranslated(-stonemap[i][0], -stonemap[i][1], -stonemap[i][2]);
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, stone_id);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(stonemap[i][0] - stonetexwide, stonemap[i][1] - stonetexwide, stonemap[i][2]);
				glTexCoord2f(0.0, 1.0); glVertex3f(stonemap[i][0] + stonetexwide, stonemap[i][1] - stonetexwide, stonemap[i][2]);
				glTexCoord2f(1.0, 1.0); glVertex3f(stonemap[i][0] + stonetexwide, stonemap[i][1] + stonetexwide, stonemap[i][2]);
				glTexCoord2f(1.0, 0.0); glVertex3f(stonemap[i][0] - stonetexwide, stonemap[i][1] + stonetexwide, stonemap[i][2]);
				glEnd();
				glDisable(GL_TEXTURE_2D);

				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, stone_id);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(stonemap[i][0], stonemap[i][1] - stonetexwide, stonemap[i][2] - stonetexwide);
				glTexCoord2f(0.0, 1.0); glVertex3f(stonemap[i][0], stonemap[i][1] - stonetexwide, stonemap[i][2] + stonetexwide);
				glTexCoord2f(1.0, 1.0); glVertex3f(stonemap[i][0], stonemap[i][1] + stonetexwide, stonemap[i][2] + stonetexwide);
				glTexCoord2f(1.0, 0.0); glVertex3f(stonemap[i][0], stonemap[i][1] + stonetexwide, stonemap[i][2] - stonetexwide);
				glEnd();
				glDisable(GL_TEXTURE_2D);

				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, stone_id);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex3f(stonemap[i][0] - stonetexwide, stonemap[i][1], stonemap[i][2] - stonetexwide);
				glTexCoord2f(0.0, 1.0); glVertex3f(stonemap[i][0] + stonetexwide, stonemap[i][1], stonemap[i][2] - stonetexwide);
				glTexCoord2f(1.0, 1.0); glVertex3f(stonemap[i][0] + stonetexwide, stonemap[i][1], stonemap[i][2] + stonetexwide);
				glTexCoord2f(1.0, 0.0); glVertex3f(stonemap[i][0] - stonetexwide, stonemap[i][1], stonemap[i][2] + stonetexwide);
				glEnd();
				glDisable(GL_TEXTURE_2D);

				glPopMatrix();
			}
			glDisable(GL_BLEND);
		}
		flash();
		glPushMatrix();

		glTranslated(role.x, role.y, role.z);
		glRotated(angleTD + shake, -1.0, 0.0, 0.0);
		glTranslated(0.0, 0.0, (cameradistant - 5.0));
		HUD();
		glPopMatrix();
		glPopMatrix();

		glutSwapBuffers();
	}
	else if (mode == 4)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(0.0, 0.0, 0.0 - cameradistant, 0.0, 0.0, 0.0, 0.0, 1.0, 0);
		glTranslatef(role.x, role.y, role.z);
		glRotated(angleTD, 1.0, 0.0, 0.0);
		glRotated(angleRL, 0.0, 1.0, 0.0);
		glTranslated(-role.x, -role.y, -role.z);
		wallend();
		glPushMatrix();
		glTranslatef(role.x, role.y, role.z);
		role_material();
		glRotated(rolefaceangle, 0.0, -1.0, 0.0);
		glRotated(180, 0.0, -1.0, 0.0);
		glCallList(gudako[animetion]);
		glPopMatrix();
		summoning();

		glutSwapBuffers();
	}
	else if (mode == 41)
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0);
		glPushMatrix();
		summoned();
		glPopMatrix();
		glutSwapBuffers();
	}



}
void spinDisplay(void)
{
	if (energy < 20.0)
	{
		energy = energy + energyv0 / 6;
	}
	else if (energy > 20.0)
		energy = 20.0;
	else if (energy <= 0.0)
	{
		energy = 0.0;
	}

	accerlate_spin += 0.05;
	if (accerlate_spin > 1.0)
		accerlate_spin -= 1.0;
	stonespin += 5.0;
	if (stonespin >= 360.0)
		stonespin -= 360.0;
	glutPostRedisplay();
}
void preparelighting()
{
	GLfloat lamp_ambient[] = { 0.0, 0.0 ,0.0, 1.0 };
	GLfloat lamp_diffuse[] = { 1.0, 1.0 ,1.0, 1.0 };
	GLfloat lamp_specular[] = { 1.0, 1.0 ,1.0, 1.0 };
	GLfloat lamp_position[] = { 50.0, 30.0 ,0.0, 0.0 };
	GLfloat lamp1_ambient[] = { 0.0, 0.0 ,0.0, 1.0 };
	GLfloat lamp1_diffuse[] = { 1.0, 1.0 ,1.0, 1.0 };
	GLfloat lamp1_specular[] = { 1.0, 1.0 ,1.0, 1.0 };
	GLfloat lamp1_position[] = { -20.0,20.0,0.0 , 0.0 };
	GLfloat lamp2_ambient[] = { 0.0, 0.0 ,0.0, 1.0 };
	GLfloat lamp2_diffuse[] = { 1.0, 1.0 ,1.0, 1.0 };
	GLfloat lamp2_specular[] = { 1.0, 1.0 ,1.0, 1.0 };
	GLfloat lamp2_position[] = { 20.0,20.0,0.0, 0.0 };
	GLfloat lamp3_ambient[] = { 0.0, 0.0 ,0.0, 1.0 };
	GLfloat lamp3_diffuse[] = { 1.0, 0.2 ,0.0, 1.0 };
	GLfloat lamp3_specular[] = { 1.0, 0.0 ,0.0, 1.0 };
	GLfloat lamp3_position[] = { 0.0,-50.0,-50.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, lamp_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lamp_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lamp_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, lamp_position);
	glLightfv(GL_LIGHT1, GL_AMBIENT, lamp1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lamp1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lamp1_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, lamp1_position);
	glLightfv(GL_LIGHT2, GL_AMBIENT, lamp2_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, lamp2_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, lamp2_specular);
	glLightfv(GL_LIGHT2, GL_POSITION, lamp2_position);
	glLightfv(GL_LIGHT3, GL_AMBIENT, lamp3_ambient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, lamp3_diffuse);
	glLightfv(GL_LIGHT3, GL_SPECULAR, lamp3_specular);
	glLightfv(GL_LIGHT3, GL_POSITION, lamp3_position);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);

}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	preparelighting();
}

void ending()
{
	if (mode == 4)
	{
		if (endtimecnt == 10)
		{
			PlaySound(TEXT("res/sound/smmon0.wav"), NULL, SND_ASYNC);

		}
		charactetismoving = false;
		angleTD = 0;
		angleRL = -15;
		cameradistant = 35;
		if (endtimecnt <= 150 && endtimecnt > 50)
		{
			charactetismoving = true;
			role.z -= 0.2;
		}
		else if (endtimecnt <= 250 && endtimecnt >160)
		{
			charactetismoving = false;
			animetion = 2;
		}
		if (endtimecnt == 320)
		{
			PlaySound(TEXT("res/sound/smmon1.wav"), NULL, SND_ASYNC);
		}
		if (endtimecnt >= 200 && endtimecnt < 280)
		{
			if (summonscale <= 8.0)
			{
				summonscale += 0.1;
			}
		}
		else if (endtimecnt >= 280)
		{
			if ((endtimecnt - 280)*0.25 <= 30)                // spinuppon==60
				summonspin += (endtimecnt - 280)*0.25;
			else
				summonspin += 30;

			if (summonspin >= 360)
				summonspin -= 360;
		}

		if (endtimecnt >= 310 && endtimecnt < 480)
		{
			if (summonmidlightscale <= 15)
			{
				summonmidlightscale += 0.2;
			}
		}
		else if (endtimecnt >= 480)
		{
			mode = 41;
			flashspin = 0;
			endtimecnt = 0;
			animetion = 0;
		}
		if (endtimecnt == 440)
		{
			PlaySound(TEXT("res/sound/astorufo.wav"), NULL, SND_ASYNC);
		}
		if (endtimecnt >= 360 && endtimecnt <= 480)
		{
			flashspin += 5;
		}


	}
	else if (mode == 41)
	{
		switch (endtimecnt)
		{
		case 2:
			animetion = 0;
			break;
		case 29:
			animetion++;
			break;
		case 120:
			animetion++;
			break;
		case 165:
			animetion++;
			break;
		case 210:
			animetion++;
			break;
		case 300:
			mode = 0;
			restart();
		default:
			break;
		}
	}

	endtimecnt++;
}
void dooropen()
{
	if (mode == 35)
	{
		charactetismoving = false;
		rolefaceangle = 0.0;
		if (endtimecnt <= 200)
		{
			doorpositionL[0] += 0.1;
			doorpositionR[0] -= 0.1;
		}
		if ((endtimecnt >= 300) && (endtimecnt <= 400))        //stop at max-25 +10
		{
			charactetismoving = true;
			role.z -= move / 2;
		}
		if ((endtimecnt >= 410) && (endtimecnt <= 610))
		{
			flashspin += 1.0;
		}
		if (endtimecnt >= 650)
		{
			mode = 4;
			role.x = 0.0;
			role.y = 0.0;
			role.z = 0.0;
			endtimecnt = 0;
			flashspin = 0;
		}
		endtimecnt++;
	}
}
void characterjump()
{
	if (CHARACTER_ACTION == 1 || CHARACTER_ACTION == 2)
	{
		role.y += jumpv0 - gravity*jumpcnt;
		jumpcnt += 1;
		if (jumpcnt == 20 * CHARACTER_ACTION || role_down>0)
		{
			CHARACTER_ACTION = 0;
			role.y = 0.0;
		}
	}
}
void characterburst()            //   timeline--->  0-------5------------------------20------------------25
{                                //               start  cameraview++                     cameraview--   end
	if (role_down>0 || drop_down>0)
	{
		CHARACTET_BURST = 0;
		burstcnt = 0;
		cameradistant = 15.0;
		angleTD = anglestart;

	}
	if (CHARACTET_BURST == 1)
	{
		role.z -= 10 * move - 0.2*burstcnt;
		rolefaceangle = 0.0;
		if (burstcnt<5)
		{
			cameradistant += 2;
			angleTD -= 1;
		}

		if ((burstcnt>20) && (burstcnt <= 25))
		{
			cameradistant -= 2;
			angleTD += 1;
		}

		if (burstcnt == 25)
		{
			CHARACTET_BURST = 0;
			burstcnt = 0;
			cameradistant = 15.0;
			angleTD = anglestart;
		}
		burstcnt++;
	}

}

void animeframe()
{
	if (charactetismoving)
	{
		if (role_down == 0)
		{
			animetiontimecnt++;
			if (animetiontimecnt>10)
			{
				animetion++;
				animetiontimecnt -= 10;
				if (animetion > animetionnum - 1)
					animetion -= animetionnum;
			}
		}
	}
}

void TimerFunction(int value)
{
	if (mode == 3 || mode == 35) {
		if (role_down > 0) {

			role_down--;

		}

		if (drop_down > 1) {
			open = 0;
			drop_down--;
			DROP = DROP + 0.4;

		}
		if (drop_down == 1) {

			drop_down--;
			role.z = (Drop[drop_index]).MaxZ + 10;
			DROP = 0;
			rolefaceangle = 0.0;
			role.y = 0; //回到地面
			role_down = Role_Time;  //倒著回地面
			open = 1;  // box開啟

		}
		for (int i = 0; i < Hurdle_Number; i++) {
			if (Hurdle_down[i] > 0) {

				Hurdle_down[i]--;

			}
		}
		dooropen();
		characterjump();
		characterburst();
		animeframe();

	}// mode 3結尾
	else if (mode == 4)
	{
		animeframe();
		ending();
	}
	else if (mode == 41)
	{
		ending();
	}
	glutPostRedisplay();
	glutTimerFunc(30, TimerFunction, 1);
}
void keyup(unsigned char key, int x, int y)
{
	keystates[key] = up;
}
void keyboard(unsigned char key, int x, int y)
{
	keystates[key] = down;

	if (mode == 0) {//主選單
		switch (key) {
		case 32:  //空白
			restart();
			if (select == 0) { mode = 11; }  //教學結束緊接著遊戲
			else if (select == 1) { mode = 21; }  // 教學結束會回到主選單
			else if (select == 2) { exit(0); }  // 離開 關閉遊戲
			select = 0;  //順便初始化
			PlaySound(TEXT("res/sound/decision4.wav"), NULL, SND_ASYNC);
			glutPostRedisplay();
			break;

		case 'w':
		case 'W':  //上
			if (select == 0) { select = 2; }
			else { select--; }
			PlaySound(TEXT("res/sound/decision3.wav"), NULL, SND_ASYNC);
			glutPostRedisplay();
			break;

		case 's':
		case 'S':  //往下選
			if (select == 2) { select = 0; }
			else { select++; }
			PlaySound(TEXT("res/sound/decision3.wav"), NULL, SND_ASYNC);
			glutPostRedisplay();
			break;

		default:
			break;
		}

	}  //主選單結尾

	else if (mode == 11) { //教學模式 1-1  會開始遊戲的
		switch (key) {
		case 32:  //空白
			mode = 12;  //到下一頁的教學
			glutPostRedisplay();
			break;

		case 27: //esc鍵

			mode = 0;  //回主選
			break;
		default:
			break;
		}

	} //教學模式1-1結尾

	else if (mode == 21) { //教學模式 2-1  會回主選單的
		switch (key) {
		case 32:  //空白
			mode++;  //到下一頁的教學
			glutPostRedisplay();
			break;

		case 27: //esc鍵

			mode = 0;  //回上一頁
			break;

		default:
			break;
		}

	} //教學模式2-1結尾

	else  if (mode == 16) { //教學part5 準備進遊戲
		switch (key) {
		case 'w':
		case 'W':  //上
			if (select == 0) { select = 1; }
			else { select--; }
			PlaySound(TEXT("res/sound/decision3.wav"), NULL, SND_ASYNC);
			glutPostRedisplay();
			break;

		case 's':
		case 'S':  //往下選
			if (select == 1) { select = 0; }
			else { select++; }
			PlaySound(TEXT("res/sound/decision3.wav"), NULL, SND_ASYNC);
			glutPostRedisplay();
			break;


		case 32:  //空白

			if (select == 0) {
				mode = 3;  //開始遊戲   進行初始化
				angleTD = anglestart;
				endtimecnt = 0;
				stonecnt = 0;
				restart();

			}
			else if (select == 1) {
				mode = 11;  //重新聽取說明
				select = 0;
			}
			PlaySound(TEXT("res/sound/decision4.wav"), NULL, SND_ASYNC);
			glutPostRedisplay();
			break;

		default:
			break;
		}

	} //教學模式part 3結尾

	else if (mode == 25) { //教學part 2-4  教學結束回主選
		switch (key) {


		case 32:  //空白
			mode = 0;  //回主選單
			angleTD = 0;
			select = 0;
			glutPostRedisplay();
			break;

		default:
			break;
		}

	} //教學模式part 2結尾


	else if (mode>10 && mode <30) { //教學中
		switch (key) {
		case 32:  //空白
			mode++;  //到下一頁的教學
			glutPostRedisplay();
			break;

		case 27: //esc鍵

			mode--;  //回上一頁
			break;

		default:
			break;
		}

	} //教學結尾

	else if (mode == 3) { //遊戲模式
		switch (key) {
		case 'M':  //作弊
		case 'm':
			if (m == 0) { m = 1; stonecnt = 30;
			}
			else { m = 0; }
			break;
		case 'U':
			if (m == 1)
				jumpmusicisopen = !jumpmusicisopen;
			break;

		case 32:  //空白
			if (jumpmusicisopen) PlaySound(TEXT("res/sound/wowuu.wav"), NULL, SND_ASYNC);

			if (CHARACTER_ACTION == 1)
			{
				if (jumpmusicisopen) PlaySound(TEXT("res/sound/yahuo1.wav"), NULL, SND_ASYNC);
				CHARACTER_ACTION = 2;
				jumpcnt = 0;
			}
			break;
		case 'b':  //空白
			if (m == 1)
			{
				if (CHARACTET_BURST == 0)
				{
					CHARACTET_BURST = 1;
					jumpcnt = 0;
				}
			}
			break;

		case 27:  //esc 切 menu
			mode = 31;
			//angleTD = 0;
			PlaySound(TEXT("res/sound/decision3.wav"), NULL, SND_ASYNC);
			break;

		default:
			break;

		}
	} //遊戲模式結尾

	else  if (mode == 31) { //遊戲menu
		switch (key) {
		case 'w':
		case 'W':  //上
			if (select == 0) { select = 1; }
			else { select--; }
			PlaySound(TEXT("res/sound/decision3.wav"), NULL, SND_ASYNC);
			glutPostRedisplay();
			break;
		case 's':
		case 'S':  //往下選
			if (select == 1) { select = 0; }
			else { select++; }
			PlaySound(TEXT("res/sound/decision3.wav"), NULL, SND_ASYNC);
			glutPostRedisplay();
			break;
		case 32:  //空白
			if (select == 0) {
				mode = 3;  //繼續遊戲 
						   //angleTD = 30;

			}
			else if (select == 1) {
				mode = 0;  //回到主畫面  所有東西init
				angleTD = 0;
				select = 0;
				role.x = 0;
				role.y = 0;
				role.z = 0;
			}
			PlaySound(TEXT("res/sound/decision4.wav"), NULL, SND_ASYNC);
			glutPostRedisplay();
			break;

		case 27:  //空白
				  //angleTD = 30;
			mode = 3;
			select = 0;
			PlaySound(TEXT("res/sound/decision3.wav"), NULL, SND_ASYNC);
			glutPostRedisplay();
			break;

		default:
			break;
		}

	} //menu結束
	if (mode == 35)
	{
		switch (key)
		{
		case 27:  //esc 切 menu
			mode = 31;
			break;
		default:
			break;
		}
	}
	if (mode == 4 || mode == 41 || mode == 42)
	{
		switch (key)
		{
		case ' ':
			printf("%d\n", endtimecnt);
			break;
		case 27:  //exit
			mode = 0;
			restart();
			break;
		default:
			break;
		}
	}
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
	glutInitWindowSize(800, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Final");
	init();
	loading();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyup);
	glutIdleFunc(spinDisplay);
	glutTimerFunc(16, TimerFunction, 1);
	glutMainLoop();
	return 0;
}