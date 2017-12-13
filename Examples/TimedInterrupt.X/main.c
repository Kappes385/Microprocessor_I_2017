/* 
 * File:   main.c
 * Author: SVU
 *
 * Created on 13 December 2017, 09:11
 */

#include <stdio.h>
#include <stdlib.h>
#include "../config.h"
#include <xc.h>
#include <sys/attribs.h>

/*
 * 
 */
int ms;

int main(int argc, char** argv) {
    __asm__("DI");
    
    ms = 0;
    TRISCbits.TRISC1 = 0; // LD5 is output
    LATCbits.LATC1 = 0; // LD5 is off
    
    INTCONbits.MVEC = 1; // Multivector interrupts
    IPC4bits.T4IP = 3;  // set prirority to 3
    IEC0bits.T4IE = 1;  // Enable interrupts for Timer 4
    
    __asm__("EI");
    
    T4CONbits.TCKPS = 0b11; // 3
    PR4 = 10000;            // Set timer perioud to 10000
    T4CONbits.ON = 1;       // Turn on Timer 4
    
    
    while(1)
    {
        
    }
    return (EXIT_SUCCESS);
}

void __ISR(16, ipl3SOFT) Timer4ISR(void)
{
    ms++;
    if(ms%500 == 0)
    {
        LATCbits.LATC1 = !LATCbits.LATC1;
    }
    IFS0bits.T4IF = 0;
}

