#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "solution.h"
#include <string.h>

#define LD4ON()  (LATASET = 0b1000) // set the fourth bit of the LATA register
#define LD4OFF() (LATACLR = 0b1000) // clear the fourth bit of the LATA register
#define LD4T()   (LATAINV = 0b1000) // invert the fourth bit of the LATA register
#define LD5ON()  (LATCSET = 0b10) // set the second bit of the LATC register
#define LD5OFF() (LATCCLR = 0b10) // clear the second bit of the LATC register
#define LD5T()   (LATCINV = 0b10) // invert the second bit of the LATC register

typedef enum {false, true} bool;

void solution()
{
    init();

    char rxBuf[100] = "";
    int bufIndex = 0;
    
    while(1)
    {
        if(U1STAbits.URXDA) // if data is available, put char in buffer
        {
            rxBuf[bufIndex] = U1RXREG;
            if(rxBuf[bufIndex] == '\n')
            {   // recieved newline
                rxBuf[bufIndex] == '\0';
                parseCommand(rxBuf);
                bufIndex = 0;
            }
            else
            {
                bufIndex++;
            }
        } 
    }
}

void init()
{
    // GPIO configuration
    // set up the LEDs as turned off outputs
    LATAbits.LATA3 = 0;
    TRISAbits.TRISA3 = 0;
    LATCbits.LATC1 = 0;
    TRISCbits.TRISC1 = 0;
    
    // UART configuration
    U1BRG = 80000000/(16*9600)-1; // Set baudrate to 9600 baud
    U1STAbits.UTXEN = 1; // Enable trasnmit functionality
    U1STAbits.URXEN = 1; // Enable recieve functionality
    U1MODEbits.ON = 1; // Turn on UART module
}

void parseCommand(char *command)
{
    int i;
    bool validCommand = false;
    // List of valid commands
    static const char *commands[] = {"LD4ON", "LD4OFF", "LD4T", "LD5ON", "LD5OFF", "LD5T"}; 

    for(i = 0; i < 6; i++)
    {   // See if any of the commands match the recieved message
        if (strstr(command, commands[i]) != NULL)
        { 
            switch(i)
            {
                case 0: // LD4ON
                    LD4ON();
                    validCommand = true;
                    break;
                case 1: // LD4OFF
                    LD4OFF();
                    validCommand = true;
                    break;
                case 2: // LD4T
                    LD4T();
                    validCommand = true;
                    break;
                case 3: // LD5ON
                    LD5ON();
                    validCommand = true;
                    break;
                case 4: // LD5OFF
                    LD5OFF();
                    validCommand = true;
                    break;
                case 5: // LD5T
                    LD5T();
                    validCommand = true;
                    break;
            }
        }
    }
    if(validCommand == false)
    {   // If the command was not valid, send the user guide
        sendUserGuide();
    }
}

// Note that this is not a good function as it contains blocking code
void sendUserGuide()
{
    // User guide variable
    char *ug = "\nUsage:\n\tLD#ON  - switch LD# ON\n\tLD#OFF - switch LD# OFF\n\tLD#T   - toggle the state of LD#\n\t\tWhere # is either 4 or 5\n";
    int i = 0;
    while(ug[i]) // as long as the current char is not the null character, keep sending 
    {
        if(!U1STAbits.UTXBF) // only send if the transmit buffer is not full
        {
            U1TXREG = ug[i++]; // add the next character
        }
    }
}
