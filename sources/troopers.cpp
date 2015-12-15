/** @file troopers.cpp
 *  @brief Main file of a project
 */

#include "bonus.h"
#include "celltype.h"
#include "player.h"
#include "trooper.h"
#include "unit.h"
#include "world.h"

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

/**
 * @namespace model
 * @brief A namespace that contains project Model
 */

using namespace std;

void renderScene()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glutSwapBuffers();
}

void setupRC()
{
   glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
}

void changeSize(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
    glutPostRedisplay();
}

void timerFunction(GLint value)
{
    glutPostRedisplay();
    glutTimerFunc(100, timerFunction, 1);
}

int main(int argc, char** argv)
{
    const int windowWidth = 700;
    const int windowHeight = 700;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Strategy runner");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutTimerFunc(100, timerFunction, 1);
    changeSize(windowWidth, windowHeight);
    setupRC();
    glutMainLoop();
    return 0;
}