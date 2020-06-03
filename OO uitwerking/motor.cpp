#include "motor.h"
void Motor::setStatus(Status status) {
	this->status = status;
}
Status Motor::getStatus() {
	return this->status;
}
void Motor::veranderSnelheid(int snelheid) {
	this->snelheid = snelheid;
}