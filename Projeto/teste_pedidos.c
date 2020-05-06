//Autor: Marco A.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecas/pedidos.h"

int main(int argc, char ** argv){
    Pedidos * P = inicializa_Pedidos();
    pedido p;
    p.num = 0;
    p.regiao = centro;
    p.tempo_entrega = 20;
    p.v_pedido = 60;
    p.I = inicializa_Itens();
    item itm = set_item("Cachorro Quente", 2, 15.00, "Sem picles, por favor! :-) Obrigado.");
    push_item(p.I,itm);
    itm = set_item("Xturbo", 1, 30.00, NULL);
    push_item(p.I,itm);
    insere_Pedidos(P, p);
    imprime_Pedidos(P);
    item retirado = pop_item(p.I);
    strcpy(retirado.nome,(char*)"Xturbo GIGANTESCO");
    /*ATENCAO A MANIPULACAO MANUAL DO PEDIDO E SEUS ITENS NAO EH RECOMENDADA,
    esta sendo feita aqui pois a biblioteca sistema.h AINDA não está pronta,
    então esta foi a forma que encontrei de testar!!!! NÃO RECOMENDO !!!
    POIS EH MT FACIL COMETER UM EQUIVOCO!!! irei desenvolver uma forma mais segura..
    */
    retira_Pedidos(P);
    imprime_Pedidos(P);// IMPRIMO FILA DE PEDIDOS VAZIA
    retirado.v_total = retirado.v_unidade = 38.99;
    p.v_pedido = 2*15.00 + 38.99;
    push_item(p.I,retirado);
    p.num = 1;
    insere_Pedidos(P, p);
    imprime_Pedidos(P);// IMPRIMO A FILA DE PEDIDOS COM O MEU NOVO PEDIDO!
    libera_Pedidos(P);
    return 0;
}