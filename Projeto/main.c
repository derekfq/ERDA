#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas/sistema.h"

int main(int argc, char ** argv){
    Pontos * ListaDePontos = NULL;
    /*
    CadastraPonto(&ListaDePontos,norte,baixa);
    CadastraPonto(&ListaDePontos,sul,media);
    CadastraPonto(&ListaDePontos,leste,alta);
    CadastraPonto(&ListaDePontos,oeste,baixa);
    CadastraPonto(&ListaDePontos,centro,alta);*/

    gera_Info(&ListaDePontos);
    printf("\n\n\n\n");
    Relatorio(ListaDePontos);
   // imprime_Pontos(ListaDePontos);

    printf("\n\n\n\n\n\n\n\n\n");
    libera_Pontos(ListaDePontos);
    return 0;

}
