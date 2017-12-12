/* 
 * File:   Solution.h
 * Author: Svutb
 *
 * Created on 12 December 2017, 16:59
 */

#ifndef MACROS_H
#define	MACROS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    #include <xc.h>
    
    // These macros are made for the Digilent chipkit Max32
    #define INITLD() ({TRISACLR = 0b1000; TRISCCLR = 0b10;}) // define the LEDs as outputs
    #define LD4ON()  (LATASET = 0b1000) // set the fourth bit of the LATA register
    #define LD4OFF() (LATACLR = 0b1000) // clear the fourth bit of the LATA register
    #define LD4T()   (LATAINV = 0b1000) // invert the fourth bit of the LATA register
    #define LD5ON()  (LATCSET = 0b10) // set the second bit of the LATC register
    #define LD5OFF() (LATCCLR = 0b10) // clear the second bit of the LATC register
    #define LD5T()   (LATCINV = 0b10) // invert the second bit of the LATC register

#ifdef	__cplusplus
}
#endif

#endif	/* MACROS_H */