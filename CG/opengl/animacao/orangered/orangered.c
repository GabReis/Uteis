#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592654

static GLfloat xpnn ;		
static GLfloat zpnn ;
static GLfloat xrnn ;
static GLfloat zrnn ;
static GLfloat vitinv ;
int vit ;
static GLuint texName[2];	 /*Creation d'un tableau de deux gluint*/
int cont1 = 0;
int cont2 = 0;
int aleat;
int movecam,zoomcam;
int curx, cury, width, height;
float radius,phi,theta;

GLfloat mat_specular[] = {0.2,0.2,0.2,1.0};			/*Paramètisation du matériau*/
GLfloat mat_ambient[] = {0.4,0.5,0.2,1.0};
GLfloat mat_diffuse[] = {0.9,0.5,0.2,1.0};
GLfloat mat_shininess[] = {5.0};
GLfloat mat_specular2[] = {0.1,0.1,0.1,1.0};		/*Paramètisation du matériau 2 */
GLfloat mat_ambient2[] = {1.0,1.0,1.0,1.0};
GLfloat mat_diffuse2[] = {0.1,0.1,0.1,1.0};
GLfloat mat_shininess2[] = {1.0};

#define TEXTURE_WIDTH  256				/* Largeur de la texture en pixel*/
#define TEXTURE_HEIGHT 256				/* Hauteur de la texture en pixel*/

#define TEXTURE_NAME1   "panel.bmp"	/* Fichier dans lequel se trouve la texture 1 */
#define TEXTURE_NAME2   "panel.bmp"	/* Fichier dans lequel se trouve la texture 2 */

unsigned char texture1[TEXTURE_WIDTH*TEXTURE_HEIGHT*4];	/* La texture elle-même */
unsigned char texture2[TEXTURE_WIDTH*TEXTURE_HEIGHT*4];	/* La texture elle-même */

void load_texture(char* name, unsigned char* texture)
{
	int i,j;
	unsigned char header[54];
	FILE *ftexture;
	if (!(ftexture = fopen(name,"rb"))) {
		printf("Error opening texture file...");
		exit(-1);
	}
	fread(header,54,1,ftexture);
	for (j=0; j<TEXTURE_HEIGHT; j++) {
		for (i=0; i<TEXTURE_WIDTH; i++) {
			texture[i*4+j*TEXTURE_WIDTH*4+3] = 255;
			fread(&texture[i*4+j*TEXTURE_WIDTH*4+2],1,1,ftexture);
			fread(&texture[i*4+j*TEXTURE_WIDTH*4+1],1,1,ftexture);
			fread(&texture[i*4+j*TEXTURE_WIDTH*4+0],1,1,ftexture);
		}
	}
	fclose(ftexture);
}

void init (void)					/* Initialisation */
{	
		GLfloat light0_ambient[] = {0.2,0.2,0.2,1.0};	/* Initialisation des paramètres de luminosité*/
		GLfloat light0_specular[] = {1.0,1.0,1.0,1.0};
		GLfloat light0_position[] = {10.0,11.0,1.0,0.0};	/*Positionnement de l'éclairage*/
		float posx;
		float posz;
		/* Message d'acceuil*/
		printf ("Le programme suivant represente un echiquier sur lequel sont\n");
			printf ("places un pion et un roi. Le bouton gauche de la souris permet de changer\n");
			printf ("l angle de vue et le bouton droit de zoomer sur l echiquier.\n");
		printf ("La touche p du clavier permet au roi de prendre le pion.\n");
			printf ("La touche b fait bouger le pion de manière aleatoire \n");
		/*Initialisation de la vitesse d'avancement*/
		printf ("Vitesse du pion (10 : rapide - 100 : tres lent) = ");
		scanf ("%i",&vit);
		printf ("Vitesse %i\n",vit);
		vitinv = (GLfloat)1/vit;
		/* Initilisation des position du pion et du roi*/
		printf ("position du pion (0-7)(x) = ");
		scanf ("%f",&posx);
		printf ("position du pion (0-7)(z) = ");
		scanf ("%f",&posz);
		xpnn= (posx*5.0)+4.5;
    	zpnn= (posz*5.0)+4.5;
		printf ("position du roi (0-7)(x) = ");
		scanf ("%f",&posx);
		printf ("position du roi (0-7)(z) = ");
		scanf ("%f",&posz);
		xrnn= (posx*5.0)+4.5;
		zrnn= (posz*5.0)+4.5;	
		/*Initialisation de la position de la caméra*/
		movecam = 0;						
		zoomcam = 0;
		theta = 45.0;
		phi = -30.0;
		radius = 100.0;
	load_texture(TEXTURE_NAME1,texture1);
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	glGenTextures(2,texName);
	glBindTexture(GL_TEXTURE_2D,texName[0]);
	glTexImage2D(GL_TEXTURE_2D,0,4,TEXTURE_WIDTH,TEXTURE_HEIGHT,0,GL_RGBA,GL_UNSIGNED_BYTE,texture1);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	load_texture(TEXTURE_NAME2,texture2);
	glBindTexture(GL_TEXTURE_2D,texName[1]);
	glTexImage2D(GL_TEXTURE_2D,0,4,TEXTURE_WIDTH,TEXTURE_HEIGHT,0,GL_RGBA,GL_UNSIGNED_BYTE,texture2);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

  	glEnable(GL_DEPTH_TEST);
	glShadeModel (GL_SMOOTH);
	glLightfv (GL_LIGHT0,GL_AMBIENT,light0_ambient);
	glLightfv (GL_LIGHT0,GL_DIFFUSE,light0_specular);
	glLightfv (GL_LIGHT0,GL_POSITION,light0_position);
	glEnable (GL_LIGHT0);
	glEnable (GL_LIGHTING);
}

