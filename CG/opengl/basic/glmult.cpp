/* 
   glMultMatrix Translate Example
   Ionildo Jose Sanches - 17/02/03
*/ 

/* Includes requeridos */
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h> 
#include <GL/glut.h>

float tx=0, ty=0, tz=0;

void display(void)
{
   float T[16]={1, 0, 0, 0,  0, 1, 0, 0,  0, 0, 1, 0,  tx, ty, tz, 1};
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 0.0, 0.0);
   glPushMatrix();
     glMultMatrixf(T);
     glRectf(-1.0, 1.0, 1.0, -1.0);  /* coordenadas (x0,y0) e (x1,y1) */
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

void SpecialKeys(int key, int x, int y)
{
    switch (key) {
      case GLUT_KEY_RIGHT: tx+=1; break;
      case GLUT_KEY_LEFT: tx-=1; break;
      case GLUT_KEY_UP: ty+=1; break;
      case GLUT_KEY_DOWN: ty-=1; break;
      default: break;
    }
    glutPostRedisplay();
}

void Key(unsigned char key, int x, int y)
{
    switch (key) {
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
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("My OpenGL Program");
  myInit();
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
  glutKeyboardFunc(Key);
  glutSpecialFunc(SpecialKeys);
  glutMainLoop();
  return(0);
}
