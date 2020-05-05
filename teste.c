//Autor: Marco A.
#include <stdio.h>
#include <stdlib.h>
#include "items.h"

int main(int argc, char ** argv){
    //EXEMPLOS PARA biblioteca "items.h" ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ 
    //Primeiramente inicializa-se a variavel I, nossa PILHA de items
    Itens * I = inicializa_Itens(); /* O tipo de dado "Itens" é uma estrutura que 
                                    contém um ponteiro (*) para o TOPO da pilha! */
    
    //Como trata-se de uma pilha, vamos utilizar as funções "push_item" e "pop_item".

    //Vamos começar fazendo um push para a pilha,
    
    //Primeiramente, precisamos criar uma variavel contendo as informações desejadas!

    item variavel_item;
    /*Podemos configura-la na mão fazendo:
    strcpy(variavel_item.nome,"CACHORRO QUENTE");
    variavel_item.qntd = 3;
    variavel_item.v_unidade = 7.99;
    variavel_item.v_total = (variavel_item.v_unidade)*(variavel_item.v_unidade);
    strcpy(variavel_item.obs,"Sem mostarda, por favor...");
    
    OU, de maneira mais facil utilizar a funcao "set_item":             */
    variavel_item = set_item("CACHORRO QUENTE",3,7.99, NULL);
    //O ULTIMO PARAMETRO EH A OBSERVACAO, DEIXE NULL para NAO INCLUI-LA!
    //Esta funcao calcula automaticamente o v_total!
    printf("variavel_item.v_total=%.2f\n",variavel_item.v_total);

    //Agora basta fazermos o PUSH
    push_item(I,variavel_item);

    //Vamos imprimir para ver se está certo?
    imprime_Itens(I);
    printf("\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");

    //Funcionou! Agora vamos adicionar mais valores!
    variavel_item = set_item("Cachorro Quente Prensado",2,12.3,NULL);
    push_item(I,variavel_item);
    variavel_item = set_item("Dogao Tunado Gourmet",4,18,NULL);
    push_item(I,variavel_item);
    //Vamos imprimir para ver se está certo?
    imprime_Itens(I);
    printf("\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
    //Legal!  Agora vamos remover o ultimo item inserido (TOPO DA PILHA), fazer um POP!
    pop_item(I);
    //Vamos ver se funcionou? Vamos imprimir a pilha:
    imprime_Itens(I);
    printf("\n~ ~ ~Se vc reparar, o dogao tunado sumiu!! /\\~ ~ ~ ~ ~  ~ ~ ~ ~ ~ ~ ~ ~ \n\n\n");
    //Legal, funcionou... Mas e se eu quiser saber qual era a informacao que foi feita POP?
    //Eh simples, basta salvar em uma variavel do tipo "item"
    //OBS (NESSE MOMENTO, A INFO QUE ESTA NO TOPO DA LISTA EH A DO "Cachorro Quente Prensado")
    item var_salvacao;
    var_salvacao = pop_item(I);
    //Neste caso, estamos retirando o item do topo da lista e agora temos em maos suas informacoes
    
    printf("Informacoes salvas do POP:\n");
    printf("Nome: %s\n",var_salvacao.nome);
    printf("QNTD: %d\n",var_salvacao.qntd);
    printf("Valor Und: %.2f\n",var_salvacao.v_unidade);
    printf("Valor Total: %.2f\n",var_salvacao.v_total);

    printf("Podemos tambem editar essas informacoes e fazer um PUSH novamente para incluir na PILHA!\n");
    printf("Vamos editar o valor da unidade?\n");
    var_salvacao.v_unidade = 300.2;//Um pouco inflacionado por conta da crise...
    //Nao podemos esquecer de alterar tambem o total!
    var_salvacao.v_total = var_salvacao.qntd * var_salvacao.v_unidade;
    //Agora basta fazer um PUSH :-)
    push_item(I,var_salvacao);
    printf("\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
    //Vamos ver como ficou!
    printf("Vamos ver como ficou!\n");
    imprime_Itens(I);
    printf("\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
    
    //~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~


    libera_Itens(I); //sempre lembrar de liberar apos o uso!

    return 0;
}
