#include <math.h>
#include <stdio.h>
#include <xc.h>
#include "tone.h"


void init_tone()
{
    T1CONbits.TCKPS = 0b00; // ps 1:1
    OC5CONbits.OCM = 0b110; // PWM mode on OCx; Fault pin disabled
    T2CONbits.ON = 1;
    OC5CONbits.ON = 1; 
}

void set_tone(tone t)
{
    if(t.octave <= 0b111 && t.octave > 0 && t.l >= C && t.l <= B)
    {
        T2CONbits.TCKPS = 0b111-t.octave;
        // 6019.67 is a constant obtained as 10000000/64/(2^((-49)/12)*440)
        PR2 =  5061.92/pow(2,t.l/12.0); 
        OC5RS = PR2 >> 1; // 50% duty cycle 
    }
    else
    {
        OC5RS = 0;
    }
}

void clear_tone()
{
    //static tone t = {C, 0};
    set_tone(no_tone); // Invalid tone,
}

void play_note(note n)
{
    TMR1 = 0;
    int ms = 0;
    T1CONbits.ON = 1;
    set_tone(n.t);
    
    while(ms < n.duration)
    {
        if(TMR1 >= 10000)
        {
            ms++;
            TMR1 -= 10000;
        }
    }
}
