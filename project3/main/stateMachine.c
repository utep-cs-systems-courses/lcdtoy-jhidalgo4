//USE ASSEMBLY FILE INSTEAD
//stateMachine.c file

#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

// curState is the state of the machine depending on switches.c the button pushed
void stateMachine(){
  char changed = 0;   
  switch(curState){
  case 1: changed = state1_red(); break;
  case 2: changed = state4_bothOff(); break;
  case 3: changed = state3_bothOn(); break;  //Dimmed 2 lights
  case 4: changed = state2_green(); break; 
  }
  led_changed = changed;
  led_update(); 
  
}
