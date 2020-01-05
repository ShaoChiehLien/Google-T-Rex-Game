/*
 * glcd.c
 *
 *  Created on: Nov 25, 2019
 *  Updated: 08:00 11/27/2019
 *      Author: dave
 */


#include "stdint.h"
#include "string.h"
#include "stdio.h"
#include "glcd.h"
#include "stm32f0xx.h"
#include "stm32f0_discovery.h"

#define CS2 8
#define CS1 9
#define RES 10
#define RW  11
#define RS  12
#define EN  13

uint8_t screen[64][8][2] = {0};

//Wait for "t" nanoseconds
void nano_wait(int t) {
	asm(
			"mov r0, %0\n"
			"rep:\n"
			"sub r0, #83\n"
			"bgt rep\n"
			: : "r"(t) : "r0" , "cc");
}

//Wait for "t" microseconds
void micro_wait(int t) {
	t = t * 1000;
	asm(
			"mov r0, %0\n"
			"repeat:\n"
			"sub r0, #83\n"
			"bgt repeat\n"
			: : "r"(t) : "r0" , "cc");
}

//Pulse the enable signal to the GLCD
//Need to do this in order to send a command to the GLCD
void en_pulse() {
	GPIOB->ODR |= (1 << EN);
	micro_wait(5);
	GPIOB->ODR &= ~(1 << EN);
	micro_wait(5);
}

//Initialize GPIOB
void gpiob_init() {
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

	GPIOB->MODER |= 	GPIO_MODER_MODER13_0 | GPIO_MODER_MODER12_0 |
						GPIO_MODER_MODER11_0 | GPIO_MODER_MODER10_0 |
						GPIO_MODER_MODER9_0  | GPIO_MODER_MODER8_0  |
						GPIO_MODER_MODER7_0  | GPIO_MODER_MODER6_0  |
						GPIO_MODER_MODER5_0  | GPIO_MODER_MODER4_0  |
						GPIO_MODER_MODER3_0  | GPIO_MODER_MODER2_0  |
						GPIO_MODER_MODER1_0  | GPIO_MODER_MODER0_0 ;

	GPIOB->ODR &= ~0xFFFF;
}

void clear_data() {
	GPIOB->ODR &= ~0xFF;
}

//Initialize GLCD
void GLCD_init() {
	GPIOB->ODR |= (1 << CS2);
	micro_wait(10);
	GPIOB->ODR |= (1 << RES);
	micro_wait(10);
	GPIOB->ODR &= ~(1 << RES);
	micro_wait(10);
	GPIOB->ODR &= ~(1 << CS2);
	GPIOB->ODR |= (1 << CS1);
	micro_wait(10);
	GPIOB->ODR |= (1 << RES);
	GPIOB->ODR |= (1 << CS2);
	micro_wait(10);
}

void GLCD_on() {
	GPIOB->ODR |= (1 << CS1);
	GPIOB->ODR &= ~(1 << CS2);
	GPIOB->ODR &= ~(1 << RS);
	GPIOB->ODR &= ~(1 << RW);
	GPIOB->ODR &= ~0xFF;		//clear D0-D7
	GPIOB->ODR |=  0x3F;		//ON command
	en_pulse();


	GPIOB->ODR &= ~(1 << CS1);
	GPIOB->ODR |= (1 << CS2);
	GPIOB->ODR &= ~(1 << RS);
	GPIOB->ODR &= ~(1 << RW);
	GPIOB->ODR &= ~0xFF;		//clear D0-D7
	GPIOB->ODR |=  0x3F;
	en_pulse();
}

void set_line(uint8_t line) {
//	uint8_t l = (uint8_t) line;
	GPIOB->ODR &= ~(1 << RS);
	GPIOB->ODR &= ~(1 << RW);
	GPIOB->ODR &= ~(0xFF);
	GPIOB->ODR |= (0xC0 | line);
	en_pulse();
}

void goto_col(uint8_t x) {
	GPIOB->ODR &= ~(1 << RS);
	GPIOB->ODR &= ~(1 << RW);
	uint8_t col;
	if(x < 64){
		GPIOB->ODR &= ~(1 << CS1);
		GPIOB->ODR |=  (1 << CS2);
		col = x;
	}
	else {
		GPIOB->ODR |=  (1 << CS1);
		GPIOB->ODR &=  ~(1 << CS2);
		col = x - 64;
	}
	col = (col | 0x40) & 0x7F;
	GPIOB->ODR &= ~(0xFF);
	GPIOB->ODR |= col;
	en_pulse();
}

