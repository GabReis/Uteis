/***************************************************************************|
|**                          Super Penguin Bros.                          **|
|**                              display.cpp                              **|
|***************************************************************************|
|***************************************************************************|
|** This file was written by Kyle Gancarz (tommacco) with some code derived |
| from the tutorials at http://nehe.gamedev.net.  Use this code freely,as   |
| some of it was available to me freely.                                  **|
|***************************************************************************/


#include <GL/glut.h>
#include <windows.h>
//#include <iostream.h>

GLfloat x;
GLfloat xpos=0.0;
GLuint penguin;

//create box data storage for collision detection
float box[1][4];


//create tube data storage
float tube[1][3];



void display(void)
{



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -30.0f);
	glColor3f(1.0f, 1.0f, 1.0f);




//draw ground

	glBindTexture(GL_TEXTURE_2D, texture[1]);
	for(x=0.0; x<=40.0; x+=2.0)
	{
	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(xpos + x, -11.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(xpos + x, -13.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(xpos + x - 2.0, -13.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(xpos + x - 2.0, -11.0f, 0.0f);		
	glEnd();
	}
	for(x+=2.0; x<=46.0; x+=2.0)
	{
	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(xpos + x, -11.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(xpos + x, -13.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(xpos + x - 2.0, -13.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(xpos + x - 2.0, -11.0f, 0.0f);		
	glEnd();
	}
	for(x+=4.0; x<=70.0; x+=2.0)
	{
	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(xpos + x, -11.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(xpos + x, -13.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(xpos + x - 2.0, -13.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(xpos + x - 2.0, -11.0f, 0.0f);		
	glEnd();
	}

//draw box

	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(xpos + 24.0, -5.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(xpos + 24.0, -7.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(xpos + 22.0, -7.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(xpos + 22.0, -5.0f, 0.0f);
	glEnd();
	//box1 top
	box[1][4] = -5.0,-7.0,22.0,24.0;


//draw full tube
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(xpos + 12.0, -7.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(xpos + 12.0, -11.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(xpos + 8.0, -11.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(xpos + 8.0, -7.0f, 0.0f);
	glEnd();
	
	tube[1][1] = 8.0;
	tube[1][2] = 12.0;
	tube[1][3] = -7.0;

//drawpenguin
	glBindTexture(GL_TEXTURE_2D, texture[0]);
		glCallList(penguin);

	glutSwapBuffers();
}



void Lists()
{
	penguin=glGenLists(1);
	
//penguin

	glNewList(penguin,GL_COMPILE);
	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -9.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -11.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -11.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -9.0f, 0.0f);
	glEnd();
	glEndList();

}


bool collision(GLfloat position, int thedirection)
{
	switch(thedirection)
	{
	case 1: //moving right
		if(position==-(tube[1][1]))
			return true;
	break;

	case 2:
		if(position==-(tube[1][2]))
			return true;
	break;

	default:
		break;

	}
	return false;

}



void keyboard(unsigned char key, int x, int y)
{
	bool contact=false;

	switch(key)
	{
	case 27:
		glutLeaveGameMode(); 
		exit(1);
		break;
	case 46:
		contact=collision(xpos, 1);
		if(!contact)
			xpos-=0.5;

		display();
	break;

	case 44:
		contact=collision(xpos, 2);
		if(!contact)
			xpos+=0.5;

		display();
		break;
	default:
		break;
	}
}


void reshape(int w, int h)
{
	if(h==0)
	{
		h=1;
	}

	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,(float)w/(float)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
