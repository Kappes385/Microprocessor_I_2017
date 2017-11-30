/* 
 * File:   main.c
 * Author: SVU
 *
 * Created on 30 November 2017, 09:15
 */

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include <xc.h>

#ifdef SOLUTION
    #include "solution/solution.h"
#endif

/*
 *  Assignment:
 *      Write your program to setup a timer, in such a configuration that you 
 *      can count milliseconds. Based on this millisecond count, toggle LD4 and
 *      LD5 every 500 and every 200 milliseconds respectively
 */
int main(int argc, char** argv) {
    
    #ifdef SOLUTION
        solution();
    #else
        // TODO: Write your code here
        
        
    #endif

    return (EXIT_SUCCESS);
}

