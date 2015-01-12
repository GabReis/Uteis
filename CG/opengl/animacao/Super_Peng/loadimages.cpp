/***************************************************************************|
|**                          Super Penguin Bros.                          **|
|**                            loadimages.cpp                             **|
|***************************************************************************|
|***************************************************************************|
|** This file was written by Kyle Gancarz (tommacco) with some code derived |
| from the tutorials at http://nehe.gamedev.net.  Use this code freely,as   |
| some of it was available to me freely.                                  **|
|***************************************************************************/


#include <GL/glut.h>
#include <stdio.h>
#include "BMPLoader.cpp"


const int numTextures=5;
GLuint texture[numTextures];



void LoadGLTextures(void)
{
  char* filenames[] = { "Data/penguin.bmp", "Data/floor.bmp", 
						"Data/herring.bmp", "Data/tube.bmp",
						"Data/tubelong.bmp" };

  for (int i=0; i<numTextures; i++)
  {
    loadOpenGL2DTextureBMP(filenames[i], &texture[i]);
  }
}
