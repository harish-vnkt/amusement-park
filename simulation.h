#include <GL/glut.h>

#ifndef _SIMULATION_H_
#define _SIMULATION_H_
#endif

// Drawing functions
void drawHorse();
void drawMerryGoRound();
void drawCar();
void drawWheel();
void drawPlane();

// Boiler-plate functions
void init();
void display();
void reshape(GLint, GLint);
GLvoid keyboard(unsigned char, int, int);