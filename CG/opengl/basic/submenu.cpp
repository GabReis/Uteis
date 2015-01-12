/* 
   MyOpenGl.c
   Sub Menu Example
   Ionildo Jose Sanches - 17/02/03
*/

/* Includes requeridos */
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h> 
#include <GL/glut.h>

float color[3] = {1.0, 1.0, 1.0};
int rect=0;

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(color[0], color[1], color[2]);
   if (rect) 
      glRectf(-0.5, 0.5, 0.5, -0.5);  /* coordenadas (x0,y0) e (x1,y1) */
   glFlush();
}

void myReshape(int w, int h)
{
   glViewport (0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void Key(unsigned char key, int x, int y)
{
    switch (key) {
      case 27: exit(1); break;   /* Esc finaliza o programa */
      default: break;
    }
}

void Select(int value)
{
    switch (value) {
      case 2: rect=1; glutPostRedisplay(); break;
      case 3: rect=0; glutPostRedisplay(); break;
      case 4: exit(0); break;
    }
}

void Color(int value)
{
    switch (value) {
      case 1: color[0]=1.0; color[1]=0.0, color[2]=0.0; glutPostRedisplay(); break;
      case 2: color[0]=0.0; color[1]=1.0, color[2]=0.0; glutPostRedisplay(); break;
      case 3: color[0]=0.0; color[1]=0.0, color[2]=1.0; glutPostRedisplay(); break;
    }
}

void myInit(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

int main(int argc, char** argv) 
{
  int submenu;
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(250, 250);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Sub Menu Program Example");
  myInit();
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
  glutKeyboardFunc(Key);

/* Create Menu and Sub Menu*/
  submenu = glutCreateMenu(Color);
  glutAddMenuEntry("Red", 1);
  glutAddMenuEntry("Green", 2);
  glutAddMenuEntry("Blue", 3);
  glutCreateMenu(Select);
  glutAddSubMenu("Color", submenu);
  glutAddMenuEntry("Rectangule", 2);
  glutAddMenuEntry("Clear Window", 3);
  glutAddMenuEntry("Quit", 4);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  glutMainLoop();
  return(0);
}
