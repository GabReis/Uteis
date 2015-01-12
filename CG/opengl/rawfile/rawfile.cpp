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
#include <stdio.h>

FILE *in;

void ReadImage()
{
  int i, j;
  unsigned char v;
  if ((in=fopen("lenabw.rgb","rb")) == NULL)
  {
     printf("Cannot open input file.\n");
     exit(1);
  }
  glBegin(GL_POINTS);
  for (i=0; i<=255; i++)
  {  
     for (j=0; j<=255; j++)
     {
        fread(&v,1,1,in);
        glColor3ub(v,v,v);
        glVertex2i(j,i);
     }
  }
  fclose(in);
  glEnd();
}

/* Executada sempre que é necessario re-exibir a imagem */
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   ReadImage();
//   glFlush();
   glutSwapBuffers();
}

/* Função ativada qdo a janela é aberta pela primeira vez e toda vez 
   que a janela é reconfigurada (movida ou modificado o tamanho) */

void myReshape(int w, int h)
{
   glViewport (0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 255.0, 255.0, 0.0, 1.0, -1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

/* Função ativada qdo alguma tecla é pressionada */

void Key(unsigned char key, int x, int y)
{
    switch (key) {
      case 'r': glRotatef(90, 0.0, 0.0, 1.0); 
                glTranslatef(0.0, -255.0, 0.0);
                glutPostRedisplay();
		break;
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
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(256, 256);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Load RAW Image File");
  myInit();
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
  glutKeyboardFunc(Key);
  glutMainLoop();
  return(0);
}

