#ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED
#include "pontos.h"
/* BIBLIOTECA DE IMPLEMENTAÇÃO DO FUNCIONAMENTO DE TODAS AS FUNCIONALIDADES DO SISTEMA */

static unsigned long int GERADOR_ID = 0;//VALOR UNICO P/ CADA PEDIDO, GERA AUTOMATICAMENTE PELO SISTEMA
unsigned int gera_pedidoId() {
    GERADOR_ID++;
    return GERADOR_ID - 1;
}


/*Cadastra um Ponto inicialmente sem nenhuma informação sobre os pedidos,
tempo de entrega ou qualquer informação que depende dos pedidos e itens dos pedidos
que serão inseridos futuramente p/ aquele ponto.*/
//chamada: CadastraPonto(&P) // sendo Pontos * P
void CadastraPonto(Pontos** ListaDePontos, Regiao reg, Experiencia exp) {
    ponto novo;
    novo.regiao = reg;
    novo.exp = exp;
    novo.pedidos_total = 0;
    novo.v_total_vendido = 0.00;
    novo.P = inicializa_Pedidos();
    novo.prox = NULL;
    insere_Ponto(ListaDePontos, novo);
}

//-------------------------------------------------------------------------------------------
//DOING: 

//--- CADASTRAR PEDIDOS --------------------------------------
int TempoPedido(Itens* PilhaItens, int exp);
float ValorPedido(Itens* PilhaItens);

void CadastraPedido(ponto* Ponto, Itens* NovosItens) {
    pedido novo;
    novo.num = gera_pedidoId();
    novo.regiao = Ponto->regiao;
    novo.tempo = TempoPedido(NovosItens, Ponto->exp);//tempo para todos os itens do pedido
    novo.v_pedido = ValorPedido(NovosItens);//calcula valor total do pedido
    novo.I = NovosItens;
    novo.prox = NULL;
    //registrar Pedido na FILA de pedidos (DENTRO DO PONTO)
    insere_Pedidos(Ponto->P, novo);
    //atualizar total de pedidos do ponto
    Ponto->pedidos_total = Ponto->pedidos_total + 1;
    /*OBS: tempo = tempo de preparo do pedido individualmente
        na hora de imprimir info do pedido, eu dou o tempo de espera total
        (considerando ordem da fila e 15min da entrega) */
}

int TempoPedido(Itens* PilhaItens, int exp) { //PILHA
    int qntd_total = 0;
    Itens* AUX = inicializa_Itens();
    item x;
    while (!vazia_Itens(PilhaItens)) {
        x = pop_item(PilhaItens);
        qntd_total += x.qntd;
        push_item(AUX, x);
    }
    while (!vazia_Itens(AUX)) {
        push_item(PilhaItens, pop_item(AUX));
    }
    libera_Itens(AUX);
    return qntd_total * exp + 5;
}
float ValorPedido(Itens* PilhaItens) { //PILHA
    float valor_pedido = 0;
    Itens* AUX = inicializa_Itens();
    item x;
    while (!vazia_Itens(PilhaItens)) {
        x = pop_item(PilhaItens);
        x.v_total = x.qntd * x.v_unidade; //coisa de noia
        valor_pedido += x.v_total;
        push_item(AUX, x);
    }
    while (!vazia_Itens(AUX)) {
        push_item(PilhaItens, pop_item(AUX));
    }
    libera_Itens(AUX);
    return valor_pedido;
}

//-----------------------------------------------------------

//Atender Pedido
void Atende_Pedido(int id, ponto* ponto) {
    //Pedidos* Pedidos

    pedido auxInfo;
    Pedidos* aux = inicializa_Pedidos();
    aux = ponto->P;

    while (!vazia_Pedidos(ponto->P)){

        auxInfo = retira_Pedidos(ponto->P);
        if (auxInfo.num == id){

            printf("Pedido #%d\n", auxInfo.num);
            printf("Regiao: ");
            switch (auxInfo.regiao) {
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
            printf("Tempo de Entrega: %d\n", GetTempoEspera(ponto->P, auxInfo.num));
            //printf("Valor do Pedido: R$%.2f\n", aux->v_pedido);
            imprime_Itens(auxInfo.I);

            ponto->v_total_vendido += auxInfo.v_pedido;

            excluir_Pedido(ponto->P, id);
        }
    }

    while (!vazia_Pedidos(aux))
    {
        auxInfo = retira_Pedidos(aux);
        insere_Pedidos(ponto->P, auxInfo);
    }


}


#endif
