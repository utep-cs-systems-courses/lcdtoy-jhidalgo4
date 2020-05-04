//Joaquin Hidalgo
//Main file -> runner.c
#include <msp430.h>
#include "../timerLib/libTimer.h"   //clock timer
#include "buzzer.h"   //buzzer
#include "led.h"   //led's
#include "switches.h"   //switches & buttons
#include "stateMachine.h"
#include "lcdutils.h"
#include "lcddraw.h"

int main(void){
  configureClocks(); //setup mast OSC, CPU & periperal clocks
  
  buzzer_init();
  switch_init();
  led_init();
  lcd_init();
  enableWDTInterrupts();
  unsigned char width = screenWidth;
  unsigned char height = screenHeight;
  clearScreen(COLOR_BLACK);
  or_sr(0x18); //CPU off, GIE on
}
