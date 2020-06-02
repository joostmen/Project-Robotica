/* 
 * File:   Interrupt.h
 * Author: Niels
 *
 * Created on 31 mei 2020, 17:19
 */

#ifndef INTERRUPT_H
#define	INTERRUPT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Define.h"
#include "Input.h"
    
#define button_led LATCbits.LATC6
#define timer_led LATCbits.LATC7

    //Interrupt Functies
    void Button_int(void);
    void Timer0_int(void);

    u8 edge = 0;
    u8 button_state = 0;
    u8 timer_count = 0;
    
    u8 input_count = 0;
    u16 transmision = 0;

#ifdef	__cplusplus
}
#endif

#endif	/* INTERRUPT_H */

