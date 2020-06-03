#pragma once
#include <iostream>
using namespace std;

#include "enum.h"
#include "motor.h"
#include "afstandSensor.h"
#include "CAMERA.H"

class Robot
{
private:
	RobotStatus status = aan;
	Motor motorR;
	Motor motorL;
	AfstandSensor sensor;
	Camera camera;


public:
	void zetRecht();
	void volgMens();
	void zoeken();
	void stuurSignaal(string toDo);
	string ontvangSignaal();
};

