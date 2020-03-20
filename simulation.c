#include "simulation.h"
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265

// Window parameters
GLint width = 1100;
GLint height = 650;

GLfloat rotateMerryGoRound = 0.0f; // Angle of merry-go-round 
GLfloat speedMerryGoRound = 0.05f; // Angle increment

GLfloat rotateHorse = 0.0f; // Position of horse
GLfloat speedHorse = 0.2f; // Position increment

GLfloat speedWheel = 0.5f; // Speed of rotation
GLfloat circumferenceWheel = 6.0 * PI;
GLfloat distanceWheel = 0.0f; // Distance travelled for every angle of rotation
GLfloat rotateWheel = 0.0f; // Angle of rotation
GLfloat trainInitPos = 75.0f; // Where to start drawing train
GLfloat trainFinalPos = 0.0f;

GLfloat minHorseY = 5.0f; // Minimum height for rotation of horse
GLfloat maxHorseY = 17.0f; // Maximum height for rotation of horse
GLfloat rangeHorseY, horseY1, horseY2, horseY3, horseY4;

float pan = 0.0f; // Pan angle
double pan1 = 0.0f;
float zoom = 0.0f; // Zoom value
float eyeX = 0.0f;
float eyeZ = 60.0f;
double hypotenuse = 0.0;
double theta = 0.0; // Angle of pan
double amountX = 0.0;
double amountZ = 0.0;
double centreZ = 0.0;

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(width, height);
    glutCreateWindow("Amusement Park");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutReshapeFunc(reshape);
    glutDisplayFunc(render);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    init();

    printf("W/w - Move forward\nS/s - Move backward\nA/a - Rotate left\nD/d - Rotate right\nR/r - Reset\nQ/q/Esc - Quit\n");

    glutMainLoop();

}

void init() {
    
    rangeHorseY = maxHorseY - minHorseY;
    horseY1 = 0.0f;
    horseY2 = 45.0;
    horseY3 = 90.0;
    horseY4 = 135.0;

    glShadeModel(GL_SMOOTH);

    GLfloat directionalLightPosition[] = {1.0f, 1.0f, 1.0f, 0.0f};
    GLfloat white_weak[] = {0.7f, 0.7f, 0.7f, 1.0f};
    GLfloat white_strong[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat ambient[] = {0.3f, 0.3f, 0.3f, 0.7f};
    GLfloat pointlightDirection[] = {0.0f, 25.0f, 30.0f, 1.0f};

    // Directional light
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_weak);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_weak);
	glLightfv(GL_LIGHT0, GL_POSITION, directionalLightPosition);

    // Positional light
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, white_strong);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white_strong);
	glLightfv(GL_LIGHT1, GL_POSITION, pointlightDirection);

	glEnable(GL_LIGHTING);                
	glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

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
	gluLookAt(eyeX, 30.0f, eyeZ,
		pan + amountX, 0.0f, centreZ,   
		0.0f, 1.0f, 0.0f);  

    glMatrixMode(GL_MODELVIEW);

}

void idle() {

    // Update values for rotation of merry-go-round and the horses
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

    // Rotation of wheel and movement of train
    rotateWheel += speedWheel;
    distanceWheel = (rotateWheel * circumferenceWheel)/360.0;
    trainFinalPos = trainInitPos - distanceWheel;
    if (trainFinalPos < -75.0) {
        rotateWheel = 0.0f;
    }

    glutPostRedisplay();

}

GLvoid keyboard(unsigned char key, int x, int y) {

    switch (key) {
        case 27:
        case 81:
        case 113:
            exit(1);
            break;

        // left rotate
        case 65: // A
	    case 97: // a
		    pan -= 1.0f;
            pan1 = pan - amountX;
            hypotenuse = sqrt((eyeZ*eyeZ) + (pan1*pan1));
            break;

        // right rotate
        case 68: // D
        case 100: // d
            pan += 1.0f;
            pan1 = pan - amountX;
            hypotenuse = sqrt((eyeZ*eyeZ) + (pan1*pan1));
            break;

		// zoom-out
        case 83: // S
        case 115: // s
            if (pan1 != 0.0f) theta = asin(pan1/hypotenuse);
            else theta = 0.0;
            zoom -= 1.0f;
            amountZ = zoom * cos(theta);
            amountX = zoom * sin(theta);
            eyeZ += amountZ;
            eyeX -= amountX;
            centreZ += amountZ;
            break;

		// zoom-in
        case 87: // W
        case 119: // w
            if (pan1 != 0.0f) theta = asin(pan1/hypotenuse);
            else theta = 0.0;
            zoom += 1.0f;
            amountZ = zoom * cos(theta);
            amountX = zoom * sin(theta);
            eyeZ -= amountZ;
            eyeX += amountX;
            centreZ -= amountZ;
            break;

        // reset
        case 82: // R
        case 114: // r
            eyeX = 0.0f;
            eyeZ = 60.0f;
            pan = 0.0f;
            zoom = 0.0f;
            centreZ = 0.0f;
            break;

    }

}

