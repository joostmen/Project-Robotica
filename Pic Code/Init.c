#include "Init.h"

void pic_init() {
    //500KHz clock speed
    OSCCON = 0b00111000;

    PORTC_init();
    Button_init();
    Timer0_init();
    PWM_init();

    //Enable all interrupts
    GIE = 1;
    PEIE = 1;
}

void PORTC_init() {
    TRISC = 0b00000000;
    //          ||||
    //          |||RC2  D  P2B
    //          ||RC3   C  P2A
    //          |RC4    B  P1B
    //          RC5     A  P1A

    //Force output of portC low/off
    LATC = 0x00;
}

void Button_init() {
    //Button PORTA,2 settings
    //Digital input
    TRISAbits.TRISA2 = 1;
    ANSELAbits.ANSA2 = 0;
    //Button interrupt
    INTCONbits.IOCIE = 1;
    IOCANbits.IOCAN2 = 1;
    IOCAPbits.IOCAP2 = 1;
}

void Timer0_init() {
    //Timer 0 settings
    //Timer0 Clock Source Select bit
    OPTION_REGbits.TMR0CS = 0;

    //Prescaler Assignment bit
    OPTION_REGbits.PSA = 0;
    //0 = Prescaler assigned
    //1 = Prescaler not assigned

    //Prescaler Rate Select bits
    OPTION_REGbits.PS = 0b111;
    //0b000 -> 2
    //0b001 -> 4
    //0b010 -> 8
    //0b011 -> 16

    //Timer 0 interrupt enable
    //INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 0;
}

void PWM_init() {
    APFCON1bits.P1DSEL = 1; //RC0
    APFCON1bits.P1CSEL = 1; //RC1
    APFCON1bits.P2BSEL = 0; //RC2
    APFCON1bits.CCP2SEL = 0; //RC3

    CCP1_init();
    CCP2_init();

    PR2 = 255;
    //Prescaler
    T2CONbits.T2CKPS = 0b01;
    //0b00 -> 1
    //0b01 -> 4
    //0b10 -> 16
    //0b11 -> 64

    //start the PWM
    T2CONbits.TMR2ON = 1;
}

void CCP1_init() {
    //P1A RC5
    //P1B RC4
    //P1C RC1
    //P1D RC0

    //CCP1CONbits.CCP1M = 0b1100;
    //CCP1CONbits.P1M = 0b00;//RC5 PWM    P1A
    //Single output; P1A Modulated;
    //CCP1CONbits.P1M = 0b11;//RC4 PWM    P1B
    //Full-bridge reverse output; P1B Modulated; P1C active;

    //select PWM source
    CCPTMRSbits.C1TSEL = 0b00;
    //0b00 = timer 2
}

void CCP2_init() {
    //P2A RC3
    //P2B RC2
    //P2C ???
    //P2D ???

    //CCP2CONbits.CCP2M = 0b1100;
    //CCP2CONbits.P2M = 0b00;//RC3 PWM    P2A
    //Single output; P2A Modulated
    //CCP2CONbits.P2M = 0b11;//RC2 PWM    P2B
    //Full-bridge reverse output; P2B Modulated; P2C active;

    //select PWM source
    CCPTMRSbits.C2TSEL = 0b00;
    //0b00 = timer 2
}