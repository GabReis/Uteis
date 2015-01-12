/* 
   Anim1.c
   Animacao usando a funcao Idle
   Ionildo Jose Sanches - 17/02/03
*/ 

/* Includes requeridos */
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h> 
#include <GL/glut.h>
#include <stdio.h>

/* Executada sempre que é necessario re-exibir a imagem */
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 0.0, 1.0);
   glutWireCube(0.5);
   glutSwapBuffers();
}

/* Função ativada qdo a janela é aberta pela primeira vez e toda vez 
   que a janela é reconfigurada (movida ou modificado o tamanho) */

void myReshape(int w, int h)
{
   glViewport (0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

/* Inicializações do programa */

void myInit(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Idle(void)
{
   glRotatef(1, 1, 1, 1);
   glutPostRedisplay();
}

void NoIdle(void)
{}

/* Função ativada qdo alguma tecla é pressionada */
void Key(unsigned char key, int x, int y)
{
    switch (key) {
      case 'p': glutIdleFunc(NoIdle); break;
      case 'c': glutIdleFunc(Idle); break;
      case 27: exit(1); break;   /* Esc finaliza o programa */
      default: break;
    }
}

/* Parte principal - ponto de início de execução */
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
  glutIdleFunc(Idle);
  glutMainLoop();
  return(0);
}
