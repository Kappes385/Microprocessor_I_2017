#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "solution.h"
#include "../../macros.h"
#include <sys/attribs.h>


// comment out this define to disable the button interrupt
#define USE_EXTERNAL_INTERRUPTS


void solution()
{
    __asm__("DI");      // Disable interrupts

    INITLD();
    initInterrupts();   // Initialise interrupt settings
    initTimer1(10000);  // Init timer1 with perioud 10000 -> should result in 1ms periouds
    
    __asm__("EI");      // Enable interrupts    
    while(1)
    {   
        // We are not doing anything here. We could have had all sorts of code running here...
    }
}

void initTimer1(int PR)
{
    T1CONbits.ON = 0;   // Turn off timer
    T1CONbits.TCKPS = 1; // Set prescaler to 8 
    PR1 = PR;           // Set perioud register
    T1CONbits.ON = 1;   // Turn on timer
}

void initInterrupts()
{
    INTCONbits.MVEC = 1;    // multivector interrupt mode
    
    IEC0bits.T1IE = 1;      // Enable interrupts for Timer1
    IPC1bits.T1IP = 1;      // Set interrupt priority to 1  
    #ifdef USE_EXTERNAL_INTERRUPTS
        IEC0bits.INT0IE = 1; // Enable external interrupt 0
        IPC0bits.INT0IP = 2; // Set interrupt priority to 2  
    #endif
}

void __ISR(4, ipl1SOFT) Timer1ISR(void)
{
    static int ms = 0;
    ms++; // increment ms counter
    #ifdef USE_EXTERNAL_INTERRUPTS
        IFS0bits.INT0IF = 0; // This clears the button interrupt flag
    #endif
    if(ms%500)  // Every 500ms toggle LD5
    {
        LD5T();
    }
    if(ms%5000)  // Every 500ms toggle LD5
    {
        LD4T();
    }
    IFS0bits.T1IF = 0;  // Clear interrupt flag
}

#ifdef USE_EXTERNAL_INTERRUPTS
void __ISR(3, ipl2SOFT) ButtonISR(void)
{
    IEC0bits.T1IE = !IEC0bits.T1IE; // invert the enable flag for Timer1 interrupts
    
    IFS0bits.INT0IF = 0; // This clears the button interrupt flag
}
#endif