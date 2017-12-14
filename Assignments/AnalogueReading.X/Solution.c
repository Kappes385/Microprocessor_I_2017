#include "Solution.h"
#include "main.h"
#include <xc.h>


void solution()
{
    int ms = 0;
    initADC();
    initTimer1();
    
    while(1)
    {
        if(TMR1 >= 10000)
        {
            TMR1 -= 10000;
            ms++;
            if(ms%500==0)
            {
                transmitMilliVolts(ADC1BUF0);
            }
            
        }
    }
}

void initTimer1()
{
    T1CONbits.TCKPS = 1;    // prescaler set to 8
    T1CONbits.ON = 1;       // Turn on timer
}

// Initialise ADC
void initADC()
{
    AD1CON1bits.SSRC = 0b111;   // Auto convert
    AD1CON1bits.ASAM = 1;       // Auto start
    AD1CON2bits.CSCNA = 1;      // Scan inputs
    AD1CON3bits.SAMC = 0b11111; // Max time for sampling
    AD1CSSLbits.CSSL0 = 1;      // scan AN0/RB0
    AD1CON1bits.ON = 1; // Turn on ADC module 1
}

// just for debugging 
void transmitBinaryDigits(int num)
{
    while(num > 0)
    {
        if(!U1STAbits.UTXBF)
        {
            U1TXREG = (num&0b1)?'1':'0';
            num = num>>1;
        }
    }
    while(U1STAbits.UTXBF);
    
    U1TXREG = '\n';
    
}