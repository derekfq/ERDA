#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas/sistema.h"

int main(int argc, char ** argv){
    Pontos * ListaDePontos = NULL;
    /*OBS: Vão existir no maximo 5 pontos, um para cada regiao.
    Senão da conflituo, isso foi conversado com a patricia.*/
    CadastraPonto(&ListaDePontos,norte,baixa);
    CadastraPonto(&ListaDePontos,sul,media);
    CadastraPonto(&ListaDePontos,leste,alta);
    CadastraPonto(&ListaDePontos,oeste,baixa);
    CadastraPonto(&ListaDePontos,centro,alta);
    //NÃO CADASTREM MAIS DE 5 PONTOS!!!
    //imprime_Pontos(ListaDePontos);

    Itens * I = inicializa_Itens();
    item itm = set_item("Cachorro Quente", 2, 15.00, "Sem picles, por favor! :-) Obrigado.");
    push_item(I,itm);
    itm = set_item("Xturbo", 1, 30.00, NULL);
    push_item(I,itm);

    CadastraPedido(ListaDePontos, I);
    //Valor Total Vendido do Ponto so sera escrito no momento de atendimento dos pedidos
    imprime_Pontos(ListaDePontos);





    libera_Pontos(ListaDePontos);
    return 0;

}
