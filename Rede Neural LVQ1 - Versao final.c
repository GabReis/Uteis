#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


//************parametros da rede***********************
#define TAMANHO_ENTRADA 80  //max 80
#define TAMANHO_ENTRADA_CLASSIFICACAO 20 //max 20
#define EPOCA 10//número de iterações
#define TAXA_APREDIZAGEM_INICIAL 0.1
#define NOME_ARQUIVO_ENTRADA "Input.txt"
#define NOME_ARQUIVO_CLASSIFICAR "Classificar.txt"
#define QTDE_NEURONIO 100
#define MENOR_DISTANCIA 1000
//***************************************************

//*********estrutura de dados *************************
typedef struct instancia{
    float peso[4];
    int classe;//0= setosa, 1= versicolor
}Instancia;
typedef struct vencedor{
    int indiceVencedor;//guarda o índice do neurônio vencedor
    int classeVencedor;
    int classeEntrada;
}NeuronioVencedor;
Instancia vetorEntrada[TAMANHO_ENTRADA];//vetor de entrada contém 4 peso em cada instancia, além da classe
Instancia neuronio[QTDE_NEURONIO]; //vetor com os pesos, na primeira vez é gerado aleatório
Instancia classificar[TAMANHO_ENTRADA_CLASSIFICACAO];
NeuronioVencedor neuronioVencedor;
//********************************************************


//***************** variáveis globais ***********************
int indiceAleatorio[TAMANHO_ENTRADA];//usado no Fisher-Yates. É responsável pela aleatoriedade das instancias do vetor de entrada
int menorDistancia;
float aprendizagem = TAXA_APREDIZAGEM_INICIAL;
int matrizConfusao[2][2] = {{0, 0},
                            {0, 0}};
//*********************************************************

//****************matriz de confusão**********************
//           Setosa   Versicolor
//Setosa    |--------|----------|  sendo setosa = 0
//Versicolo |--------|----------|  sendo versicolor = 1
//*******************************************************


//*****protótipos de funções *****************************
void lerBaseDados(Instancia vetor[], int tamanho, char nomeArquivo []);
void preencherNeuronios();
void calcularDistanciaEuclidiana(int indiceEntrada, int indiceNeuronio);
//********************************************************

void mostrarClassificacao(){
    printf("Neuronio Vencedor: %d |  ", neuronioVencedor.indiceVencedor);

    if (neuronioVencedor.classeEntrada == 0)
        printf("Classe Correta: Setosa     |  ");
    else
        printf("Classe Correta: Versicolor |  ");
    //------------------------------

    if (neuronioVencedor.classeVencedor == 0)
        printf("LVQ1: Setosa     | ");
    else
        printf("LVQ1: Versicolor | ");
    //---------------------------------
    if (neuronioVencedor.classeVencedor == neuronioVencedor.classeEntrada)
        printf("ACERTOU\n");
    else
        printf("ERROU\n");

}
void atualizarMatrizDeCofusao(){
    if (neuronioVencedor.classeVencedor == neuronioVencedor.classeEntrada){//acertou
        if (neuronioVencedor.classeVencedor == 0)
            matrizConfusao[0][0] += 1;
        else
            matrizConfusao[1][1] += 1;
    }else{//errou
        if (neuronioVencedor.classeEntrada == 0)
            matrizConfusao[0][1]+=1;
        else
            matrizConfusao[1][0]+=1;
    }
}
void mostrarMatrizDeConfusao(){
    printf("\n\n******Matriz de Confusao**************\n\n");
    printf("              Setosa    Versicolor\n");
    printf(" Setosa     |  %d         %d\n", matrizConfusao[0][0], matrizConfusao[0][1]);
    printf(" Versicolor |  %d         %d\n", matrizConfusao[1][0], matrizConfusao[1][1]);
    printf("\n\n***************************************\n");
}

