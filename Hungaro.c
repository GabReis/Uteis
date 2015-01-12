/**M�todo Hungaro - Gabriel e Luma **********
** Exerc�cio de Laborat�rio para disciplina de Pesquisa Operacional
** Exemplo de uma matriz de tamanho 3x3 montada pelo algoritmo:
** 0 5 4             0 1 1 1
** 4 0 0   ==>       1 0 5 4 Para cada linha i e coluna j, as posi��es [i][0] e
** 2 3 3             2 4 0 0 [0][j] da nova matriz contam a quantidade de zeros
**                   0 2 3 3  da linha i e coluna j, respectivamente.
**
**/

#include <stdio.h>
#include <stdlib.h>

float **matriz;   //matriz utilizada pelo m�todo h�ngaro
float **verdMatriz;  //matriz que ir� conter os valores iniciais para designa��o
int n;             // Tamanho da matriz

/** Toda vez que uma nova contagem de zeros � realizada na matriz, deve-se zerar
** a quantidade obtida antes. As posi��es demarcadas com -1 significam que aquela linha
** ou coluna foi riscada n�o devendo mais ser considerada na contagem
*/
void resetBordas(){
    int i;
    for(i=1;i<=n;i++){
        if(matriz[i][0] > -1)
            matriz[i][0] = 0;
        if(matriz[0][i] > -1)
            matriz[0][i] = 0;
    }
}

/** A matriz � lida de um arquivo txt onde a primeira cont�m o tamanho da matriz (n)
** e todas linhas seguintes cont�m os elementos desta matriz. Caso exista uma linha
** ou coluna fantasma, esta � preenchida com zeros para n�o interferir no valor final
** retornado como designa��o �tima no algoritmo.
**  S�o alocadas n+1 linhas e colunas para cada matriz, pois a primeira linha e coluna
** s�o utilizadas para contagem de zeros como no exemplo dado acima.
*/

alocaMatriz(){
    int i,j;
    FILE *arq;

    arq = fopen("5.31.txt","r"); // leitura do arquivo
    if(arq == NULL){
        printf("Problemas na leitura do arquivo");
        exit(1);
    }
    fscanf(arq,"%d",&n);         // leitura do tamanho da matriz
    if(n<1){
        printf("Tamanho insuficiente");
        exit(1);
    }
    matriz = (float **)malloc(sizeof(float*)*(n+1)); // N+1 espa�os criados para aloca��o
    verdMatriz = (float **)malloc(sizeof(float*)*(n+1));

    if(matriz == NULL || verdMatriz == NULL){
        printf("Erro para alocar");
        exit(1);
    }
    // Para cada espa�o alocado, criam-se n+1 espa�os formando uma matriz.
    for(i=0;i<n+1;i++){
        matriz[i] = (float*) calloc (n+1, sizeof(float));
        verdMatriz[i] = (float*) calloc (n+1, sizeof(float));
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            fscanf(arq,"%f",&matriz[i][j]); //Matrizes recebem os valores iniciais, menos
            verdMatriz[i][j] = matriz[i][j]; //nas bordas
        }
    }
    resetBordas(); //As bordas ganham os valores iniciais para futuras
                   //contagem de zeros
}

void imprimeMatriz(){ //Impress�o da matriz. Utilizada para testes
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            printf("%.2f\t",matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Para corte na linha e coluna, utiliza-se um valor maior que os demais
//da matriz e percorre-se a matriz procurando o menor elemento

void corteNaLinha(){ //Encontra o menor de cada linha e
    int i,j;         //subtrai em cada posi��o este valor
    float menor = 9999;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(matriz[i][j]< menor)
                menor=matriz[i][j];
        }
        for(j=1;j<=n;j++){
            matriz[i][j]-= menor;
        }
        menor = 9999;
    }
}

void corteNaColuna(){ //Encontra o menor de cada coluna e
    int i,j;          // subtrai em cada posi��o este valor
    float menor = 9999;
    for(j=1;j<=n;j++){
        for(i=1;i<=n;i++){
            if(matriz[i][j]<menor)
                menor=matriz[i][j];
        }
        for(i=1;i<=n;i++){
            matriz[i][j]-=menor;
        }
        menor = 9999;
    }
}

/** Fun��o utilizada para ver se existe ainda algum zero na matriz que n�o foi riscado.
** Toda linha i e coluna j riscada recebe -1 em [i][0] e [0][j], respectivamente.
** Ent�o basta percorrer a matriz procurando um zero e verificar, se ali, nem a linha e
** nem a coluna ainda foram riscados
*/
int verificaMatriz(){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(matriz[i][j] == 0){
                if(matriz[i][0]>=0 && matriz[0][j] >=0)
                    return 1;
            }
        }
    }
    return 0;
}
/** Para se contar zeros basta percorrer as i linhas e j colunas  da matriz
** e verificar se para cada zero encontrado, este ainda n�o foi riscado. Caso n�o
** tenha sido, a matriz em [i][0] e [0][j] ter� seu valor acrescido, demarcando que ali
** se encontra um zero que ainda n�o foi riscado.
*/
void contZeros(){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(matriz[i][j] == 0){
                if(matriz[i][0] > -1 && matriz[0][j]>-1){
                    matriz[i][0]++;
                    matriz[0][j]++;
                }
            }
        }
    }
}

