/* 
   MyOpenGl.c
   Menu and 3D Glut Primitives Example
   Ionildo Jose Sanches - 17/02/03
*/

/* Includes requeridos */
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h> 
#include <GL/glut.h>

int op=0;

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 0.0, 0.0);
   glPushMatrix();
   glRotatef(45, 1.0, 1.0, 0.0);
   switch (op) {
     case 1: glutWireSphere(0.5, 15, 15); break;
     case 2: glutWireCube(0.5); break;
     case 3: glutWireCone(0.5, 0.5, 15, 15); break;
     case 4: glutWireOctahedron(); break;
     case 5: glutWireTorus(0.1, 0.3, 15, 15); break;
     case 6: glutWireTeapot(0.5); break;
   }
   glPopMatrix();
   glutSwapBuffers();
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
      case 1: op=1; glutPostRedisplay(); break;
      case 2: op=2; glutPostRedisplay(); break;
      case 3: op=3; glutPostRedisplay(); break;
      case 4: op=4; glutPostRedisplay(); break;
      case 5: op=5; glutPostRedisplay(); break;
      case 6: op=6; glutPostRedisplay(); break;
      case 7: exit(0); break;
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
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(250, 250);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Menu and 3D GLUT Objects");
  myInit();
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
  glutKeyboardFunc(Key);

  /* Create Menu */
  glutCreateMenu(Select);
  glutAddMenuEntry("Sphere", 1);
  glutAddMenuEntry("Cube", 2);
  glutAddMenuEntry("Cone", 3);
  glutAddMenuEntry("Octahedron", 4);
  glutAddMenuEntry("Torus", 5);
  glutAddMenuEntry("Teapot", 6);
  glutAddMenuEntry("Sair", 7);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  glutMainLoop();
  return(0);
}
