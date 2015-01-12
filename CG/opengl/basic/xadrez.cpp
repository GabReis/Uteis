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

void desenho()
{
   int x,y; float cor=0;
   for (y=0; y<=7; y++) {
      cor=!cor;
      for (x=0; x<=7; x++) {
        glColor3f(cor, 0.6, 0.2);
        cor=!cor;
        glRectf(-40+x*10, 40-y*10, -40+x*10+10, 40-y*10-10);  /* coordenadas (x0,y0) e (x1,y1) */
      }
   }
}

/* Executada sempre que é necessario re-exibir a imagem */
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   desenho();
   glFlush();
}

/* Função ativada qdo a janela é aberta pela primeira vez e toda vez 
   que a janela é reconfigurada (movida ou modificado o tamanho) */

void myReshape(int w, int h)
{
   glViewport (0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

/* Função ativada qdo alguma tecla é pressionada */

void Key(unsigned char key, int x, int y)
{
    switch (key) {
      case 27: exit(1); break;   /* Esc finaliza o programa */
      default: break;
    }
}

/* Inicializações do programa */

void myInit(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

/* Parte principal - ponto de início de execução */

int main(int argc, char** argv) 
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(150, 0);
  glutCreateWindow("Tabuleiro de Xadrez 2D");
  myInit();
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
  glutKeyboardFunc(Key);
  glutMainLoop();
  return(0);
}
