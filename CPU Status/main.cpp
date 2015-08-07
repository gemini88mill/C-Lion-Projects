#include<stdio.h>
#include<stdlib.h>
#include<GL/glew.h>

#include <GL/glut.h>





int main(int argc, char *argv[])
{
    //program starts here...
    printf("hello world");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tutorial 01");

    //glutDisplayFunc(RenderSceneCB);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glutMainLoop();

    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
    return 0;
}

