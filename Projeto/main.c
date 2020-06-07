#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas/sistema.h"

int main(int argc, char ** argv){
    int escolha=0,id=0,qtdd_Itens=0,escolha_item=0,regiao_pedido=0;
    int jafoi=0;//flag para nao permitir gerar dados 2 vezes;

    Itens * I = inicializa_Itens();
    item itm;
    Pontos * ListaDePontos = NULL;

    escolha = Menu_principal();
    while(escolha!=6){

        switch(escolha){

    case 1:
        system("cls");
        if(jafoi!=1){
        gera_Info(&ListaDePontos);
        jafoi=1;
        printf("Dados gerados\n");
        }
        else
        printf("Ja gerou dados uma vez\n");
        system("pause");
        break;
    case 2:
        system("cls");
        Relatorio(ListaDePontos);
        break;
    case 3:
        system("cls");
        atende_pedido(ListaDePontos,ListaDePontos->P);
        break;
    case 4:
        system("cls");
        id=0;
        printf("Qual o id do pedido que deseja excluir?:");
        scanf("%d",&id);
        excluir_Pedido(ListaDePontos,id);//arrumar
        printf("Pedido [%d] excluido.",id);
        system("pause");
        break;

    case 5:
        imprime_Pontos_Simples(ListaDePontos);
        printf("\n\nem qual regiao deseja fazer o pedido?\n");
        printf("\n 1-centro\n 2-sul\n 3-leste\n 4-norte\n 5-oeste\n:");
        scanf("%d",&regiao_pedido);
        system("cls");
        ponto * PontoAtual = busca_Pontos(ListaDePontos,regiao_pedido);

        do{
        printf("Qual(ais) item(ns) deseja adicionar no pedido?");
        printf("\n1-Dog Xtudao\t\tPreco:20,00\n2-Dog Milhao\t\tPreco:15,00\n3-Doginho\t\tPreco:8,00\n4-Dog Tradicional\tPreco:13,50\n5-Podrao do Tio\t\tPreco:25,50\n6-voltar\n:");
        scanf("%d",&escolha_item);
        system("cls");
        if(escolha_item!=6){
        qtdd_Itens=0;
        printf("Quantos deste item?:");
        scanf("%d",&qtdd_Itens);
        }

        switch(escolha_item){
    case 1:

        itm = set_item("Dog Xtudao",qtdd_Itens,20,NULL);// cadastra o item itm
        push_item(I,itm);// manda o item para lista de item
        break;

    case 2:
        itm = set_item("Dog Milhao",qtdd_Itens,15,NULL);// cadastra o item itm
        push_item(I,itm);// manda o item para lista de item

        break;
    case 3:
        itm = set_item("Doginho",qtdd_Itens,8,NULL);// cadastra o item itm
        push_item(I,itm);// manda o item para lista de item

        break;
    case 4:
        itm = set_item("Dog Tradicional",qtdd_Itens,13.50,NULL);// cadastra o item itm
        push_item(I,itm);// manda o item para lista de item
        break;

    case 5:
        itm = set_item("Podrao do Tio",qtdd_Itens,25.50,NULL);// cadastra o item itm
        push_item(I,itm);// manda o item para lista de item
        break;

    case 6:
        CadastraPedido(PontoAtual,I);
        system("pause");
        break;
        }
        }while(escolha_item!=6);

        break;
        }
        escolha = Menu_principal();
    }

    return 0;

    libera_Pontos(ListaDePontos);
    return 0;

}
