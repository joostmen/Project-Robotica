#include "camera.h"
bool Camera::getZieMens() {
	return this->zieMens;
}
Richting Camera::getRichting() {
	return this->richting;
}
bool Camera::scanVoorMens() {
	//luister naar camera module geeft deze de coords van een mens terug?
	if (/* signaal ontvangen dat mens gezien */ true) {
		this->mensXpos; /* = ontvangenSignaal; */
		this->zieMens = true;
		return true;
	}
	else {
		this->zieMens = false;
		this->mensXpos = 0;
		return false;
	}
}

int Camera::getMensXpos() {
	return this->mensXpos;
}

void Camera::setRichting(Richting richting) {
	this->richting = richting;
}