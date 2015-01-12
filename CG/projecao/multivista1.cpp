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

float x=1, y=1, z=1;

void display(void)
{
   float Mx[16]={0, 0, 0, 0,  0, 1, 0, 0,  0, 0, 1, 0,  0, 0, 0, 1};
   float My[16]={1, 0, 0, 0,  0, 0, 0, 0,  0, 0, 1, 0,  0, 0, 0, 1};
   float Mz[16]={1, 0, 0, 0,  0, 1, 0, 0,  0, 0, 0, 0,  0, 0, 0, 1};
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 0.0, 0.0);
   glPushMatrix();
     glTranslatef(-10, 10.0, 0);
     glRotatef(90, 0, 1, 0);
     glMultMatrixf(Mx);
     glutWireTeapot(3.0);
   glPopMatrix();

   glPushMatrix();
     glTranslatef(-10, 0, 0);
     glRotatef(90, 1, 0, 0);
     glMultMatrixf(My);
     glutWireTeapot(3.0);
   glPopMatrix();

   glPushMatrix();
     glTranslatef(-10, -10, 0);
//     glRotatef(90, 0, 1, 0);
     glMultMatrixf(Mz);
     glutWireTeapot(3.0);
   glPopMatrix();

   glPushMatrix();
   glColor3f(1.0, 1.0, 0.0);
     glBegin(GL_LINES);
       glVertex2f(-4, 15); glVertex2f(-4, -15);
       glVertex2f(-15, 5); glVertex2f(-4, 5);
       glVertex2f(-15, -5); glVertex2f(-4, -5);
     glEnd();
     glTranslatef(5, 0, 0);
     glColor3f(1.0, 0.0, 0.0);
     glutWireTeapot(5.0);
   glPopMatrix();

   glutSwapBuffers();
}

void myReshape(int w, int h)
{
   glViewport (0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0, 15.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void Key(unsigned char key, int a, int b)
{
    switch (key) {
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
  glutInitWindowPosition(100, 100);
  glutCreateWindow("My OpenGL Program");
  myInit();
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
  glutKeyboardFunc(Key);
  glutMainLoop();
  return(0);
}
