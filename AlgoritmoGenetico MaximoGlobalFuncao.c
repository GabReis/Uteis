#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>


#define QTDE_GERACOES 60
#define TAMANHO_POPULACAO 40 //valor deve ser par
#define TAXA_MUTACAO 5 //taxa em %


#define QTDE_BITS 10
#define INTERVALO_INICIAL -1
#define INTERVALO_FINAL 2
#define PI 3.14159
#define CONSTANTE_MAIOR_MAX_NEGATIVO 1 //p/ evita erro na roleta com valor negativo ou zero


typedef struct structPopulacao{
    char individuo[QTDE_BITS+1];
    float valorDecimalFx;
}Populacao;

typedef struct structNovaGeracao{
        char individuo [QTDE_BITS+1];
}NovaGeracao;

typedef struct structCromossomoElite{
    float maiorFx;
    int indiceCromossomoElite;
}CromossomoElite;

Populacao populacao[TAMANHO_POPULACAO];
NovaGeracao novaGeracao[TAMANHO_POPULACAO];
CromossomoElite cromossomoElite;
float somaAvaliacao = 0;
int indiceNovaGeracao =0;

void trocarPopulacaoAntigaPelaNovaGeracao(){
    int i;
    for (i=0; i < TAMANHO_POPULACAO; i++){
        strcpy(populacao[i].individuo, novaGeracao[i].individuo);
    }
}
void mutar(){
    int i, valor, bit;

    for (i=0; i < TAMANHO_POPULACAO; i++){
        valor = rand()%100;//probabilidade de mutar
        if (valor < TAXA_MUTACAO){//ocorre mutação
            bit = rand()%QTDE_BITS;//seleciona um bit para mutar

            if (novaGeracao[i].individuo[bit] == '0')//inverte os bits
                novaGeracao[i].individuo[bit] = '1';
            else
                novaGeracao[i].individuo[bit] = '0';
        }
    }
    trocarPopulacaoAntigaPelaNovaGeracao();

}

int roletaViciada(){

    int i;
    float aux;
    int numeroAleatorio = rand()%((int)somaAvaliacao-1)+1;//numero de 1 até (soma-1)

    i=0;
    aux = populacao[0].valorDecimalFx;//valor da avaliação do 1º individuo

    while(aux < numeroAleatorio){
        i++;
        aux = aux + populacao[i].valorDecimalFx;
    }

    return i;//índice do indivíduo escolhido para o cruzamento
}

//o crossOver pode ser de 0 até o (tamanho do individuo - 1)
//o ponto é definido da esquerda pra direita, ex: ponto = 0,
//entao o crossOver terá somente um bit pra esquerda e o resto pra direita =|====...n , o ponto de crossOver é a barra
int getPontoCrossOver(){
    return (rand()%(QTDE_BITS-1)+1);
}
void crossOverGeraDoisFilhos(){

    int indicePai;
    int indiceMae;
    int j, pontoCrossOver;

    indicePai = roletaViciada();
    indiceMae = roletaViciada();

    pontoCrossOver = getPontoCrossOver();

    for(j=0; j < QTDE_BITS; j++){
        if (j < pontoCrossOver){
            novaGeracao[indiceNovaGeracao].individuo[j] = populacao[indicePai].individuo[j];//filho1
            novaGeracao[indiceNovaGeracao+1].individuo[j] = populacao[indiceMae].individuo[j]; //filho2
        }else{
            novaGeracao[indiceNovaGeracao].individuo[j] = populacao[indiceMae].individuo[j];//filho1
            novaGeracao[indiceNovaGeracao+1].individuo[j] = populacao[indicePai].individuo[j];//filho2
        }
    }

    novaGeracao[indiceNovaGeracao].individuo[QTDE_BITS] = '\0';
    novaGeracao[indiceNovaGeracao+1].individuo[QTDE_BITS] = '\0';
    indiceNovaGeracao+=2;//2 porque é gerado 2 filhos por vez


}
void imprimirPopulacao(){
    int i;
    printf("\n\nPopulacao\n\n");
    for (i=0; i < TAMANHO_POPULACAO; i++){
            printf("[%d] %s\n", i, populacao[i].individuo);
    }
}

void criarDoisIndividuoComUmPaiUmaMae(){
    int i;
    for (i=0; i < ((int)(TAMANHO_POPULACAO/2)-1);i++){
        crossOverGeraDoisFilhos();
    }
}

void criarUmIndividuoComUmPaiUmaMae(){
    int indicePai;
    int indiceMae;
    int j, pontoCrossOver;

    indicePai = roletaViciada();
    indiceMae = roletaViciada();
    pontoCrossOver = getPontoCrossOver();

    for(j=0; j < QTDE_BITS; j++){
        if (j < pontoCrossOver){
            novaGeracao[indiceNovaGeracao].individuo[j] = populacao[indicePai].individuo[j];//filho1
        }else{
            novaGeracao[indiceNovaGeracao].individuo[j] = populacao[indiceMae].individuo[j];//filho1
        }
    }
    novaGeracao[indiceNovaGeracao].individuo[QTDE_BITS] = '\0';
    indiceNovaGeracao++;
}

