/* 
 * File:   main.c
 * Author: Steffen Vutborg & Asbjørn Hoffskov Lund
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
#define BPM 150
#define O 4

int main(int argc, char** argv) {
    
    //Setting tonelength
    const int T4 = (60*1000)/BPM; //quartertone
    const int T8 = (60*1000)/BPM/2; //Eighth-tone
    const int T2 = (60*1000)/BPM*2; //half-tone
    const int T1 = (60*1000)/BPM*4; //You do the math ;-)
    
    //setting tones in range B3 to G5 (range of the song)
    tone B3 = {B, O-1};
    tone C4 = {C, O};
    tone C4s = {CS, O};
    tone D4 = {D, O};
    tone E4 = {E, O};
    tone F4 = {F, O};
    tone F4s = {FS, O};
    tone G4 = {G, O};
    tone Ab4 = {Ab, O};
    tone A4 = {A, O};
    tone Bb4 = {Bb, O};
    tone B4 = {B, O};
    tone C5 = {C, O+1};
    tone C5s = {CS, O+1};
    tone D5 = {D, O+1};
    tone Eb5 = {Eb, O+1};
    tone E5 = {E, O+1};
    tone F5 = {F, O+1};
    tone F5s = {FS, O+1};
    tone G5 = {G, O+1};
    
    
    
    note p = {no_tone, T4};
    note p2 = {no_tone, T4/10};
    note song[] = {
        //Song of the Dragonborn
        {B3, T4},
        {E4, T4},
        {E4, T4},
        {F4s, T4},
        {G4, T4},
        {A4, T4},
        {A4, T8},
        {A4, T8},
        {F4s, T4},
        {E4, T4},
        {D4, T4},
        {E4, T1},
        //{no_tone, dt},
        {B3, T4},
        {E4, T4},
        {E4, T4},
        {F4s, T4},
        {G4, T4},
        {A4, T8},
        {A4, T8},
        {A4, T4},
        {F4s, T4},
        {E4, T4},
        {D4, T4},
        {E4, T1},
        //{no_tone, dt},
        {B4, T8},
        {B4, T8},
        {B4, T4},
        {E4, T4},
        {F4s, T4},
        {G4, T4},
        {A4, T8},
        {A4, T8},
        {A4, T4},
        {F4s, T4},
        {G4, T4},
        {A4, T4},
        {B4, T1},
        //{no_tone, dt},
        {B3, T4},
        {E4, T4},
        {E4, T4},
        {F4s, T4},
        {G4, T4},
        {A4, T8},
        {A4, T8},
        {A4, T4},
        {F4s, T4},
        {E4, T4},
        {D4, T4},
        {E4, T1},
        {no_tone, T2},
        //Morrowind section
        {E4, T4},
        {F4s, T4},
        {G4, T2},
        {G4, T2},
        {G4, T4},
        {A4, T4},
        {B4, T2},
        {B4, T2},
        {B4, T4},
        {D5, T4},
        {A4, T1},
        {G4, T4},
        {F4s, T4},
        {E4, T1},
        {E4, T4},
        {F4s, T4},
        {G4, T2},
        {G4, T2},
        {G4, T4},
        {A4, T4},
        {B4, T2},
        {B4, T2},
        {B4, T4},
        {D5, T4},
        {E5, T1},
        {D5, T4},
        {F5s, T4},
        {E5, T1},
        {E5, T4},
        {F5s, T4},
        {G5, T2},
        {F5s, T2},
        {E5, T2},
        {D5, T2},
        {C5, T2},
        {B4, T2},
        {A4, T2},
        {G4, T4},
        {B4, T4},
        {A4, T1}
        //Dovahkiin part missing
            
        
    };
    
    
    
    init_tone();
    AD1PCFG = 0xFFFF;
    TRISB &= ~(0x3FF);
    
    while(1)
    {
        int i;
        //for (i = 0; i < 26; i++)
        for (i = 0; i < 91; i++)
        {
            LATB ^= 0x3FF;
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

