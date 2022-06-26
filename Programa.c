/*Trabalho feito em dupla pelos alunos: Ana Beatriz Medeiros Cardoso e Newton Matheus Feitosa Lomar. Para 
a matéria de Estrutura de Dados.*/


#include <stdio.h> //chamada das bibliotecas
#include <stdlib.h>

//Criando a struct no
struct no {

    int num;
    struct no * prox;

};

typedef struct no * ptrno;

//Função para inserir no inicio da lista
int insere_ini(ptrno * L, int elem) {

    ptrno novono=(struct no *)malloc(sizeof(struct no));

    if (novono==NULL) {

        return 0;
    }
    else {

        novono->num = elem;
        novono->prox = *L;
        *L = novono;
        return 1;
    }
}


//Função para inserir no final da lista
int insere_fim(ptrno * L, int elem) {

    ptrno novono=(struct no *)malloc(sizeof(struct no));
    ptrno aux = *L;

    if(novono==NULL) {
        return 0;
    }
    else {

        novono->num=elem;

        if(*L==NULL){

            *L=novono;
        }
        else {

            while(aux->prox!=NULL) {

            aux=aux->prox;
            
            }
            aux->prox=novono;
        }

        return 1;
    }
}


//Função para remover no inicio da lista
int remove_ini(ptrno *L) {

    ptrno apaga=*L;

    if (*L==NULL) {

        return 0;
    }
    else {

        *L = (*L)->prox;
        free(apaga);
        return 1;
    }
}


//Função para remover no final da lista
int remove_fim(ptrno *L) {
    if (*L==NULL) {

        return 0;
    }
    else {

        ptrno apaga=*L;

        //Checa e age quando o último elemento da lista, que será removido, também é o primeiro elemento.
        if((*L)->prox == NULL) {

            free(apaga);
            (*L) = NULL;

            return 1;
        }

        while (apaga->prox->prox != NULL) {

            apaga = apaga->prox;
        }

        free(apaga->prox);
        apaga->prox = NULL;

        return 1;
    }
}


int main() {

    //declarando as variaveis necessárias para executar as funções
    int opcao = -1;
    int valorUsuario;
    ptrno lista = NULL;
    
    // Construindo a lista de opções do menu
    while (opcao !=0) {
        
        printf("\n1. Inserir um elemento no inicio");
        printf("\n2. Inserir um elemento no final");
        printf("\n3. Remover o elemento no inicio");
        printf("\n4. Remover o elemento no final");
        printf("\n5. Mostrar a lista atual");
        printf("\n0. Sair");
        printf("\nEscolha a opcao: ");
        scanf("%d",&opcao);

        // Definindo o que cada opção irá fazer
        switch (opcao){
                
            // Caso a opção escolhida seja 0- Sair
            case 0:
                {
                    printf("\nFIM");

                    break;
                }
                
            case 1: //Caso a opção escolhida for a 1, o usuario poderá inserir no inicio da lista
                {
                    printf("\nDigite um valor para inserir no inicio: ");
                    scanf(" %d", &valorUsuario);

                    insere_ini(&lista, valorUsuario);
                    printf("\nInserido no inicio.\n");

                    break;
                }
                
            case 2: //Caso a opção escolhida for a 2, o usuario poderá inserir no final da lista
                {
                    printf("\n Digite um valor para inserir no fim: ");
                    scanf(" %d", &valorUsuario);

                    insere_fim(&lista, valorUsuario);
                    printf("\nInserido no final.\n");

                    break;
                }
                
            /*Caso a opção escolhida for a 3, o programa fará uma verificação para saber se
            a lista está ou não vazia, caso ela esteja vazia, o programa emitirá uma menssagem avisando que ela está vazia.*/
            case 3:
                {
                    if (lista == NULL) {

                        printf("\nA lista está vazia.\n");
                        break;
                    }

                    remove_ini(&lista); //Caso ela não esteja vazia, o elemento no inicio da lista será removido.
                    printf("\nElemento do inicio da lista removido.\n");

                    break;
                }

            /*Caso a opção escolhida for a 4, o programa fará uma verificação para saber se
            a lista está ou não vazia, caso ela esteja vazia, o programa emitirá uma menssagem avisando que ela está vazia.*/
            case 4:
                {
                    if (lista == NULL) {
                        printf("\nA lista está vazia.\n");

                        break;
                    }

                    remove_fim(&lista); //Caso ela não esteja vazia, o elemento no final da lista será removido.
                    printf("\nElemento do fim da lista removido.\n");

                    break;
                }
                
            //Código para mostrar a lista atual
            case 5:
                {
                    if (lista == NULL) {
                        printf("\nLista vazia!\n");

                        break;
                    }

                    ptrno aux = lista;

                    while(aux != NULL) {

                        printf("\n%d", aux->num);
                        aux = aux->prox;
                    }

                    printf("\n");

                    break;
                }

            // Caso seja inserido qualquer caracter que não seja os pré-definidos no menu
            default: 
                printf("\n Opção inválida!\n");

        }

    }

    return 0;
}