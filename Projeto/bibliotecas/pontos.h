#ifndef PONTOS_H_INCLUDED
#define PONTOS_H_INCLUDED
#include "pedidos.h"
/*ESTA BIBLIOTECA SOMENTE DEFINE A ESTRUTURA DOS PONTOS DE VENDA!! E IMPLEMENTA SEU
FUNCIONAMENTO EM LISTA EH IMPORTANTE LEMBRAR QUE ELA NÃO IMPLEMENTA O FUNCIONAMENTO REAL
DOS PONTOS NO SISTEMA (Ex: Cadastro).*/

typedef enum Exp { baixa = 5, media = 3, alta = 2 } Experiencia;

typedef struct ponto {
    Regiao regiao;                      //controla a região do ponto(centro, sul, leste, norte, oeste)
    Experiencia exp;                    //controla a experiencia do ponto(baixa, media, alta)
    unsigned long int pedidos_total;    //quantidade total de pedidos
    float v_total_vendido;              //valor total (em R$) que foi vendido
    Pedidos* P;                         // FILA DE PEDIDOS
    struct ponto* prox;                 
} Pontos;
typedef struct ponto ponto; //Pontos = ponto

// Funcao que inicializa a lista
Pontos* inicializa_Pontos() {
    return NULL;
}

//  Função que insere o ponto na lista com toda a struct de pedidos
void insere_Ponto(Pontos** L, ponto valor) {//insere no fim
    Pontos* novo = (Pontos*)malloc(sizeof(Pontos));
    novo->regiao = valor.regiao;
    novo->exp = valor.exp;
    novo->pedidos_total = valor.pedidos_total;
    novo->v_total_vendido = valor.v_total_vendido;
    novo->P = valor.P;
    novo->prox = NULL; //todas as informações foram passadas para esse novo ponto

    if (!*L) {
        *L = novo;
    }
    else {
        Pontos* AUX;
        for (AUX = *L; AUX->prox; AUX = AUX->prox);
        AUX->prox = novo;
    }
}

// Funcao que percorre a lista, imprimindo todos os valores de todos os pontos
void imprime_Pontos(Pontos* recebida) {
    Pontos* p; /* variável auxiliar para percorrer a Pontos */
    for (p = recebida; p; p = p->prox) {
        printf("//////////////////////////////////////////////////////////////////////////\n");
        printf("Regiao: ");
        switch (p->regiao) {
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
        default:    //se algo tiver errado
            printf("?????\n");
            break;
        }
        printf("Experiencia de preparo: ");
        switch (p->exp) {
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
        printf("Qntd. Total de Pedidos: %ld\n", p->pedidos_total);
        printf("Valor Total Vendido: R$ %.2f\n", p->v_total_vendido);
        printf("Fila de Pedidos: ");
        imprime_Pedidos(p->P);
    }
}

// Funcao que verifica se a lista de pontos está vazia
int vazia_Pontos(Pontos* recebida) {
    if (recebida == NULL)
        return 1;
    else
        return 0;
}

//  Busca o ponto, passando região como parametro
ponto* busca_Pontos(Pontos* ListaDePontos, Regiao reg) {
    ponto* p;
    for (p = ListaDePontos; p; p = p->prox) {
        if (p->regiao == reg)
            return p;
    }
    return NULL;
}

// Funcao que percorre a lista, e libera memoria (free)
void libera_Pontos(Pontos* L) {
    Pontos* X = L, * RMV;
    while (X->prox) {
        RMV = X;
        X = X->prox;
        free(RMV);
    }
}

#endif
