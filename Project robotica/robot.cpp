#include "robot.h"
#include "view.h"
Robot::Robot(){

}

Robot::~Robot(){
    motorR.~Motor();
    motorL.~Motor();
    camera.~Camera();
    afstandsensor.~Afstandsensor();
}

void Robot::Start(){
    this->motorR.Aan();
    this->motorL.Aan();
}

void Robot::Stop(){
    this->motorR.Uit();
    this->motorL.Uit();
}

void Robot::DraaiR()
{
    this->motorR.Achteruit();
    this->motorL.Aan();
}

void Robot::DraaiL()
{
    this->motorL.Achteruit();
    this->motorR.Aan();
}

robotStatus Robot::getRobotStatus() 
{
    return this->status;
}

richting Robot::getRobotRichting()
{
    return this->richt;
}

void Robot::setRobotRichting(richting richt) {
    this->richt = richt;
}
void Robot::setRobotStatus(robotStatus status) {
    this->status = status;
}


