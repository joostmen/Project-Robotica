#pragma once
class AfstandSensor
{
private:
	int afstandTotMens;

public:
	int getAfstand();
	void ontvangAfstand(int afstand);
};

