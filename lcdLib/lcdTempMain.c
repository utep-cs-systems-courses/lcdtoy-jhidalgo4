/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;
  u_char j;

  clearScreen(COLOR_BLACK);
  char xLimit = 0;
  char yLimit = 0;
  char max = 40;

/* 
// triangle - bottom left corner of screen. also called, half the width  
  for(int j =0; j<40;j++){
    drawPixel(0,j, COLOR_GREEN); //up and down
    drawPixel(j/2, 40, COLOR_GREEN); //left and right
    drawPixel(j/2, j, COLOR_GREEN);    //diagnol
    
  }
*/


  
/*  
//triangle - top part of the house yLimit(20) x max(40)
  yLimit = 20;
  for(j =0; j<max;j++){
    drawPixel(j, yLimit, COLOR_GREEN); //botom flat
    if(j< max/2){
      drawPixel(j, yLimit-j, COLOR_GREEN); 
    }
    else{
      drawPixel(j, j-yLimit, COLOR_GREEN);
    }
  }
*/


  
/*
//right trangle - bottom left screen triangle, equals w&h 
  for(j =0; j<15;j++){
    drawPixel(xLimit,j, COLOR_GREEN);
    drawPixel(j, j, COLOR_GREEN);
    drawPixel(j, 15, COLOR_GREEN);    
  }  
*/
  
}
