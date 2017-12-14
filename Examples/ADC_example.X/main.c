/* 
 * File:   main.c
 * Author: SVU
 *
 * Created on 14 December 2017, 09:07
 */

#include <stdio.h>
#include <stdlib.h>
#include "../config.h"
#include <xc.h>
#include <proc/p32mx795f512l.h>

/*
 * 
 */
int main(int argc, char** argv) {
    AD1CON1bits.SSRC = 0b111;   // Auto convert mode
    AD1CON1bits.ASAM = 1;       // Auto start
    AD1CON2bits.CSCNA = 1;      // Configure to scan mode
    AD1CON3bits.SAMC = 0b11111; // Max sample time
    AD1CSSLbits.CSSL0 = 1;      // scan RB0
    
    AD1CON1bits.ON = 1;         // Turn on ADC
    
    U1STAbits.UTXEN = 1;        // Enable uart transmit
    U1BRG = 80000000/(19200*16)-1; // Set up Baudrate
    U1MODEbits.ON = 1;          // UART on
    
    while(1)
    {
        if (!U1STAbits.UTXBF)
        {
            U1TXREG = ADC1BUF0>>2;
        }
        
    }
    
    return (EXIT_SUCCESS);
}

