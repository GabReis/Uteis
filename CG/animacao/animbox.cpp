/* 
   MyOpenGl.c
   Rectangles, Special Keys, Idle Time and Animation Examples
   Ionildo Jose Sanches - 17/02/03
*/ 

/* Includes requeridos */
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h> 
#include <GL/glut.h>

#define STEP 3

float xx=50;
int k=-1, right=1;

/* Executada sempre que é necessario re-exibir a imagem */
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3ub(100, 100, 100);
   glRectf(0.0, 0.0, 640.0, 30.0);  /* coordenadas (x0,y0) e (x1,y1) */
   glRectf(0.0, 30.0, 40.0, 480.0);  
   glRectf(600.0, 30.0, 640.0, 480.0);  
   glColor3ub(255, 255, 0);
   glRectf(30.0, 100.0, 90.0, 110.0);
   glColor3ub(255, 255, 0);
   glRectf(610.0, 100.0, 550.0, 110.0);
   glColor3ub(0, 255, 0);
   glRectf(xx, 110, xx+20, 130);
   glutSwapBuffers();
}

void myReshape(int w, int h)
{
   glViewport (0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, 640, 0, 480, 1.0, -1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

/* Função ativada qdo for detectado tempo ocioso */
void Idle(void)
{
    if (k==1) {
       if (xx>=570) right=0;   /* se estiver no limite direito, volta para a esquerda */
       if (xx<=50) right=1;    /* o mesmo para o limite esquerdo */ 
       if (right && xx<570)
          xx+=STEP;
       else if (!right && xx>50)
               xx-=STEP;
       glutPostRedisplay();
    }
}

/* Função ativada qdo alguma tecla especial é pressionada */
void SpecialKeys(int key, int x, int y)
{
    switch (key) {
      case GLUT_KEY_RIGHT: 
         if (xx<570) xx+=STEP;  /* avança o quadrado para a direita */
         glutPostRedisplay();
         break;
      case GLUT_KEY_LEFT: 
         if (xx>50) xx-=STEP;  /* avança o quadrado para a esquerda */
         glutPostRedisplay();
         break;
      default: break;
    }
/* Para consultar outras teclas especiais consulte glut.h */
}

/* Função ativada qdo alguma tecla é pressionada */
void Key(unsigned char key, int x, int y)
{
    switch (key) {
      case 'k': k=-k; break;     /* seta k para movimentar ou não o quadrado */
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
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Special Keys and Idle Time");
  myInit();
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
  glutKeyboardFunc(Key);
  /* Especifica a funcao que vai tratar teclas especiais */
  glutSpecialFunc(SpecialKeys);
  /* Especifica a funcao que vai tratar ociosidade */
  glutIdleFunc(Idle);
  glutMainLoop();
  return(0);
}
