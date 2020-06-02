#pragma once
//#include "robot.h"

class Camera
{
private:
	char richt; //tussen 0 en 8
	bool zieMens;

public:
	Camera();
	~Camera();

	int getRicht();
	
	void createCamera();
};
