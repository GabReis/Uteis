/* 
   Color Example
   Ionildo Jose Sanches - 17/02/03
*/ 

/* Includes requeridos */
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h> 
#include <GL/glut.h>
#include <stdio.h>

int r=1, g=0, b=0;
unsigned int red=255, green=255, blue=255;

/* Executada sempre que é necessario re-exibir a imagem */
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3ub(red, green, blue);
   glRectf(-0.5, 0.8, 0.5, 0.2);
   glColor3ub(255, 0, 0);
   glColor3f(r, g-1, b-1);
   glRectf(-0.9, -0.3, -0.4, -0.6);
   glColor3f(r-1, g, b-1);
   glRectf(-0.25, -0.3, 0.25, -0.6);
   glColor3f(r-1, g-1, b);
   glRectf(0.4, -0.3, 0.9, -0.6);
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
void Key(unsigned char key, int x, int y)
{
    static int old_x = 100;
    static int old_y = 100;
    static int old_width = 400;
    static int old_height = 400;

    switch (key) {
      case 'w': glutPositionWindow(old_x, old_y);
                glutReshapeWindow(old_width, old_height);
                break;
      case 'f': if (glutGet(GLUT_WINDOW_WIDTH) != glutGet(GLUT_SCREEN_WIDTH)) {
                   old_x = glutGet(GLUT_WINDOW_X);
 	               old_y = glutGet(GLUT_WINDOW_Y);
	     	       old_width = glutGet(GLUT_WINDOW_WIDTH);
	    	       old_height = glutGet(GLUT_WINDOW_HEIGHT);
	    	       glutFullScreen();
	    	    }
	    	    break;
      case 'r': r=1; g=b=0; break;
      case 'g': g=1; r=b=0; break;
      case 'b': b=1; r=g=0; break;
      case '+': if (r) { if (red < 255) red++; }
                  else if (g) { if (green < 255) green++; }
                          else if (b) { if (blue < 255) blue++; }
                break; 
      case '-': if (r) { if (red > 0) red--; }
                  else if (g) { if (green > 0) green--; }
                          else if (b) { if (blue > 0) blue--; }
                break; 
      case 27: exit(1); break;     /* Esc will quit */
      default: break;
    }
    glutPostRedisplay();
    printf("RGB = (%d, %d, %d)   \r", red, green, blue);
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
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("My OpenGL Program");
  myInit();
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
  glutKeyboardFunc(Key);
  glutMainLoop();
  return(0);
}
