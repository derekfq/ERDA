# Projeto: Delivery de Hot Dog

## CRONOGRAMA
**(10/05)** Etapa 1 - Bibliotecas items.h & pedidos.h (ver: item 2 e 3).

**(17/05)** Etapa 2 - Biblioteca pontos.h , programa principal (sistema.h) e permitir cadastrar ponto (ver: item 4).

**(24/05)** Etapa 3 - (sistema.h) ->> cadastrar pedido (ver: item 5), atender pedido (ver: item 6), cancelar pedido (ver: item 7).

**(31/05)** Etapa 4 - Gerar dados (ver: item 9).

**(07/06)** Etapa 5 - Relatórios (ver: item 8).

**(14/06)** Etapa 6 - Apresentação deixar preparada 100%.

*(OBS: o limite de entrega das Etapas é às 23h59 do dia programado)*


## MANUAL BIBLIOTECAS:

### Biblioteca "items.h"        -   (Implementação de PILHAS para registro dos Itens).
#### Estrutura de dados:
```c
typedef struct item{
    char nome[64];          //item: descricao do produto
    unsigned short qntd;    //quantidade
    float v_unidade;        //valor da unidade em R$
    float v_total;          //valor total do item do pedido em R$
    char obs[256];          //campo nao obrigatorio
    struct item * prox;     //ponteiro para proxima pilha
} item;

typedef struct itens{
    item * topo;
} Itens; //contem vetor de item
```


### Funções:
> ```c
>Itens * inicializa_Itens ()
>```
***Descrição:** Inicializa a PILHA de Itens em um ponteiro do tipo **Itens**, alocando em memória.
ATENÇÃO, caso o espaço em memória que foi alocado sua PILHA de Itens não seja mais utilizado dentro do programa, é preciso liberar este de forma manual, usando: **libera_Itens(Itens * I)**.*


> ```c
>item set_item(const char nome[64], unsigned short qntd, float valor_unidade, char obs[256])
>```
***Descrição:** Edita os valores duma variavel do tipo item, para facilitar o manuseio, v_total é calculado automaticamente.
O campo *char obs[256]* deve ser = **NULL** caso não necessário!*


> ```c
>void push_item(Itens * I, item info)
>```
***Descrição:** Faz um push das informações contidas em **info** para a PILHA de Itens **I**.*


> ```c
>item pop_item(Itens * I)
>```
***Descrição:** Faz um pop da PILHA de Itens **I**. RETORNA: Valor do **item** no topo da PILHA **I**.*


> ```c
>int vazia_Itens(Itens * I)
>```
***Descrição:** Verifica se a PILHA de Itens *I* está vazia. RETORNO: 1 = vazia / 0 = não vazia.*


> ```c
>void libera_Itens(Itens * I)
>```
***Descrição:** Faz um free em todos os espaços de memória envolvidos na estrutura **I**, liberando esta memória.*


> ```c
>void imprime_Itens(Itens * I)
>```
***Descrição:** Faz a impressão da PILHA de Itens **I**, começando pelo TOPO.*

--------------------------------------------------------------------------------------------------------------------

### Biblioteca "pedidos.h"      -   (Implementação de FILAS para registro dos Pedidos).
#### Estrutura de dados:
```c
typedef enum Reg {centro=1, sul=2, leste=3, norte=4, oeste=5} Regiao;

typedef struct pedido{
    unsigned int num; //id do pedido
    Regiao regiao; //regiao do pedido
    unsigned int tempo_entrega; //tempo de entrega
    float v_pedido; //valor total do pedido, calculado automaticamente pelo sistema
    Itens * I;    // PILHA de ITENS DO PEDIDO!
    struct pedido * prox;
} pedido;

typedef struct pedidos{
    pedido * ini;
    pedido * fim;
} Pedidos; //ATENCAO, OS PEDIDOS SERAO UMA FILA!!!
```


### Funções:
> ```c
>int vazia_Pedidos (Pedidos* f)
>```
***Descrição:** Verifica se a FILA de Pedidos **P** está vazia. RETORNO: 1 = vazia / 0 = não vazia.*


> ```c
>Pedidos* inicializa_Pedidos ()
>```
***Descrição:** Inicializa a FILA de Itens em um ponteiro do tipo **Pedidos**, alocando em memória.
ATENÇÃO, caso o espaço em memória que foi alocado sua FILA de Itens não seja mais utilizado dentro do programa, é preciso liberar este de forma manual, usando: **libera_Pedidos(Pedidos * P)**.*

> ```c
>void insere_Pedidos(Pedidos * P, pedido info)
>```
***Descrição:** Insere no final da FILA de Pedidos **P** o pedido **info**, é preciso preencher previamente as informações de **info** (uma função para preenchimento correto dos dados do **pedido** será implementada na biblioteca sistema.h).*

> ```c
>pedido retira_Pedidos(Pedidos * P)
>```
***Descrição:** Retira da FILA de Pedidos **P** o pedido do inicio da FILA ("atende"). RETORNO: Valor do **pedido** que foi retirado.*

> ```c
>void imprime_Pedidos(Pedidos * P)
>```
***Descrição:** Faz a impressão da FILA de Pedidos **P**, começando pelo inicio.*

> ```c
>void libera_Pedidos(Pedidos * P)
>```
***Descrição:** Faz um free em todos os espaços de memória envolvidos na estrutura **P**, liberando esta memória.*

------

### Biblioteca "pontos.h"       -   (Implementação de LISTAS para registro dos Pontos de venda).

------

### Biblioteca "sistema.h       -   (Implementações GERAIS para funcionamento do Sistema).

-----
