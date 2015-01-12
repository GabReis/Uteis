/* Ionildo Jose Sanches */
/*  Computação Grafica  */

/* Includes required */
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

void DrawTable(void);
void DrawVase(void);
void DrawGoblet(void);

GLUquadricObj *qobj; 		/* used in drawscene */
int obj=0;   			/* Vase Selected */
float tx[3]={0,4,-3}, ty[3]={0,0,0}, tz[3]={6.3,0,2.5}; /* Initial Translate */
float grau[3]={0,0,0}, rx[3]={0,0,0}, ry[3]={0,0,0}, rz[3]={1,0,0};  /* Initial Rotation */
float sx[3]={0.6,0.6,0.6}, sy[3]={0.6,0.6,0.6}, sz[3]={0.6,0.6,0.6};  /* Initial Scale */
float ta[3]={1, 1, 1};    /* Initial Transparency */

/*  Clear the screen.  Set the current color to objects.
 *  Draw the table, vase and goblet. */

void DrawTable()
 {
// mesa
  glPushMatrix();
  gluLookAt(1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
  gluQuadricDrawStyle(qobj, GLU_FILL);
  glColor4f(0.65,0.16,0.16,ta[0]);    //Brown(RGB) = 165, 42, 42
  glTranslatef(tx[0],ty[0],tz[0]);
  glRotatef(grau[0],rx[0],ry[0],rz[0]);
  glScalef(sx[0], sy[0], sz[0]);
    gluCylinder(qobj, 15, 10, 0.2, 4, 1);    // base
  glPushMatrix();
    glTranslatef(-12.5,0,0.2);
    gluCylinder(qobj, 1.5, 1.5, 15, 4, 1);  // pé
  glPopMatrix();
  glPushMatrix();
    glTranslatef(12.5,0,0.2);
    gluCylinder(qobj, 1.5, 1.5, 15, 4, 1);  // pé
  glPopMatrix();
  glPushMatrix();
    glTranslatef(0,-12.5,0.2);
    gluCylinder(qobj, 1.5, 1.5, 15, 4, 1);  // pé
  glPopMatrix();
  glPushMatrix();
    glTranslatef(0,12.5,0.2);
    gluCylinder(qobj, 1.5, 1.5, 15, 4, 1);  // pé
  glPopMatrix();
 glPopMatrix();
}

void DrawVase()
{
// vaso
  glPushMatrix();
  gluLookAt(1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
  glColor4f(1.0,1.0,0.0,ta[1]);     //Yellow(RGB) = 255, 255, 0
  glTranslatef(tx[1],ty[1],tz[1]);
  glRotatef(grau[1],rx[1],ry[1],rz[1]);
  glScalef(sx[1], sy[1], sz[1]);
  gluCylinder(qobj,3,2,2,15,2);  // parte superior
  glTranslatef(0,0,2);
  gluCylinder(qobj,2,4,4,15,2);  // parte do meio
  glTranslatef(0,0,4);
  gluCylinder(qobj,4,2,4,15,2);  // parte inferior
  glTranslatef(0,0,4);
  gluCylinder(qobj,2,0,0,15,2);  // tampa inferior
 glPopMatrix();
}

void DrawGoblet()
{
// taça
 glPushMatrix();
  gluLookAt(1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
  glColor4f(0.0,0.0,1.0,ta[2]);      //Blue(RGB) = 0, 0, 255
  glTranslatef(tx[2], ty[2], tz[2]);
  glRotatef(grau[2],rx[2],ry[2],rz[2]);
  glScalef(sx[2], sy[2], sz[2]);
  gluCylinder(qobj, 1.5, 1 ,2,15,2);	 // copo
  glTranslatef(0,0,2);
  gluCylinder(qobj, 1, 0,0.1,15,2);      // base do copo
  glTranslatef(0,0,0.1);
  gluCylinder(qobj, 0.1, 0.2,2,5,2);     // haste superior
  glTranslatef(0,0,2);
  gluCylinder(qobj, 0.2, 0.1,2,5,2);     // haste inferior
  glTranslatef(0,0,2);
  gluCylinder(qobj, 0.1, 1.5,0.2,10,2);  // base da taça
 glPopMatrix();
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   DrawTable();   //Desenha a Mesa
   DrawVase();    //Desenha o Vaso
   DrawGoblet();  //Desenha a Taça
   glutSwapBuffers();
}

/* Initialize shading model */
void myInit(void)
{
      glShadeModel(GL_FLAT);
      glClearColor(0.0, 0.0, 0.0, 0.0);
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
/*  Called when the window is first opened and whenever 
 *  the window is reconfigured (moved or resized).  */

void myReshape(int w, int h)
{
  glViewport (0, 0, w, h);       /*  define the viewport */
  glMatrixMode(GL_PROJECTION);        /* clear the matrix */
  glLoadIdentity();   // Reset The Projection Matrix
  glOrtho(-20.0, 20.0, -20.0, 20.0, -20.0, 20.0);  /* normaliza coordenadas da janela */
  glMatrixMode(GL_MODELVIEW);    /* back to modelview matrix */
  glLoadIdentity();   // Reset The Projection Matrix
}

/* Keyboard handler */

void Key(unsigned char key, int x, int y)
{
    static int old_x = 100;
    static int old_y = 100;
    static int old_width = 400;
    static int old_height = 400;

    switch (key) {
//Active Object
    case 'm': obj=0; printf("Active Object -> Table\n"); break;
    case 'v': obj=1; printf("Active Object -> Vase\n"); break;
    case 't': obj=2; printf("Active Object -> Goblet\n"); break;

// Rotation
    case 'x': grau[obj]+=10; rx[obj]=1.0; ry[obj]=0.0; rz[obj]=0.0; break;
    case 'y': grau[obj]+=10; rx[obj]=0.0; ry[obj]=1.0; rz[obj]=0.0; break;
    case 'z': grau[obj]+=10; rx[obj]=0.0; ry[obj]=0.0; rz[obj]=1.0; break;

//Translation
    case '6': tx[obj]++; break;
    case '4': tx[obj]--; break;
    case '8': ty[obj]++; break;
    case '2': ty[obj]--; break;
    case '/': tz[obj]++; break;
    case '*': tz[obj]--; break;

// Scale
    case '-': if (sz[obj]<0.02) sz[obj]=0.02; sx[obj]=sy[obj]=sz[obj]=sz[obj]-0.02; break;
    case '+': sx[obj]=sy[obj]=sz[obj]=sz[obj]+0.02; break;

// Transparency
    case '[': if (ta[obj]<0.05) ta[obj]=0.05; ta[obj]-=0.05; break;
    case ']': if (ta[obj]>0.95) ta[obj]=0.95; ta[obj]+=0.05; break;

    case 'w': glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); break;
    case 'f': glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); break;

    case 'W': glutPositionWindow(old_x, old_y);
              glutReshapeWindow(old_width, old_height);
              break;
    case 'F': if (glutGet(GLUT_WINDOW_WIDTH) != glutGet(GLUT_SCREEN_WIDTH)) {
                 old_x = glutGet(GLUT_WINDOW_X);
                 old_y = glutGet(GLUT_WINDOW_Y);
       	         old_width = glutGet(GLUT_WINDOW_WIDTH);
	    	     old_height = glutGet(GLUT_WINDOW_HEIGHT);
	    	     glutFullScreen();
	    	  }
	    	  break;

    case 27:           /* Esc will quit */
        exit(1); break;
    default: break;
    }
    glutPostRedisplay();
}

/* Handle Menus and print selected object on the screen */
void Select(int value)
{
    switch (value) {
    case 1: obj=0; printf("Active Object -> Table\n");  break;
    case 2: obj=1; printf("Active Object -> Vase\n");   break;
    case 3: obj=2; printf("Active Object -> Goblet\n");	break;
    case 4: glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	    glutPostRedisplay(); break;
    case 5: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	    glutPostRedisplay(); break;
    case 6: exit(0); break;
    }
}

/*  Main Loop
 *  Open window with initial window size, title bar, 
 *  RGBA display mode, and handle input events. */

int main(int argc, char** argv)
{
      qobj = gluNewQuadric();  	    /* this will be used in drawScene */
      glutInit(&argc, argv);
      //seta a caracteristica double buffered visual e RGBA (Red, Green, Blue, Alfa Channel)
      glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GL_STENCIL_BUFFER_BIT);
      glutInitWindowPosition(0, 0);  /* set position */
      glutInitWindowSize(640, 480);  /* set window size */
      glutCreateWindow ("CG - Ionildo Jose Sanches");
      myInit ();
      glutKeyboardFunc(Key);
      glutReshapeFunc (myReshape);
      glutDisplayFunc(display);

      glutCreateMenu(Select);
    /* Create Menu */
      glutAddMenuEntry("Mesa", 1);
      glutAddMenuEntry("Vaso", 2);
      glutAddMenuEntry("Taça", 3);
      glutAddMenuEntry("---------------------",0);
      glutAddMenuEntry("Wireframe",4);
      glutAddMenuEntry("Preenchido",5);
      glutAddMenuEntry("Sair", 6);
      glutAttachMenu(GLUT_RIGHT_BUTTON);
      glutMainLoop();
      return 0;
}

