/* 
 * File:   main.c
 * Author: SVU
 *
 * Created on 07 December 2017, 18:11
 */

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include <xc.h>

#ifdef SOLUTION
    #include "solution.h"
#endif
/*
 *  Assignment:
 *      Write a program that allows you to turn on/off LD4 or LD5
 *      by sending commands from your computer over the serial UART interface.
 *      
 *      It is reccomended that the commands be simple, as you will have to 
 *      interpret them in your code on the microcontroller
 * 
 *      as a part two to the assignment, send a usage guide to the terminal
 *      if a non valid command is recieved
 */
int main(int argc, char** argv) {

    #ifdef SOLUTION
        solution();
    #else
        // TODO: Write your code here
        
        
    #endif
    
    return (EXIT_SUCCESS);
}