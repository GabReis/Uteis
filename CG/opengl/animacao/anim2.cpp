/* 
   Anim3.c
   Animcacao usando a funcao Timer
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
int yy=100;

/* Executada sempre que é necessario re-exibir a imagem */
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 0.0, 1.0);
     
   glPushMatrix();
//     glRotatef(xx, 1, 1, 1);
     glutWireCube(0.5);
   glPopMatrix();

//   glColor3f(1.0, 0.0, 0.0);
//   glutWireSphere(0.8, 30, 30);
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

/* Função ativada qdo alguma tecla é pressionada */

/* Inicializações do programa */

void myInit(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

void TimerFunction(int value)
{
  if (xx!=0)
  {
//     xx++;
     glRotatef(1, 1, 1, 1);
     glutPostRedisplay();
     glutTimerFunc(yy,TimerFunction, 1);
  }
}

void Key(unsigned char key, int x, int y)
{
    switch (key) {
      case 'p': xx=0; break;
      case 'c': if (xx==0){
                   glutTimerFunc(yy, TimerFunction, 1);
                   xx=1; 
                } break;
      case '+': yy++; break;  /* speed */
      case '-': yy--; break;
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
  glutTimerFunc(yy, TimerFunction, 1);
  glutMainLoop();
  return(0);
}
