#ifndef PONTOS_H_INCLUDED
#define PONTOS_H_INCLUDED
#include "pedidos.h"
/*ESTA BIBLIOTECA SOMENTE DEFINE A ESTRUTURA DOS PONTOS DE VENDA!! E IMPLEMENTA SEU
FUNCIONAMENTO EM LISTA EH IMPORTANTE LEMBRAR QUE ELA NÃO IMPLEMENTA O FUNCIONAMENTO REAL
DOS PONTOS NO SISTEMA (Ex: Cadastro).*/

//typedef enum  Exp { baixa = 5, media = 3, alta = 2 } Experiencia;

typedef struct ponto {
    int regiao;
    int exp;
    unsigned long int pedidos_total; //quantidade total de pedidos
    float v_total_vendido; //valor total (em R$) que foi vendido
    Pedidos* P; // FILA DE PEDIDOS
    struct ponto* prox;
} Pontos;
typedef struct ponto ponto; //Pontos = ponto

Pontos* inicializa_Pontos() {
    return NULL;
}

void insere_Ponto(Pontos** L, ponto valor) {//insere no fim
    Pontos* novo = (Pontos*)malloc(sizeof(Pontos));
    novo->regiao = valor.regiao;
    novo->exp = valor.exp;
    novo->pedidos_total = valor.pedidos_total;
    novo->v_total_vendido = valor.v_total_vendido;
    novo->P = valor.P;
    novo->prox = NULL;

    if (!*L) {
        *L = novo;
    }
    else {
        Pontos* AUX;
        for (AUX = *L; AUX->prox; AUX = AUX->prox);
        AUX->prox = novo;
    }
}

void imprime_Pontos(Pontos* recebida) {
    Pontos* p; /* variável auxiliar para percorrer a Pontos */
    for (p = recebida; p; p = p->prox) {
        printf("//////////////////////////////////////////////////////////////////////////\n");
        printf("Regiao: ");
        switch (p->regiao) {
        case 1:
            printf("Centro\n");
            break;
        case 2:
            printf("Zona Sul\n");
            break;
        case 3:
            printf("Zona Leste\n");
            break;
        case 4:
            printf("Zona Norte\n");
            break;
        case 5:
            printf("Zona Oeste\n");
            break;
        default:
            printf("?????\n");
            break;
        }
        printf("Experiencia de preparo: ");
        switch (p->exp) {
        case 2:
            printf("Alta\n");
            break;
        case 3:
            printf("Media\n");
            break;
        case 5:
            printf("Baixa\n");
            break;
        default:
            printf("?????\n");
            break;
        }
        printf("Qntd. Total de Pedidos: %ld\n", p->pedidos_total);
        printf("Valor Total Vendido: R$ %.2f\n", p->v_total_vendido);
        printf("Fila de Pedidos: ");
        printf("\n\n%x", p->P->ini->I);
        imprime_Pedidos(p->P);
    }
}

int vazia_Pontos(Pontos* recebida) {
    if (recebida == NULL)
        return 1;
    else
        return 0;
}

//BUSCA PONTO POR REGIAO
ponto* busca_Pontos(Pontos* ListaDePontos, int reg) {
    ponto* p;
    for (p = ListaDePontos; p; p = p->prox) {
        if (p->regiao == reg)
            return p;
    }
    return NULL;
}

void libera_Pontos(Pontos* L) {
    Pontos* X = L, * RMV;
    while (X->prox) {
        RMV = X;
        X = X->prox;
        free(RMV);
    }
}

#endif