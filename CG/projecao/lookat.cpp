/* 
   glLookAt and glFrustum Example - Redbook
*/ 

/* Includes requeridos */
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h> 
#include <GL/glut.h>

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);
   glLoadIdentity();          /* clear the matrix */
   /* viewing transformation  */
   gluLookAt(0.0, 0.0, 5.0,    /* eye is at (0,0,5) */
	         0.0, 0.0, 0.0,    /* center is at (0,0,0) */
	         0.0, 1.0, 0.0);   /* up is Y direction */
   glutWireCube(2.0);
   glFlush();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 10.0);
//   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.5, 10.0);
   glMatrixMode (GL_MODELVIEW);
}

void Key(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:           /* Esc will quit */
        exit(1); break;
    default: break;
    }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Projection Example");
   init ();
   glutKeyboardFunc(Key);
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}

