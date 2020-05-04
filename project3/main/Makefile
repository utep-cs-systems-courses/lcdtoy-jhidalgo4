all: libLcd.a project3.elf

CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h 
LDFLAGS 	= -L/opt/ti/msp430_gcc/include -L../lib 
#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

libLcd.a: font-11x16.o font-5x7.o font-8x12.o lcdutils.o lcddraw.o
	$(AR) crs $@ $^

lcddraw.o: lcddraw.c lcddraw.h lcdutils.h
lcdutils.o: lcdutils.c lcdutils.h

install: libLcd.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

clean:
	rm -f libLcd.a *.o *.elf *~ *#

project3.elf: wdInterruptHandler.o lcddemo.o libLcd.a stateMachine.o led.o switches.o buzzer.o runner.o  ../lib/libTimer.a  
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer 

load: project3.elf
	msp430loader.sh $^

