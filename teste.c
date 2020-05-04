#include <stdio.h>
#include <stdlib.h>
#include "items.h"

int main(int argc, char ** argv){
    Itens * I = inicializa_Itens();
    item * i = novo_item("cachorro quente", 2, 11.2);
    push_item(I,i);
    i = novo_item("cachorro quente tunado", 1, 15.99);
    push_item(I,i);
    i = novo_item_obs("cachorro quente presenado", 420, 4.20, "MACONHEIROS, CAPRICHAR NA MAIONESE POR FAVOR.");
    push_item(I,i);

    imprime_Itens(I);
    free(pop_item(I));
    imprime_Itens(I);
    libera_Itens(I);

    return 0;
}
