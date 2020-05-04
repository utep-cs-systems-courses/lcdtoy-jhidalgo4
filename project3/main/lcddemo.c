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
    drawShape4(curX, curY, colorP); //easrse old
   
    curX = newX;
    curY = newY;
    drawShape4(newX, newY, colorN); //update new
  }
}


void drawShape1(){
  drawString5x7(5,5, "Joaquin", COLOR_WHITE, COLOR_NAVY);
}

//Triangle
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

// DOWN-WARD ARROW
void drawShape3(char curX, char curY, int colorP){
  //bottom pointer of arrow
  for(int c =0; c<40; c++){
    if(c<= 40/2){
      for(int r =0; r<c;r++){
	drawPixel(c+curX, r+curY, colorP);
      }
    }
    else{
      for(int r = 0;r< 40-c;r++ ){
	drawPixel(c+curX, r+curY, colorP);
      }
    }
  }

  //top part of Arrow (square)
  for(int i=0;i<20;i++){
    for(int j=0;j<10;j++){
      drawPixel(i+curX+10, curY-j, colorP);
    }
  }
}


//DIAMOND
void drawShape4(char curX, char curY, int colorP){
  //bottom part of DIAMOND
  for(int c =0; c<40; c++){
    if(c<= 40/2){
      for(int r =0; r<c;r++){
	drawPixel(c+curX, r+curY, colorP);
      }
    }
    else{
      for(int r = 0;r< 40-c;r++ ){
	drawPixel(c+curX, r+curY, colorP);
      }
    }
  }

  //top part of Diamond (trapizoid)
  for(int i=0;i<20;i++){
    for(int j=0;j<10;j++){
      drawPixel(i+curX+10, curY-j, colorP);
    }
  }

  for(int i =0; i<10;i++){
    for(int j =0;j<i;j++){
      drawPixel(i+curX, curY-j, colorP);
    }
  }

  for(int i =0; i<10;i++){
    for(int j=9-i; j>=0;j--){
      drawPixel(i+curX+30, curY-j, colorP);
    }
  }
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