//adiciona o melhor individuo na nova geracao (Elitismo)
void adicionarIndividuoEliteNaNovaGeracao(){
    strcpy(novaGeracao[indiceNovaGeracao].individuo, populacao[cromossomoElite.indiceCromossomoElite].individuo);
}

//(populacao-2) gera 2 filhos com apenas 1 pai e 1 mãe
//1 filho é produzido por 1 pai e uma mãe
//1 filho é o melhor individuo da população anterior (elitismo)
//a soma dos 3 itens anteriores resulta no mesmo numero de individuos da população anterior
void cruzar(){

    criarDoisIndividuoComUmPaiUmaMae();
    criarUmIndividuoComUmPaiUmaMae();
    adicionarIndividuoEliteNaNovaGeracao();
}

//soma os valores de f(x) para determinar suas probabilidades de serem selecionados na roleta viciada
void calcularSomaAvaliacao(){
    int i;
    for (i=0; i < TAMANHO_POPULACAO; i++){
        somaAvaliacao += populacao[i].valorDecimalFx;
    }
}

//calcula a f(x)
//a constante é usada para garantir que a f(x) nao retorne valores negativos ou zero
//Na roleta nao pode aparecer valor negativo ou zero, porque esse individuo nunca será selecionado
float calcularValorDeY(float x){

    float valorY = x*sin(10.0*PI*x)+1.0+CONSTANTE_MAIOR_MAX_NEGATIVO;

    return valorY;
}
//conversão do valor do cromossomo para float
float converterCromossomoInteiroParaFloat(int cromossomo){
    float valorFloat = INTERVALO_INICIAL + (float)(INTERVALO_FINAL-INTERVALO_INICIAL)*((float)cromossomo / ((float)((pow(2,QTDE_BITS))-1)));
    return valorFloat;
}
int converterCromossomoBinarioParaInteiro(char individuo[QTDE_BITS]){
   int i, resposta;
   for ( i = 0 , resposta = 0 ; individuo[i] ; i++ ){
       resposta <<= 1;
       resposta |= individuo[i] == '1' ;
    }
    return resposta;

}
void setCromossomoDeElite(float valorFx, int indiceCromossomo){

    if ( valorFx > cromossomoElite.maiorFx){
        cromossomoElite.maiorFx = valorFx;
        cromossomoElite.indiceCromossomoElite = indiceCromossomo;
    }

}
void calcularAptidao(){
    int i, valorInteiro;
    float valorFloat, valorFx;

    for (i=0; i < TAMANHO_POPULACAO; i++){
        valorInteiro = converterCromossomoBinarioParaInteiro(populacao[i].individuo);
        valorFloat = converterCromossomoInteiroParaFloat(valorInteiro);
        valorFx = calcularValorDeY(valorFloat);//calcula a f(x)
        populacao[i].valorDecimalFx = valorFx;
        setCromossomoDeElite(valorFx, i);
    }
    calcularSomaAvaliacao();
}

//criar a população inicial de forma aleatória
void inicializarPopulacao(){
    int i, j;
    srand(time(NULL));

    for (i=0; i < TAMANHO_POPULACAO; i++){
        for (j=0; j < QTDE_BITS; j++){
            populacao[i].individuo[j] = (rand()%2) + '0';//'0' = é usado para a converter para char
        }
        populacao[i].individuo[QTDE_BITS] = '\0';
    }
}
void inicializarVariaveis(){
    indiceNovaGeracao = 0;
    somaAvaliacao = 0;
    cromossomoElite.maiorFx = -1.0;
}
float getValorDeX(){
    int i;
    float maiorFx = -1.0, valorXDaMaiorFx;
    int valorXInteiro;
    float valorXFloat, valorFx;
    for(i=0; i < TAMANHO_POPULACAO; i++){
        valorXInteiro = converterCromossomoBinarioParaInteiro(populacao[i].individuo);
        valorXFloat = converterCromossomoInteiroParaFloat(valorXInteiro);
        valorFx = calcularValorDeY(valorXFloat);
        if (valorFx > maiorFx){
            maiorFx = valorFx;
            valorXDaMaiorFx = valorXFloat;
        }
    }
    return valorXDaMaiorFx;
}
float encontrarMaximoGlobal(){
    int i, j;

    inicializarPopulacao();

   for(i=0; i < QTDE_GERACOES; i++){
        printf("\n\n-------------------------geracao %d--------------------------", i);
        inicializarVariaveis();
        calcularAptidao();
        cruzar();
        imprimirPopulacao();
        mutar();//a mutação é aplicada na nova população
    }
    return getValorDeX();

}
int main(){

    float valorDeX = encontrarMaximoGlobal();
    printf("\n\n\n-----------------------------------------------");
    printf("\n          PONTO MAXIMO GLOBAL:\n            x = %f\n", valorDeX);
    printf("            f(x) = %f\n", calcularValorDeY(valorDeX)-CONSTANTE_MAIOR_MAX_NEGATIVO);
    printf("-------------------------------------------------\n\n\n\n");
    return 0;
}
