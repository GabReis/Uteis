/* 
   MyOpenGl.c
   Simple Template of programming using the OpenGL graphics library
   Ionildo Jose Sanches - 17/02/03
*/ 

/* Includes requeridos */
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h> 
#include <GL/glut.h>

/* Executada sempre que � necessario re-exibir a imagem */
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 0.0, 0.0);
   glutWireCube(0.5);
   glutSwapBuffers();
}

/* Fun��o ativada qdo a janela � aberta pela primeira vez e toda vez 
   que a janela � reconfigurada (movida ou modificado o tamanho) */

void myReshape(int w, int h)
{
   glViewport (0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void TimerFunction(int value)
{
   glRotatef(1, 1, 1, 1);
   glutPostRedisplay();
   glutTimerFunc(33,TimerFunction, 1);
}

/* Fun��o ativada qdo alguma tecla � pressionada */

void Key(unsigned char key, int x, int y)
{
    switch (key) {
      case 27: exit(1); break;   /* Esc finaliza o programa */
      default: break;
    }
}

/* Inicializa��es do programa */

void myInit(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

/* Parte principal - ponto de in�cio de execu��o */

int main(int argc, char** argv) 
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(250, 250);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("My OpenGL Program");
  myInit();
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
  glutKeyboardFunc(Key);
  glutTimerFunc(33, TimerFunction, 1);
  glutMainLoop();
  return(0);
}
