/* 
 * File:   main.c
 * Author: SVU
 *
 * Created on 15 December 2017, 09:03
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <proc/p32mx795f512l.h>
#include "../config.h"

/*
 * 
 */
int main(int argc, char** argv) {

    TRISDbits.TRISD0 = 1; // Button on D0 is input
    
    T2CONbits.TCKPS = 0b101; // prescaler = 32
    PR2 = 50000;
    OC3RS = 5000;
    OC3CONbits.OCM = 0b110; // PWM without fault detection
    
    OC3CONbits.ON = 1;  // OC3 on 
    T2CONbits.ON = 1;   // T2 on
    
    while(1)
    {
        if(PORTDbits.RD0 == 1)
        {
            OC3RS = 50000*0.05;
        }
        else
        {                    
            OC3RS = 50000*0.1;
        }

    }
    
    return (EXIT_SUCCESS);
}

