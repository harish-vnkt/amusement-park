#include "simulation.h"
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265

GLint width = 1100;
GLint height = 650;

GLfloat rotateMerryGoRound = 0.0f;
GLfloat speedMerryGoRound = 0.75f;

GLfloat rotateHorse = 0.0f;
GLfloat speedHorse = 2.0f;

GLfloat minHorseY = 5.0f;
GLfloat maxHorseY = 17.0f;
GLfloat rangeHorseY, horseY1, horseY2, horseY3, horseY4;

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(width, height);
    glutCreateWindow("Amusement Park");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // sky blue

    glutReshapeFunc(reshape);
    glutDisplayFunc(render);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    init();

    glutMainLoop();

}

void init() {
    
    rangeHorseY = maxHorseY - minHorseY;
    horseY1 = 0.0f;
    horseY2 = 45.0;
    horseY3 = 90.0;
    horseY4 = 135.0;

    GLfloat directionalLightPosition[] = {1.0f, 1.0f, 1.0f, 0.0f};
    GLfloat white[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat ambient[] = {0.3f, 0.3f, 0.3f, 0.7f};

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);
	glLightfv(GL_LIGHT0, GL_POSITION, directionalLightPosition);

	glEnable(GL_LIGHTING);                
	glEnable(GL_LIGHT0);
    
    glColorMaterial(GL_FRONT, GL_DIFFUSE);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST); // Antialias lines

}

void reshape(GLint w, GLint h) {

	width = w;
	height = h;

	glViewport(0, 0, w, h);
	
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (float)w / (float)h, 1.0f, 120.0f);
	gluLookAt(0.0f, 30.0f, 60.0f,
		0.0f, 0.0f, 0.0f,   
		0.0f, 1.0f, 0.0f);  

    glMatrixMode(GL_MODELVIEW);

}

void idle() {

    rotateMerryGoRound += speedMerryGoRound;
    horseY1 += speedHorse;
    horseY2 += speedHorse;
    horseY3 += speedHorse;
    horseY4 += speedHorse;
    
    if (rotateMerryGoRound==360.0) {
        rotateMerryGoRound = 0.0f;
    }

    if (horseY1>=180.0) horseY1 = 0.0f;
    if (horseY2>=180.0) horseY2 = 0.0f;
    if (horseY3>=180.0) horseY3 = 0.0f;
    if (horseY4>=180.0) horseY4 = 0.0f;

    glutPostRedisplay();

}

GLvoid keyboard(unsigned char key, int x, int y) {

    switch (key) {
        case 27:
            exit(1);
            break;
    }
}

void render() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    skyPlane();
    
    glPushMatrix();

        drawPlane();

        glPushMatrix();

            glTranslatef(0.0f, 0.0f, -25.0f);
            glRotatef(rotateMerryGoRound, 0.0f, -1.0f, 0.0f);
            glScalef(0.7f, 0.7f, 0.7f);
            drawMerryGoRound();

            glPushMatrix();

                glTranslatef(18.25f, 
                    minHorseY + (sin(horseY1 * (PI/180.0)) * rangeHorseY), 
                        0.0f);
                glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
                drawHorse();

            glPopMatrix();

            glPushMatrix();

                glTranslatef(0.0f, 
                    minHorseY + (sin(horseY2 * (PI/180.0)) * rangeHorseY), 
                        18.25f);
                glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
                drawHorse();

            glPopMatrix();

            glPushMatrix();

                glTranslatef(-18.25f, 
                    minHorseY + (sin(horseY3 * (PI/180.0)) * rangeHorseY), 
                        0.0f);
                glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
                drawHorse();

            glPopMatrix();

            glPushMatrix();

                glTranslatef(0.0f, 
                    minHorseY + (sin(horseY4 * (PI/180.0)) * rangeHorseY), 
                        -18.25f);
                glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
                drawHorse();

            glPopMatrix();

        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();

}