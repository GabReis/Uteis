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

/* Executada sempre que é necessario re-exibir a imagem */
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
//   glColor3f(1.0, 0.0, 0.0);
   glutSolidSphere(0.6, 20, 20);
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
      case 27: exit(1); break;   /* Esc finaliza o programa */
      default: break;
    }
}

/* Inicializações do programa */

void myInit(void)
{
  GLfloat light_diffuse[] = {1.0, 0.0, 0.0, 1.0};  /* Red diffuse light. */
  GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};  /* Infinite light location. */
  GLfloat light_ambient[] = {1.0, 0.0, 0.0, 1.0};  /* white ambient light. */
  GLfloat light_specular[] = {1.0, 0.0, 0.0, 1.0}; /* white specular light. */
  /* Enable a single OpenGL light. */
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);

  GLfloat mat_diffuse[] = {0.9, 0.9, 0.3, 1.0};
  GLfloat mat_specular[] = {1.0, 0.0, 0.0, 1.0};
  /* Enable a single OpenGL material. */
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialf(GL_FRONT, GL_SHININESS, 1.0);
   glColor4fv(mat_diffuse);
   glColorMaterial(GL_FRONT, GL_DIFFUSE);
   glEnable(GL_COLOR_MATERIAL);

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
