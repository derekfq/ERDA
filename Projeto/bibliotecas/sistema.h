#ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED
#include "pontos.h"
#include <time.h>
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

//-------------------------------------------------------------------------------------------
//DOING:

//--- CADASTRAR PEDIDOS --------------------------------------
int TempoPedido(Itens * PilhaItens, int exp);
float ValorPedido(Itens * PilhaItens);

void CadastraPedido(ponto * Ponto, Itens * NovosItens){
    //PRECISO INSERIR NO FIM
    pedido novo;
    novo.num = gera_pedidoId();
    novo.regiao = Ponto->regiao;
    novo.tempo = TempoPedido(NovosItens, Ponto->exp);//tempo para todos os itens do pedido
    novo.v_pedido = ValorPedido(NovosItens);//calcula valor total do pedido
    novo.I = NovosItens;
    novo.prox = NULL;
    //registrar Pedido na FILA de pedidos (DENTRO DO PONTO)
    insere_Pedidos(Ponto->P,novo);
    //atualizar total de pedidos do ponto
    Ponto->pedidos_total = Ponto->pedidos_total + 1;
    /*OBS: tempo = tempo de preparo do pedido individualmente
        na hora de imprimir info do pedido, eu dou o tempo de espera total
        (considerando ordem da fila e 15min da entrega) */
}

int TempoPedido(Itens * PilhaItens, int exp){ //PILHA
    int qntd_total = 0;
    Itens * AUX = inicializa_Itens();
    item x;
    while(!vazia_Itens(PilhaItens)){
        x = pop_item(PilhaItens);
        qntd_total += x.qntd;
        push_item(AUX,x);
    }
    while(!vazia_Itens(AUX)){
        push_item(PilhaItens,pop_item(AUX));
    }
    libera_Itens(AUX);
    return qntd_total*exp + 5;
}
float ValorPedido(Itens * PilhaItens){ //PILHA
    float valor_pedido = 0;
    Itens * AUX = inicializa_Itens();
    item x;
    while(!vazia_Itens(PilhaItens)){
        x = pop_item(PilhaItens);
        x.v_total = x.qntd*x.v_unidade; //coisa de noia
        valor_pedido += x.v_total;
        push_item(AUX,x);
    }
    while(!vazia_Itens(AUX)){
        push_item(PilhaItens,pop_item(AUX));
    }
    libera_Itens(AUX);
    return valor_pedido;
}


void gera_Info(Pontos ** ListaDePontos)
{
////Ponto
    int i,contador=0,ja_Tem;
    int regioes[5],num_Exp[3]={2,3,5};
    int qtdd_Pontos=0,exp=0,regiao=0;
////Pedido
    int j;
    int qtdd_Pedidos=0;
////
////Item
    Itens * I;
    item itm;
    int k,qtdd_Itens=0,valor_Int=0,num_nome_Item=0,qtdd_Itens_Pedido=0;
    float valor_Unitario=0;
    char nomes_itens_Aux[5][20]={"Dog Xtudao","Dog Milhao","Doginho","Dog Tradicional","Podrao do Tio"};
    char nomes_itens[5][20];
////

    srand(time(NULL));
//quantidade de pontos e de itens que serao gerados
    qtdd_Pontos = 3 + rand() % 3 ;// de 3 a 7

    //Verificador para os numeros aleatorios nao serem repetidsos
    while(contador<5){
        ja_Tem=0;
        regiao = 1 + rand () % 5 ;

        for(i=0;i<5;i++)
        {
            if(regiao==regioes[i])
            {
                ja_Tem=1;
            }
        }

        if(ja_Tem==0)
        {
            regioes[contador]=regiao;
            contador++;
        }
    }
    //REGIOES OK

    //gera os pontos com regiao(sem repetir) e experiencia aleatorios
    for(i=0;i<qtdd_Pontos;i++)
    {//PARA CADA PONTO
        printf("CADASTRANDO PONTO i=%d\n",i);
        exp = rand() % 3 ; // gera o numero de experiencia de 0 a 2, num_Exp possui os numeros 2 3 e 5
        CadastraPonto(ListaDePontos,regioes[i],num_Exp[exp]);
        printf("\nPONTO CADASTRADO\n");

        //QUANTOS PEDIDOS NAQUELE PONTO SERAO CADASTRADOS
        

        qtdd_Pedidos= 5 + rand() % 11;// de 5 a 15
        for(j=0;j<qtdd_Pedidos;j++) //FOR PARA CADA PEDIDO
        {
            I = inicializa_Itens();
            qtdd_Itens_Pedido = 1 + rand() % 5;//QUANTOS ITENS DAQUELE PEDIDO
            for (k=0;k<5;k++)// zera a matriz de nomes
            {
                memset(nomes_itens[k],'\0',20);
            }
            contador=0;
            while(contador<5)// verifica para nao repetir nome dos produtos
            {
                ja_Tem=0;
                char nome[20];
                num_nome_Item = rand() %5;// de 0 a 4
                strcpy(nome,nomes_itens_Aux[num_nome_Item]);

                for(k=0;k<5;k++)
                {
                    if(strcmp(nome,nomes_itens[k])==0)
                    {
                        ja_Tem=1;
                    }
                }

                if(ja_Tem==0)
                {
                strcpy(nomes_itens[contador],nome);
                contador++;
                }
            }
            //DEFINE CADA ITEM DO PEDIDO
            for(k=0;k<qtdd_Itens_Pedido;k++)
                {
                    qtdd_Itens = 1 + rand() % 5;
                    valor_Int= 100+ rand()%51; //valor unitario em int
                    valor_Unitario=(float)valor_Int/10;// valor convertido em float
                    itm = set_item(nomes_itens[k],qtdd_Itens,valor_Unitario,NULL);// cadastra o item itm
                    push_item(I,itm);// manda o item para lista de item
                }

        ponto * PontoAtual = busca_Pontos(*ListaDePontos,regioes[i]);
        CadastraPedido(PontoAtual,I);//manda a lista de itens para o pedido do ponto
        printf("xD PEDIDO (j=%d) CADASTRADO!\n",j);
        
        }
        printf("////////////////////////////////////////////////\n");
    }
}


//-----------------------------------------------------------

#endif