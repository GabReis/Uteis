#ifdef WIN32
#include <windows.h>
#endif

#ifndef M_PI
#define M_PI        3.14159265358979323846
#endif

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#include "readtexture.c"
#define TEXTURE_SIZE 128


GLfloat light0_position[] = {0.0, 0.0, 0.0, 1.0};

GLfloat light0_off[] = {0.0, 0.0, 0.0, 1.0};

GLfloat light0_ambient[] = {0.1, 0.1, 0.1, 1.0};

GLfloat light0_specular[] = {0.1, 0.1, 0.1, 1.0};

GLfloat light0_diffuse[] = {0.1, 0.1, 0.1, 1.0};

GLfloat light1_position[] = {0.0, 0.0, 0.0, 1.0};

GLfloat light1_off[] = {0.0, 0.0, 0.0, 1.0};

GLfloat light1_ambient[] = {0.0, 0.0, 0.0, 1.0};

GLfloat light1_specular[] = {0.5, 0.5, 0.5, 1.0};

GLfloat light1_diffuse[] = {0.7, 0.6, 0.6, 1.0};



GLfloat material_diffuse[] = {0.7, 1.0, 0.7, 0.0};

GLfloat background_ambient[] = {0.0, 0.0, 0.0, 1.0};

GLfloat shininess = 20.0;



void init_gl_settings(void);

void display(void);

void idle(void);

void keyboard(unsigned char, int, int);

void draw_square(GLfloat);





GLuint texid[1];



GLfloat angle1, angle2, angle3, angle4, angle5, angle6, angle7;



int main(int argc, char** argv){

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(1024, 768);

	glutInitWindowPosition(0, 0);

	glutCreateWindow(argv[0]);

	init_gl_settings();

	angle1=angle4=0.0;

	glutDisplayFunc(display);

	glutIdleFunc(idle);

	glutKeyboardFunc(keyboard);

	glutFullScreen();

	glutMainLoop();

	return 0;

}



void init_gl_settings(void){

    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(45.0, 4.0/3.0, 2.0, 20.0);

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);

    glEnable(GL_NORMALIZE);

    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);

    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);

    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);

    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);

    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);

    glEnable(GL_LIGHT1);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, texid);

    SetupTexture("texture1.ppm", texid[0]);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    glEnable(GL_TEXTURE_2D);

}



void display(void){

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	glTranslatef(0.0, 0.0, -6.0);

	glPushMatrix();

		glRotatef(angle4, 0.0, 1.0, 0.0);

		glRotatef(angle5, 1.0, 0.0, 0.0);

		glTranslatef(0.0, 0.0, 1.8);

		glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

	glPopMatrix();

	glPushMatrix();

		glRotatef(15.0, 1.0, 0.0, 0.0);

		glRotatef(-40.0, 0.0, 1.0, 0.0);

		glRotatef(angle7, 0.0, 1.0, 0.0);

		glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);

		glutSolidCube(1.2);

	glPopMatrix();

	glEnable(GL_BLEND);

	glBlendFunc(GL_ONE, GL_ONE);

	glDisable(GL_LIGHTING);

	glPushMatrix();

		glRotatef(angle4, 0.0, 1.0, 0.0);

		glRotatef(angle5, 1.0, 0.0, 0.0);

		glTranslatef(0.0, 0.0, 1.8);

		glRotatef(-angle5, 1.0, 0.0, 0.0);

		glRotatef(-angle4, 0.0, 1.0, 0.0);

		glRotatef(angle6, 0.0, 0.0, 1.0);

		glBindTexture(GL_TEXTURE_2D, texid[0]);

		glEnable(GL_TEXTURE_2D);

		draw_square(1.0);

	glPopMatrix();



	glEnable(GL_LIGHTING);

	glDisable(GL_BLEND);

	glDisable(GL_TEXTURE_2D);

	glutSwapBuffers();

}



void draw_square(GLfloat l){

	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 0.0);

	glVertex3f(-0.5*l, 0.5*l, 0.0);

	glTexCoord2f(0.0, 1.0);

	glVertex3f(-0.5*l, -0.5*l, 0.0);

	glTexCoord2f(1.0, 1.0);

	glVertex3f(0.5*l, -0.5*l, 0.0);

	glTexCoord2f(1.0, 0.0);

	glVertex3f(0.5*l, 0.5*l, 0.0);

	glEnd();

}



void idle(void){

	angle7 += .02;

	angle1+=5;

	angle2=90.0*sin(0.1*M_PI*angle1/180.0);

	angle3=180.0*sin(M_PI*angle1/177.0);

	angle4-=3;

	angle5=90.0*sin(0.1*M_PI*angle4/180.0);

	angle6=180.0*sin(M_PI*angle4/177.0);

	glutPostRedisplay();

}



void keyboard(unsigned char c, int x, int y){

	static int move=1;

	switch(c){

	case 'q':

		exit(0);

	case ' ':

		move=move?0:1;

		if(move == 1) glutIdleFunc(NULL);

		else glutIdleFunc(idle);

		break;

	default:

		break;

	}

}



