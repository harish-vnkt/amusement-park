#include "simulation.h"
#include <stdio.h>
#include <GL/glut.h>

GLint width = 1100;
GLint height = 650;

GLfloat rotateMerryGoRound = 0.0f;
GLfloat speedMerryGoRound = 0.75f;

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(width, height);
    glutCreateWindow("Amusement Park");

    glClearColor( 47.055, 55.289, 86.785, 1.0 ); // sky blue

    glutReshapeFunc(reshape);
    glutDisplayFunc(render);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    init();

    glutMainLoop();

}

void init() {

    GLfloat direction[] = {1.0f, 1.0f, 1.0f, 0.0f};
    GLfloat white[] = {1.0f, 1.0f, 1.0f, 1.0f};

	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);
	glLightfv(GL_LIGHT0, GL_POSITION, direction);

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
	gluLookAt(0.0f, 0.0f, 60.0f,
		0.0f, 0.0f, 0.0f,   
		0.0f, 1.0f, 0.0f);  

    glMatrixMode(GL_MODELVIEW);

}

void idle() {

    rotateMerryGoRound += speedMerryGoRound;
    
    if (rotateMerryGoRound==360.0) {
        rotateMerryGoRound = 0.0f;
    }

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

    glPushMatrix();
        
        drawPlane();

        glPushMatrix();

            glTranslatef(0.0f, 0.0f, -25.0f);
            glRotatef(rotateMerryGoRound, 0.0f, -1.0f, 0.0f);
            glScalef(0.7f, 0.7f, 0.7f);
            drawMerryGoRound();

            glPushMatrix();

                glTranslatef(15.0f, 10.0f, 0.0f);
                glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
                drawHorse();

            glPopMatrix();

            glPushMatrix();

                glTranslatef(0.0f, 10.0f, 15.0f);
                glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
                drawHorse();

            glPopMatrix();

            glPushMatrix();

                glTranslatef(-15.0f, 10.0f, 0.0f);
                glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
                drawHorse();

            glPopMatrix();

            glPushMatrix();

                glTranslatef(0.0f, 10.0f, -15.0f);
                glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
                drawHorse();

            glPopMatrix();

        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();

}