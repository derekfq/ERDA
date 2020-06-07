#ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED
#include <windows.h>
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


void gera_Info(Pontos ** ListaDePontos){


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
    qtdd_Pontos = 3 + rand() % 3 ;// de 3 a 5

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
        exp = rand() % 3 ; // gera o numero de experiencia de 0 a 2, num_Exp possui os numeros 2 3 e 5
        CadastraPonto(ListaDePontos,regioes[i],num_Exp[exp]);

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
        CadastraPedido(PontoAtual,I);//manda a lista de itens para o pedido do ponto;
        }
    }
}
void imprime_Pontos_Simples(Pontos* recebida){
Pontos*p;
for (p = recebida; p; p = p->prox){
    printf("\n");
        printf("Regiao: ");
        switch(p->regiao){
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
        printf("Experiencia de preparo: ");
        switch(p->exp){
            case alta:
                printf("Alta\n");
                break;
            case media:
                printf("Media\n");
                break;
            case baixa:
                printf("Baixa\n");
                break;
            default:
                printf("?????\n");
                break;
        }
        printf("Qntd. Total de Pedidos: %ld\n",p->pedidos_total);
        printf("Valor Total Vendido: R$ %.2f\n",p->v_total_vendido);
    }

}

void imprime_Pedidos_ponto(Pedidos * P){

    system("cls");

    pedido * aux;
    for(aux=P->ini;aux;aux=aux->prox){
        printf("Pedido #%d\n",aux->num);
        printf("Regiao: ");
        switch(aux->regiao){
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
        printf("Tempo de Entrega: %d\n",GetTempoEspera(P,aux->num));
        printf("Valor do Pedido: R$%.2f\n",aux->v_pedido);
        imprime_Itens(aux->I);
        printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
    }





}

void imprime_Pedido_Escolha(Pontos * recebida,int id){

    Pontos* p;
    Pedidos * Paux;

    for (p = recebida; p; p = p->prox){
    pedido * aux;
    printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
    Paux=p->P;
    for(aux=Paux->ini;aux;aux=aux->prox){

        if(aux->num==id){
        printf("Pedido #%d\n",aux->num);
        printf("Regiao: ");
        switch(aux->regiao){
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
        printf("Tempo de Entrega: %d\n",GetTempoEspera(Paux,aux->num));
        printf("Valor do Pedido: R$%.2f\n",aux->v_pedido);
        imprime_Itens(aux->I);
        printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
    }
}

    }
}

void Relatorio(Pontos* recebida){
    int escolha=0,reg,id=0;
    char continuar;
    ponto * PontoAtual;
   // Pontos* p;  variável auxiliar para percorrer a Pontos
   do{
        system("cls");
    do{
    system("cls");
    printf("\n\n\n\n");
    printf("\tRelatorio\n\n");
    printf(" 1-Listar pontos\n 2-Listar pedidos de um ponto\n 3-Procurar pedido\n 4-Voltar\n\n escolha:");
    scanf("%d",&escolha);
    }while(escolha!=1&&escolha!=2&&escolha!=3&&escolha!=4);

    switch(escolha){
        case 1:
            system("cls");
        imprime_Pontos_Simples(recebida);
        system("pause");
            break;

        case 2:
            do{

            do{
        reg=0;
        system("cls");
        printf("De qual regiao voce deseja ver os pedidos?");
        printf("\n1-centro\n2-sul\n3-leste\n4-norte\n5-oeste\n:");
        scanf("%d",&reg);
        if(reg!=1&&reg!=2&&reg!=3&&reg!=4&&reg!=5)
        {
         printf("Regiao invalida.\n");
         system("pause");
        }
            }while(reg!=1&&reg!=2&&reg!=3&&reg!=4&&reg!=5);
        PontoAtual = busca_Pontos(recebida,reg);
        imprime_Pedidos_ponto(PontoAtual->P);
         system("pause");
            do{
                printf("\n\nDeseja ver os pedidos de outra regiao?<s/n>\n:");
                scanf("%c",&continuar);
                system("cls");
                }while(continuar!='s'&&continuar!='n');
            }while(continuar!='n');
            break;

        case 3:
            do{
                id=0;
                system("cls");
                printf("Qual pedido deseja consultar?: ");
                scanf("%d",&id);

                imprime_Pedido_Escolha(recebida,id);
                system("pause");
                do{
                    printf("\n\nDeseja procurar outro item?<s/n>\n:");
                    scanf("%c",&continuar);
                    system("cls");
                }while(continuar!='s'&&continuar!='n');
            }while(continuar!='n');

            break;

        default:
            break;
    }
   }    while(escolha!=4);



}

int Menu_principal(){



    int escolha;
    do
    {
        system("cls");
        escolha = 0;
        printf("\n");
        printf("\t\t\t\t|--------------|\n");
        printf("\t\t\t\t|Menu Principal|\n");
        printf("\t\t\t\t|--------------|\n");
        printf("\n\n\n");
        printf("\t 1 =Gerar informacoes(Pontos,Pedidos,Itens)\n");
        printf("\t 2 =Relatorios\n");
        printf("\t 3 =Atender Pedido\n");
        printf("\t 4 =Cancelar pedido\n");
        printf("\t 5 =Fazer Pedido\n");
        printf("\t 6 =Sair\n");
        printf("\n\n\t :");
        scanf("%d",&escolha);

        if(escolha < 1 || escolha > 6)
        {
            MessageBox(NULL,"  Opcao invalida  ", " << ERRO >>", MB_ICONEXCLAMATION);
            fflush(stdin);
        }
    }
    while(escolha < 1 || escolha > 6);
    system("cls");
    return escolha;
}
void excluir_Pedido(Pontos* recebida,int id)//
{
    Pedidos*Pedidos_Carrinho;
    Pontos* p;
    Pedidos * auxPedidos = inicializa_Pedidos();
    pedido  auxInfo ;

for (p = recebida; p; p = p->prox){
        Pedidos_Carrinho=p->P;

    while(!vazia_Pedidos(Pedidos_Carrinho))
     {
        auxInfo=retira_Pedidos(Pedidos_Carrinho);
        printf("%d-",auxInfo.num);
        if(auxInfo.num!=id)
        {
            insere_Pedidos(auxPedidos,auxInfo);
        }
     }

         while(!vazia_Pedidos(auxPedidos))
     {
        auxInfo=retira_Pedidos(auxPedidos);
        insere_Pedidos(Pedidos_Carrinho,auxInfo);
     }

}
}

void atende_pedido(Pontos*recebida,Pedidos * P){
    pedido ret;
    Pontos* p;
    ret=retira_Pedidos(P);

    printf("Pedido #%d\n",ret.num);
        printf("Regiao: ");
        switch(ret.regiao){
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
        printf("Tempo de Entrega: %d\n",GetTempoEspera(P,ret.num));
        printf("Valor do Pedido: R$%.2f\n",ret.v_pedido);
        imprime_Itens(ret.I);
        printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");

    system("pause");
    for (p = recebida; p; p = p->prox){

    if(ret.regiao==p->regiao)
        p->v_total_vendido+=ret.v_pedido;
    }

}


//-----------------------------------------------------------

#endif
