#ifndef ITEMS_H_INCLUDED
#define ITEMS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item{
    char nome[64];          //item: descricao do produto
    unsigned short qntd;    //quantidade
    float v_unidade;        //valor da unidade em R$
    float v_total;          //valor total do item do pedido em R$
    char obs[256];          //campo nao obrigatorio
    struct item * prox;            //ponteiro para proxima pilha
} item;

typedef struct itens{
    item * prim;
} Itens; //contem vetor de item

Itens * inicializa_Itens (){
    Itens * i;
    i=(Itens*)malloc(sizeof(Itens));
    i->prim = NULL;
    return i;
}

item * novo_item(char nome[64], unsigned short qntd, float valor_unidade){
    item * aux = (item *) malloc(sizeof(item));
    strcpy(aux->nome,nome);
    aux->qntd = qntd;
    aux->v_unidade = valor_unidade;
    aux->v_total = valor_unidade * qntd;
    aux->obs[0] = '\0';
    aux->prox = NULL;
    return aux;
}

item * novo_item_obs(char nome[64], unsigned short qntd, float valor_unidade, char obs[256]){
    item * aux = (item *) malloc(sizeof(item));
    strcpy(aux->nome,nome);
    aux->qntd = qntd;
    aux->v_unidade = valor_unidade;
    aux->v_total = valor_unidade * qntd;
    strcpy(aux->obs,obs);
    aux->prox = NULL;
    return aux;
}

void push_item(Itens * I, item * add){
    add->prox = I->prim;
    I->prim = add;
}

item * pop_item(Itens * I){
    if(!I){
        printf("Pilha de Itens VAZIA.\n");
        exit(1);
    }
    item * pop = I->prim;
    I->prim = I->prim->prox;
    return pop;
}

int vazia_Itens(Itens * I){
    if (!I->prim)
        return 1; //pilha vazia
    return 0;
}

void libera_Itens(Itens * I){
    item * i = I->prim, * tmp;
    while(i){
        tmp = i->prox;
        free(i);
        i = tmp;
    }
    free(I);
    return;
}

void imprime_Itens(Itens * I){
    if(!I->prim)
        printf("\n[Pilha de Itens]: VAZIA!\n");
    else{
        printf("\n[Pilha de Itens]: <TOPO> **********\n");
        item * x;
        for(x=I->prim;x;x=x->prox){
            printf("Nome : %s\n",x->nome);
            printf("Qtd. : x%d\n",x->qntd);
            printf("Und. : R$ %.2f\n",x->v_unidade);
            if(x->obs[0]!='\0')
            printf("OBS* : %s\n",x->obs);
            printf("Total: R$ %.2f\n",x->v_total);
            
            
            printf("***********************************\n");
        }
    }
}

#endif