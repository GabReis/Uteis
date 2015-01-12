/***************************************************************************|
|**                          Super Penguin Bros.                          **|
|**                               main.cpp                                **|
|***************************************************************************|
|***************************************************************************|
|** This file was written by Kyle Gancarz (tommacco) with some code derived |
| from the tutorials at http://nehe.gamedev.net.  Use this code freely,as   |
| some of it was available to me freely.                                  **|
|***************************************************************************/

#include <GL/glut.h>
#include <stdio.h>
#include "loadimages.cpp"
#include "display.cpp"




void init()
{
	Lists();
	LoadGLTextures();
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
	glClearDepth(1.0f);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glLoadIdentity();
}




int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutGameModeString("800x600:16");
	glutEnterGameMode();
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}


/************************************************************************
TODO:

1)  Jump
2)  Collision Detection
3)  Animation
4)  Enemies/AI
5)  Level data stored in separate file
6)  Level change
7)  Score/Other data
8)  Sound
9)  OpenSource
10) Game play enhancement (active tubes, crazy stuff, et cetera)
*************************************************************************/
