
#include <math.h>
#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <string.h>
#include <stdlib.h>


float ratio;
int font=(int)GLUT_STROKE_ROMAN;
unsigned int b=0;
int ctrl=1;

void changeSize(int w, int h)
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0) h = 1;
	ratio = 1.0f * w / h;
	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);
	// Set the clipping volume
	gluPerspective(45,ratio,1,10000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void renderStrokeCharacter(float x, float y, float z, void *font,char *string)
{
  char *c;
  glPushMatrix();
  glTranslatef(x, y, z);
  if (b==0 || b==255) ctrl=-ctrl;
  if (ctrl==1) b--; else b++;
  glColor3ub(0, 0, b);
  for (c=string; *c != '\0'; c++) {
    glutStrokeCharacter(font, *c);
  }
  glPopMatrix();
}

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	renderStrokeCharacter(-460,0,-800,(void *)font,"Ionildo Sanches");
	glPopMatrix();
	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27) exit(0);
}

void initScene() {
	glEnable(GL_DEPTH_TEST);
	glLineWidth(5.0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,360);
	glutCreateWindow("SnowMen from 3D-Tech");
	initScene();
	glutKeyboardFunc(processNormalKeys);
	glutIgnoreKeyRepeat(1);
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutMainLoop();
	return(0);
}

