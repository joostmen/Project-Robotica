#pragma once
class Afstandsensor
{
private:
	int afstandTotMens;

public:
	Afstandsensor();
	~Afstandsensor();

	int berekenAfstandTotMens();
	void createAfstandsensor();
};
