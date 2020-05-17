#ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED
#include "pontos.h"
/* BIBLIOTECA DE IMPLEMENTAÇÃO DO FUNCIONAMENTO DE TODAS AS FUNCIONALIDADES DO SISTEMA */

static unsigned long int GERADOR_ID = 0;//VALOR UNICO P/ CADA PEDIDO, GERA AUTOMATICAMENTE PELO SISTEMA
unsigned int gera_pedidoId(){
    GERADOR_ID++;
    return GERADOR_ID-1;
}


    /*Cadastra um Ponto inicialmente sem nenhuma informação sobre os pedidos,
    tempo de entrega ou qualquer informação que depende dos pedidos e itens dos pedidos
    que serão inseridos futuramente p/ aquele ponto.*/
//chamada: CadastraPonto(&P) // sendo Pontos * P
void CadastraPonto(Pontos ** ListaDePontos, Regiao reg, Experiencia exp){
    ponto novo;
    novo.regiao = reg;
    novo.exp = exp;
    novo.pedidos_total = 0;
    novo.v_total_vendido = 0.00;
    novo.P = inicializa_Pedidos();
    novo.prox = NULL;
    insere_Ponto(ListaDePontos, novo);
}

void LiberaSistema(Pontos * ListaDePontos){

}


//cadastrar ponto (LISTA) [adicao, busca]
//cadastra pedido (FILA / PILHA): 
    //calcula tempo de entrega do pedido
    //calcula valor total do pedido (valor total dos items tem q ta certo)

#endif