/** Para riscar, verifica-se qual a linha possui mais zeros e qual coluna possui
** mais zeros. Ap�s isto, compara se a linha que possui mais zeros, possui uma quantidade
** maior de zeros do que a coluna e vice-versa. Qual possuir mais, ser� riscado.
**  Se empatar, verifica-se quantas linhas e quantas colunas possuem aquela quantidade
** de zeros. Se tiver mais linhas com aquela quantidade de zeros, risca-se uma das linhas,
** se for coluna, risca-se uma das colunas. Se mesmo assim empatar, ent�o escolhe-se
** arbitrariamente. Neste c�digo, escolheu riscar a coluna caso empate.
*/

void riscar(){
    int i,linha=-1,coluna=-1,indiceL,indiceC;
    for(i=1;i<=n;i++){
        if(matriz[0][i] > coluna){ // vari�vel coluna guarda a coluna com a maior
            coluna = matriz[0][i];  // numero de zeros
            indiceC = i; //indiceC guarda qual � a coluna na matriz com aquela quantidade
        }
        if(matriz[i][0] > linha){ // vari�vel linha guarda a linha com a maior
            linha = matriz[i][0]; // numero de zeros
            indiceL = i; //indiceC guarda qual � a linha na matriz com aquela quantidade
        }
    }
    if(linha > coluna)
        matriz[indiceL][0] = -1; // Sempre risca-se colocando -1
    else if(linha < coluna)
        matriz[0][indiceC] = -1;
    else{               //Caso empate em quantidade
        int maior=0;
        int contC=0,contL=0;
        for(i=1;i<=n;i++){
            if(maior == matriz[0][i]) //Contagem de linhas e colunas com aquela
                contC++;            // quantidade de zeros
            if(maior == matriz[i][0])
                contL++;
        }
        if(contL > contC)
            matriz[indiceL][0] = -1;
        else
            matriz[0][indiceC] = -1;
    }
}

/** Procedimento para encontrar o menor valor que n�o foi riscado na matriz
** e subtrai este valor dos outros elementos n�o riscados. Na intersec��o
** de dois riscos, este valor � somado.
*/

void alteraAposRiscar(){
    int i, j;
    float menor = 9999;
    for (i=1;i<=n;i++){ //Para encontrar elementos n�o riscados, n�o pode
        for(j=1;j<=n;j++){  //ter a linha nem a coluna valendo -1 no local
            if(matriz[i][0] >-1 && matriz[0][j] >-1){ //onde conta-se os zeros
                    if(matriz[i][j] < menor)
                        menor = matriz[i][j];
            }
        }
    }
    for (i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(matriz[i][0] >-1 && matriz[0][j] >-1){ //subtra��o do valor
                matriz[i][j] -= menor;
            }
            else{
                if(matriz[i][0] == -1 && matriz[0][j] == -1) //soma do valor
                    matriz[i][j] += menor;
            }
        }
    }
}

void resetRiscos(){ //Para uma nova itera��o do m�todo h�ngaro, desconsidera-se onde
    int i;          // foi riscado anteriormente e realiza-se nova contagem
    for(i=1;i<=n;i++){  // considerando toda a matriz novamente
        matriz[i][0] = 0;
        matriz[0][i] = 0;
    }
}

/** A designa��o de zeros funciona em duas partes.
** Primeiramente tenta-se designar zeros que sejam �nicos em linha ou coluna,
** pois nestes casos eles devem ser obrigatoriamente escolhidos. H� uma contagem
** de zeros que s�o escolhidos pela variavel qtoFta (quanto falta).
**  Caso consiga designar um zero para cada linha e coluna diferentes, esta
** vari�vel ter� o valor referente � dimens�o da matriz, n�o necessitando
** da segunda parte deste procedimento.
*/

float designarZeros(){
    int i,j,qtoFta=0;
    float soma=0;
    contZeros();
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(matriz[i][j] == 0){ //Encontrou um zero na matriz
                if(matriz[i][0] == 1 || matriz[0][j] == 1){ // Verifica se o zero � �nico
                    matriz[i][0] = -1;      //na linha ou na coluna, se for, marca com -1
                    matriz[0][j] = -1;
                    soma+=verdMatriz[i][j]; //Soma guardar� a solu��o �tima
                    qtoFta++;
                    break;
                }
            }
        }
    }
    if(qtoFta == n)
        return soma;    //Se for igual, a designa��o terminou

