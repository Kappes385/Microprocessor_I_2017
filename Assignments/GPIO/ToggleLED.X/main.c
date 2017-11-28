/* 
 * File:   main.c
 * Author: SVU
 *
 * Created on 24 November 2017, 09:31
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#ifdef SOLUTION
    #include "solution/solution.h"
#endif
/*
 *  Assignment:
 *      Wire-up the circuit shown in the picture in the resources folder
 *      Write your program so that pushing the button toggles either LD4 or LD5
 *      once per push
 *          Note: the button pin should be configured as an input and the pin for
 *          the LED should be configured as an output.
 *          You will also need some code to notice when the state of the button
 *          changes from high to low
 *      As a second part have the other LED toggle every other push
 */
int main(int argc, char** argv) {

    #ifdef SOLUTION
        solution();
    #else
        // TODO: Write your code here
        
        
    #endif
    
    return (EXIT_SUCCESS);
}

