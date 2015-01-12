#include <stdio.h>
#include <conio.h>
#include <math.h>
#define tamPop 65       //tamanho da população

typedef struct cromossomo{
       double x1,x2,x3;     //definição das raízes
}Cromossomo;

Cromossomo populacao[tamPop];   //Cromosso das populações
Cromossomo melhorFenotipo;      //Cromossomo vencedor de cada iteração


void inicializar(){ //Inicializa os cromossomos com um valor inteiro de 0
                    //até o tamanho da amostra e uma parte fracionaria
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

double merito(double fenotipo){//função do mérito, quanto melhor o fenotipo,
                                //mais proximo de 1 resultará a função
        return (1/(1+fenotipo*fenotipo));
}


calculaFenotipo(int terceiroGrau,int segundoGrau,int primeiroGrau,int valorIndependente){
    //Calcula os fenotipos procurando a raiz de x1,x2,x3 mais proximas de
    //zero na equação dada
    int i;
    double fenotipo;
    for(i=0;i<tamPop;i++){
            fenotipo = (terceiroGrau*pow(populacao[i].x1,3)+
                       segundoGrau*pow(populacao[i].x1,2)+
                       primeiroGrau*populacao[i].x1 + valorIndependente);
            //calcula o valor para cada raiz na equação

            fenotipo = 1 - merito(fenotipo);    //retirando 1 do valor do merito, posso
                                            //verificar qual é o menor fenotipo vendo
                                            //qual é mais proximo de zero
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
        //terceiro grau = coeficiente de x³ na equação
        //segundo grau = coeficiente de x² na equação
        //primeiro grau = coeficiente de x na equação
        int op,terceiroGrau=1,segundoGrau=-6,primeiroGrau=11,valorIndependente=-6;
        inicializar();  //inicializa cromossomos
        do{
        printf("Equacao padrao:  x^3 -6x^2 + 11x - 6 = 0 \nTecle 0 se deseja altera-la ou 1 para mante-la\n");
        scanf("%d",&op);
        }while(op<0||op>1); //escolhe equação
        if(op==0){  //pode-se trocar a equação do terceiro grau a ser usada
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
