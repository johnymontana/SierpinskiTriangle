// William Lyon
// hw2.c
// CSCI 441
// Homework 2
// Rendering Sierpenski Gasket using point approximation
// 09.14.12



#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif

#include "stdlib.h"

static void display()
{
    typedef GLfloat point2[2];
    point2 vertices[3] = {{-1.0,-1.0},{0.0, 1.0},{1.0,-1.0}};
    int random_num;
    point2  p = {0, 0};
    glClear (GL_COLOR_BUFFER_BIT);
    
    int i;
    for(i =0; i < 4000000;i++)
        {   
            random_num = rand();
            random_num %= 3;
            p[0] = (p[0] + vertices[random_num][0])/2.0;
            p[1] = (p[1] + vertices[random_num][1])/2.0;
            glBegin(GL_POINTS);
            glVertex2fv(p);
            
            // Playing with differnt pseudo random colors - this will be some sort of teal with randomness sprinkled in
            glColor3f((rand() % 7) / (rand()%75*1.0) , (rand() % 75) / (rand()%100*1.0) , (rand() % 75) / (rand()%100*1.0) );
            glEnd();
        }
       
    glFlush ();
}

static void set_projection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(900, 900);
    glutCreateWindow("Sierpenski Gasket");
    glutDisplayFunc(display);
    set_projection();
    glutMainLoop();
    return 0;
}
