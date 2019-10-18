#include "simulation.h"
#include <stdio.h>
#include <GL/glut.h>

void drawHorse() {

    glColor3f(0.5f, 0.35f, 0.05f);
    // Body
    glBegin(GL_QUADS);

        // Front face
        glVertex3f(-3.0f, 1.5f, 1.5f);
        glVertex3f(-3.0f, -1.5f, 1.5f);
        glVertex3f(3.0f, -1.5f, 1.5f);
        glVertex3f(3.0f, 1.5f, 1.5f);

        // Back face
        glVertex3f(-3.0f, 1.5f, -1.5f);
        glVertex3f(-3.0f, -1.5f, -1.5f);
        glVertex3f(3.0f, -1.5f, -1.5f);
        glVertex3f(3.0f, 1.5f, -1.5f);

        // Top face
        glVertex3f(-3.0f, 1.5f, 1.5f);
        glVertex3f(3.0f, 1.5f, 1.5f);
        glVertex3f(3.0f, 1.5f, -1.5f);
        glVertex3f(-3.0f, 1.5f, -1.5f);

        // Bottom face
        glVertex3f(-3.0f, -1.5f, 1.5f);
        glVertex3f(3.0f, -1.5f, 1.5f);
        glVertex3f(3.0f, -1.5f, -1.5f);
        glVertex3f(-3.0f, -1.5f, -1.5f);

        // Left face
        glVertex3f(-3.0f, 1.5f, 1.5f);
        glVertex3f(-3.0f, -1.5f, 1.5f);
        glVertex3f(-3.0f, -1.5f, -1.5f);
        glVertex3f(-3.0f, 1.5f, -1.5f);

        // Right face
        glVertex3f(3.0f, 1.5f, 1.5f);
        glVertex3f(3.0f, -1.5f, 1.5f);
        glVertex3f(3.0f, -1.5f, -1.5f);
        glVertex3f(3.0f, 1.5f, -1.5f);

    glEnd();

    // Neck triangle
    glBegin(GL_QUADS);

        glVertex3f(-1.0f, 1.5f, 1.5f);
        glVertex3f(-1.0f, 1.5f, -1.5f);
        glVertex3f(-1.0f, 3.5f, -1.5f);
        glVertex3f(-1.0f, 3.5f, 1.5f);

        glVertex3f(-1.0f, 3.5f, 1.5f);
        glVertex3f(-1.0f, 3.5f, -1.5f);
        glVertex3f(-3.0f, 1.5f, -1.5f);
        glVertex3f(-3.0f, 1.5f, 1.5f);

    glEnd();

    // Neck triangles
    glBegin(GL_TRIANGLES);

        glVertex3f(-1.0f, 3.5f, 1.5f);
        glVertex3f(-3.0f, 1.5f, 1.5f);
        glVertex3f(-1.0f, 1.5f, 1.5f);

        glVertex3f(-1.0f, 3.5f, -1.5f);
        glVertex3f(-3.0f, 1.5f, -1.5f);
        glVertex3f(-1.0f, 1.5f, -1.5f);

    glEnd();

    // Neck cuboid
    glBegin(GL_QUADS);

        // Front face
        glVertex3f(-4.0f, 2.5f, 1.5f);
        glVertex3f(-3.0f, 1.5f, 1.5f);
        glVertex3f(-1.0f, 3.5f, 1.5f);
        glVertex3f(-2.0f, 4.5f, 1.5f);

        // Back face
        glVertex3f(-4.0f, 2.5f, -1.5f);
        glVertex3f(-3.0f, 1.5f, -1.5f);
        glVertex3f(-1.0f, 3.5f, -1.5f);
        glVertex3f(-2.0f, 4.5f, -1.5f);

        // Top face
        glVertex3f(-4.0f, 2.5f, 1.5f);
        glVertex3f(-2.0f, 4.5f, 1.5f);
        glVertex3f(-2.0f, 4.5f, -1.5f);
        glVertex3f(-4.0f, 2.5f, -1.5f);

        // Left face
        glVertex3f(-4.0f, 2.5f, 1.5f);
        glVertex3f(-4.0f, 2.5f, -1.5f);
        glVertex3f(-3.0f, 1.5f, -1.5f);
        glVertex3f(-3.0f, 1.5f, 1.5f);

        // Right face
        glVertex3f(-2.0f, 4.5f, 1.5f);
        glVertex3f(-2.0f, 4.5f, -1.5f);
        glVertex3f(-1.0f, 3.5f, -1.5f);
        glVertex3f(-1.0f, 3.5f, 1.5f);

    glEnd();
    
    // Neck cube
    glBegin(GL_QUADS);

        // Front face
        glVertex3f(-4.0f, 2.5f, 1.5f);
        glVertex3f(-2.0f, 4.5f, 1.5f);
        glVertex3f(-4.0f, 6.5f, 1.5f);
        glVertex3f(-6.0f, 4.5f, 1.5f);

        // Back face
        glVertex3f(-4.0f, 2.5f, -1.5f);
        glVertex3f(-2.0f, 4.5f, -1.5f);
        glVertex3f(-4.0f, 6.5f, -1.5f);
        glVertex3f(-6.0f, 4.5f, -1.5f);
        
        // Top face
        glVertex3f(-6.0f, 4.5f, 1.5f);
        glVertex3f(-4.0f, 6.5f, 1.5f);
        glVertex3f(-4.0f, 6.5f, -1.5f);
        glVertex3f(-6.0f, 4.5f, -1.5f);

        // Left face
        glVertex3f(-6.0f, 4.5f, -1.5f);
        glVertex3f(-4.0f, 2.5f, -1.5f);
        glVertex3f(-4.0f, 2.5f, 1.5f);
        glVertex3f(-6.0f, 4.5f, 1.5f);

        // Right face
        glVertex3f(-4.0f, 6.5f, -1.5f);
        glVertex3f(-2.0f, 4.5f, -1.5f);
        glVertex3f(-2.0f, 4.5f, 1.5f);
        glVertex3f(-4.0f, 6.5f, 1.5f);

    glEnd();

    // Face
    glBegin(GL_TRIANGLES);

        // Front face
        glVertex3f(-6.0f, 4.5f, 1.5f);
        glVertex3f(-7.0f, 1.5f, 0.0f);
        glVertex3f(-4.0f, 2.5f, 1.5f);
        
        // Back face
        glVertex3f(-6.0f, 4.5f, -1.5f);
        glVertex3f(-7.0f, 1.5f, 0.0f);
        glVertex3f(-4.0f, 2.5f, -1.5f);

        // Top face
        glVertex3f(-6.0f, 4.5f, 1.5f);
        glVertex3f(-6.0f, 4.5f, -1.5f);
        glVertex3f(-7.0f, 1.5f, 0.0f);

        // Bottom face
        glVertex3f(-4.0f, 2.5f, -1.5f);
        glVertex3f(-4.0f, 2.5f, 1.5f);
        glVertex3f(-7.0f, 1.5f, 0.0f);

    glEnd();

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
    glBegin(GL_QUADS);

        // Tail triangle
        glVertex3f(2.0f, 1.5f, -0.5f);
        glVertex3f(2.0f, 2.5f, -0.5f);
        glVertex3f(2.0f, 2.5f, 0.5f);
        glVertex3f(2.0f, 1.5f, 0.5f);

        glVertex3f(2.0f, 2.5f, 0.5f);
        glVertex3f(2.0f, 2.5f, -0.5f);
        glVertex3f(3.0f, 1.5f, -0.5f);
        glVertex3f(3.0f, 1.5f, 0.5f);

        // Tail cuboid

        // Front face
        glVertex3f(2.0f, 2.5f, 0.5f);
        glVertex3f(4.0f, 4.5f, 0.5f);
        glVertex3f(5.0f, 3.5f, 0.5f);
        glVertex3f(3.0f, 1.5f, 0.5f);

        // Back face
        glVertex3f(2.0f, 2.5f, -0.5f);
        glVertex3f(4.0f, 4.5f, -0.5f);
        glVertex3f(5.0f, 3.5f, -0.5f);
        glVertex3f(3.0f, 1.5f, -0.5f);

        // Top face
        glVertex3f(2.0f, 2.5f, 0.5f);
        glVertex3f(4.0f, 4.5f, 0.5f);
        glVertex3f(4.0f, 4.5f, -0.5f);
        glVertex3f(2.0f, 2.5f, -0.5f);

        // Bottom face
        glVertex3f(3.0f, 1.5f, 0.5f);
        glVertex3f(3.0f, 1.5f, -0.5f);
        glVertex3f(5.0f, 3.5f, -0.5f);
        glVertex3f(5.0f, 3.5f, 0.5f);

        // Right face
        glVertex3f(4.0f, 4.5f, 0.5f);
        glVertex3f(4.0f, 4.5f, -0.5f);
        glVertex3f(5.0f, 3.5f, -0.5f);
        glVertex3f(5.0f, 3.5f, 0.5f);

    glEnd();

    // Tail triangles
    glBegin(GL_TRIANGLES);
    
        glVertex3f(-3.0f, 1.5f, 1.5f);
        glVertex3f(2.0f, 2.5f, 1.5f);
        glVertex3f(3.0f, 1.5f, 0.5f);

        glVertex3f(2.0f, 1.5f, -0.5f);
        glVertex3f(2.0f, 2.5f, -0.5f);
        glVertex3f(3.0f, 1.5f, -0.5f);
        
    glEnd();

    // Front legs
    glBegin(GL_QUADS);

        // Leg triangle
        glVertex3f(-2.0f, -1.5f, 0.5f);
        glVertex3f(-2.0f, -2.5f, 0.5f);
        glVertex3f(-2.0f, -2.5f, 1.5f);
        glVertex3f(-2.0f, -1.5f, 1.5f);
        
        glVertex3f(-2.0f, -1.5f, -0.5f);
        glVertex3f(-2.0f, -2.5f, -0.5f);
        glVertex3f(-2.0f, -2.5f, -1.5f);
        glVertex3f(-2.0f, -1.5f, -1.5f);

        glVertex3f(-3.0f, -1.5f, 0.5f);
        glVertex3f(-2.0f, -2.5f, 0.5f);
        glVertex3f(-2.0f, -2.5f, 1.5f);
        glVertex3f(-3.0f, -1.5f, 1.5f);

        glVertex3f(-3.0f, -1.5f, -0.5f);
        glVertex3f(-2.0f, -2.5f, -0.5f);
        glVertex3f(-2.0f, -2.5f, -1.5f);
        glVertex3f(-3.0f, -1.5f, -1.5f);

        // Leg cuboid
        // Front face
        glVertex3f(-3.0f, -1.5f, 1.5f);
        glVertex3f(-5.0f, -3.5f, 1.5f);
        glVertex3f(-4.0f, -4.5f, 1.5f);
        glVertex3f(-2.0f, -2.5f, 1.5f);

        // Back face
        glVertex3f(-3.0f, -1.5f, 0.5f);
        glVertex3f(-5.0f, -3.5f, 0.5f);
        glVertex3f(-4.0f, -4.5f, 0.5f);
        glVertex3f(-2.0f, -2.5f, 0.5f);

        // Top face
        glVertex3f(-5.0f, -3.5f, 1.5f);
        glVertex3f(-3.0f, -1.5f, 1.5f);
        glVertex3f(-3.0f, -1.5f, 0.5f);
        glVertex3f(-5.0f, -3.5f, 0.5f);

        // Bottom face
        glVertex3f(-4.0f, -4.5f, 1.5f);
        glVertex3f(-2.0f, -2.5f, 1.5f);
        glVertex3f(-2.0f, -2.5f, 0.5f);
        glVertex3f(-4.0f, -4.5f, 0.5f);

        // Left face
        glVertex3f(-4.0f, -4.5f, 1.5f);
        glVertex3f(-5.0f, -3.5f, 1.5f);
        glVertex3f(-5.0f, -3.5f, 0.5f);
        glVertex3f(-4.0f, -4.5f, 1.5f);

        // Front face
        glVertex3f(-3.0f, -1.5f, -0.5f);
        glVertex3f(-5.0f, -3.5f, -0.5f);
        glVertex3f(-4.0f, -4.5f, -0.5f);
        glVertex3f(-2.0f, -2.5f, -0.5f);

        // Back face
        glVertex3f(-3.0f, -1.5f, -1.5f);
        glVertex3f(-5.0f, -3.5f, -1.5f);
        glVertex3f(-4.0f, -4.5f, -1.5f);
        glVertex3f(-2.0f, -2.5f, -1.5f);

        // Top face
        glVertex3f(-5.0f, -3.5f, -0.5f);
        glVertex3f(-3.0f, -1.5f, -0.5f);
        glVertex3f(-3.0f, -1.5f, -1.5f);
        glVertex3f(-5.0f, -3.5f, -1.5f);

        // Bottom face
        glVertex3f(-4.0f, -4.5f, -0.5f);
        glVertex3f(-2.0f, -2.5f, -0.5f);
        glVertex3f(-2.0f, -2.5f, -1.5f);
        glVertex3f(-4.0f, -4.5f, -1.5f);

        // Left face
        glVertex3f(-4.0f, -4.5f, -0.5f);
        glVertex3f(-5.0f, -3.5f, -0.5f);
        glVertex3f(-5.0f, -3.5f, -1.5f);
        glVertex3f(-4.0f, -4.5f, -1.5f);

    glEnd();

    // Leg triangles
    glBegin(GL_TRIANGLES);
    
        glVertex3f(-3.0f, -1.5f, 1.5f);
        glVertex3f(-2.0f, -2.5f, 1.5f);
        glVertex3f(-2.0f, -1.5f, 1.5f);

        glVertex3f(-3.0f, -1.5f, 0.5f);
        glVertex3f(-2.0f, -2.5f, 0.5f);
        glVertex3f(-2.0f, -1.5f, 0.5f);

        glVertex3f(-3.0f, -1.5f, -0.5f);
        glVertex3f(-2.0f, -2.5f, -0.5f);
        glVertex3f(-2.0f, -1.5f, -0.5f);

        glVertex3f(-3.0f, -1.5f, -1.5f);
        glVertex3f(-2.0f, -2.5f, -1.5f);
        glVertex3f(-2.0f, -1.5f, -1.5f);
        
    glEnd();

    // Back legs
    glBegin(GL_QUADS);

        // Leg triangle
        glVertex3f(2.0f, -1.5f, 0.5f);
        glVertex3f(2.0f, -2.5f, 0.5f);
        glVertex3f(2.0f, -2.5f, 1.5f);
        glVertex3f(2.0f, -1.5f, 1.5f);
        
        glVertex3f(2.0f, -1.5f, -0.5f);
        glVertex3f(2.0f, -2.5f, -0.5f);
        glVertex3f(2.0f, -2.5f, -1.5f);
        glVertex3f(2.0f, -1.5f, -1.5f);

        glVertex3f(3.0f, -1.5f, 0.5f);
        glVertex3f(2.0f, -2.5f, 0.5f);
        glVertex3f(2.0f, -2.5f, 1.5f);
        glVertex3f(3.0f, -1.5f, 1.5f);

        glVertex3f(3.0f, -1.5f, -0.5f);
        glVertex3f(2.0f, -2.5f, -0.5f);
        glVertex3f(2.0f, -2.5f, -1.5f);
        glVertex3f(3.0f, -1.5f, -1.5f);

        // Leg cuboid
        // Front face
        glVertex3f(3.0f, -1.5f, 1.5f);
        glVertex3f(5.0f, -3.5f, 1.5f);
        glVertex3f(4.0f, -4.5f, 1.5f);
        glVertex3f(2.0f, -2.5f, 1.5f);

        // Back face
        glVertex3f(3.0f, -1.5f, 0.5f);
        glVertex3f(5.0f, -3.5f, 0.5f);
        glVertex3f(4.0f, -4.5f, 0.5f);
        glVertex3f(2.0f, -2.5f, 0.5f);

        // Top face
        glVertex3f(5.0f, -3.5f, 1.5f);
        glVertex3f(3.0f, -1.5f, 1.5f);
        glVertex3f(3.0f, -1.5f, 0.5f);
        glVertex3f(5.0f, -3.5f, 0.5f);

        // Bottom face
        glVertex3f(4.0f, -4.5f, 1.5f);
        glVertex3f(2.0f, -2.5f, 1.5f);
        glVertex3f(2.0f, -2.5f, 0.5f);
        glVertex3f(4.0f, -4.5f, 0.5f);

        // Left face
        glVertex3f(4.0f, -4.5f, 1.5f);
        glVertex3f(5.0f, -3.5f, 1.5f);
        glVertex3f(5.0f, -3.5f, 0.5f);
        glVertex3f(4.0f, -4.5f, 1.5f);

        // Front face
        glVertex3f(3.0f, -1.5f, -0.5f);
        glVertex3f(5.0f, -3.5f, -0.5f);
        glVertex3f(4.0f, -4.5f, -0.5f);
        glVertex3f(2.0f, -2.5f, -0.5f);

        // Back face
        glVertex3f(3.0f, -1.5f, -1.5f);
        glVertex3f(5.0f, -3.5f, -1.5f);
        glVertex3f(4.0f, -4.5f, -1.5f);
        glVertex3f(2.0f, -2.5f, -1.5f);

        // Top face
        glVertex3f(5.0f, -3.5f, -0.5f);
        glVertex3f(3.0f, -1.5f, -0.5f);
        glVertex3f(3.0f, -1.5f, -1.5f);
        glVertex3f(5.0f, -3.5f, -1.5f);

        // Bottom face
        glVertex3f(4.0f, -4.5f, -0.5f);
        glVertex3f(2.0f, -2.5f, -0.5f);
        glVertex3f(2.0f, -2.5f, -1.5f);
        glVertex3f(4.0f, -4.5f, -1.5f);

        // Left face
        glVertex3f(4.0f, -4.5f, -0.5f);
        glVertex3f(5.0f, -3.5f, -0.5f);
        glVertex3f(5.0f, -3.5f, -1.5f);
        glVertex3f(4.0f, -4.5f, -1.5f);

    glEnd();

    // Leg triangles
    glBegin(GL_TRIANGLES);

        glVertex3f(3.0f, -1.5f, 1.5f);
        glVertex3f(2.0f, -2.5f, 1.5f);
        glVertex3f(2.0f, -1.5f, 1.5f);

        glVertex3f(3.0f, -1.5f, 0.5f);
        glVertex3f(2.0f, -2.5f, 0.5f);
        glVertex3f(2.0f, -1.5f, 0.5f);

        glVertex3f(3.0f, -1.5f, -0.5f);
        glVertex3f(2.0f, -2.5f, -0.5f);
        glVertex3f(2.0f, -1.5f, -0.5f);

        glVertex3f(3.0f, -1.5f, -1.5f);
        glVertex3f(2.0f, -2.5f, -1.5f);
        glVertex3f(2.0f, -1.5f, -1.5f);
        
    glEnd();
    

}