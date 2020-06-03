#include "robot.h"

void Robot::zetRecht() {
	//zolang camera richting != vooruit draai
		switch (camera.getRichting()) {
		case vooruitL:
			while (camera.getRichting() != vooruit) {
				//MotorL achteruit MotorR vooruit
				motorL.setStatus(achteruitStat);
				motorR.setStatus(vooruitStat);
				//stuur signaal
			}
			break;
		case links:
			while (camera.getRichting() != vooruit) {
				//MotorL achteruit MotorR vooruit
				motorL.setStatus(achteruitStat);
				motorR.setStatus(vooruitStat);
				//stuur signaal
			}
			break;
		case achteruitL:
			while (camera.getRichting() != vooruit) {
				//MotorL achteruit MotorR vooruit
				motorL.setStatus(achteruitStat);
				motorR.setStatus(vooruitStat);
				//stuur signaal
			}
			break;
		case achteruit:
			while (camera.getRichting() != vooruit) {
				//MotorL achteruit MotorR vooruit
				motorL.setStatus(achteruitStat);
				motorR.setStatus(vooruitStat);
				//stuur signaal
			}
			break;
		case achteruitR:
			while (camera.getRichting() != vooruit) {
				//MotorL vooruit MotorR achteruit
				motorL.setStatus(vooruitStat);
				motorR.setStatus(achteruitStat);
				//stuur signaal
			}
			break;
		case rechts:
			while (camera.getRichting() != vooruit) {
				//MotorL vooruit MotorR achteruit
				motorL.setStatus(vooruitStat);
				motorR.setStatus(achteruitStat);
				//stuur signaal
			}
			break;
		case vooruitR:
			while (camera.getRichting() != vooruit) {
				//MotorL vooruit MotorR achteruit
				motorL.setStatus(vooruitStat);
				motorR.setStatus(achteruitStat);
				//stuur signaal
			}
			break;
		default:
			break;
		}
}

void Robot::volgMens() {
	//zolang camera ziet mens blijf rijden als mens iets draaid draai dan mee tot hij weer in center zit
		while (camera.getZieMens() == true) {
			if ((sensor.getAfstand() > 5) && (sensor.getAfstand() < 50)) {
				motorL.setStatus(vooruitStat);
				motorR.setStatus(vooruitStat);
				//stuur signaal

				if (camera.getMensXpos() < 290) { //mens teveel links
					//links langzamer tot hij weer in het midden loopt
					motorL.veranderSnelheid(5);
					camera.scanVoorMens();
					//stuur signaal
				}

				else if (camera.getMensXpos() > 350) { //mens teveel rechts
					//rechts langzamer tot hij weer in het midden loopt
					motorR.veranderSnelheid(5);
					camera.scanVoorMens();
					//stuur signaal
				}

				else {
					motorL.veranderSnelheid(10);
					motorR.veranderSnelheid(10);
					//stuur signaal
				}
				//centerwaarde buurt 320 met max 30 speling
			}
			else if ((sensor.getAfstand() < 5) | (sensor.getAfstand() > 50))
			{
				motorL.setStatus(uit);
				motorR.setStatus(uit);
				//stuur signaal
			}
			if (camera.scanVoorMens() == false) {
				zoeken();
			}
		}
}
void Robot::zoeken() {
	//sta stil en draai de camera
	int j;
	while (camera.getZieMens() == false) {
		
		int i;
		for (i = 0; i < 100; i++) {
			camera.scanVoorMens();
			//stuur signaal
			if (j == 8) {
				j = 0;
			}
		}
		camera.setRichting((Richting)j);
		//stuur signaal
	}
	zetRecht();
	volgMens();
}
void Robot::stuurSignaal(string toDo) {
	//veel if statemenst
}

string ontvangSignaal() {
	//ontvang signaal
}