
/* Exemplo10.c - Marcionílio Barbosa Sobrinho
*  Carga de textura através de arquivo BMP
* Referência do Código: OpenGL Programming Guide - RedBook
*         planet.c, movelight.c, material.c
*
*/

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>

static int year = 0, day = 0;
int posicaoluz = 0;

int tx;

GLuint  texture_id[1];

/* 
  Função responsável pela carga de
  um arquivo BMP
   
  Esta função utiliza leitura direta do BMP sem
  a necessidade de outras bibliotecas assim
  segue abaixo a descrição de cada deslocamento
  do Header.
  Referencia :http://www.fastgraph.com/help/bmp_header_format.html   
  
 Formato do header de arquivos BMP (Windows) 
 Windows BMP files begin with a 54-byte header:
 offset  size   description 
   0       2     signature, must be 4D42 hex 
   2       4     size of BMP file in bytes (unreliable) 
   6       2     reserved, must be zero 
   8       2     reserved, must be zero 
  10       4     offset to start of image data in bytes
  14       4     size of BITMAPINFOHEADER structure, must be 40 
  18       4     image width in pixels 
  22       4     image height in pixels 
  26       2     number of planes in the image, must be 1 
  28       2     number of bits per pixel (1, 4, 8, or 24) 
  30       4     compression type (0=none, 1=RLE-8, 2=RLE-4) 
  34       4     size of image data in bytes (including padding) 
  38       4     horizontal resolution in pixels per meter (unreliable) 
  42       4     vertical resolution in pixels per meter (unreliable) 
  46       4     number of colors in image, or zero 
  50       4     number of important colors, or zero  
  
*/

int  LoadBMP(char *filename)
 {
    #define SAIR        {fclose(fp_arquivo); return -1;}
    #define CTOI(C)     (*(int*)&C)
 
    GLubyte     *image;
    GLubyte     Header[0x54]; 
    GLuint      DataPos, imageSize;
    GLsizei     Width,Height;
    int retorno = 0;
    int nb = 0;
    int t = 0;
    int i = 0;
    
    
    // Abre o arquivo e efetua a leitura do Header do arquivo BMP
    FILE * fp_arquivo = fopen(filename,"rb");
    if (!fp_arquivo) 
        return -1;
    if (fread(Header,1,0x36,fp_arquivo)!=0x36) 
        SAIR;
    if (Header[0]!='B' || Header[1]!='M')   
        SAIR;
    if (CTOI(Header[0x1E])!=0)              
        SAIR;
    if (CTOI(Header[0x1C])!=24)             
        SAIR;
    
    // Recupera a informação dos atributos de 
    // altura e largura da imagem

    Width   = CTOI(Header[0x12]);
    Height  = CTOI(Header[0x16]);
    ( CTOI(Header[0x0A]) == 0 ) ? ( DataPos=0x36 ) : ( DataPos = CTOI(Header[0x0A]) );
 
    imageSize=Width*Height*3;
    
    // Efetua a Carga da Imagem
    image = (GLubyte *)malloc(imageSize);

    retorno = fread(image,1,imageSize,fp_arquivo);
    
    if (retorno !=imageSize) 
     {
        free (image);
        SAIR;
     }

    // Inverte os valores de R e B

    
    for ( i = 0; i < imageSize; i += 3 )
     {
        t = image[i];
        image[i] = image[i+2];
        image[i+2] = t;
     } 

    // Tratamento da textura para o OpenGL

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

    glTexEnvf ( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
   
    // Faz a geraçao da textura na memória
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
                        
    fclose (fp_arquivo);
    free (image);
    return 1;
 }


void init(void)
{


   /* Cria as matrizes responsáveis pelo
      controle de luzes na cena */

   GLfloat ambiente[] = { 0.2, 0.2, 0.2, 1.0 };
   GLfloat difusa[] = { 0.7, 0.7, 0.7, 1.0 };
   GLfloat especular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat posicao[] = { 0.0, 3.0, 2.0, 0.0 };
   GLfloat lmodelo_ambiente[] = { 0.2, 0.2, 0.2, 1.0 };

   tx=0;

   glClearColor(0.0, 0.0, 0.0, 1.0);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_SMOOTH);

   /* Cria e configura a Luz para a cena */

   glLightfv(GL_LIGHT0, GL_AMBIENT, ambiente);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, difusa);
   glLightfv(GL_LIGHT0, GL_POSITION, posicao);
   glLightfv(GL_LIGHT0, GL_SPECULAR, especular);
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodelo_ambiente);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_COLOR_MATERIAL);
   
   
   /*
     Habilita a Texturizacao.
     Criacao inicial das texturas.     
   */
   
   glEnable ( GL_TEXTURE_2D );
   glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 );
   glGenTextures ( 1, texture_id );
   glBindTexture ( GL_TEXTURE_2D, texture_id[0] );
   LoadBMP ("pedra.bmp");
 

}

/* 
  Esta função cria uma esfera através do
  comando gluNewQuadric do GLU
  Esta esfera permite o mapeamento de texturas
  
  comando : gluSphere ( GLUquadricObj, raio, subdivisoes_em_torno_de_Z,
                        subdivisoes_ao_longo_de_Z )
*/

