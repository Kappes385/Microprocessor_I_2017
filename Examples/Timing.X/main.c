/* 
 * File:   main.c
 * Author: SVU
 *
 * Created on 01 December 2017, 09:23
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "config.h"
/*
 * 
 */
int main(int argc, char** argv) {
    TRISCbits.TRISC1 = 0;
    TRISAbits.TRISA3 = 0;
    T1CONbits.TCKPS = 1;
    T1CONbits.ON = 1;
    int ms = 0;
    
    while(1)
    {
        if(TMR1 >= 1000)
        {
            LATAbits.LATA3 = !LATAbits.LATA3;
            ms++;
            TMR1 -= 1000;
            if(ms%1000 == 0)
            {
                LATCbits.LATC1 = !LATCbits.LATC1;
            }
        }
    }
    return (EXIT_SUCCESS);
}

