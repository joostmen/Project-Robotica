#pragma once
enum motorStatus {
	uitM,
	vooruitM,
	achteruitM
};

class Motor
{
private:
	motorStatus status;

public:
	Motor();
	~Motor();

	void Aan();
	void Uit();
	void Achteruit();
	void createMotor();
};
