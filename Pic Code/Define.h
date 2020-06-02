/* 
 * File:   Define.h
 * Author: Niels
 *
 * Created on 31 mei 2020, 17:32
 */

#ifndef DEFINE_H
#define	DEFINE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#define _XTAL_FREQ 500000

    //config bits that are part-specific for the PIC16F1829
#pragma config FOSC=INTOSC, WDTE=OFF, PWRTE=OFF, MCLRE=OFF, CP=OFF, CPD=OFF, BOREN=ON
#pragma config CLKOUTEN=OFF, IESO=OFF, FCMEN=OFF
#pragma config WRT=OFF, PLLEN=OFF, STVREN=OFF, LVP=OFF

    typedef unsigned char u8;
    typedef unsigned int u16;


#ifdef	__cplusplus
}
#endif

#endif	/* DEFINE_H */

