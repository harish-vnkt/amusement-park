#include "simulation.h"
#include <stdio.h>
#include <GL/glut.h>

GLfloat specular[] = {0.5f, 0.5f, 0.5f};
GLfloat shininess = 0.5f;
GLfloat red[] = {1.0f, 0.0f, 0.0f};
GLfloat blue[] = {0.0f, 0.0f, 1.0f};
GLfloat green[] = {0.0f, 1.0f, 0.0f};
GLfloat dark_green[] = {0.0f, 0.3f, 0.0f};
GLfloat white[] = {1.0f, 1.0f, 1.0f};
GLfloat gray[] = {0.5f, 0.5f, 0.5f};
GLfloat brown[] = {0.7f, 0.35f, 0.05f};
GLfloat black[] = {0.0f, 0.0f, 0.0f};

void skyPlane() {
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blue);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, black);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.0f);
    
    glBegin(GL_QUADS);
    
        glVertex3f(-200.0f, 500.0f, -50.0f);
        glVertex3f(-200.0f, -500.0f, -50.0f);
        glVertex3f(200.0f, -500.0f, -50.0f);
        glVertex3f(200.0f, 500.0f, -50.0f);

    glEnd();

}

void drawPlane() {

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dark_green);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, black);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.0f);

    glBegin(GL_QUADS);
    
        glVertex3f(-50.0f, 0.0f, -50.0f);
        glVertex3f(-50.0f, 0.0f, 50.0f);
        glVertex3f(50.0f, 0.0f, 50.0f);
        glVertex3f(50.0f, 0.0f, -50.0f);

    glEnd();

}

void drawMerryGoRound() {

    GLUquadricObj *quadratic = gluNewQuadric();
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    // Pole
    glPushMatrix();

        glTranslatef(0.0f, 1.0f, 0.0f);
        glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic, 1.0f, 1.0f, 23.0f, 8, 8);

    glPopMatrix();

    // Pillars
    glPushMatrix();

        glTranslatef(18.0f, 1.0f, 0.0f);
        glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic, 0.75f, 0.75f, 23.0f, 8, 8);

    glPopMatrix();

    glPushMatrix();

        glTranslatef(0.0f, 1.0f, 18.0f);
        glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic, 0.75f, 0.75f, 23.0f, 8, 8);

    glPopMatrix();

    glPushMatrix();

        glTranslatef(-18.0f, 1.0f, 0.0f);
        glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic, 0.75f, 0.75f, 23.0f, 8, 8);

    glPopMatrix();

    glPushMatrix();

        glTranslatef(0.0f, 1.0f, -18.0f);
        glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic, 0.75f, 0.75f, 23.0f, 8, 8);

    glPopMatrix();

    // Lower platform
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, black);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.2f);
    glPushMatrix();

        glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic, 20.0f, 20.0f, 1.0f, 12, 12);

    glPopMatrix();

    // Lower platform, top disk
    glPushMatrix();

        glTranslatef(0.0f, 1.0f, 0.0f);
        glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
        gluDisk(quadratic, 0.0f, 20.0f, 12, 12);

    glPopMatrix();

    // Upper platform
    
    glPushMatrix();

        glTranslatef(0.0f, 24.0f, 0.0f);
        glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic, 20.0f, 20.0f, 1.0f, 12, 12);

    glPopMatrix();

    // Upper platform, top disk
    glPushMatrix();

        glTranslatef(0.0f, 25.0f, 0.0f);
        glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
        gluDisk(quadratic, 0.0f, 20.0f, 12, 12);

    glPopMatrix();

    // Upper platform, bottom disk
    glPushMatrix();

        glTranslatef(0.0f, 24.0f, 0.0f);
        glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
        gluDisk(quadratic, 0.0f, 20.0f, 12, 12);

    glPopMatrix();

}

