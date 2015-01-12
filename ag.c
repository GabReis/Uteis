#include <stdio.h>
#include <conio.h>
#include <math.h>
#define tamPop 65       //tamanho da popula��o

typedef struct cromossomo{
       double x1,x2,x3;     //defini��o das ra�zes
}Cromossomo;

Cromossomo populacao[tamPop];   //Cromosso das popula��es
Cromossomo melhorFenotipo;      //Cromossomo vencedor de cada itera��o


void inicializar(){ //Inicializa os cromossomos com um valor inteiro de 0
                    //at� o tamanho da amostra e uma parte fracionaria
    int i;
    srand(time(NULL));
    for(i=0;i<tamPop;i++){
        populacao[i].x1 = ((rand()%tamPop) + (rand()%tamPop)/(double)tamPop);
        populacao[i].x2 = -(rand()%tamPop)+(rand()%tamPop)/(double)tamPop;
        populacao[i].x3 = (rand()%tamPop)-(rand()%tamPop)/(double)tamPop;
        printf("\n%d -  %f\t%f\t%f",i+1,populacao[i].x1,populacao[i].x2,populacao[i].x3);
    }
    melhorFenotipo.x1=10;
    melhorFenotipo.x2=10;
    melhorFenotipo.x3=10;
}

double merito(double fenotipo){//fun��o do m�rito, quanto melhor o fenotipo,
                                //mais proximo de 1 resultar� a fun��o
        return (1/(1+fenotipo*fenotipo));
}


calculaFenotipo(int terceiroGrau,int segundoGrau,int primeiroGrau,int valorIndependente){
    //Calcula os fenotipos procurando a raiz de x1,x2,x3 mais proximas de
    //zero na equa��o dada
    int i;
    double fenotipo;
    for(i=0;i<tamPop;i++){
            fenotipo = (terceiroGrau*pow(populacao[i].x1,3)+
                       segundoGrau*pow(populacao[i].x1,2)+
                       primeiroGrau*populacao[i].x1 + valorIndependente);
            //calcula o valor para cada raiz na equa��o

            fenotipo = 1 - merito(fenotipo);    //retirando 1 do valor do merito, posso
                                            //verificar qual � o menor fenotipo vendo
                                            //qual � mais proximo de zero
            if(fenotipo<melhorFenotipo.x1)
                melhorFenotipo.x1=fenotipo;

            fenotipo = (terceiroGrau*pow(populacao[i].x2,3)+
                       segundoGrau*pow(populacao[i].x2,2)+
                       primeiroGrau*populacao[i].x2 + valorIndependente);
            fenotipo = 1 - merito(fenotipo);
            if(fenotipo<melhorFenotipo.x2)
                melhorFenotipo.x2=fenotipo;

            fenotipo = (terceiroGrau*pow(populacao[i].x3,3)+
                       segundoGrau*pow(populacao[i].x3,2)+
                       primeiroGrau*populacao[i].x3 + valorIndependente);
            fenotipo = 1 - merito(fenotipo);
            if(fenotipo<melhorFenotipo.x3)
                melhorFenotipo.x3=fenotipo;
        }
}
int main(){
        //terceiro grau = coeficiente de x� na equa��o
        //segundo grau = coeficiente de x� na equa��o
        //primeiro grau = coeficiente de x na equa��o
        int op,terceiroGrau=1,segundoGrau=-6,primeiroGrau=11,valorIndependente=-6;
        inicializar();  //inicializa cromossomos
        do{
        printf("Equacao padrao:  x^3 -6x^2 + 11x - 6 = 0 \nTecle 0 se deseja altera-la ou 1 para mante-la\n");
        scanf("%d",&op);
        }while(op<0||op>1); //escolhe equa��o
        if(op==0){  //pode-se trocar a equa��o do terceiro grau a ser usada
            printf("Digite o coeficiente de x do terceiro grau: ");
            scanf("%d",&terceiroGrau);
            printf("\nDigite o coeficiente de x do segundo grau: ");
            scanf("%d",&segundoGrau);
            printf("\nDigite o coeficiente de x do primeiro grau: ");
            scanf("%d",&primeiroGrau);
            printf("\nDigite o valor independente da equacao: ");
            scanf("%d",&valorIndependente);

        }
        calculaFenotipo(terceiroGrau,segundoGrau,primeiroGrau,valorIndependente);
        printf("Melhor fenotipo: %f\t%f\t%f",melhorFenotipo.x1,melhorFenotipo.x2,melhorFenotipo.x3);
        getch();
}
