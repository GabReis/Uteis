#include <GL/glut.h>
#include <stdlib.h>

GLfloat mat_diffuse[4] = { 0.4, 0.4, 0.4, 1.0 };

/*  Initialize material property, light source, lighting model,
 *  and depth buffer.
 */
void init(void) 
{
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 0.0 };
   GLfloat light_position[] = { 1.0, 1.0, 0.0, 0.0 };
   GLfloat light_ambient[] = { 1.0, 1.0, 1.0, 0.0 };
   GLfloat light_specular[] = { 1.0, 1.0, 1.0, 0.0 };
   GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 0.0 };
         
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
   glEnable(GL_DEPTH_TEST);

   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialf(GL_FRONT, GL_SHININESS, 1.0);

   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
   glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);

   glColor4f(0.9, 0.9, 0.3, 1.0);
   glColorMaterial(GL_FRONT, GL_DIFFUSE);
   glEnable(GL_COLOR_MATERIAL);
}

void DrawVase()
{
  GLUquadricObj *qobj; 		/* used in drawscene */
  qobj = gluNewQuadric();  	    /* this will be used in drawScene */
  gluQuadricTexture(qobj, GL_TRUE);
  glPushMatrix();
      glRotatef(90, 1.0, 0.0, 0.0);
      glTranslatef(0, 0, -5);
      gluCylinder(qobj, 3, 2, 2, 20, 2);  // parte superior
      glTranslatef(0, 0, 2);
      gluCylinder(qobj, 2, 4, 4, 20, 2);  // parte do meio
      glTranslatef(0, 0, 4);
      gluCylinder(qobj, 4, 2, 4, 20, 2);  // parte inferior
      glTranslatef(0, 0, 4);
      gluCylinder(qobj, 2, 0, 0, 20, 2);  // tampa inferior
      gluDeleteQuadric(qobj);
  glPopMatrix();
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   DrawVase();
   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-10, 10, -10, 10, 10, -10);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN) {
            mat_diffuse[0] += 0.1;
            if (mat_diffuse[0] > 1.0)
               mat_diffuse[0] = 0.0;
            glColor4fv(mat_diffuse);
            glutPostRedisplay();
         }
         break;
      case GLUT_MIDDLE_BUTTON:
         if (state == GLUT_DOWN) {
            mat_diffuse[1] += 0.1;
            if (mat_diffuse[1] > 1.0)
               mat_diffuse[1] = 0.0;
            glColor4fv(mat_diffuse);
            glutPostRedisplay();
         }
         break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN) {
            mat_diffuse[2] += 0.1;
            if (mat_diffuse[2] > 1.0)
               mat_diffuse[2] = 0.0;
            glColor4fv(mat_diffuse);
            glutPostRedisplay();
         }
         break;
      default: break;
   }
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
     case 'x': glRotatef(15, 1.0, 0.0, 0.0); break;
     case 'y': glRotatef(15, 0.0, 1.0, 0.0); break;
     case 'z': glRotatef(15, 0.0, 0.0, 1.0); break;
     case 27: exit(0); break;
     default: break;
   }
   glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
