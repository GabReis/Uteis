/* 
   Lines.c
   Lines Examples
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
   glColor3f(1.0, 1.0, 1.0);
   glBegin(GL_LINES);   /* Linha normal */
     glVertex2f(-1,0.9);
     glVertex2f(1,0.9);
   glEnd();

   glEnable(GL_LINE_STIPPLE);

   glLineStipple (1, 0x0101);  /*  dotted (0101010101010101) */
   glBegin(GL_LINES);
     glVertex2f(-1,0.8);    /* ponto inicial (x1, y1) */
     glVertex2f(1,0.8);     /* ponto final (x2, y2) */
   glEnd();

   glLineStipple (1, 0x00FF);  /*  dashed (0000000011111111)*/
   glBegin(GL_LINES);
     glVertex2f(-1,0.7);
     glVertex2f(1,0.7);
   glEnd();

  glLineStipple (3, 0x5757);  /*  dash/dot/dash (0101011101010111 - repetido 3 vezes) */
   glBegin(GL_LINES);
     glVertex2f(-1,0.6);
     glVertex2f(1,0.6);
   glEnd();

   glDisable(GL_LINE_STIPPLE);
   
   glLineWidth (3.0);  /* largura da linha */
   glBegin(GL_LINES);
     glVertex2f(-1,0.5);
     glVertex2f(1,0.5);
   glEnd();

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

void myInit(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

int main(int argc, char** argv) 
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(250, 250);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Lines Program Examples");
  myInit();
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
  glutKeyboardFunc(Key);
  glutMainLoop();
  return(0);
}
