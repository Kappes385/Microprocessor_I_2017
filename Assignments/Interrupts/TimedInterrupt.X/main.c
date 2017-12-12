/* 
 * File:   main.c
 * Author: Svutborg
 *
 * Created on 12 December 2017, 16:57
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../config.h"
#include "../../macros.h"
#include <xc.h>

#ifdef SOLUTION
    #include "solution.h"
#endif
/*
 *  Assignment:
 *      Write a program that uses a timed interrupt to toggle a led every 500 ms
 *      
 *      Remember that even though you do not need to run any code in a loop for this
 *      you will still need the infinite loop at the end to keep your program running
 * 
 *      As a port two the exercise, setup an interrupt on a button to switch the timed interrupt on/off
 */
int main(int argc, char** argv) {

    #ifdef SOLUTION
        solution();
    #else
        // TODO: Write your code here
        
        
    #endif
    
    return (EXIT_SUCCESS);
}