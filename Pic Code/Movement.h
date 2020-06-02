/* 
 * File:   Movement.h
 * Author: Niels
 *
 * Created on 31 mei 2020, 17:09
 */

#ifndef MOVEMENT_H
#define	MOVEMENT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Define.h"

    //Left motor
    //LATCbits.LATC5 == A
    //LATCbits.LATC4 == B

    //Right motor
    //LATCbits.LATC3 == C
    //LATCbits.LATC2 == D

#define A LATCbits.LATC5
#define B LATCbits.LATC4
#define C LATCbits.LATC3
#define D LATCbits.LATC2



    //Speed is number between 0 (stop) and 255 (full) 8bits
    void free(void);
    void forward(u8 speed); //default is 255
    void backward(u8 speed); //default is 255
    void break_motor(void);
    void rotate_right(void);
    void rotate_left(void);
    void turn_right(u8 speed); //default is 0
    void turn_left(u8 speed); //default is 0



#ifdef	__cplusplus
}
#endif

#endif	/* MOVEMENT_H */

