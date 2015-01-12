
#include <stdio.h>
#include <stdlib.h>     /* For "exit" prototype */
#include <GL/glut.h>    /* Header File For The GLUT Library */

/* ASCII code for the escape key. */
#define ESCAPE 27

GLuint	textures;

/* Image type - contains height, width, and data */
struct Image {
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
};
typedef struct Image Image;

#include "BMPloader.c"                      /* include the BMP loader code */

GLvoid LoadTexture(GLvoid)
{	
  Image *TextureImage;
    
    TextureImage = (Image *) malloc(sizeof(Image));
    if (TextureImage == NULL) {
        printf("Error allocating space for image");
        exit(1);
    }
    if (!ImageLoad("globo.bmp", TextureImage)) {
        exit(1);
    }  
      
    /*  2d texture, level of detail 0 (normal), 3 components (red, green, blue),            */
    /*  x size from image, y size from image,                                              */    
    /*  border 0 (normal), rgb color data, unsigned byte data, and finally the data itself. */ 

    glBindTexture(GL_TEXTURE_2D, textures);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 TextureImage->sizeX, TextureImage->sizeY,
                 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST); /*  cheap scaling when image bigger than texture */    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); /*  cheap scaling when image smalled than texture*/

    free( TextureImage->data);
    free( TextureImage );
}

/* Simple window transformation routine */
GLvoid Redisplay(int w, int h)
{
  glViewport(0, 0, w, h);              /* Set the viewport */
  glMatrixMode(GL_PROJECTION);                  /* Select the projection matrix */
  glLoadIdentity();				/* Reset The Projection Matrix */
  glOrtho(-10, 10,-10, 10, -10, 10);
  glMatrixMode(GL_MODELVIEW);                   /* Switch back to the modelview matrix */
  glLoadIdentity();				/* Reset The Projection Matrix */
}

/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void InitGL()	
{
  glClearColor(0.0, 0.0, 0.0, 0.0);		/* This Will Clear The Background Color To Black */
  LoadTexture();
  glEnable(GL_TEXTURE_2D);                      /*  Enable texture mapping. */
  glCullFace(GL_FRONT);
  glEnable(GL_CULL_FACE);
}

/* The main drawing function
   In here we put all the OpenGL and calls to routines which manipulate
   the OpenGL state and environment.
   This is the function which will be called when a "redisplay" is requested.
*/

void DrawGlobe()
{
  GLUquadricObj *qobj; 		/* used in drawscene */
  qobj = gluNewQuadric();  	    /* this will be used in drawScene */
  gluQuadricTexture(qobj, GL_TRUE);
  gluSphere(qobj, 5, 20, 20); // size, slices, stacks
  gluDeleteQuadric(qobj);
}


void DrawCube()
{
  GLUquadricObj *qobj; 		/* used in drawscene */
  qobj = gluNewQuadric();  	    /* this will be used in drawScene */
  gluQuadricTexture(qobj, GL_TRUE);
  glTranslatef(0, 0, -2.5);
  gluCylinder(qobj, 0, 5, 0, 4, 20);  // top
  gluCylinder(qobj, 5, 5, 5, 4, 20);  // lateral
  glTranslatef(0, 0, 5);
  gluCylinder(qobj, 5, 0, 0, 4, 20);  // bottom
  gluDeleteQuadric(qobj);
}

void DrawVase()
{
  GLUquadricObj *qobj; 		/* used in drawscene */
  qobj = gluNewQuadric();  	    /* this will be used in drawScene */
  gluQuadricTexture(qobj, GL_TRUE);
  glTranslatef(0, 0, -5);
  gluCylinder(qobj, 3, 2, 2, 15, 2);  // parte superior
  glTranslatef(0, 0, 2);
  gluCylinder(qobj, 2, 4, 4, 15, 2);  // parte do meio
  glTranslatef(0, 0, 4);
  gluCylinder(qobj, 4, 2, 4, 15, 2);  // parte inferior
  glTranslatef(0, 0, 4);
  gluCylinder(qobj, 2, 0, 0, 15, 2);  // tampa inferior
  gluDeleteQuadric(qobj);
}

GLvoid DrawGLScene()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	/* Clear The Screen And The Depth Buffer */
  glPushMatrix();
    glRotatef(90, 1.0, 0, 0);
    glutSolidTeapot(5.0);
//    DrawGlobe();
//    DrawVase();
//    DrawCube();
  glPopMatrix();
  glutSwapBuffers();
}

/*  The function called whenever a "normal" key is pressed. */
void NormalKey(GLubyte key, GLint x, GLint y) 
{
    switch ( key )    { 
     case ESCAPE : exit(0);	/* Very dirty exit */                  
        break;				/* Do we need this??? */
     case 'x': glRotatef(15, 1.0, 0.0, 0.0); break;
     case 'y': glRotatef(15, 0.0, 1.0, 0.0); break;
     case 'z': glRotatef(15, 0.0, 0.0, 1.0); break;
     default: break;
    }
    glutPostRedisplay();
}

/*************************** Main ***************************************************************/
int main(int argc, char **argv) 
{  
/* Initialisation and window creation */
  glutInit(&argc, argv);               /* Initialize GLUT state. */
  glutInitDisplayMode(GLUT_RGBA |      /* RGB and Alpha */
                      GLUT_DOUBLE |     /* Single buffer */
                      GLUT_DEPTH);     /* Z buffer (depth) */
  glutInitWindowSize(400,400);         /* set initial window size. */
  glutInitWindowPosition(0,0);         /* upper left corner of the screen. */
  glutCreateWindow("Globo Terrestre");     /* Open a window with a title. */ 
  InitGL();                     /* Initialize our window. */
/* Now register the various callback functions */
  glutDisplayFunc(DrawGLScene);        /* Function to do all our OpenGL drawing. */
  glutReshapeFunc(Redisplay);
  glutKeyboardFunc(NormalKey);         /*Normal key is pressed */
/* Now drop into the event loop from which we never return */
  glutMainLoop();                      /* Start Event Processing Engine. */  
  return 0;
}
