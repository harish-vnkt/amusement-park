#include "simulation.h"
#include <stdio.h>
#include <GL/glut.h>

void drawPlane() {

    glColor3f(0.0f, 0.3f, 0.0f);

    glBegin(GL_QUADS);
    
        glVertex3f(-50.0f, 0.0f, -50.0f);
        glVertex3f(-50.0f, 0.0f, 50.0f);
        glVertex3f(50.0f, 0.0f, 50.0f);
        glVertex3f(50.0f, 0.0f, -50.0f);

    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);

}

void drawMerryGoRound() {

    GLUquadricObj *quadratic = gluNewQuadric();
    
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
    glColor3f(1.0f, 0.0f, 0.0f);
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
    glColor3f(1.0f, 0.0f, 0.0f);
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

    glColor3f(0.5f, 0.35f, 0.05f);
    GLUquadricObj *quadratic = gluNewQuadric();
    
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
    glColor3f(0.0f, 0.0f, 0.0f);
    glPushMatrix();
    
        glTranslatef(-5.75f, 2.75f, 0.75f);
        glutSolidSphere(0.5f, 10, 10);
    
    glPopMatrix();
    
    glPushMatrix();
    
        glTranslatef(-5.75f, 2.75f, -0.75f);
        glutSolidSphere(0.5f, 10, 10);
    
    glPopMatrix();
    glColor3f(0.5f, 0.35f, 0.05f);
    
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
    
    glColor3f(1.0f, 1.0f, 1.0f);
    
}