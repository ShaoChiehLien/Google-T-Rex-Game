/*
 * glcd.h
 *
 *  Created on: Nov 25, 2019
 *  Updated: 8:00 11/27/2019
 *      Author: dave
 */

#ifndef GLCD_H_
#define GLCD_H_

void nano_wait(int t);
void micro_wait(int t);
void en_pulse(void);
void gpiob_init(void);//first to do
void clear_data(void);
void GLCD_init(void);//second to do
void GLCD_on(void);//turn on the lcd(could still write data)
void set_line(uint8_t line);//just run set_line(0);
void goto_col(uint8_t x);//select the column(Won't need in main)
void goto_row(uint8_t y);//select the row(Won't need in main)
void goto_xy(uint8_t x, uint8_t y);//select the xy(Won't need in main)
void GLCD_write(uint8_t data);//(Won't need in main)
void GLCD_clearLine(uint8_t ln);//clear the row line
void GLCD_clear(void);//clear the whole screen
void dot(uint8_t x, uint8_t y, int color);//All the stuffs are taken care
void GLCD_fill(void);//fill the entire screen with black
void GLCD_fillLine(uint8_t ln);//fill the entire line with black
void rectangle(uint8_t x, uint8_t y, uint8_t a, uint8_t b, int color);//All the stuffs are taken care
void line(uint8_t x, uint8_t y, uint8_t a, uint8_t b, int color);//Draws a line between two lines
void circle(uint8_t x, uint8_t y, uint8_t r, int color);//Draws a circle between two lines(x y center)
void image(uint8_t *sprite, int w, int h, uint8_t x, uint8_t y);
#endif /* GLCD_H_ */

