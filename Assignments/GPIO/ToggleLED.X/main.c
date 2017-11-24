/* 
 * File:   main.c
 * Author: SVU
 *
 * Created on 24 November 2017, 09:31
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

//#define USE_SOLUTION
#ifdef USE_SOLUTION
    #include "solution.h"
#endif
/*
 * 
 */
int main(int argc, char** argv) {

    #ifdef USE_SOLUTION
        solution();
    #else
        // TODO: Write your code here
        
        
    #endif
    
    return (EXIT_SUCCESS);
}

