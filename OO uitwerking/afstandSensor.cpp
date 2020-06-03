#include "afstandSensor.h"
int AfstandSensor::getAfstand() {
	return this->afstandTotMens;
}
void AfstandSensor::ontvangAfstand(int afstand) {
	this->afstandTotMens = afstand;
}