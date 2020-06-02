/* 
 * File:   Init.h
 * Author: Niels
 *
 * Created on 31 mei 2020, 17:15
 */

#ifndef INIT_H
#define	INIT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Define.h"

    //Initialisatie Functies
    void pic_init(void);
    void PORTC_init(void);
    void Button_init(void);
    void Timer0_init(void);
    void PWM_init(void);
    void CCP1_init(void);
    void CCP2_init(void);


#ifdef	__cplusplus
}
#endif

#endif	/* INIT_H */

