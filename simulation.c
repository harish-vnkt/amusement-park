#include "simulation.h"
#include <stdio.h>
#include <GL/glut.h>

GLint width = 1100;
GLint height = 650;

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(width, height);
    glutCreateWindow("Amusement Park");

    glClearColor( 0.0, 0.0, 0.0, 1.0 );

    glutReshapeFunc(reshape);
    glutDisplayFunc(render);
    glutKeyboardFunc(keyboard);
    init();

    glutMainLoop();

}

void init() {

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST); // Antialias lines
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void reshape(GLint w, GLint h) {

	width = w;
	height = h;

	glViewport(0, 0, w, h);
	
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (float)w / (float)h, 1.0f, 120.0f);
	gluLookAt(0.0f, 10.0f, 15.0f,
		0.0f, 0.0f, 0.0f,   
		0.0f, 1.0f, 0.0f);  

    glMatrixMode(GL_MODELVIEW);

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
    glutSwapBuffers();

}