/** Caso a segunda parte seja necess�ria, criam-se pilhas com o tamanho destas sendo
** referente a quantidade de linhas que n�o tiveram nenhum zero designado.
**  Como nesta parte somente entra casos onde existem pelo menos dois zeros em cada
** linha e em cada coluna, ent�o deve-se testar cada uma das possibilidades ao se
** incluir um determinado zero. A pilha ficar� encarregada de empilhar um zero designado
** em uma linha, ir para a pr�xima que n�o tem zero designado e tentar designar um zero
** para ela tamb�m. Caso percorra a linha inteira e n�o tenha sido poss�vel
** designar (j=n), ent�o desempilha o zero designado anteriormente, voltando
** para o local onde houve desempilhamento ( i=pilhaL[ctrl] e j=pilhaC[ctrl] ),
** escolhendo outro zero desta linha antes de ir novamente para a linha que n�o tinha
** conseguido designar um zero.
** Exemplo:
**
**   4 4 2 2    Como nenhuma linha ou coluna possui um �nico zero. A primeira parte do
** 4 0 0 0 0   procedimento n�o designaria nenhum elemento. Nesta parte, empilharia o zero
** 4 0 0 0 0   da linha (1,1) e depois o zero de (2,2). Como na linha 3 n�o haveria zeros
** 2 0 0 1 2   para designar, desempilharia (2,2) e continuava procurando outro zero. Encontraria
** 2 0 0 3 4   (2,3) e iria novamente para linha 3. Ter�amos ent�o o zero de (3,2), por�m na
**             linha 4 ningu�m seria designado. Voltaria para linha 3, mas n�o h� zeros
**             depois de (3,2), o que desempilharia (2,3) e empilharia (2,4). O procedimento
**             termina quando algu�m da �ltima linha for designado.
*/
    int pilhaL[n-qtoFta], pilhaC[n-qtoFta],ctrl=0; //Cria��o das pilhas
    qtoFta=0;
    for (i=1;i<=n;i++){
        if(matriz[i][0]>-1){ //Somente entra nas linhas que n�o foram designadas
            for(j=1;j<=n;j++){      //Se a coluna n�o foi designada e a
                if(matriz[0][j]>-1 && matriz[i][j] == 0){ //posi��o vale 0
                    matriz[i][0] = matriz[i][0] * (-1); //Deixe a linha e a coluna
                    matriz[0][j] = matriz[0][j] *(-1); //temporariamente negativa
                    soma+=verdMatriz[i][j]; //Soma o valor
                    pilhaL[ctrl] = i; pilhaC[ctrl++]=j; //Empilha
                    break;
                }
   //Se em uma linha, j chegar a n, ent�o ningu�m naquela linha foi designado, devendo
   //desempilhar. Para isso, torna a linha e coluna que estava negativa em positiva novamente,
   //informando que pode-se percorrer novamente neste local.
   //Retira o valor somado e desempilha, fazendo i e j voltar para a posi��o onde
   //houve o �ltimo empilhamento.
                while(j==n){
                    ctrl--;
                    matriz[pilhaL[ctrl]][0] = matriz[pilhaL[ctrl]][0] * (-1);
                    matriz[0][pilhaC[ctrl]] = matriz[0][pilhaC[ctrl]] * (-1);
                    soma-=verdMatriz[pilhaL[ctrl]][pilhaC[ctrl]];
                    i=pilhaL[ctrl];j=pilhaC[ctrl];
                }
            }
        }
    }
    return soma;    //Retorna a soma
}

void hungaro(){
    int numCortes; //Loop fica rodando enquanto numero de cortes for menor que
    while(1){ //a dimens�o da matriz
        numCortes = 0; //Contagem de cortes
        while(verificaMatriz() == 1){ //Se ainda existir zeros n�o riscados
             numCortes++; //Aumenta contagem de cortes
             contZeros(); //Conta os zeros de linhas e colunas
             riscar(); //Risca onde tem mais zeros
             resetBordas(); //Reset onde n�o foi riscado, para realizar nova contagem
                            //a partir dos cortes j� realizado
        }
        if(numCortes == n)
            break;
        alteraAposRiscar(); //Subtrai menor valor entre n�o riscados e soma na intersec��o
        resetRiscos(); //Reset tudo incluindo onde riscou, para realizar contagem desde
                        // o in�cio
    }
    resetRiscos();
    printf("Solucao otima: %.2f", designarZeros()); //Chama a designa��o
}

int main(){
    alocaMatriz();  //Cria��o de matrizes
    corteNaLinha(); //Cortes em linha e depois em coluna
    corteNaColuna();
    hungaro(); //M�todo principal

    return 0;
}
