#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arvore{
    int codigo;
    char nome[30];
    char email[40];
    char telefone[14];
    char aniversario[6];
    struct arvore *esq;
    struct arvore *dir;
};

int codigo =1;

struct arvore* cadastrar(struct arvore** raiz){
    struct arvore *novo;
    novo = (struct arvore *)malloc(sizeof(struct arvore));;
    printf("Digite o nome: ");
    fflush(stdin);
    gets(novo->nome);
    printf("Digite o email: ");
    gets(novo->email);
    printf("Digite o telefone: ");
    gets(novo->telefone);
    printf("Digite o aniversario: ");
    gets(novo->aniversario);

    while(*raiz != NULL) {
		if(strcmp(novo->nome, (*raiz)->nome) < 0)
			raiz = &(*raiz)->esq;
		else
			raiz = &(*raiz)->dir;
	}

    novo->codigo = codigo;
    codigo++;
    novo->dir = NULL;
    novo->esq = NULL;

    *raiz = novo;

}

void buscar(struct arvore* raiz, int menu){
    if(menu == 1){
        printf("Digite o codigo: ");
        scanf("%d", &codigo);
        while(raiz != NULL) {
            if(codigo == raiz->codigo)
                printf("Nome: %s\nEmail: %s\nTelefone: %s\nAniversario: %s\n\n",raiz->nome,raiz->email,raiz->telefone, raiz->aniversario);
            if(codigo < raiz->codigo)
                raiz = raiz->esq;
            else
                raiz = raiz->dir;
        }
    }
    else if (menu == 2){
        char nome[30];
        printf("Digite o nome: ");
        fflush(stdin);
        gets(nome);
        while(raiz != NULL) {
            if(strcmp(nome, raiz->nome) == 0)
                printf("Codigo: %d\nEmail: %s\nTelefone: %s\nAniversario: %s\n\n",raiz->codigo,raiz->email,raiz->telefone, raiz->aniversario);
            if(strcmp(nome, raiz->nome) < 0)
                raiz = raiz->esq;
            else
                raiz = raiz->dir;
        }
    }
    else if (menu == 3){
        char mes[2];
        printf("Digite o mes de aniversario: ");
        fflush(stdin);
        scanf("%s", &mes);
    }
    else if (menu == 4){
        if (raiz == NULL)
            return;
        buscar(raiz->esq, menu);
        printf("Codigo: %d\nNome: %s\nEmail: %s\nTelefone: %s\nAniversario: %s\n\n",raiz->codigo,raiz->nome,raiz->email,raiz->telefone, raiz->aniversario);
        buscar(raiz->dir, menu);
    }

}

struct arvore *maiorDireita(struct arvore **no){
    if((*no)->dir != NULL)
       return maiorDireita(&(*no)->dir);
    else{
       struct arvore *aux = *no;
       if((*no)->esq != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
          *no = (*no)->esq;
       else
          *no = NULL;
       return aux;
    }
}

struct arvore *menorEsquerda(struct arvore **no){
    if((*no)->esq != NULL)
       return menorEsquerda(&(*no)->esq);
    else{
       struct arvore *aux = *no;
       if((*no)->dir != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
          *no = (*no)->dir;
       else
          *no = NULL;
       return aux;
    }
}

void remover(struct arvore **raiz, char* nome){

    if(*raiz == NULL){
       printf("Numero nao existe na arvore!");
       getch();
       return;
    }
    if(strcmp(nome, (*raiz)->nome) < 0)
       remover(&(*raiz)->esq, nome);
    else
       if(strcmp(nome, (*raiz)->nome) > 0)
          remover(&(*raiz)->dir, nome);
       else{    // se nao eh menor nem maior, logo, eh o numero que estou procurando! :)
          struct arvore *aux = *raiz;
          if (((*raiz)->esq == NULL) && ((*raiz)->dir == NULL)){         // se nao houver filhos...
                free(aux);
                (*raiz) = NULL;
          }
          else{     // so tem o filho da direita
             if((*raiz)->esq == NULL){
                (*raiz) = (*raiz)->dir;
                aux->dir = NULL;
                free(aux); aux = NULL;
            }
             else{            //so tem filho da esquerda
                if ((*raiz)->dir == NULL){
                    (*raiz) = (*raiz)->esq;
                    aux->esq = NULL;
                    free(aux); aux = NULL;
                }
                else{       //Escolhi fazer o maior filho direito da subarvore esquerda.
                   aux = maiorDireita(&(*raiz)->esq);
                   aux->esq = (*raiz)->esq;
                   aux->dir = (*raiz)->dir;
                   (*raiz)->esq = (*raiz)->dir = NULL;
                   free((*raiz));  *raiz = aux;  aux = NULL;
                }
            }
        }
    }
}

int main(){
    int menu;
    struct arvore* raiz = NULL;
    do{
        do{
            system("cls");
            printf("Agenda telefonica\n\nDigite:\n1- Cadastrar\n2- Buscar\n3- Excluir\n0- Sair\n");
            scanf("%d",&menu);
        }while(menu<0||menu>3);
        switch(menu){
            case 1: {
                cadastrar(&raiz);
            }break;
            case 2: {
                printf("\n\nBusca\n\n1- Por codigo\n2- Por nome\n3- Por data\n4- Listar todos\n");
                scanf("%d",&menu);
                buscar(raiz, menu);
                printf("\nTecle ENTER para continuar..");
                getch();
            }break;
            case 3:{
                char nome[30];
                printf("Digite o nome: ");
                fflush(stdin);
                gets(nome);
                remover(&raiz, nome);
            }break;
            default: printf("\n\nSaindo..");
        }
    }while(menu!=0);
    return 0;
}
