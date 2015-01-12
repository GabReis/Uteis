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

float t=1.0;

/* Executada sempre que é necessario re-exibir a imagem */
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
     glRotatef(30,1,1,1);
     glColor3f(1.0, 0.0, 0.0);
     glutSolidCube(0.5);
     glColor3f(1.0, 1.0, 1.0);
     glutWireCube(0.5);
   glPopMatrix();
   glColor4f(0.0, 0.0, 1.0, t);
   glutSolidSphere(0.8, 20, 20);

   glutSwapBuffers();
}

/* Função ativada qdo a janela é aberta pela primeira vez e toda vez 
   que a janela é reconfigurada (movida ou modificado o tamanho) */

void myReshape(int w, int h)
{
   glViewport (0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

/* Função ativada qdo alguma tecla é pressionada */

void Key(unsigned char key, int x, int y)
{
    switch (key) {
      case '-': t=t-0.01; break;
      case '+': t=t+0.01; break;
      case 27: exit(1); break;   /* Esc finaliza o programa */
      default: break;
    }
    glutPostRedisplay();
}

/* Inicializações do programa */

void myInit(void)
{
  glEnable (GL_BLEND);
  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glClearColor(0.0, 0.0, 0.0, 0.0);
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
