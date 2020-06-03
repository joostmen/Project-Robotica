#pragma once
#include "enum.h"
class Motor
{
private:
	Status status;
	int snelheid = 10;


public:
	void setStatus(Status status);
	Status getStatus();
	void veranderSnelheid(int snelheid);
};

