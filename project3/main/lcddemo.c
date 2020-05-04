//file lcddemo.c


#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"
#include "stateMachine.h"
#include "led.h"


//passed in background color
void checkShape(int colorP, int colorN){
  if (curX != newX || curY != newY){
    
    // here change method to fit current shape inside "switches.c"
    drawShape2(curX, curY, colorP); //easrse old
    drawShape2(newX, newY, colorN); //update new
    curX = newX;
    curY = newY;
  }
}


void drawShape1(){
  drawString5x7(5,5, "Joaquin", COLOR_WHITE, COLOR_NAVY);
}

void drawShape2(char curX, char curY, int colorP){
  //fillRectangle(curX,curY, 60, 60, COLOR_RED);
  for(int c =0; c<40; c++){
    char rowStart = 0;
    char rowEnd = c;
    for(int r =0; r<rowEnd; r++){
      drawPixel(c+curX, r+curY, colorP);
    }
  }    
}

void drawShape3(){ 
  
}

void drawShape4(){ 
  
}

void diamondSqu(char curX, char curY, int colorP){
  for(int r = 0; r<40;r++){
    char colL = 40 - r;
    char colR = 40;
    for(int c = r; c<= 40; c++){
      drawPixel(curX+c, curY+r, colorP);
      drawPixel(curX+c, curY-r, colorP);
      drawPixel(curX-c, curY-r, colorP);
      drawPixel(curX-c, curY+r, colorP);
      
    }
  }
}



  /*
// triangle - bottom left corner of screen. also called, half the width  
  for(int j =0; j<40;j++){
    drawPixel(0,j, COLOR_GREEN); //up and down
    drawPixel(j/2, 40, COLOR_GREEN); //left and right
    drawPixel(j/2, j, COLOR_GREEN);    //diagnol
    
  }
  */


  
  
//triangle - top part of the house
//  yLimit = 20;
//  for(j =0; j<max;j++){
//    drawPixel(j, yLimit, COLOR_GREEN); //botom flat
//    if(j< max/2){
//      drawPixel(j, yLimit-j, COLOR_GREEN); 
//    }
//    else{
//      drawPixel(j, j-yLimit, COLOR_GREEN);
//    }
//  }
  


  
  /*
//right trangle - bottom left screen triangle, equals w&h 
  for(j =0; j<15;j++){
    drawPixel(xLimit,j, COLOR_GREEN);
    drawPixel(j, j, COLOR_GREEN);
    drawPixel(j, 15, COLOR_GREEN);    
  }  
*/


