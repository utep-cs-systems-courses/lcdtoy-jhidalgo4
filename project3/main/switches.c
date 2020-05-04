//switches.c
#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachine.h"
#include "lcdutils.h"
#include "lcddraw.h"

unsigned char curState = 0;

char switch_state_down1, switch_state_down2, switch_state_down3, switch_state_down4;
char switch_state_down, switch_state_changed;
char curX = 30;
char curY = 30;
char newX = 30;
char newY = 30;
int backColor = COLOR_BLACK;
int drawColor = COLOR_RED;


static char
switch_update_interrupt_sense(){
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);  // if switch up, sense down
  P2IES &= (p2val | ~SWITCHES);  //if switch down, sense up
  return p2val;
}

void
switch_init(){
  P2REN |= SWITCHES;  //enable registers for switches
  P2IE = SWITCHES;  //enable interrupts from switches
  P2OUT |= SWITCHES;  //pullups for switches
  P2DIR &= ~SWITCHES;  //set switches bits for input
  switch_update_interrupt_sense();
  led_update();
  
}


// Called when a button is pushed on MSP430 from Interrput
void
switch_interrupt_handler(){
  char curCase = 0; // relates to the state of the machine from button pushed
  
  char p2val = switch_update_interrupt_sense(); //update 
  switch_state_down1 = (p2val & sw1) ? 0:1;  //switch_state_down: 1 if down, 0 if up  booleans
  switch_state_down2 = (p2val & sw2) ? 0:1; 
  switch_state_down3 = (p2val & sw3) ? 0:1;
  switch_state_down4 = (p2val & sw4) ? 0:1;

  //these methods connect to lcddemo.c
  //diamondSqu(curX, curY, drawColor);
  drawShape4(curX, curY, drawColor);


  
  if(switch_state_down1){
    curState = 1;
    newX = newX - 1;
    checkShape(backColor, drawColor); //pass background color and drawing color
    play_noise();
  }
  
  else if (switch_state_down2){
    curState = 2;
    newY = newY -1;
    checkShape(backColor, drawColor);
    play_noise();
  }
  
  else if (switch_state_down3){
    curState = 3;
    newY = newY +1;
    checkShape(backColor, drawColor);
    play_noise();
  }
  
  else if (switch_state_down4){
    curState = 4;
    newX = newX + 1;
    checkShape(backColor, drawColor); //pass background color & drawing color
    play_noise();
  }
}

