#pragma once
#include "enum.h"

class Camera
{
private:
	Richting richting = vooruit;
	bool zieMens = false;
	int mensXpos = 0;

public:
	bool getZieMens();
	Richting getRichting();
	bool scanVoorMens();
	int getMensXpos();
	void setRichting(Richting richting);
};