void render() {

	glViewport(0, 0, width, height);
	
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (float)width / (float)height, 1.0f, 120.0f);
    gluLookAt(eyeX, 30.0f, eyeZ,
		pan + amountX, 0.0f, centreZ,   
		0.0f, 1.0f, 0.0f);  

    glMatrixMode(GL_MODELVIEW);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glPushMatrix();

        // Sky
        skyPlane();

        // Ground
        drawPlane();

        // Merry-go-round
        glPushMatrix();

            glTranslatef(0.0f, 0.0f, -25.0f);
            glRotatef(rotateMerryGoRound, 0.0f, -1.0f, 0.0f);
            glScalef(0.7f, 0.7f, 0.7f);
            drawMerryGoRound();

            // Horses
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

        // Train
        glPushMatrix();

            glTranslatef(trainFinalPos, 9.0f, 25.0f);
            drawTrain();
            
            // Wheels
            glPushMatrix();

                glTranslatef(-25.0f, -6.0f, 1.5f);
                glRotatef(rotateWheel, 0.0f, 0.0f, 1.0f);
                drawWheel();

            glPopMatrix();

            glPushMatrix();

                glTranslatef(-25.0f, -6.0f, -1.5f);
                glRotatef(rotateWheel, 0.0f, 0.0f, 1.0f);
                drawWheel();

            glPopMatrix();

            glPushMatrix();

                glTranslatef(-15.0f, -6.0f, 1.5f);
                glRotatef(rotateWheel, 0.0f, 0.0f, 1.0f);
                drawWheel();

            glPopMatrix();

            glPushMatrix();

                glTranslatef(-15.0f, -6.0f, -1.5f);
                glRotatef(rotateWheel, 0.0f, 0.0f, 1.0f);
                drawWheel();

            glPopMatrix();

            glPushMatrix();

                glTranslatef(-5.0f, -6.0f, 1.5f);
                glRotatef(rotateWheel, 0.0f, 0.0f, 1.0f);
                drawWheel();

            glPopMatrix();

            glPushMatrix();

                glTranslatef(-5.0f, -6.0f, -1.5f);
                glRotatef(rotateWheel, 0.0f, 0.0f, 1.0f);
                drawWheel();

            glPopMatrix();

            glPushMatrix();

                glTranslatef(5.0f, -6.0f, 1.5f);
                glRotatef(rotateWheel, 0.0f, 0.0f, 1.0f);
                drawWheel();

            glPopMatrix();

            glPushMatrix();

                glTranslatef(5.0f, -6.0f, -1.5f);
                glRotatef(rotateWheel, 0.0f, 0.0f, 1.0f);
                drawWheel();

            glPopMatrix();

            glPushMatrix();

                glTranslatef(15.0f, -6.0f, 1.5f);
                glRotatef(rotateWheel, 0.0f, 0.0f, 1.0f);
                drawWheel();

            glPopMatrix();

            glPushMatrix();

                glTranslatef(15.0f, -6.0f, -1.5f);
                glRotatef(rotateWheel, 0.0f, 0.0f, 1.0f);
                drawWheel();

            glPopMatrix();

            glPushMatrix();

                glTranslatef(25.0f, -6.0f, 1.5f);
                glRotatef(rotateWheel, 0.0f, 0.0f, 1.0f);
                drawWheel();

            glPopMatrix();

            glPushMatrix();

                glTranslatef(25.0f, -6.0f, -1.5f);
                glRotatef(rotateWheel, 0.0f, 0.0f, 1.0f);
                drawWheel();

            glPopMatrix();


        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();

}