void calcularPorcentualAcerto(){
    float setosa      = ((float)matrizConfusao[0][0]/(float)(matrizConfusao[0][0]+matrizConfusao[0][1]))*100;
    float versicolor = ((float)matrizConfusao[1][1]/(float)(matrizConfusao[1][0]+matrizConfusao[1][1]))*100;
    printf("\n\n\n******* DESEMPENHO DA REDE************\n\n");
    printf("\n\n%% ACERTO SETOSA         = %.3f %%\n", setosa);
    printf("%% ACERTO VERSICOLOR     = %.3f %%\n", versicolor);
    printf("\n\n***************************************\n");

}

void classificarEntrada(){
    int i, j;
    menorDistancia = MENOR_DISTANCIA;
    lerBaseDados(classificar, TAMANHO_ENTRADA_CLASSIFICACAO, NOME_ARQUIVO_CLASSIFICAR);

    for(i=0; i < TAMANHO_ENTRADA_CLASSIFICACAO; i++){
        for(j=0; j < QTDE_NEURONIO; j++){
            calcularDistanciaEuclidiana(i, j);
        }
        menorDistancia = MENOR_DISTANCIA;
        mostrarClassificacao();
        atualizarMatrizDeCofusao();
    }
    calcularPorcentualAcerto();
    mostrarMatrizDeConfusao();
}


