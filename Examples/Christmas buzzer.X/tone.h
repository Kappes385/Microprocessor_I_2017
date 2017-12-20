/* 
 * File:   tone.h
 * Author: SVU
 *
 * Created on 19 December 2017, 15:01
 */

#ifndef TONE_H
#define	TONE_H

#ifdef	__cplusplus
extern "C" {
#endif


typedef enum {C = 1, CS, D, Eb, E, F, FS, G, Ab, A, Bb, B} letter;
typedef struct
{
    letter l;
    int octave;
} tone;
typedef struct
{
    tone t;
    int duration;
} note;

static tone no_tone = {C, 0};

void set_tone(tone t);
void clear_tone();
void play_note(note n);



#ifdef	__cplusplus
}
#endif

#endif	/* TONE_H */

