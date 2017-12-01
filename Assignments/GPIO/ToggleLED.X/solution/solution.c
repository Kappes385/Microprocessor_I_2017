
#include <xc.h>
#include <proc/p32mx795f512l.h>

#include "solution.h"

void solution()
{
    TRISAbits.TRISA3 = 0;   // RA3 -> Output
    TRISCbits.TRISC1 = 0;   // RC1 -> Output
    TRISAbits.TRISA2 = 1;   // RA2 -> Input
    int state = 0;          // This state variable is to keep track of changes of the state of the button on port RA2
    int state2 = 0;
    
    while(1)
    {
        if(state != PORTAbits.RA2) 
        {   // If the state has changed update the state variable and toggle the LED
            state = PORTAbits.RA2;
            if (state == 0)
            {   // if the button is pressed
                //LATAINV = 1<<3; // invert the 4th bit on LATA register (LATA3)
                LATAbits.LATA3 = !LATAbits.LATA3; // Toggle LD4
                state2 = !state2;
                if (state2 == 0)
                {
                    LATCINV = 1<<1; // invert the 2nd bit on LATC register (LATC1)
                }
            }
        }
    }
}
