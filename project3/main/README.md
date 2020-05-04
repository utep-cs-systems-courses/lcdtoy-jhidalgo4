Joaquin Hidalgo
Due Date: May 3,2020

------------------------------------------------
HOW TO RUN:
1. start by running the command line "make" in the timerLib Directory.
2. run the command line "make install" inside the timerLib Directory.
3. Run the command line "make" inside the main Directory
4. Run the command line "make load" onto the MSP420 (make sure the msp430 is connected)
5. END

ALT:
2.1 If you want to clean .o files, run line code "make clean"
2.2 END

3.1 If you want to clean .o files & *~ files, run line of code "make clean"
3.2 END

4.1 If you want to stop work load just execute into command line: "mspdebug
rf2500"erase" "
4.2 END

-------------------------------------------------
WHAT IT DOES: it makes lights, DIM lights and plays noises when you press a
button. pretty cool toy.


-far left button moves shape to the LEFT & plays small jingle and shows 2 in binary thru LED

-mid left button moves shape UP & plays small jingle and turns OFF LED's 

-mid right button moves shape DOWN & plays short jingle and shows 3 in binary thru LED - DIM LIGHT

-far right button moves shape to the RIGHT & plays short jingle and shows 1 in binary thru LED


------------------------------------------------
Classes involved:
Main.c
Interupter.c
buzzer.c /.h
led.c /.h
switches.c /.h
stateMachine.c /.h
lcdutils.c /.h
lcddemo.c
lcddraw.c /.h
3 font files
