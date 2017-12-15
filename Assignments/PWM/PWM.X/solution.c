#include <xc.h>
#include "solution.h"
#include "main.h"
#include <math.h>

// This is the periode corresponding to 100% duty cycle
#define PR 50000

void solution()
{
    // Setup timer 1 for timekeeping
    T1CONbits.TCKPS = 1;        // prescaler 8
    T1CONbits.ON = 1;           // T1 on
    int ms = 0;
    
    // Setup timer 2 for use with the output compare module
    T2CONbits.TCKPS = 0b100;    // prescaler 16
    PR2 = PR;                   // 100 Hz
    T2CONbits.ON = 1;           // T2 on
    
    // Setup the output compare module 
    OC2RS = 0;                  // Initialuse duty cycle to 0%
    OC2CONbits.OCM = 0b110;     // PWM mode
    OC2CONbits.ON = 1;          // OC2 on
    
    while(1)
    {
        if(TMR1 >= 10000)   // If a millisecond has passed
        {
            TMR1 -= 10000;  // Subtract the equivalent value for a millisecond from the timer register
            ms++;           // Increment the millisecond time variable
            OC2RS = breathEffect(ms)*PR; // Adjust duty cycle by the "breathing" effect
        }
    }
}