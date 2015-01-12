/* BasicoTeclado.cpp
*  
*  fevereiro,2002 por Carla Freitas
*
*  incrementa o programa Basico com uso de teclado 
*/

/* include de definicoes das funcoes da glut 
   glut.h inclui gl.h, que contem os headers de funcoes da OpenGL propriamente dita
   glut.h inclui tambem definicoes necessarias para o uso de OpenGl nos diversos ambientes Windows
*/
#include <gl/glut.h>



// estrutura que descreve um ponto (x,y)
typedef struct XY {
        float x;
        float y;
} PontoXY;

PontoXY P1, P2, P3;


// Função de callback de desenho
// Executada sempre que é necessario re-exibir a imagem
void RenderScene(void)
	{
	// Limpa a janela com a cor especificada como cor de fundo
	glClear(GL_COLOR_BUFFER_BIT);
 
    // Especifica que as primitivas graficas devem ser de cor vermelha
    glColor3f (1.0f, 0.0f, 0.0f);
    
    // Chamadas de funções OpenGL para desenho
    glBegin (GL_TRIANGLES);
	  glVertex2f (P1.x,P1.y);
	  glVertex2f (P2.x,P2.y);
	  glVertex2f (P3.x,P3.y);
    glEnd();

	// Flush dos comandos de desenho que estejam no "pipeline" da OpenGL
    // para conclusao da geracao da imagem
    glFlush();
	}


// Inicializa aspectos do rendering
void SetupRC(void)
    {
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);  // cor de fundo da janela
    }

// Inicializa os tres pontos com valores default
void SetupObjeto (void)
    { 
    P1.x = 0;
    P1.y = 1;
    P2.x = -1;
    P2.y = 0;
    P3.x = 1;
    P3.y = 0;
    }
    
void SpecialKeys(int key, int x, int y)
	{
	
    if(key == GLUT_KEY_UP)
		P1.y += 0.5;

	if(key == GLUT_KEY_DOWN)
		P1.y -= 0.5f;

	if(key == GLUT_KEY_LEFT)
		P1.x -= 0.5f;

	if(key == GLUT_KEY_RIGHT)
		P1.x += 0.5f;

	if(P1.y < -1.0f)
		P1.y = -1.0f;

	if (P1.y > 1.0f)
		P1.y = 1.0f;

    if (P1.x < -1.0f)
		P1.x = -1.0f;

    if (P1.x > 1.0f)
		P1.x = 1.0f;

// Refresh da imagem: força a execuçao da RenderScene
	glutPostRedisplay();
    }
    

// Especifica callback comum de teclado     
void KeyboardFunc ( unsigned char key, int x, int y )
{
     if(key == 'r')
       SetupObjeto();
     glutPostRedisplay();
     
}



// Parte principal - ponto de início de execução
// Cria janela 
// Inicializa aspectos relacionados a janela e a geracao da imagem
// Especifica a função de callback de desenho
// Especifica funções de callback de teclado para teclas normais e especiais
int main(void)
{
	// Indica que deve ser usado um unico buffer para armazenamento da imagem e representacao de cores RGB
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    // Cria uma janela com o titulo especificado
	glutCreateWindow("Programa com uso de Teclado");

    // Especifica a funcao que vai tratar teclas comuns 
    glutKeyboardFunc(KeyboardFunc);
    
    // Especifica a funcao que vai tratar teclas especiais
 	glutSpecialFunc(SpecialKeys);
  
    // Especifica para a OpenGL que funcao deve ser chamada para geracao da imagem
	glutDisplayFunc(RenderScene);

    // Executa a inicializacao de parametros de exibicao
	SetupRC();
 
    // Inicializa as informacoes geometricas do objeto
    SetupObjeto();

    // Dispara a "maquina de estados" de OpenGL 
	glutMainLoop();
	return 0;
 }

