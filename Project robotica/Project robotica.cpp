#include "GL/glew.h"
#include "GL/glut.h"
#include "robot.h"
#include "view.h"
#include <iostream>
#include "colors.h"

void display();
void idle();
void glinit();
void processNormalKeys(unsigned char key, int x, int y);

View view;

int main(int ac, char** ap) 
{
	glutInit(&ac, ap);
	glinit();

	return 0;
}
void idle() 
{
	glutPostRedisplay();
	Sleep(50);
}
void display () 
{
	glClearColor(WHITE, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	view.update();
	view.tekenMens();
	view.tekenRobot();
	glEnd();
	glFlush();
}

void glinit() 
{
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Project Robotica");
	glutKeyboardFunc(processNormalKeys);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
	glutMainLoop();
	
}


void processNormalKeys(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 119: //w
        //update mens omhoog
		view.updateMens(true, true);
        break;
    case 97: // a
        //update mens naar links
		view.updateMens(false, false);
        break;
    case 115: //s
        //update mens omlaag
		view.updateMens(true, false);
		break;
    case 100: //d
        //update mens rechts
		view.updateMens(false, true);
        break;
    
    }
}