///------------------------Treinamento da rede ---------------------------------------------------------------------
void atualizarTaxaAprendizagem(int n){
    float expoente = (float)1.0/(float)(n-1);
    aprendizagem = TAXA_APREDIZAGEM_INICIAL*(pow(((float)0.01/(float)TAXA_APREDIZAGEM_INICIAL), expoente));
}
void atualizarPesoNeuronioVencedor(int indiceEntrada){
     Instancia *w = &neuronio[neuronioVencedor.indiceVencedor];
     Instancia *x = &vetorEntrada[indiceEntrada];

    if (neuronioVencedor.classeVencedor == neuronioVencedor.classeEntrada){//acertou a classe
        (*w).peso[0] = (*w).peso[0] + aprendizagem * ((*x).peso[0] - (*w).peso[0]);
        (*w).peso[1] = (*w).peso[1] + aprendizagem * ((*x).peso[1] - (*w).peso[1]);
        (*w).peso[2] = (*w).peso[2] + aprendizagem * ((*x).peso[2] - (*w).peso[2]);
        (*w).peso[3] = (*w).peso[3] + aprendizagem * ((*x).peso[3] - (*w).peso[3]);
    }else{//errou a classe
        (*w).peso[0] = (*w).peso[0] - aprendizagem * ((*x).peso[0] - (*w).peso[0]);
        (*w).peso[1] = (*w).peso[1] - aprendizagem * ((*x).peso[1] - (*w).peso[1]);
        (*w).peso[2] = (*w).peso[2] - aprendizagem * ((*x).peso[2] - (*w).peso[2]);
        (*w).peso[3] = (*w).peso[3] - aprendizagem * ((*x).peso[3] - (*w).peso[3]);
    }
}
//calcula a distancia de uma entrada com todos os neurônios da rede e encontra a menor distancia
void calcularDistanciaEuclidiana(int indiceEntrada, int indiceNeuronio){
    float distancia;
    distancia = sqrt (pow ((vetorEntrada[indiceEntrada].peso[0] - neuronio[indiceNeuronio].peso[0]), 2) +
                      pow ((vetorEntrada[indiceEntrada].peso[1] - neuronio[indiceNeuronio].peso[1]), 2) +
                      pow ((vetorEntrada[indiceEntrada].peso[2] - neuronio[indiceNeuronio].peso[2]), 2) +
                      pow ((vetorEntrada[indiceEntrada].peso[3] - neuronio[indiceNeuronio].peso[3]), 2));

    if (distancia < menorDistancia){
        menorDistancia = distancia;
        neuronioVencedor.indiceVencedor = indiceNeuronio;
        neuronioVencedor.classeVencedor = neuronio[indiceNeuronio].classe;
        neuronioVencedor.classeEntrada = vetorEntrada[indiceEntrada].classe;
    }
}
//gerar números aleatórios sem repetir
void Fisher_Yates(){
    int i, key, temp;
    for(i=0; i < TAMANHO_ENTRADA; i++){//preenche o vetor com elementos ordenados
        indiceAleatorio[i] = i;
    }

    srand(time(NULL));
    for (i= TAMANHO_ENTRADA; i > 0; i--){
         key = rand() % i;
         temp = indiceAleatorio[key];
         indiceAleatorio[key] = indiceAleatorio[i-1];
         indiceAleatorio[i-1] = temp;
    }

}
void treinarRedeLVQ1(){
    int n, j, k;

    lerBaseDados(vetorEntrada, TAMANHO_ENTRADA, NOME_ARQUIVO_ENTRADA);
    preencherNeuronios();//vetor de pesos gerados aleatoriamentes, juntamente com uma classe gerada de forma aleatória

    for (n = EPOCA; n > 1; n--){//iterações p/ treinamento da rede (época)
        Fisher_Yates();//gerar vetor com índices aleatórios para ler a entrada

        for (j= 0; j < TAMANHO_ENTRADA; j++){//percorre toda a entrada
            menorDistancia = MENOR_DISTANCIA;
            //indiceAleatório[j] corresponde ao indice de uma entrada (aleatório seu valor, mas nunca repetido)
            //k é o índice do neurônio
            for (k=0; k < QTDE_NEURONIO; k++){//percorre todo os neurônios
                calcularDistanciaEuclidiana(indiceAleatorio[j], k);
            }
            atualizarPesoNeuronioVencedor (indiceAleatorio[j]);

        }
        atualizarTaxaAprendizagem(n);
    }
}
void preencherNeuronios(){
    int i;
    srand(time(NULL));

    for(i=0; i < QTDE_NEURONIO; i++){
        //gera pesos aleatórios
        neuronio[i].peso[0] = (float)(rand()%100+1)/(float)100;
        neuronio[i].peso[1] = (float)(rand()%100+1)/(float)100;
        neuronio[i].peso[2] = (float)(rand()%100+1)/(float)100;
        neuronio[i].peso[3] = (float)(rand()%100+1)/(float)100;
        //-------------------------------------------
        neuronio[i].classe = rand()%2;//tem duas classes, gera 0 e 1
    }
}
///--------------------fim treinamento da rede -----------------------------------------
void lerBaseDados(Instancia vetor[], int tamanho, char nomeArquivo []){
    FILE *arquivo;
    int i;

    arquivo = fopen(nomeArquivo, "r");
    if(arquivo ==NULL){
        printf("Erro na abertura do arquivo!");
        exit(1);
    }
    for (i=0; i < tamanho; i++){
        fscanf(arquivo,"%f%f%f%f%d",&vetor[i].peso[0],
                                    &vetor[i].peso[1],
                                    &vetor[i].peso[2],
                                    &vetor[i].peso[3],
                                    &vetor[i].classe);
    }
}
int main(){
    printf("wait...\n");
    treinarRedeLVQ1();
    system("cls");
    printf("\t\t\t\tResultados\n\n");
    classificarEntrada();
    printf("\n\n\n******* PARAMETROS DA REDE************\n\n");
    printf("\nTAMANHO ENTRADA: %d", TAMANHO_ENTRADA);
    printf("\nTAMANHOO ENTRADA CLASSIFICACAO: %d", TAMANHO_ENTRADA_CLASSIFICACAO);
    printf("\nEPOCA: %d", EPOCA);
    printf("\nTAXA DE APRENDIZAGEM INICIAL: %.3f", TAXA_APREDIZAGEM_INICIAL);
    printf("\nQTDE NEURONIOS: %d", QTDE_NEURONIO);
    printf("\n\n***************************************\n");
return 0;
}
