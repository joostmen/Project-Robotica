#include "Input.h"

void get_input(u16 transmision, u8 input_count) {
    u8 header = 0;
    u8 action = 0;
    u8 speed = 0;
    header = (transmision >> (input_count - 1))&0x01;
    if (header == 1) {
        if (input_count >= 4) {
            action = (transmision >> (input_count - 4))&0x07;
        }
        if (input_count >= 12) {
            speed = transmision & 0xFF;
        }
        if (input_count >= 4 && input_count < 12) {
            switch (action) {
                case Forward:
                case Backward:
                    speed = 0xFF;
                    break;
                case Turn_Right:
                case Turn_Left:
                    speed = 0x0F;
                    break;
                default:
                    break;
            }
        }
        input_select(action,speed);
    }
}

void input_select(motorinput value, u8 motor_speed) {
    switch (value) {
        case Free:
        default:
            free();
            break;
        case Forward:
            forward(motor_speed);
            break;
        case Backward:
            backward(motor_speed);
            break;
        case Break:
            break_motor();
            break;
        case Rotate_Right:
            rotate_right();
            break;
        case Rotate_Left:
            rotate_left();
            break;
        case Turn_Right:
            turn_right(motor_speed);
            break;
        case Turn_Left:
            turn_left(motor_speed);
            break;
    }
}
