/* 
 * File:   main.h
 * Author: SVU
 *
 * Created on 13 December 2017, 17:06
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

void initUART(int BAUD_rate);
void transmitNumber(int num);
void transmitMilliVolts(int reading);


#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