void esfera ( int raio,int longitude,int latitude  )
{   
   GLUquadricObj*  q = gluNewQuadric ( );
   gluQuadricDrawStyle ( q, GLU_FILL   );
   gluQuadricNormals   ( q, GLU_SMOOTH );
   gluQuadricTexture   ( q, GL_TRUE    );
   gluSphere ( q, raio, longitude, latitude );
   gluDeleteQuadric ( q );
}


/*
  Função responsável pelo desenho da esfera.
  E da aplicação da textura na mesma  
  Nesta função também serão aplicadas as tranformações
  necessárias para o efeito desejado.
*/

void display(void)
{
  /* Variáveis para definição da capacidade de brilho do material */
  GLfloat semespecular[4]={0.0,0.0,0.0,1.0};
  GLfloat especular[] = { 1.0, 1.0, 1.0, 1.0 };

  /* Posição da luz */
  GLfloat posicao[] = { 0.0, 3.0, 2.0, 0.0 };

  /*
    Limpa o buffer de pixels e
    determina a cor padrão dos objetos.
  */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f (1.0, 1.0, 1.0);

  /* Armazena o estado anterior para
     rotação da posição da luz */

  glPushMatrix () ;

    glRotated ((GLdouble) posicaoluz, 1.0, 0.0, 0.0);
    glLightfv (GL_LIGHT0, GL_POSITION, posicao);

  glPopMatrix(); // Posição da Luz

    /* Armazena a situação atual da pilha de matrizes */
 
 glPushMatrix (); 
     glRotatef (tx, 1.0, 0.0, 0.0);
     glTranslatef( 0.0, 0.0, 2.0);
 glPushMatrix ();
     glTranslatef (0.0, 0.0, -3.0);
 glPushMatrix ();
     glRotatef (9, 0.0, 0.0, 1.0);
    
    glPushMatrix();
      glRotatef ((GLfloat) year, 1.0, 0.0, 0.0);
      //glTranslatef (tx, ty, tz);
      glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
      glColor3f (1.0, 1.0, 1.0);


      /* Define a propriedade do material */
      //refletância do material
      glMaterialfv(GL_FRONT,GL_SPECULAR, semespecular);
        // Define a concentração do brilho
      glMateriali(GL_FRONT,GL_SHININESS,20);

      
      /* Habilita a textura e cria a esfera */
      glBindTexture ( GL_TEXTURE_2D, texture_id[0] ); 
      esfera ( 1.50, 20, 18); 

    glPopMatrix();
 glPopMatrix();
 glPopMatrix();
 glPopMatrix();

 // Executa os comandos
  glutSwapBuffers();

}

/*
   Função responsável pelo desenho da tela
   Nesta função são determinados o tipo de Projeção
   o modelo de Matrizes e
   a posição da câmera
   Quando a tela é redimensionada os valores
   da visão perspectiva são recalculados com base no novo tamanho da tela
   assim como o Viewport
*/   

void reshape (int w, int h)
{

  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

/* Função responsável pelo controle de teclado
   quando pressionada a tecla ESC
   o programa é terminado.
   a tecla D desabilita a textura enquanto
   a tecla H habilita a mesma.
*/   

void keyboard (unsigned char key, int x, int y)
{
  switch (key) {
      case 'd':
      case 'D':
           glDisable(GL_TEXTURE_2D);
           glutPostRedisplay();
           break;
      case 'A':
      case 'a':
           glEnable(GL_TEXTURE_2D);
           glutPostRedisplay();
           break;
  }
}

/*
  Esta função é chamada quando o botão esquerdo do 
  mouse é pressionado, a mesma irá calcular um novo
  valor para os valores dos ângulos contidos em year e day  
*/

void spinDisplay(void)
{
  year = (year + 1) % 360;
  day  = (day + 2 ) % 360;
  tx = (tx + 1) % 360 ;
  Sleep(5);
  glutPostRedisplay();
}


/* 
  Esta função irá controlar os botões do mouse.
  Se pressionado o botão da esquerda ela define
  a função spinDisplay como a função de "idle" do GLUT
  o comando glutIdelFunc, executa uma determinada função quando 
  nenhum evento estiver ocorrendo. (pressionamento de botões etc.)
  Quando o botão do meio é pressionado a função de Idle recebe NULL
  desabilitando a animação
*/
void mouse(int button, int state, int x, int y)
{
  switch (button) {
      case GLUT_LEFT_BUTTON:
           if (state == GLUT_DOWN)
              glutIdleFunc(spinDisplay);
           break;
      case GLUT_MIDDLE_BUTTON:
           if (state == GLUT_DOWN)
              glutIdleFunc(NULL);
           break;
      case GLUT_RIGHT_BUTTON:
           posicaoluz = (posicaoluz + 2) % 360;
           glutPostRedisplay();	  
           break;
      default:
           break;
  }
}

/*
 Função principal do programa.
*/
int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (800, 600);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Exemplo 10 - Carga de Textura .BMP");
  init ();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}

