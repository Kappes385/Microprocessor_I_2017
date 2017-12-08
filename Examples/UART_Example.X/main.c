

#include <stdlib.h>
#include <stdio.h>
#include "../config.h"
#include <xc.h>

int main(int argc, char **argv)
{
    U1STAbits.UTXEN = 1; // Enable transmit 
    U1STAbits.URXEN = 1; // Enable recieve
    U1BRG = 80000000/(16*19200)-1; // Set BRG to 19200 Baud
    U1MODEbits.ON = 1; // Turn on UART module
    char c;
    while(1)
    {    
        if (U1STAbits.URXDA) // if data is available
        {
            c = U1RXREG; // read data 
            if (!U1STAbits.UTXBF) // If there is room in the transmission buffer
            {
                if(c >= 'A' && c <= 'Z') // given a capital letter
                {
                    U1TXREG = c + ('a'-'A'); // send lovercase equivalent letter
                }
                else if (c >= 'a' && c <= 'z') // given lower case letter
                {
                    U1TXREG = c - ('a'-'A'); // end uppercase letter
                }
            }
        }
    }
    return 0;
}
