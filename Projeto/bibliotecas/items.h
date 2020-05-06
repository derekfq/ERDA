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
    struct item * prox;     //ponteiro para proxima pilha
} item;

typedef struct itens{
    item * topo;
} Itens; //contem vetor de item

// Funcao que inicializa 
Itens * inicializa_Itens (){
    Itens * i;
    i=(Itens*)malloc(sizeof(Itens));
    i->topo = NULL;
    return i;
}

item set_item(const char nome[64], unsigned short qntd, float valor_unidade, const char obs[256]){
    item ret;
    strcpy(ret.nome,nome);
    ret.qntd=qntd;
    ret.v_unidade=valor_unidade;
    ret.v_total=valor_unidade*qntd;
    if(obs)
        strcpy(ret.obs,obs);
    else
        memset(ret.obs,'\0',256);
    ret.prox = NULL;
    return ret;
}

void push_item(Itens * I, item info){
    item * aux = (item *) malloc(sizeof(item));
    strcpy(aux->nome,info.nome);
    aux->qntd = info.qntd;
    aux->v_unidade = info.v_unidade;
    aux->v_total = info.v_total;
    strcpy(aux->obs,info.obs);
    aux->prox = NULL;
    aux->prox = I->topo;
    I->topo = aux;
}

item pop_item(Itens * I){
    if(!I){
        printf("Pilha de Itens VAZIA.\n");
        exit(1);
    }
    item ret;
    strcpy(ret.nome,I->topo->nome);
    ret.qntd=I->topo->qntd;
    ret.v_unidade = I->topo->v_unidade;
    ret.v_total = I->topo->v_total;
    strcpy(ret.obs,I->topo->obs);
    ret.prox = NULL;
    item * tmp = I->topo->prox;
    free(I->topo);
    I->topo = tmp;
    return ret;
}

int vazia_Itens(Itens * I){
    if (!I->topo)
        return 1; //pilha vazia
    return 0;
}

void libera_Itens(Itens * I){
    item * i = I->topo, * tmp;
    while(i){
        tmp = i->prox;
        free(i);
        i = tmp;
    }
    free(I);
    return;
}

void imprime_Itens(Itens * I){
    if(!I->topo)
        printf("\n[Pilha de Itens]: VAZIA!\n");
    else{
        printf("\n[Pilha de Itens]: <TOPO> **********\n");
        item * x;
        for(x=I->topo;x;x=x->prox){
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