void goto_row(uint8_t y) {
	uint8_t row;
	GPIOB->ODR &= ~(1 << RS);
	GPIOB->ODR &= ~(1 << RW);
	row = (y | 0xB8);
	GPIOB->ODR &= ~(0xFF);
	GPIOB->ODR |= row;
	en_pulse();
}

void goto_xy(uint8_t x, uint8_t y) {
	goto_col(x);
	goto_row(y);
}

void GLCD_write(uint8_t data) {
	GPIOB->ODR |=  (1 << RS);
	GPIOB->ODR &= ~(1 << RW);
	GPIOB->ODR &= ~(0xFF);
	GPIOB->ODR |= data;
	micro_wait(1);
	en_pulse();
}

void GLCD_clearLine(uint8_t ln) {
	int i;
	goto_xy(0, ln);
	micro_wait(1);
	for(i = 0; i < 64; i += 1){
		screen[i][ln][0] = 0x00;
		GLCD_write(0x00);
	}
	micro_wait(1);
	goto_xy(64, ln);
	for(i = 0; i < 64; i += 1) {
		screen[i][ln][1] = 0x00;
		GLCD_write(0x00);
	}
}

void GLCD_clear() {
	uint8_t m;
	for (m = 0; m < 8; m += 1) {
		micro_wait(1);
		GLCD_clearLine(m);
	}
}

void dot(uint8_t x, uint8_t y, int color) {
	uint8_t row = y / 8;
	uint8_t col = x % 64;
	uint8_t scr = x >> 6;
	uint8_t pix = y % 8;
	if(x < 0 || y < 0 || x >= 128 || y >= 64){

	}else{
		goto_xy(x, row);
		if (color == 1) {
		screen[col][row][scr] |= (1 << pix);
		}
		else screen[col][row][scr] &= ~(1 << pix);
		GLCD_write(screen[col][row][scr]);
	}
}

void GLCD_fill() {
	uint8_t n;
	for (n = 0; n < 8; n += 1) {
		micro_wait(1);
		GLCD_fillLine(n);
	}
}

void GLCD_fillLine(uint8_t ln) {
	int i;
	goto_xy(0, ln);
	micro_wait(1);
	for(i = 0; i < 64; i += 1){
		screen[i][ln][0] = 0xFF;
		GLCD_write(0xFF);
	}
	micro_wait(1);
	goto_xy(64, ln);
	for(i = 0; i < 64; i += 1) {
		screen[i][ln][1] = 0xFF;
		GLCD_write(0xFF);
	}
}

void rectangle(uint8_t x, uint8_t y, uint8_t a, uint8_t b , int color) {
	uint8_t j;
	uint8_t i;
	for(i = 0; i <= b; i++){
		for(j = 0; j <= a; j++){
			dot(x + i, y + j, color);
		}
	}
}

void line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2 , int color) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	int x;
	int y;
	for(x = x1; x < x2; x+=1){
		y = y1 + dy * (x - x1) /dx;
		dot(x, y, color);
	}
}
void circle(uint8_t x_center, uint8_t y_center, uint8_t r, int color) {
	uint8_t x = r;
	uint8_t y = 0;

	dot (x + x_center, y + y_center, color);

	if (r > 0) {
		dot(x + x_center, y_center, color);
		dot (y + x_center, x + y_center, color);
		dot (x_center - y, x + y_center, color);
	}
	int P = 1 - r;
	while(x > y) {
		y = y + 1;
		if (P <= 0) P = P + 2*y + 1;
		else {
			x= x -1;
			P = P + 2*y - 2*x + 1;
		}
		if (x < y) break;

		dot(x + x_center, y + y_center, color);
		dot(x_center - x, y + y_center, color);
		dot(x + x_center, y_center - y, color);
		dot(x_center - x, y_center - y, color);

		if (x != y) {

			dot(y + x_center, x + y_center, color);
			dot(x_center - y, x + y_center, color);
			dot(y + x_center, y_center - x, color);
			dot(x_center - y, y_center - x, color);
		}
	}
}

void image(uint8_t* sprite, int w, int h, uint8_t x, uint8_t y){
	int i;
	int j;
	for(i = 0; i < w; i++){
		for(j = 0; j < h; j++){
			dot(x+j, y+i, *((sprite+i*h) + j));
		}
	}
}