void makeSquare ()							/*  Fonction de construction de carre */ 
									/*  de 5 sur 5 centrés en 4.5,4.5	*/
{												
glBegin (GL_QUADS);
	glTexCoord2f( 0.0f, 0.0f);				
	glVertex3f( 2.0f, 4.20f,2.0f);			
	glTexCoord2f( 0.0f,  1.0f);				
	glVertex3f( 7.0f, 4.20f, 2.0f);
	glTexCoord2f( 1.0f,  1.0f);				
	glVertex3f( 7.0f, 4.20f, 7.0f);
	glTexCoord2f( 1.0f,  0.0f);			
    glVertex3f( 2.0f, 4.20f, 7.0f);
glEnd();
}

void makeChessBoard ()						/*Fonction de positionnement des */
{											/* petits carrés */											 
int j = 0;
int k = 0;
do
	{
	j=0;
	do
	{
		glPushMatrix ();
		glTranslated ((10.0)*j,0.0,(5.0)*k);
		makeSquare ();
		glPopMatrix ();
		glPushMatrix ();
		glTranslated ((5.0+(10.0*j)),0.0,(5.0)*(k+1));
		makeSquare ();
		glPopMatrix ();
		j++;
	}while (j!=4);
	k=k+2;
} while (k!=8);
}

void makeEchiquier ()							/* Fonction de construction de l'échiquier*/
{
	glEnable(GL_TEXTURE_2D);					/* Mise en fonction des textures */	
	glBindTexture(GL_TEXTURE_2D, texName[0]);   /* Attribution de la texture 1 au plateau*/	
									/* de fond */
   glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f( 2.0f, 4.10f, 2.0f);			
	glTexCoord2f(0.0, 1.0);
	glVertex3f(42.0f, 4.10f, 2.0f);			
	glTexCoord2f(1.0, 1.0);
	glVertex3f(42.0f, 4.10f,42.0f);			
	glTexCoord2f(1.0,0.0);
	glVertex3f( 2.0f, 4.10f,42.0f);			
   glEnd ();

	glBindTexture(GL_TEXTURE_2D, texName[1]);	/* Attribution de la texture 2 aux */	
	makeChessBoard ();/* petits carrés */
glDisable (GL_TEXTURE_2D);						/* Mise a l'arret des textures */
}

void makePion ()								/* Constuction du pion */
{
  glPushMatrix ();
	glColor3d(1.0,0.0,0.0);
	glTranslated(xpnn,3.0,zpnn);
	glRotated(-90,1.0,0.0,0.0);
	glutSolidCone(1.5,4.0,15,15);
	glPopMatrix();
	glPushMatrix ();
	glColor3d(1.0,0.0,0.0);
	glTranslated(xpnn,6.2,zpnn);
	glutSolidSphere(0.7,15,15);
	glPopMatrix();
	glPushMatrix ();
	glColor3d(1.0,0.0,0.0);
	glTranslated(xpnn,3.4,zpnn);
	glRotated(-90,1.0,0.0,0.0);
	glutSolidTorus(0.6,0.8,15,15);
	glPopMatrix();
}

void makeRoi ()									/* Constuction du roi*/
{
	glPushMatrix ();
	glColor3d(1.0,0.0,0.0);
	glTranslated(xrnn,4.0,zrnn);
	glRotated(-90,1.0,0.0,0.0);
	glutSolidCone(2.0,5.0,15,15);
	glPopMatrix();
	glPushMatrix ();
	glTranslated(xrnn,9.0,zrnn);
	glRotated(90,1.0,0.0,0.0);
	glutSolidCone(1.5,2.0,15,15);
	glPopMatrix();
	glPushMatrix ();
	glTranslated(xrnn,10.0,zrnn);
	glutSolidSphere(0.7,30,16);
	glPopMatrix();
	glPushMatrix ();
	glTranslated(xrnn,10,zrnn);
	glScalef(0.5,3.0,0.5);			
	glutSolidCube(1.0);
	glPopMatrix();
	glPushMatrix ();
	glTranslated(xrnn,11.0,zrnn);
	glScalef(2.0,0.3,0.3);			
	glutSolidCube(1.0);
	glPopMatrix();
	glPushMatrix ();
	glTranslated(xrnn,9.0,zrnn);
	glRotated (-90,1.0,0.0,0.0);
	glutSolidCone (1.5,0.5,15,15);
	glPopMatrix();
}