void drawHorse() {

    
    GLUquadricObj *quadratic = gluNewQuadric();

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, brown);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, black);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    
    // Body cylinder
    glPushMatrix();

        glTranslatef(3.0f, 0.0f, 0.0f);
        glRotatef(90.0f, 0.0f, -1.0f, 0.0f);
        gluCylinder(quadratic, 1.5f, 1.5f, 6.0f, 8, 8);

    glPopMatrix();

    // Body disks
    glPushMatrix();

        glTranslatef(-3.0f, 0.0f, 0.0f);
        glRotatef(90.0f, 0.0f, -1.0f, 0.0f);
        gluDisk(quadratic, 0.0f, 1.5f, 8, 8);

    glPopMatrix();

    glPushMatrix();

        glTranslatef(3.0f, 0.0f, 0.0f);
        glRotatef(90.0f, 0.0f, -1.0f, 0.0f);
        gluDisk(quadratic, 0.0f, 1.5f, 8, 8);

    glPopMatrix();
    
    // Neck cylinder
    glPushMatrix();

        glTranslatef(-2.5f, 2.0f, 0.0f);
        glRotatef(45.0f, 0.0f, 0.0f, -1.0f);
        glRotatef(90.0f, 0.0f, -1.0f, 0.0f);
        gluCylinder(quadratic, 1.0f, 0.75f, 4.25f, 8, 8);

    glPopMatrix();

    // Neck disk
    glPushMatrix();

        glTranslatef(-2.5f, 2.0f, 0.0f);
        glRotatef(45.0f, 0.0f, 0.0f, -1.0f);
        glRotatef(90.0f, 0.0f, -1.0f, 0.0f);
        gluDisk(quadratic, 0.0f, 1.0f, 8, 8);

    glPopMatrix();

    // Face cone
    glPushMatrix();

        glTranslatef(-5.0f, 3.5f, 0.0f);
        glRotatef(-45.0f, 0.0f, 0.0f, -1.0f);
        glRotatef(90.0f, 0.0f, -1.0f, 0.0f);
        glutSolidCone(1.5f, 3.0f, 8, 8);

    glPopMatrix();

    // Face disk
    glPushMatrix();

        glTranslatef(-5.0f, 3.5f, 0.0f);
        glRotatef(-45.0f, 0.0f, 0.0f, -1.0f);
        glRotatef(90.0f, 0.0f, -1.0f, 0.0f);
        gluDisk(quadratic, 0.0f, 1.5f, 8, 8);        

    glPopMatrix();

    // Eyes
    glPushMatrix();
    
        glTranslatef(-5.75f, 2.75f, 0.75f);
        glutSolidSphere(0.5f, 10, 10);
    
    glPopMatrix();
    
    glPushMatrix();
    
        glTranslatef(-5.75f, 2.75f, -0.75f);
        glutSolidSphere(0.5f, 10, 10);
    
    glPopMatrix();
    
    // Tail
    glPushMatrix();

        glTranslatef(2.5f, 2.0f, 0.0f);
        glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        gluCylinder(quadratic, 1.0f, 0.75f, 4.0f, 8, 8);

    glPopMatrix();

    // Tail disk
    glPushMatrix();

        glTranslatef(2.5f, 2.0f, 0.0f);
        glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        gluDisk(quadratic, 0.0f, 1.0f, 8, 8);

    glPopMatrix();
    
    // Front legs
    glPushMatrix();

        glTranslatef(-3.0f, -1.5f, 0.75f);
        glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
        glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
        gluCylinder(quadratic, 0.5f, 0.5f, 3.0f, 8, 8);

    glPopMatrix();

    glPushMatrix();

        glTranslatef(-3.0f, -1.5f, -0.75f);
        glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
        glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
        gluCylinder(quadratic, 0.5f, 0.5f, 3.0f, 8, 8);

    glPopMatrix();

    // Front disks
    glPushMatrix();

        glTranslatef(-3.0f, -1.5f, 0.75f);
        glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
        glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
        gluDisk(quadratic, 0.0f, 0.5f, 8, 8);

    glPopMatrix();

    glPushMatrix();

        glTranslatef(-3.0f, -1.5f, -0.75f);
        glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
        glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
        gluDisk(quadratic, 0.0f, 0.5f, 8, 8);

    glPopMatrix();

    // Back legs
    glPushMatrix();

        glTranslatef(3.0f, -1.5f, 0.75f);
        glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        gluCylinder(quadratic, 0.5f, 0.5f, 3.0f, 8, 8);

    glPopMatrix();

    glPushMatrix();

        glTranslatef(3.0f, -1.5f, -0.75f);
        glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        gluCylinder(quadratic, 0.5f, 0.5f, 3.0f, 8, 8);

    glPopMatrix();

    // Back disks
    glPushMatrix();

        glTranslatef(3.0f, -1.5f, 0.75f);
        glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        gluDisk(quadratic, 0.0f, 0.5f, 8, 8);

    glPopMatrix();

    glPushMatrix();

        glTranslatef(3.0f, -1.5f, -0.75f);
        glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        gluDisk(quadratic, 0.0f, 0.5f, 8, 8);

    glPopMatrix();
    
}

void drawWheel() {

    GLUquadricObj *quadratic = gluNewQuadric();
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, gray);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    // Disks
    glPushMatrix();

        glTranslatef(0.0f, 0.0f, 0.5f);
        gluDisk(quadratic, 2.0f, 3.0f, 8, 8);
    
    glPopMatrix();

    glPushMatrix();

        glTranslatef(0.0f, 0.0f, -0.5f);
        gluDisk(quadratic, 2.0f, 3.0f, 8, 8);
    
    glPopMatrix();

    // Spokes
    for (int i = 0; i < 8; i++) {
        
        glPushMatrix();
            
            glRotatef(i*45.0f, 0.0f, 0.0f, 1.0f);
            glRotatef(90.0f, -1.0, 0.0f, 0.0f);
            gluCylinder(quadratic, 0.5f, 0.5f, 2.0f, 8, 8);

        glPopMatrix();
    
    }
}

void drawTrain() {

    GLUquadricObj *quadratic = gluNewQuadric();

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, green);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, black);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

    glPushMatrix();

        glTranslatef(-15.0f, 0.0f, 0.0f);
        glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
        gluCylinder(quadratic, 3.0f, 3.0f, 10.0f, 8, 8);

    glPopMatrix();

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, gray);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    
    glPushMatrix();

        glTranslatef(-5.0f, 0.0f, 0.0f);
        glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
        gluCylinder(quadratic, 1.0f, 1.0f, 10.0f, 8, 8);

    glPopMatrix();

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blue);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, black);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

    glPushMatrix();

        glTranslatef(5.0f, 0.0f, 0.0f);
        glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
        glutSolidCone(3.0f, 10.0f, 8, 8);

    glPopMatrix();

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, gray);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    
    glPushMatrix();

        glTranslatef(15.0f, 0.0f, 0.0f);
        glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
        gluCylinder(quadratic, 1.0f, 1.0f, 10.0f, 8, 8);

    glPopMatrix();

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, black);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    
    glPushMatrix();

        glTranslatef(20.0f, 0.0f, 0.0f);
        glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
        glutSolidTorus(3.0f, 5.0f, 6, 6);

    glPopMatrix();
    

}
