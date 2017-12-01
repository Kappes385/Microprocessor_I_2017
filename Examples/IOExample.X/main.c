/* 
 * File:   main.c
 * Author: SVU
 *
 * Created on 01 December 2017, 08:44
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
/*
 * 
 */
int main(int argc, char** argv) {

    TRISCbits.TRISC1 = 0; // LD5 is an output
    TRISAbits.TRISA3 = 0; // LD4 is an output
    TRISAbits.TRISA2 = 1; // Button is an input
    LATCbits.LATC1 = 1; // LD5 ON
    LATAbits.LATA3 = 0; // LD4 OFF
    
    
    while(1)
    {
        LATAbits.LATA3 = !PORTAbits.RA2;
    }
    
    return (EXIT_SUCCESS);
}

