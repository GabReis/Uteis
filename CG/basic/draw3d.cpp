/* 
   MyOpenGl.c
   Cylinder and Cube Functions Example
   Ionildo Jose Sanches - 17/02/03
*/ 

/* Includes requeridos */
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h> 
#include <GL/glut.h>

void Draw3D()
{
  GLUquadricObj *qobj; 		/* used in drawscene */
  qobj = gluNewQuadric();  	    /* this will be used in drawScene */
  glColor3f(0.0, 0.5, 0.0);
  glTranslatef(0, 0, -5);
  glutSolidCube(5);
  glTranslatef(0, 0, 2.5);
  glColor3f(0.0, 0.3, 0.0);
  gluCylinder(qobj, 2, 2, 6, 15, 2);
  glTranslatef(0, 0, 6);
  gluCylinder(qobj, 2, 0, 0, 15, 2);
}

void DrawVase()
{
  GLUquadricObj *qobj; 		/* used in drawscene */
  qobj = gluNewQuadric();  	    /* this will be used in drawScene */

  glTranslatef(0, 0, -5);
  gluCylinder(qobj, 3, 2, 2, 15, 2);  // parte superior
  glTranslatef(0, 0, 2);
  gluCylinder(qobj, 2, 4, 4, 15, 2);  // parte do meio
  glTranslatef(0, 0, 4);
  gluCylinder(qobj, 4, 2, 4, 15, 2);  // parte inferior
  glTranslatef(0, 0, 4);
  gluCylinder(qobj, 2, 0, 0, 15, 2);  // tampa inferior
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(0.5, 0.5, 0.0);
  glPushMatrix();
    glRotatef(60, 1.0, 0, 0);
    glTranslatef(5, 0, 0);
    DrawVase();
    glTranslatef(-10, 0, 0);
    Draw3D();
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
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("3D GLUT Examples");
  myInit();
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
  glutKeyboardFunc(Key);
  glutMainLoop();
  return(0);
}
