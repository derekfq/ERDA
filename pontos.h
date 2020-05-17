#ifndef PONTOS_H_INCLUDED
#define PONTOS_H_INCLUDED
#include "pedidos.h"
/*ESTA BIBLIOTECA SOMENTE DEFINE A ESTRUTURA DOS PONTOS DE VENDA!! E IMPLEMENTA SEU 
FUNCIONAMENTO EM LISTA EH IMPORTANTE LEMBRAR QUE ELA NÃO IMPLEMENTA O FUNCIONAMENTO REAL 
DOS PONTOS NO SISTEMA (Ex: Cadastro).*/

typedef enum Exp {baixa=5 , media=3 , alta=2} Experiencia;

typedef struct ponto{
    Regiao regiao;
    Experiencia exp;
    unsigned long int pedidos_total; //quantidade total de pedidos
    float v_total_vendido; //valor total (em R$) que foi vendido
    Pedidos * P; // FILA DE PEDIDOS
    struct ponto * prox;
} Pontos;
typedef struct ponto ponto; //Pontos = ponto

Pontos * inicializa_Pontos (){
    return NULL;
}

/*void insere_inicio(Pontos ** L, ponto valor){
    Pontos * novo = (Pontos *) malloc(sizeof(Pontos));
    if(!*L){
        novo->regiao = valor.regiao;
        novo->exp = valor.exp;
        novo->pedidos_total = valor.pedidos_total;
        novo->v_total_vendido = valor.v_total_vendido;
        novo->P = valor.P;
        novo->prox = NULL;
        *L = novo;
    }
    else{
        novo->regiao = (*L)->regiao;
        novo->exp = (*L)->exp;
        novo->pedidos_total = (*L)->pedidos_total;
        novo->v_total_vendido = (*L)->v_total_vendido;
        novo->P = (*L)->P;
        novo->prox = (*L)->prox;

        (*L)->regiao = valor.regiao;
        (*L)->exp = valor.exp;
        (*L)->pedidos_total = valor.pedidos_total;
        (*L)->v_total_vendido = valor.v_total_vendido;
        (*L)->P = valor.P;
        (*L)->prox = novo;
    }
}*/


void insere_Ponto (Pontos ** L, ponto valor){//insere no fim
    Pontos * novo = (Pontos *) malloc(sizeof(Pontos));
    novo->regiao = valor.regiao;
    novo->exp = valor.exp;
    novo->pedidos_total = valor.pedidos_total;
    novo->v_total_vendido = valor.v_total_vendido;
    novo->P = valor.P;
    novo->prox = NULL;

    if(!*L){
        *L = novo;
    }
    else{
        Pontos * AUX;
        for(AUX=*L;AUX->prox;AUX=AUX->prox);
        AUX->prox=novo;
    }
}

void imprime_Pontos (Pontos* recebida){
    Pontos* p; /* variável auxiliar para percorrer a Pontos */
    for (p = recebida; p; p = p->prox){
        printf("Regiao: ");
        switch(p->regiao){
            case centro:
                printf("Centro\n");
                break;
            case sul:
                printf("Zona Sul\n");
                break;
            case leste:
                printf("Zona Leste\n");
                break;
            case norte:
                printf("Zona Norte\n");
                break;
            case oeste:
                printf("Zona Oeste\n");
                break;
            default:
                printf("?????\n");
                break;
        }
        printf("Experiencia de preparo: ");
        switch(p->exp){
            case alta:
                printf("Alta\n");
                break;
            case media:
                printf("Media\n");
                break;
            case baixa:
                printf("Baixa\n");
                break;
            default:
                printf("?????\n");
                break;
        }
        printf("Qntd. Total de Pedidos: %ld\n",p->pedidos_total);
        printf("Valor Total Vendido: R$ %.2f\n",p->v_total_vendido);
        printf("Fila de Pedidos: ");
        imprime_Pedidos(p->P);
    }
}

int vazia_Pontos (Pontos* recebida){
    if (recebida == NULL)
        return 1;
    else
        return 0;
}

//TALVEZ PRECISE IMPLEMENTAR FUNCAO DE BUSCA

void libera_Pontos(Pontos * L){
    Pontos * X=L, * RMV;
    while(X->prox){
        RMV=X;
        X=X->prox;
        free(RMV);
    }
}

#endif