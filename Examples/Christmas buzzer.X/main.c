/* 
 * File:   main.c
 * Author: SVU
 *
 * Created on 19 December 2017, 15:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "config.h"
#include "main.h"
#include "tone.h"

/*
 * 
 */
#define BPM 190
#define dt 315//1.0/BPM*60*1000


int main(int argc, char** argv) {
    
    TRISFbits.TRISF2 = 1; // button is input
    
    note e = {E, 4, dt};
    note g = {G, 4, dt};
    note c = {C, 4, dt};
    note d = {D, 4, dt};
    note f = {F, 4, dt};
    note p = {no_tone, dt};
    note p2 = {no_tone, dt/10};

    //note song[] = {e, e, e, e, e, e, e, g, c, d, e, p, f, f, f, f, f, e, e, e, e, d, d, e, d, g};
    //typedef enum {C = 1, CS, D, DS, E, F, FS, G, GS, A, AS, B} letter;
    note song[] = {
        {E , 4, dt}, 
        {A , 5, dt}, // maybe 5
        {GS, 4, dt},
        {G , 4, dt},
        
        {E , 4, 2*dt},
        {no_tone, dt},
        {E , 4, dt/2},
        {E , 4, dt/2},
        
        {E , 4, dt}, 
        {A , 5, dt}, // maybe 5
        {GS, 4, dt},
        {G , 4, dt},
        
        {F , 4, 2*dt},
        {no_tone, 2*dt},
         
        {E , 4, dt}, 
        {A , 5, dt}, // maybe 5
        {GS, 4, dt},
        {G , 4, dt}       
    };
    init_tone();
    
    while(1)
    {
        int i;
        //for (i = 0; i < 26; i++)
        for (i = 0; i < 18; i++)
        {
            play_note(song[i]);
            play_note(p2);
        }
        play_note(p);
        play_note(p);
        play_note(p);
        play_note(p);
        
    }
    return (EXIT_SUCCESS);
}

