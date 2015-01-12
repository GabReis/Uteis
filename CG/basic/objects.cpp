/* 
   MyOpenGl.c
   Single Object Rotate Example
   Ionildo Jose Sanches - 17/02/03
*/ 

/* Includes requeridos */
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h> 
#include <GL/glut.h>

int obj=0;
int grau[2]={0,0}, rx[2]={0,0}, ry[2]={0,0}, rz[2]={0,0};  /* Initial Rotation */

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(1.0, 0.0, 0.0);
   glPushMatrix();
     glTranslatef(-5.0, 0.0, 0.0);
     glRotatef(grau[0],rx[0],ry[0],rz[0]);
     glutWireSphere(2.0, 15, 15);
   glPopMatrix();

   glColor3f(0.0, 1.0, 0.0);
   glPushMatrix();
     glTranslatef(5.0, 0.0, 0.0);
     glRotatef(grau[1],rx[1],ry[1],rz[1]);
     glutWireTeapot(2.0);
   glPopMatrix();
   
   glutSwapBuffers();
}

void myReshape(int w, int h)
{
   glViewport (0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-10.0, 10.0, -10.0, 10.0, 10.0, -10.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void Key(unsigned char key, int x, int y)
{
    switch (key) {
      case '1': obj=0; break;  /* Seleciona a Esfera */
      case '2': obj=1; break;  /* Seleciona a Chaleira */

      case 'x': grau[obj]+=10; rx[obj]=1.0; ry[obj]=0.0; rz[obj]=0.0; break;
      case 'y': grau[obj]+=10; rx[obj]=0.0; ry[obj]=1.0; rz[obj]=0.0; break;
      case 'z': grau[obj]+=10; rx[obj]=0.0; ry[obj]=0.0; rz[obj]=1.0; break;

      case 27: exit(1); break;   /* Esc finaliza o programa */
      default: break;
    }
    glutPostRedisplay();
}

void myInit(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

int main(int argc, char** argv) 
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Rotate Example");
  myInit();
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
  glutKeyboardFunc(Key);
  glutMainLoop();
  return(0);
}
