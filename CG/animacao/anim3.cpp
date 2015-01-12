/* 
   Anim1.c
   Animacao chamando a funcao display recursivamente
   Ionildo Jose Sanches - 17/02/03
*/ 

/* Includes requeridos */
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h> 
#include <GL/glut.h>
#include <stdio.h>

int xx=1;

/* Executada sempre que é necessario re-exibir a imagem */
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 0.0, 1.0);
   glRotatef(xx, 1, 1, 1);
   glutWireCube(0.5);
   glutSwapBuffers();
   if (xx==1) glutPostRedisplay();
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

/* Função ativada qdo alguma tecla é pressionada */
void Key(unsigned char key, int x, int y)
{
    switch (key) {
      case 'p': xx=0; break;
      case 'c': xx=1; break;
      case 27: exit(1); break;   /* Esc finaliza o programa */
      default: break;
    }
    glutPostRedisplay();
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
  glutMainLoop();
  return(0);
}
