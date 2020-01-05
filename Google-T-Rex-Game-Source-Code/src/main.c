/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stdint.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "glcd.h"
#include "stm32f0xx.h"
#include "stm32f0_discovery.h"

// TONES  ==========================================
// Start by defining the relationship between note, period, &  frequency.

#define  c     3830    // 261 Hz
#define  d     3400    // 294 Hz
#define  e     3038    // 329 Hz
#define  f     2864    // 349 Hz
#define  g     2550    // 392 Hz
#define  a     2272    // 440 Hz
#define  b     2028    // 493 Hz
#define  C     1912    // 523 Hz
#define  D     1702    // 523 Hz
#define a3      4531    //220 Hz
#define b3      4036    //247Hz

// Define a special note, 'R', to represent a rest
#define  R     0

int melody [] = {e,b3, c, d, c,b3,a3,a3, c, e, d, c,b3, c, d, e, c,a3,a3,    R,       d, f,a,g,f,e,c,e,d,c,b3,b3,c,d,e,c,a3,a3};
int beats [] =   {16,8,8,16,8,8,16,8,8,16,8,8,24,8,16,16,16,16,32,   0.01,    16,8,16,8,8,24,8,16,8,8,16,8,8,16,16,16,16,32};

int melody1 [] = {b,b,b,  b,b,b, b,D,g,a,b ,C,C,C, C,C,b  ,b,b,a,a,b,a,D};
int beats1 [] =   {8,8,16,8,8,16,8,8,8,8,16,8,8,16,4,8,8,16,8,8,8,8,16,80};

int MAX_COUNT = sizeof(melody) / 2;

long tempo = 12000;     //120 bps = 12000

int pause = 1000;       //1000

int rest_count = 100;

int tone_ = 0;
int beat = 0;

int indexI = 0;
int indexII = 0;
int check = 0;



struct tree1{
	int SizeA;// = 15;
	int SizeB;// = 10;
	int PositionX;// = 128;
	int PositionY;// = 64;
};

struct tree2{
	int SizeA;// = 15;
	int SizeB;// = 10;
	int PositionX;// = 128;
	int PositionY;// = 64;
};

struct crow{
	int SizeA;// = 15;
	int SizeB;// = 10;
	int PositionX;// = 128;
	int PositionY;// = 64;
};

struct tRex{
	int mode;
	int SizeA;// = 15;
	int SizeB;// = 10;
	int PositionX;// = 5;
	int PositionY;// = 45;
};

