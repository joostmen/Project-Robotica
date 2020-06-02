/* 
 * File:   Input.h
 * Author: Niels
 *
 * Created on 31 mei 2020, 18:01
 */

#ifndef INPUT_H
#define	INPUT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Define.h"
#include "Movement.h"
                        //2,3,4,5
    typedef enum {      //D,C,B,A
        Free,           //0,0,0,0   000
        Forward,        //0,1,0,1   001
        Backward,       //1,0,1,0   010
        Break,          //1,1,1,1   011
        Rotate_Right,   //1,0,0,1   100
        Rotate_Left,    //0,1,1,0   101
        Turn_Right,     //0,X,0,1   110
        Turn_Left       //0,1,0,X   111
    } motorinput; //X == Forward at ..% (PWM)

    
    void get_input(u16 transmision,u8 input_count);
    void input_select(motorinput action,u8 motor_speed);


#ifdef	__cplusplus
}
#endif

#endif	/* INPUT_H */

