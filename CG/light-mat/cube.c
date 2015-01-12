/* Includes requeridos */
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h> 
#include <GL/glut.h>

GLfloat light_diffuse[] = {1.0, 0.0, 0.0, 1.0};  /* Red diffuse light. */
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};  /* Infinite light location. */

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glutSolidCube(2);
  glutSwapBuffers();
}

void
init(void)
{
  /* Enable a single OpenGL light. */
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);
  /* Use depth buffering for hidden surface elimination. */
  glEnable(GL_DEPTH_TEST);
  /* Setup the view of the cube. */
  glMatrixMode(GL_PROJECTION);
  gluPerspective( /* field of view in degree */ 60.0,
    /* aspect ratio */ 1.0,
    /* Z near */ 1.0, /* Z far */ 100.0);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(0.0, 0.0, 5.0,  /* eye is at (0,0,5) */
    0.0, 0.0, 0.0,      /* center is at (0,0,0) */
    0, 1.0, 0);      /* up is in positive Y direction */

  /* Adjust cube position to be asthetic angle. */
  glRotatef(45, 1.0, 0.0, 1.0);
}

void Key(unsigned char key, int x, int y)
{
    switch (key) {
      case 27: exit(1); break;   /* Esc finaliza o programa */
      default: break;
    }
}

int main(int argc, char** argv) 
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutCreateWindow("red 3D lighted cube");
  glutDisplayFunc(display);
  glutKeyboardFunc(Key);
  init();
  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}
