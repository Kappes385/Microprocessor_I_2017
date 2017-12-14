/* 
 * File:   main.c
 * Author: SVU
 *
 * Created on 14 December 2017, 15:28
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "../../config.h"
#include "solution.h"
#include <math.h>

#ifdef SOLUTION
    #include "solution.h"
#endif
/*
 *  Assignment:
 *      Wire up an LED to an OC pin and configure that pin to generate a 100Hz
 *      Pulse Width Modulated (PWM) signal with a duty cycle of 30%.
 *      
 *      Verify that your code does actually generate this signal e.g. using an 
 *      oscilloscope
 * 
 *      Once you verified this, apply the "breathing" effect to your signal
 *      I.e. use the returned 0 to 1 value from the breathEffect function to scale
 *      your duty cycle. from 0 to 100 percent
 */
int main(int argc, char** argv) {
    
    #ifdef SOLUTION
        solution();
    #else
        // TODO: Write your code here
        
        
    #endif
    
    return (EXIT_SUCCESS);
}

/**
 * This function will take a time variable in milliseconds and generate a 
 * response in the form of a 1Hz sinus curve ranging from 0 to 1.
 * 
 * The formula used is : (sin(t_ms/1000.0*2*M_PI)+1)/2
 * 
 * @param t_ms  Integer value representing the time in milliseconds
 * @return      Breath scale [0:1]
 */
double breathEffect(int t_ms)
{
    return (sin(t_ms/1000.0*2*M_PI)+1)/2;
}

