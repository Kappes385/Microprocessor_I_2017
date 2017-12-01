/* 
 * File:   main.c
 * Author: SVU
 *
 * Created on 30 November 2017, 10:53
 */
#include <xc.h>

void solution()
{
    int ms = 0; // Counter variable to increment every millisecond
    T1CONbits.TCKPS = 1; // Set prescaler to 8 reducing the effective clock to 1MHz
    T1CONbits.TON = 1; // Turn on the timer
    TRISCbits.TRISC1 = 0; // LD5 is an output
    TRISAbits.TRISA3 = 0; // LD4 is an output
    
    while(1) // Infinite loop
    {
        if(TMR1 >= 10000) // If the timer counter has exceeded 10000, one millisecond has passed
        {
            ms++; // Increment the millisecond counter
            TMR1 -= 10000; // decrement the timer counter
            if(ms%500 == 0) // every 500 milliseconds, toggle LD5
            {    
                LATCbits.LATC1 = !LATCbits.LATC1; // invert LATC1
            }
            if(ms%200 == 0) // every 200 milliseconds, toggle LD5
            {
                LATAbits.LATA3 = !LATAbits.LATA3; // invert LATA3
            }
        }
    }
}