void display (void)						/* Fonction d'affichage*/
{
	glClearColor (0.0,0.0,0.0,0.0);	
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	/* Positionnement camera */
	gluLookAt(radius*sin(phi)*sin(theta), radius*cos(phi), radius*sin(phi)*cos(theta), 0.0, 0.0, 0.0, -cos(phi)*sin(theta), sin(phi), -cos(phi)*cos(theta));
	/* Constuction de la base de l'échiquier*/
	glPushMatrix ();					
	glTranslated(22.0,2.5,22.0);
	glScalef(44.0,3.0,44.0);				
	glutSolidCube(1.0);
	glPopMatrix();
	/* Affectation des paramètres de visualisation du roi*/	
	glMaterialfv (GL_FRONT,GL_SHININESS,mat_shininess);
	glMaterialfv (GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv (GL_FRONT,GL_SPECULAR,mat_ambient);
	glMaterialfv (GL_FRONT,GL_SPECULAR,mat_diffuse);
	makeRoi ();
	/* Affectation des paramètres de visualisation du pion*/
	glMaterialfv (GL_FRONT,GL_SHININESS,mat_shininess2);
	glMaterialfv (GL_FRONT,GL_SPECULAR,mat_specular2);
	glMaterialfv (GL_FRONT,GL_SPECULAR,mat_ambient2);
	glMaterialfv (GL_FRONT,GL_SPECULAR,mat_diffuse2);
	makePion ();
	/* Consruction de l'echiquier*/
	makeEchiquier ();
	glFlush();
	glutSwapBuffers ();
}

void motion(int x, int y)				/* Fonction de déplacement de la caméra*/
{
	if (movecam) {
		theta -= (float)(x - curx) * 2.0 * PI / (float)width;
		phi   -= (float)(y - cury) * PI / (float)height;
		if (theta < -2*PI) theta += 2*PI;
		if (theta >  2*PI) theta -= 2*PI;
		if (phi >  PI) phi = PI;
		if (phi < 0.0) phi = 0.0;
	}
	if (zoomcam) {
		radius += (y - cury)*0.1;
		if (radius < 0.0) radius = 0.0;
		if (radius > 100.0) radius = 100.0;
	}
	curx = x;
	cury = y;
	glutPostRedisplay();
}

void reshape (int w, int h)				/* Fonction de redimentionnent*/
{
	glViewport (0, 0, w, h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glFrustum (-2.0,2.0,-1.0,2.0,3.5,120.0);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
}

void stepmoveyourbody (GLdouble a,GLdouble b)	/* Fonction pemettant le mouvement incrémental des piéces*/
{
	GLdouble xp = (xpnn - 4.5) / 5.0;
	GLdouble zp = (zpnn - 4.5) / 5.0;
	GLdouble xr = (xrnn - 4.5) / 5.0;
	GLdouble zr = (zrnn - 4.5) / 5.0;
	GLdouble xrb = xr;
	GLdouble zrb = zr; 
	xrb = xr + a;
	zrb = zr + b;	
	cont1 ++;
	if (cont1==vit)
	{
		glutIdleFunc (NULL);
	}
    xrnn= (xrb*5.0)+4.5;
	zrnn= (zrb*5.0)+4.5;
	glutPostRedisplay();
}

/* Fonctions de déplacement dans les différentes directions*/
void stepmoveyourbody0 (void)
{
	stepmoveyourbody (vitinv,vitinv);
}

void stepmoveyourbody1 (void)
{
	stepmoveyourbody (0.0,vitinv);
}

void stepmoveyourbody2 (void)
{
	stepmoveyourbody (-vitinv,vitinv);
}

void stepmoveyourbody3 (void)
{
	stepmoveyourbody (-vitinv,0.0);
}

void stepmoveyourbody4 (void)
{
	stepmoveyourbody (-vitinv,-vitinv);
}

void stepmoveyourbody5 (void)
{
	stepmoveyourbody (0.0,-vitinv);
}

void stepmoveyourbody6 (void)
{
	stepmoveyourbody (vitinv,-vitinv);
}

void stepmoveyourbody7 (void)
{
	stepmoveyourbody (vitinv,0.0);
}

void stepchopelepion (void)					/* Fonction de capture du pion*/
{
	GLdouble xp = (xpnn - 4.5) / 5.0;
	GLdouble zp = (zpnn - 4.5) / 5.0;
	GLdouble xr = (xrnn - 4.5) / 5.0;
	GLdouble zr = (zrnn - 4.5) / 5.0;
	GLdouble deltax,deltaz;
	if (xp >= xr) 
		 xr=(xr+vitinv);
	else xr=(xr-vitinv);
	if (zp >= zr) 
			zr=(zr+vitinv);
	else 	zr=(zr-vitinv);
	deltax = xp-xr;
	deltaz = zp-zr;
	if (deltax < 0) deltax = deltax * -1;
	if (deltaz < 0) deltaz = deltaz * -1;
	if (deltax <=0.05 && deltaz<=0.05)
		glutIdleFunc(NULL);
	xrnn = (xr*5.0)+4.5;
	zrnn = (zr*5.0)+4.5;
	glutPostRedisplay();
}

void mouse (int button, int state, int x,int y)		/* Fonction de définition des fonctions*/
{													/* associées aux boutons de la souris*/	
	if (state == GLUT_DOWN) {
    switch (button) {
    case GLUT_LEFT_BUTTON:
		movecam = 1;
		motion(curx = x, cury = y);
		break;

    case GLUT_RIGHT_BUTTON:
		zoomcam = 1;
		motion(curx = x, cury = y);
		break;
    }

  } else if (state == GLUT_UP) {

    switch (button) {
    case GLUT_LEFT_BUTTON:
      movecam = 0;
      break;

    case GLUT_RIGHT_BUTTON:
      zoomcam = 0;
      break;
    }
  }
}

void keyboard(unsigned char key, int x, int y)		/* Fonction de définition des fonctions*/
{													/* associée aux touches du clavier*/
    GLdouble xp = (xpnn - 4.5) / 5.0;
				GLdouble zp = (zpnn - 4.5) / 5.0;
				GLdouble xr = (xrnn - 4.5) / 5.0;
				GLdouble zr = (zrnn - 4.5) / 5.0;
				GLdouble deltax,deltaz;
				GLdouble xrb = xr;
				GLdouble zrb = zr; 

switch (key){
		case 27:
			exit(0);
			break;
		case 112 :
			cont2 = 0;
			glutIdleFunc(stepchopelepion);
			break;
		case 98 :
				cont1 = 0;
				do {								/* Génération d'une direction aléatoire */ 
												/* et vérifiction que le mouvement dans cette*/
				aleat = rand()%8;					/* direction est permis*/
				switch (aleat) {
				case 0 : 
				xrb = xr + 1.0;
				zrb = zr + 1.0;
				break;

				case 1 : 
				xrb = xr;
				zrb = zr + 1.0;
    			 break;

				case 2 : 
				xrb = xr - 1.0;
				zrb = zr + 1.0;
				break;

				case 3 : 
				xrb = xr - 1.0;
				zrb = zr;
				break;

				case 4 : 
				xrb = xr - 1.0;
				zrb = zr - 1.0;
				break;

				case 5 : 
				xrb = xr;
				zrb = zr - 1.0;
				break;

				case 6 : 
				xrb = xr + 1.0;
				zrb = zr - 1.0;
				break;

				case 7 : 
				xrb = xr + 1.0;
				zrb = zr;
				break;
				}

				deltax = xrb-xp;
				deltaz = zrb-zp;
				if (deltax < 0) deltax = deltax * -1;
				if (deltaz < 0) deltaz = deltaz * -1;
				} while ((xrb < 0.0 || zrb < 0.0 || xrb > 7.0 || zrb > 7.0)
					|| (deltax <=0.05 && deltaz<=0.05));

				switch (aleat) {						/* Déplacement proprement dit*/
					case 0 : 
						glutIdleFunc(stepmoveyourbody0);
					break;

					case 1 : 
						glutIdleFunc(stepmoveyourbody1);
					break;

				    case 2 : 
						glutIdleFunc(stepmoveyourbody2);
					break;

					case 3 : 
						glutIdleFunc(stepmoveyourbody3);
					break;

					case 4 : 
						glutIdleFunc(stepmoveyourbody4);
					break;

					case 5 : 
						glutIdleFunc(stepmoveyourbody5);
					break;

					case 6 : 
						glutIdleFunc(stepmoveyourbody6);
					break;

					case 7 : 
						glutIdleFunc(stepmoveyourbody7);
						break;
				}
break;
}
}				

int main (int argc,char** argv)							/* Boucle principale*/
{
	glutInit (&argc,argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Orangered");
	init ();
	glutDisplayFunc (display);
	glutReshapeFunc (reshape);
	glutMouseFunc (mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