void printNum(int NUM, uint8_t LeftTopX, uint8_t LeftTopY){
	uint8_t Zero[9][5] = {
			{1, 1, 1, 1, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 1, 1, 1, 1},
	};
	uint8_t One[9][5] = {
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
	};
	uint8_t Two[9][5] = {
			{1, 1, 1, 1, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{1, 1, 1, 1, 1},
			{1, 0, 0, 0, 0},
			{1, 0, 0, 0, 0},
			{1, 0, 0, 0, 0},
			{1, 1, 1, 1, 1},
	};
	uint8_t Three[9][5] = {
			{1, 1, 1, 1, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{1, 1, 1, 1, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{1, 1, 1, 1, 1},
	};
	uint8_t Four[9][5] = {
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 1, 1, 1, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
	};

	uint8_t Five[9][5] = {
			{1, 1, 1, 1, 1},
			{1, 0, 0, 0, 0},
			{1, 0, 0, 0, 0},
			{1, 0, 0, 0, 0},
			{1, 1, 1, 1, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{1, 1, 1, 1, 1},
	};
	uint8_t Six[9][5] = {
			{1, 1, 1, 1, 1},
			{1, 0, 0, 0, 0},
			{1, 0, 0, 0, 0},
			{1, 0, 0, 0, 0},
			{1, 1, 1, 1, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 1, 1, 1, 1},
	};
	uint8_t Seven[9][5] = {
			{1, 1, 1, 1, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
	};
	uint8_t Eight[9][5] = {
			{1, 1, 1, 1, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 1, 1, 1, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 1, 1, 1, 1},
	};
	uint8_t Nine[9][5] = {
			{1, 1, 1, 1, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 1, 1, 1, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 1},
			{1, 1, 1, 1, 1},
	};
	uint8_t H[9][5] = {
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 1, 1, 1, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
	};
	uint8_t I[9][5] = {
			{1, 1, 1, 1, 1},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{1, 1, 1, 1, 1},
	};
	switch (NUM)
	{
	case 1: // code to be executed if n = 1;
		image(One, 9, 5, LeftTopX, LeftTopY);
		break;
	case 2: // code to be executed if n = 2;
		image(Two, 9, 5, LeftTopX, LeftTopY);
		break;
	case 3: // code to be executed if n = 2;
		image(Three, 9, 5, LeftTopX, LeftTopY);
		break;
	case 4: // code to be executed if n = 2;
		image(Four, 9, 5, LeftTopX, LeftTopY);
		break;
	case 5: // code to be executed if n = 2;
		image(Five, 9, 5, LeftTopX, LeftTopY);
		break;
	case 6: // code to be executed if n = 2;
		image(Six, 9, 5, LeftTopX, LeftTopY);
		break;
	case 7: // code to be executed if n = 2;
		image(Seven, 9, 5, LeftTopX, LeftTopY);
		break;
	case 8: // code to be executed if n = 2;
		image(Eight, 9, 5, LeftTopX, LeftTopY);
		break;
	case 9: // code to be executed if n = 2;
		image(Nine, 9, 5, LeftTopX, LeftTopY);
		break;
	case 72: // code to be executed if n = 2;
		image(H, 9, 5, LeftTopX, LeftTopY);
		break;
	case 73: // code to be executed if n = 2;
		image(I, 9, 5, LeftTopX, LeftTopY);
		break;
	case 0: // code to be executed if n = 2;
		image(Zero, 9, 5, LeftTopX, LeftTopY);
		break;
	default: // code to be executed if n doesn't match any cases
		break;
	}
}

void ShowPoint(int CurrentHighestPoint, int PreviousHighestPoint){
	int distanceFromUpEdgetoDigit = 3;
	int distanceFromLeftEdgetoDigit = 2;
	int digitWidth = 5;
	int distanceFromDigittoDigit = 1;
	int temp = 0;
	temp = (int)floor(CurrentHighestPoint/1) % 10;
	printNum(temp, 128 - distanceFromDigittoDigit*0 - distanceFromLeftEdgetoDigit
			- digitWidth*1, distanceFromUpEdgetoDigit);//least number
	temp = (int)floor(CurrentHighestPoint/10) % 10;
	printNum(temp, 128 - distanceFromDigittoDigit*1 - distanceFromLeftEdgetoDigit
			- digitWidth*2, distanceFromUpEdgetoDigit);//second least number
	temp = (int)floor(CurrentHighestPoint/100) % 10;
	printNum(temp, 128 - distanceFromDigittoDigit*2 - distanceFromLeftEdgetoDigit
			- digitWidth*3, distanceFromUpEdgetoDigit);//second significant number
	temp = (int)floor(CurrentHighestPoint/1000) % 10;
	printNum(temp, 128 - distanceFromDigittoDigit*3 - distanceFromLeftEdgetoDigit
			- digitWidth*4, distanceFromUpEdgetoDigit);//most significant number

	temp = (int)floor(PreviousHighestPoint/1) % 10;
	printNum(temp, 128 - distanceFromDigittoDigit*5 - distanceFromLeftEdgetoDigit*3
			- digitWidth*5, distanceFromUpEdgetoDigit);//least number
	temp = (int)floor(PreviousHighestPoint/10) % 10;
	printNum(temp, 128 - distanceFromDigittoDigit*6 - distanceFromLeftEdgetoDigit*3
			- digitWidth*6, distanceFromUpEdgetoDigit);//second least number
	temp = (int)floor(PreviousHighestPoint/100) % 10;
	printNum(temp, 128 - distanceFromDigittoDigit*7 - distanceFromLeftEdgetoDigit*3
			- digitWidth*7, distanceFromUpEdgetoDigit);//second significant number
	temp = (int)floor(PreviousHighestPoint/1000) % 10;
	printNum(temp, 128 - distanceFromDigittoDigit*8 - distanceFromLeftEdgetoDigit*3
			- digitWidth*8, distanceFromUpEdgetoDigit);//most significant number

	temp = 73;
	printNum(temp, 128 - distanceFromDigittoDigit*9 - distanceFromLeftEdgetoDigit*5
			- digitWidth*9, distanceFromUpEdgetoDigit);//I
	temp = 72;
	printNum(temp, 128 - distanceFromDigittoDigit*10 - distanceFromLeftEdgetoDigit*5
			- digitWidth*10, distanceFromUpEdgetoDigit);//H
}

void printCharacter(int CharacterLabel, uint8_t LeftTopX, uint8_t LeftTopY){
	uint8_t dino_laugh[28][25] = {
			//[20][15] to [20][25] is used to cover the head when the dino stop dodging
			{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
			{1,0,0,0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
			{1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	uint8_t dino_right[28][25] = {
			//[20][15] to [20][25] is used to cover the head when the dino stop dodging
			{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
			{1,0,0,0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
			{1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	uint8_t dino_left[28][25] = {
			{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
			{1,0,0,0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
			{1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	uint8_t cactii[15][17] = {
			{0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,1},
			{0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,1},
			{0,0,1,1,0,1,0,1,1,0,1,0,0,0,1,0,1},
			{0,0,1,1,0,1,0,1,1,0,1,0,0,0,1,0,1},
			{0,0,1,1,0,1,1,1,1,0,1,0,0,0,1,0,1},
			{1,0,1,1,0,0,0,1,1,0,1,0,0,0,1,0,1},
			{1,0,1,1,0,1,0,1,1,0,1,0,1,0,1,0,1},
			{1,0,1,1,0,1,0,1,1,1,1,0,1,0,1,0,1},
			{1,0,1,1,0,1,0,1,1,0,0,0,1,1,0,0,1},
			{1,1,1,1,1,1,0,1,1,0,0,0,0,0,1,0,1},
			{0,0,1,1,0,0,0,1,1,0,0,0,0,0,1,1,1},
			{0,0,1,1,0,0,0,1,1,0,0,0,0,0,1,0,0},
			{0,0,1,1,0,0,0,1,1,0,0,0,0,0,1,0,0},
			{0,0,1,1,0,0,0,1,1,0,0,0,0,0,1,0,0},
			{0,0,1,1,0,0,0,1,1,0,0,0,0,0,1,0,0}};
	uint8_t cactus[15][10] = {
			{0,0,0,0,1,1,1,0,0,0},
			{0,0,0,0,1,1,1,0,0,0},
			{0,0,0,0,1,1,1,0,0,0},
			{0,0,0,0,1,1,1,0,1,1},
			{0,0,0,0,1,1,1,0,1,1},
			{1,1,1,0,1,1,1,0,1,1},
			{1,1,1,0,1,1,1,0,1,1},
			{1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1},
			{0,0,0,0,1,1,1,0,0,0},
			{0,0,0,0,1,1,1,0,0,0},
			{0,0,0,0,1,1,1,0,0,0},
			{0,0,0,0,1,1,1,0,0,0},
			{0,0,0,0,1,1,1,0,0,0},
			{0,0,0,0,1,1,1,0,0,0}};
	uint8_t bird[10][15] = {
			{0,0,0,0,0,0,0,1,1,1,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
			{0,1,1,0,0,0,1,0,0,0,0,0,0,0,0},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{0,1,1,0,0,0,1,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,1,0,0,0,0,0},
			{0,0,0,0,0,0,0,1,1,1,0,0,0,0,0}};

	uint8_t dino_dodging_left[25][25] = {
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,0,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,0},
			{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0},
			{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

	uint8_t dino_dodging_right[25][25] = {
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
			{1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,0,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,0},
			{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0},
			{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0}};

	switch (CharacterLabel)
	{
	case 0: // dinasour right
		image(dino_right, 28, 25, LeftTopX, LeftTopY);
		break;
	case 1: // dinasour left
		image(dino_left, 28, 25, LeftTopX, LeftTopY);
		break;
	case 2: // cactii
		image(cactii, 15, 17, LeftTopX, LeftTopY);
		break;
	case 3: // cactus
		image(cactus, 15, 10, LeftTopX, LeftTopY);
		break;
	case 4: // bird
		image(bird, 10, 15, LeftTopX, LeftTopY);
		break;
	case 5: //dodging dino left
		image(dino_dodging_left, 25, 25, LeftTopX, LeftTopY);
		break;
	case 6: //dodging dino right
		image(dino_dodging_right, 25, 25, LeftTopX, LeftTopY);
		break;
	case 7: //dodging dino laugh
		image(dino_laugh, 25, 25, LeftTopX, LeftTopY);
		break;
	default: // code to be executed if n doesn't match any cases
		break;
	}
}


void setupMusic()
{
	/* Student code goes here */
	//Enable system clock for Timer 1
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

	TIM1->BDTR |= TIM_BDTR_MOE;

	//Set the counting direction (clear/(0) for count up)
	TIM1->CR1 &= ~TIM_CR1_DIR;

	TIM1->CR1 &= 0x0;

	//Configure CH1-3 for PWM mode 1
	TIM1->CCMR1 &= ~TIM_CCMR1_OC1M_0;
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1;

	TIM1->CCMR1 &= ~TIM_CCMR1_OC2M_0;
	TIM1->CCMR1 |= TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1; //| TIM_CCMR1_OC2PE;


	TIM1->CCER |= TIM_CCER_CC1E;
	TIM1->CCER |= TIM_CCER_CC2E;

	//Set prescaler for 2 MHz output
	TIM1->PSC = 480 - 1;

	//Set ARR for 1000 Hz output
	TIM1->ARR = 100 - 1;

	//Enable timer
	TIM1->CR1 |= TIM_CR1_CEN;

	//Enable port A
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

	//Set PA8 to alternate function
	GPIOA->MODER &= ~(15 << 16);
	GPIOA->MODER |= (10 << 16);

	GPIOA->MODER |= GPIO_MODER_MODER0_0;

	//Set the alternate function for PA8
	GPIOA->AFR[1] &= ~0xff;
	GPIOA->AFR[1] |= 0x22;

	return;
}

int mainMusic1(void){

	long elapsed_time;
	long duration;

	tone_ = melody[indexI];
	beat = beats[indexI];

	duration = beat * tempo; // Set up timing
	elapsed_time = 0;

	if (tone_ > 0)      // if not Rest
	{
		//while the tone has played less long than 'duration', pulse speaker HIGH and LOW
		while (elapsed_time < duration)
		{
			//TIM1->CCR1 = 0;
			//High
			TIM1->CCR1 = 100;
			TIM1->CCR2 = 100;
			nano_wait((tone_ / 2) * 1000);

			//Low
			TIM1->CCR1 = 0;
			TIM1->CCR2 = 0;
			nano_wait((tone_ / 2) * 1000);

			//Keep track of how long we pulsed
			elapsed_time += (tone_);
		}
	}
	else { // Rest beat; loop times delay
		for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count
			nano_wait((duration)*1000);
		}
	}

	//38 notes 0-37
	if (indexI > (37 - 1))
	{
		indexI = 0;
	}
	else
	{
		indexI++;
	}
	return 0;
}

int mainMusic2(void){

	long elapsed_time;
	long duration;

	tone_ = melody1[indexII];
	beat = beats1[indexII];

	duration = beat * tempo; // Set up timing
	elapsed_time = 0;

	if (tone_ > 0)      // if not Rest
	{
		//while the tone has played less long than 'duration', pulse speaker HIGH and LOW
		while (elapsed_time < duration)
		{
			//TIM1->CCR1 = 0;
			//High
			TIM1->CCR1 = 100;
			TIM1->CCR2 = 100;
			nano_wait((tone_ / 2) * 1000);

			//Low
			TIM1->CCR1 = 0;
			TIM1->CCR2 = 0;
			nano_wait((tone_ / 2) * 1000);

			//Keep track of how long we pulsed
			elapsed_time += (tone_);
		}
	}
	else { // Rest beat; loop times delay
		for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count
			nano_wait((duration)*1000);
		}
	}

	//24 notes 0-23
	if (indexII > (23 - 1))
	{
		indexII = 0;
	}
	else
	{
		indexII++;
	}
	return 0;
}

void beep(void){
	DAC->CR |= DAC_CR_EN1;
	nano_wait(50000000);
	DAC->CR &= ~DAC_CR_EN1;
}



int main(void)
{
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	GPIOA->MODER &= ~(0xf << 6*2);

	initSound();
	setupMusic();

	gpiob_init();
	GLCD_init();
	GLCD_on();
	set_line(0);
	GLCD_clear();
	int restart = 0;
	int PreviousHighestPoint = 0;
	int CurrentHighestPoint = 0;
	int PointReduceRateCount = 0;
	while(1){
		restart = 0;
		indexI = 0;
		indexII = 0;

		struct tree1 Tree1;
		Tree1.SizeA = 15;
		Tree1.SizeB = 17;
		Tree1.PositionX = 128;
		Tree1.PositionY = 49;

		struct tree2 Tree2;
		Tree2.SizeA = 15;
		Tree2.SizeB = 10;
		Tree2.PositionX = 220;//never exceed 250
		Tree2.PositionY = 49;

		struct crow Crow;
		Crow.SizeA = 10;
		Crow.SizeB = 15;
		Crow.PositionX = 220;//never exceed 250
		Crow.PositionY = 33;

		int horizon = 36;
		struct tRex Trex;
		Trex.mode = 0;//stand
		Trex.SizeA = 20;
		Trex.SizeB = 15;
		Trex.PositionX = 5;
		Trex.PositionY = horizon;

		int jump = 0;
		int dodge = 0;
		int randNum = 0;
		int rowTheDice = 1;
		float Speed = 5000;
		if(CurrentHighestPoint > PreviousHighestPoint){//Renew the highest point
			PreviousHighestPoint = CurrentHighestPoint;
		}
		CurrentHighestPoint = 0;
		PointReduceRateCount = 0;
		int changeFoot = 0;
		int changeFootCount = 0;
		printCharacter(0, Trex.PositionX, Trex.PositionY);
		int Cheat = 0;
		int CheatCount = 0;
		int beepSound = 1;
		//*******Start Code*******//
		while(1){
			//int randNum = rand() % 3;
			//rectangle(Trex.PositionX, Trex.PositionY, Trex.SizeA, Trex.SizeB, 1);
			//printCharacter(0, Trex.PositionX, Trex.PositionY);
			if(indexII == 23){
				printCharacter(7, Trex.PositionX, Trex.PositionY);
			}else{
				if(changeFoot == 1){
					if(dodge == 0 && jump == 0){
						printCharacter(0, Trex.PositionX, Trex.PositionY);
					}
					if(dodge == 1){
						printCharacter(5, Trex.PositionX, Trex.PositionY-10);
					}
					changeFoot = 0;
				}else{
					if(dodge == 0 && jump == 0){
						printCharacter(1, Trex.PositionX, Trex.PositionY);
					}
					if(dodge == 1){
						printCharacter(6, Trex.PositionX, Trex.PositionY-10);
					}
					changeFoot = 1;
				}
				changeFootCount = 0;
			}

			if(Cheat == 0){
				if((((GPIOA->IDR & 0x80)>>7) == 0) && (((GPIOA->IDR & 0x40)>>6) == 0)){
					CheatCount++;
					if(CheatCount >= 20){
						Cheat = 1;
					}
				}else{
					Cheat = 0;
				}
			}

			if((((GPIOA->IDR & 0x80)>>7) == 0) && (jump == 0) ){
				if(beepSound == 1){
					beep();
					beepSound = 0;
				}
				dodge = 1;//dodge = 1 dodge. dodge = 0 nothing
				jump = 0;
			}else if((((GPIOA->IDR & 0x40)>>6) == 0) && (jump == 0) ){
				if(beepSound == 1){
					beep();
					beepSound = 0;
				}
				jump = 1;//jump = 1 up. jump = 2 down
				dodge = 0;
			}else{
				dodge = 0;
				beepSound = 1;
			}

			if(jump == 1){
				rectangle(Trex.PositionX, Trex.PositionY - 2 + Trex.SizeA, Trex.SizeA, Trex.SizeB, 0);
				Trex.PositionY = Trex.PositionY - 3;
				printCharacter(1, Trex.PositionX, Trex.PositionY);
				if(Trex.PositionY <= 10){
					jump = 2;
				}
			}else if(jump == 2){
				rectangle(Trex.PositionX, Trex.PositionY - 1, 4, Trex.SizeB, 0);
				Trex.PositionY = Trex.PositionY + 3;
				printCharacter(1, Trex.PositionX, Trex.PositionY);
				if(Trex.PositionY >= horizon){
					jump = 0;
				}
			}

			if(dodge == 1 && (jump == 0)){//change the edge of Trex
				rectangle(Trex.PositionX-10, Trex.PositionY-5, 5, Trex.SizeB, 0);
				Trex.SizeA = 16;
				Trex.SizeB = 26;
				Trex.PositionX = 5;
				Trex.PositionY = 44;
				if(changeFootCount > 5){
					if(changeFoot == 1){
						printCharacter(5, Trex.PositionX, Trex.PositionY-10);
						changeFoot = 0;
					}else{
						printCharacter(6, Trex.PositionX, Trex.PositionY-10);
						changeFoot = 1;
					}
					changeFootCount = 0;
				}else{
					changeFootCount++;
				}
			}else if(dodge == 0 && (jump == 0)){
				Trex.SizeA = 20;
				Trex.SizeB = 15;
				Trex.PositionX = 5;
				Trex.PositionY = horizon;

				if(changeFootCount > 5){
					if(changeFoot == 1){
						printCharacter(0, Trex.PositionX, Trex.PositionY);
						changeFoot = 0;
					}else{
						printCharacter(1, Trex.PositionX, Trex.PositionY);
						changeFoot = 1;
					}
					changeFootCount = 0;
				}else{
					changeFootCount++;
				}
			}

			//Move Tree 1
			rectangle(Tree1.PositionX, Tree1.PositionY, Tree1.SizeA, Tree1.SizeB, 0);
			Tree1.PositionX = Tree1.PositionX - 3;
			if(Tree1.PositionX + Tree1.SizeB <= 0){
				if(randNum == 0){
					if(128 - Tree2.PositionX > 50){
						Tree1.PositionX = 128 + rand() % 50;
					}else{
						Tree1.PositionX = 128  + rand() % 50 + (50 - (128 - Tree2.PositionX));
					}
				}else{
					if(128 - Crow.PositionX > 50){
						Tree1.PositionX = 128 + rand() % 50;
					}else{
						Tree1.PositionX = 128  + rand() % 50 + (50 - (128 - Crow.PositionX));
					}
				}
				//Tree1.PositionX = 180 + rand() % 50;//Never be larger than 230
			}
			//if(Tree1.PositionX == 230){
			//	Tree1.PositionX = Tree1.PositionX + 1;
			//}//for testing
			printCharacter(2, Tree1.PositionX, Tree1.PositionY);

			if(rowTheDice == 1){
				randNum = rand() % 2;
				rowTheDice = 0;
			}
			if(randNum == 0){//Move Tree 2
				rectangle(Tree2.PositionX, Tree2.PositionY, Tree2.SizeA, Tree2.SizeB, 0);
				Tree2.PositionX = Tree2.PositionX - 3;
				if(Tree2.PositionX + Tree2.SizeB <= 0){
					if(128 - Tree1.PositionX > 50){
						Tree2.PositionX = 128 + rand() % 50;
					}else{
						Tree2.PositionX = 128  + rand() % 50 + (50 - (128 - Tree1.PositionX));
					}
					//Tree2.PositionX = 180 + rand() % 50;//Never be larger than 230
					rowTheDice = 1;
				}
				printCharacter(3, Tree2.PositionX, Tree2.PositionY);
			}else{
				//Move Crow
				rectangle(Crow.PositionX, Crow.PositionY, Crow.SizeA, Crow.SizeB, 0);
				Crow.PositionX = Crow.PositionX - 3;
				if(Crow.PositionX + Crow.SizeB <= 0){
					if(128 - Tree1.PositionX > 50){
						Crow.PositionX = 128 + rand() % 50;
					}else{
						Crow.PositionX = 128  + rand() % 50 + (50 - (128 - Tree1.PositionX));
					}
					//Crow.PositionX = 180 + rand() % 50;//Never be larger than 230
					rowTheDice = 1;
				}
				printCharacter(4, Crow.PositionX, Crow.PositionY);
			}

			if(Cheat == 1){
				mainMusic2();
			}else{
				mainMusic1();
				if((Trex.PositionY + Trex.SizeA > Tree1.PositionY &&
						Trex.PositionX + Trex.SizeB > Tree1.PositionX &&
						Trex.PositionX + Trex.SizeB < Tree1.PositionX + Tree1.SizeB)
						||(Trex.PositionY + Trex.SizeA > Tree1.PositionY &&
								Trex.PositionX > Tree1.PositionX &&
								Trex.PositionX < Tree1.PositionX + Tree1.SizeB)){
					int blackOneTime = 1;
					while(1){
						if(blackOneTime == 1){
							for(int i = 0; i <= 100; i++){
								micro_wait(10000);
							}
							blackOneTime = 0;
						}
						//Show Game Over

						//Show Game Over
						if(((GPIOA->IDR & 0x40)>>6) == 0 || ((GPIOA->IDR & 0x80)>>7) == 0){
							rectangle(Tree1.PositionX, Tree1.PositionY, Tree1.SizeA, Tree1.SizeB, 0);
							rectangle(Tree2.PositionX, Tree2.PositionY, Tree2.SizeA, Tree2.SizeB, 0);
							rectangle(Trex.PositionX, Trex.PositionY, Trex.SizeA, Trex.SizeB, 0);
							GLCD_clear();
							restart = 1;
							break;
						}
					}
				}
				if((Trex.PositionY + Trex.SizeA > Tree2.PositionY &&
						Trex.PositionX + Trex.SizeB > Tree2.PositionX &&
						Trex.PositionX + Trex.SizeB < Tree2.PositionX + Tree2.SizeB)
						||(Trex.PositionY + Trex.SizeA > Tree2.PositionY &&
								Trex.PositionX > Tree2.PositionX &&
								Trex.PositionX < Tree2.PositionX + Tree2.SizeB)){
					int blackOneTime = 1;
					while(1){
						if(blackOneTime == 1){
							for(int i = 0; i <= 100; i++){
								micro_wait(10000);
							}
							blackOneTime = 0;
						}
						//Show Game Over

						//Show Game Over
						if(((GPIOA->IDR & 0x40)>>6) == 0 || ((GPIOA->IDR & 0x80)>>7) == 0){
							rectangle(Tree1.PositionX, Tree1.PositionY, Tree1.SizeA, Tree1.SizeB, 0);
							rectangle(Tree2.PositionX, Tree2.PositionY, Tree2.SizeA, Tree2.SizeB, 0);
							rectangle(Trex.PositionX, Trex.PositionY, Trex.SizeA, Trex.SizeB, 0);

							GLCD_clear();
							restart = 1;
							break;
						}
					}
				}
				if((dodge == 0 && Trex.PositionY + Trex.SizeA > Crow.PositionY &&
						Trex.PositionX + Trex.SizeB > Crow.PositionX &&
						Trex.PositionX + Trex.SizeB < Crow.PositionX + Crow.SizeB)
						||(dodge == 0 && Trex.PositionY + Trex.SizeA > Crow.PositionY &&
								Trex.PositionX > Crow.PositionX &&
								Trex.PositionX < Crow.PositionX + Crow.SizeB)
								||(dodge == 1 && Trex.PositionY < Crow.PositionY + Crow.SizeA &&
										Trex.PositionX + Trex.SizeB > Crow.PositionX &&
										Trex.PositionX + Trex.SizeB < Crow.PositionX + Crow.SizeB)
				){
					int blackOneTime = 1;
					while(1){
						if(blackOneTime == 1){
							for(int i = 0; i <= 100; i++){
								micro_wait(10000);
							}
							blackOneTime = 0;
						}
						//Show Game Over

						//Show Game Over
						if(((GPIOA->IDR & 0x40)>>6) == 0 || ((GPIOA->IDR & 0x80)>>7) == 0){
							rectangle(Tree1.PositionX, Tree1.PositionY, Tree1.SizeA, Tree1.SizeB, 0);
							rectangle(Tree2.PositionX, Tree2.PositionY, Tree2.SizeA, Tree2.SizeB, 0);
							rectangle(Trex.PositionX, Trex.PositionY, Trex.SizeA, Trex.SizeB, 0);
							GLCD_clear();
							restart = 1;
							break;
						}
					}
				}
			}

			if(restart == 1){
				break;
			}

			CurrentHighestPoint++;
			ShowPoint(CurrentHighestPoint, PreviousHighestPoint);

		}
	}
}

