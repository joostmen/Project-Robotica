#include "Movement.h"

void free() {
    //Turn PWM off & output to motor low/off
    CCP1CONbits.CCP1M = 0b0000;
    A = 0;
    B = 0;
    CCP2CONbits.CCP2M = 0b0000;
    C = 0;
    D = 0;
}

void forward(u8 speed) {
    CCP1CONbits.CCP1M = 0b1100;
    CCP1CONbits.P1M = 0b00; //RC5 PWM    P1A
    B = 0;
    CCP2CONbits.CCP2M = 0b1100;
    CCP2CONbits.P2M = 0b00; //RC3 PWM    P2A
    D = 0;

    CCPR1L = speed;
    CCPR2L = speed;
}

void backward(u8 speed) {
    CCP1CONbits.CCP1M = 0b1100;
    CCP1CONbits.P1M = 0b11; //RC4 PWM    P1B
    A = 0;
    //Single output; P1A Modulated;
    CCP2CONbits.CCP2M = 0b1100;
    CCP2CONbits.P2M = 0b11; //RC2 PWM    P2B
    C = 0;
    //Single output; P2A Modulated

    CCPR1L = speed;
    CCPR2L = speed;
}

void break_motor() {
    //Turn PWM off & output to motor high/break
    CCP1CONbits.CCP1M = 0b0000;
    A = 1;
    B = 1;
    CCP2CONbits.CCP2M = 0b0000;
    C = 1;
    D = 1;
}

void rotate_right() {
    //Turn PWM off
    CCP1CONbits.CCP1M = 0b0000;
    A = 1;
    B = 0;
    CCP2CONbits.CCP2M = 0b0000;
    C = 0;
    D = 1;
}

void rotate_left() {
    //Turn PWM off
    CCP1CONbits.CCP1M = 0b0000;
    A = 0;
    B = 1;
    CCP2CONbits.CCP2M = 0b0000;
    C = 1;
    D = 0;
}

void turn_right(u8 speed) {
    //Turn PWM off
    CCP1CONbits.CCP1M = 0b0000;
    A = 1;
    B = 0;
    //PWM motor right on
    CCP2CONbits.CCP2M = 0b1100;
    CCP2CONbits.P2M = 0b00; //RC3 PWM    P2A
    D = 0;

    CCPR2L = speed;
}

void turn_left(u8 speed) {
    //PWM motor left on
    CCP1CONbits.CCP1M = 0b1100;
    CCP1CONbits.P1M = 0b00; //RC5 PWM    P1A
    B = 0;
    //PWM motor right off
    CCP2CONbits.CCP2M = 0b0000;
    C = 1;
    D = 0;

    CCPR1L = speed;
}