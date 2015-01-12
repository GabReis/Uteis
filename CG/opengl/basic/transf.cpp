/* 
   MyOpenGl.c
   3D Transformations Example
   Ionildo Jose Sanches - 17/02/03
*/ 

/* Includes requeridos */
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h> 
#include <GL/glut.h>

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 0.0, 0.0);
   glutWireCube(1.0);
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

void Key(unsigned char key, int x, int y)
{
    switch (key) {
      case 'x': glRotatef(10, 1.0, 0.0, 0.0); break;
      case 'y': glRotatef(10, 0.0, 1.0, 0.0); break;      
      case 'z': glRotatef(10, 0.0, 0.0, 1.0); break;

      case '+': glScalef(1.1, 1.1, 1.1); break;
      case '-': glScalef(0.9, 0.9, 0.9); break;

      case '6': glTranslatef(0.1, 0.0, 0.0); break;
      case '4': glTranslatef(-0.1, 0.0, 0.0); break;
      case '8': glTranslatef(0.0, 0.1, 0.0); break;
      case '2': glTranslatef(0.0, -0.1, 0.0); break;

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
  glutInitWindowPosition(0, 0);
  glutCreateWindow("3D Transformation Example");
  myInit();
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
  glutKeyboardFunc(Key);
  glutMainLoop();
  return(0);
}
