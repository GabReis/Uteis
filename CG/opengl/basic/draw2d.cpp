/* 
   MyOpenGl.c
   Menu and 2D Open GL Primitives Example
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
   float x, y;
   int i;
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 0.0, 0.0);
   switch (op) {
     case 1: glRectf(-0.5, -0.5, 0.5, 0.5); break;
     case 2: glBegin(GL_LINES);
               glVertex2f(-1.0, -1.0);
               glVertex2f(1.0, 1.0);
             glEnd();
             break;
     case 3: glBegin(GL_TRIANGLES);
               glVertex2f(-0.5, -0.25);
               glVertex2f(0.0, 0.5);
               glVertex2f(0.5, -0.25);
             glEnd();
             break;
     case 4: glBegin(GL_POLYGON);
               glVertex2f(-0.5, -0.5);
               glVertex2f(-0.5, 0.0);
               glVertex2f(0.0, 0.5);
               glVertex2f(0.5, 0.0);
               glVertex2f(0.5, -0.5);
             glEnd();
             break;
     case 5: for (i=0; i<=5000; i++) {
                x = (float) rand() / 32767; /* gera coordenada x aleatória */
                y = (float) rand() / 32767; /* gera coordenada y aleatória */
                /* Cores aleatórias */
                glColor3f((float) rand() / 32767, (float) rand() / 32767, (float) rand() / 32767);
                if (rand() % 2 == 0) x=-x; /* gerar numeros negativos */
                if (rand() % 2 == 0) y=-y; /* gerar numeros negativos */
                glBegin(GL_POINTS);
                  glVertex2f(x, y);
                glEnd();
             }        
             break;
   }
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
      case 1: op=1; glutPostRedisplay(); break;
      case 2: op=2; glutPostRedisplay(); break;
      case 3: op=3; glutPostRedisplay(); break;
      case 4: op=4; glutPostRedisplay(); break;
      case 5: op=5; glutPostRedisplay(); break;
      case 6: exit(0); break;
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
  glutCreateWindow("2D OpenGL Primitives");
  myInit();
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
  glutKeyboardFunc(Key);

  /* Create Menu */
  glutCreateMenu(Select);
  glutAddMenuEntry("Rectangule", 1);
  glutAddMenuEntry("Line", 2);
  glutAddMenuEntry("Triangle", 3);
  glutAddMenuEntry("Polygon", 4);
  glutAddMenuEntry("Points", 5);
  glutAddMenuEntry("Sair", 6);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  glutMainLoop();
  return(0);
}
