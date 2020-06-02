#include "Interrupt.h"

void __interrupt() ISR() {
    if (IOCAF && IOCIE) {
        Button_int();
    }
    if (TMR0IF && TMR0IE) {
        Timer0_int();
    }
}

void Button_int() {
    edge = PORTAbits.RA2;
    IOCAF = 0;
    __delay_ms(5);
    if (PORTAbits.RA2 == edge) {
        if (edge == 0) {//button pressed
            button_led = 1;
            timer_led = 1;
            button_state = 1;
            timer_count = 0;
            INTCONbits.TMR0IE = 1;
            TMR0 = 0;
        } else if (edge == 1) {//button not pressed
            button_led = 0;
            button_state = 0;
        }
    }
}

void Timer0_int() {
    TMR0IF = 0;
    timer_led ^= 1;
    timer_count++;
    if (timer_count == 2){
        input_count++;
        transmision <<=1;
        transmision |= (button_state & 0x01);
    }else if ((timer_count == 11)||(input_count>=12)){
        INTCONbits.TMR0IE = 0;
        get_input(transmision,input_count);
        input_count = 0;
    }
}