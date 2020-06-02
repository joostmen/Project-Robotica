#pragma once
#include "motor.h"
#include "onderstel.h"
#include "camera.h"
#include "Afstandsensor.h"
#include "gezichtsveld.h"
#include "enums.h"

class Robot {
private:
    Motor motorR;
    Motor motorL;
    Camera camera;
    Afstandsensor afstandsensor;

    richting richt = vooruit;
    robotStatus status = zoeken;
    bool mensInBereik = false;
    int maxAfstandTotMens = 20;
    int minAfstandTotMens = 5;

public:
    Robot();
    ~Robot();

    void Start();
    void Stop();
    void DraaiR();
    void DraaiL();
    void setRobotRichting(richting richt);
    void setRobotStatus(robotStatus status);

    robotStatus getRobotStatus();
    richting getRobotRichting();
};