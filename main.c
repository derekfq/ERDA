#include <stdio.h>
#include <stdlib.h>
#include "Bibliotecas/sistema.h"

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
    imprime_Pontos(ListaDePontos);
    libera_Pontos(ListaDePontos);
    return 0;

}