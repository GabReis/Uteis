/* 
   glMultMatrix Translate Example
   Ionildo Jose Sanches - 17/02/03
*/ 

/* Includes requeridos */
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h> 
#include <GL/glut.h>

float x=1, y=1, z=1;

void display(void)
{
   float T[16]={x, 0, 0, 0,  0, y, 0, 0,  0, 0, z, 0,  0, 0, 0, 1};
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 0.0, 0.0);
   glPushMatrix();
     if (x==0) glRotatef(90, 0, 1, 0);
     if (y==0) glRotatef(90, 1, 0, 0);
     glMultMatrixf(T);
     glutWireTeapot(3.0);
//     glutWireCube(2);
//     glutWireSphere(3, 20, 20);
   glPopMatrix();
   glutSwapBuffers();
}

void myReshape(int w, int h)
{
   glViewport (0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-10.0, 10.0, -10.0, 10.0, 10.0, -10.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void Key(unsigned char key, int a, int b)
{
    switch (key) {
      case 'x': x=0; y=1; z=1; break;
      case 'y': x=1; y=0; z=1; break;
      case 'z': x=1; y=1; z=0; break;
      case 27: exit(1); break;   /* Esc finaliza o programa */
      default: break;
    }
    glutPostRedisplay();
}

void myInit(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

int main(int argc, char** argv) 
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("My OpenGL Program");
  myInit();
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
  glutKeyboardFunc(Key);
  glutMainLoop();
  return(0);
}
