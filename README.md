# ERDA
Projeto: Delivery de Hot Dog

O sr. José começou há mais de 30 anos atrás vendendo cachorro quente em um carrinho
no seu bairro. Ao longo dos anos, seu inconfundível molho secreto e sua maionese temperada
foram conquistando cada vez mais os clientes e o negócio foi crescendo. Os filhos e os sobrinhos
do sr. José também abriram seus carrinhos de cachorro quente em outros locais da cidade,
mantendo em segredo de família o mesmo sabor do molho e da maionese originais do sr. José.
Todos os pontos de carrinho de cachorro quente da família fazem muito sucesso e ficam lotados,
principalmente aos finais de semana. O cachorro quente fez tanto sucesso que foi considerado
o melhor do país!
Porém, com a situação declarada de pandemia e a cidade em isolamento social, sr. José,
os filhos e os sobrinhos tiveram que parar as vendas presenciais de cachorro quente e decidiram
começar a vender e fazer entrega. Assim, sr. José contratou o seu grupo para desenvolver o
sistema de controle de pedidos. O sr. José, que fez colégio técnico em processamento de dados
nos anos 80 e tem conhecimento de estrutura de dados, encaminhou os seguintes requisitos
para vocês:

Parte I - Organização do código:
1. Pontos dos carrinhos de cachorro quente: cada um dos membros da família está
trabalhando em seu carrinho na garagem de sua casa. O cadastro dos pontos
dos carrinhos deve ser uma lista contendo as seguintes informações:
o Região: valor numérico que representa a região da cidade onde o
carrinho está localizado, sendo: 1-centro; 2-zona sul; 3-zona leste; 4-
zona norte; 5-zona oeste.

o Experiência em preparar o cachorro quente: baixa, média, alta;
o Quantidade total de pedidos: inicia em zero e vai incrementando
conforme um pedido é feito;
o Valor total vendido: inicia em zero e vai acumulando conforme um
pedido é atendido;
o Pedidos: deverá ser uma fila (veja os detalhes no item 2).

2. Pedidos: cada ponto de cachorro quente tem sua fila de pedidos. Um ponto
recebe um pedido de acordo com o bairro selecionado pelo cliente na hora de
montar o pedido. O pedido contém as seguintes informações:
o Número do pedido: gerado automaticamente pelo sistema (pontos
diferentes não podem ter números de pedidos iguais);
o Região de entrega: mesmas regiões dos pontos dos carrinhos;
o Tempo de entrega: depende dos itens do pedido e é calculado
automaticamente pelo sistema da seguinte forma:

 Preparo: tempo médio de preparo de um cachorro quente de
acordo com a experiência do proprietário:

• Baixa: 5 minutos;
• Média: 3 minutos;
• Alta: 2 minutos.
 Fechamento: tempo médio fixo de 5 minutos para organizar o
pacote para entrega;
 Transporte: tempo médio fixo de 15 minutos (tempo que o
motoboy leva para retirar o pedido no ponto e levar até a casa
do cliente);
 Fila: tempo de preparo + tempo de fechamentos dos outros
pedidos anteriores ao seu na fila + tempo de entrega – apenas
os 15 minutos do pedido do cliente (estamos considerando que
assim que um pedido ficar pronto para entrega, teremos um
motoboy disponível para entrega-lo).
* Valor: valor total do pedido calculado automaticamente pelo sistema de
acordo com os valores dos itens do pedido;
* Itens do pedido: deverá ser uma pilha (veja os detalhes no item 3).
3. Itens do pedido: os itens são armazenados em uma pilha conforme o cliente
adiciona os itens. Essa pilha deve ter as seguintes informações:
* Item: descrição do produto;
* Quantidade: quantidade do produto;
* Valor Unitário: valor unitário do produto;
* Valor Total: valor total do produto, calculado pelo sistema (quantidade
* valor unitário);
o Observações: campo texto para armazenar informações extras do
pedido (campo não é obrigatório).

Parte II - Sistema: O sistema deverá possuir um menu com os seguintes itens:
4. Cadastrar ponto: permite cadastrar um ponto de atendimento (conforme
detalhado no item 1);

5. Pedido: permite gerar um pedido e seus itens (conforme itens 2 e 3). Assim que
um pedido é cadastrado, o total de pedidos do ponto deve ser atualizado;

6. Atender pedido: atendimento da fila de pedidos do ponto. Remove um a um os
itens do pedido e exibe a nota fiscal (a ordem dos itens deve ser a ordem de
remoção da pilha). Por fim, remove o pedido da fila e atualiza o valor total
vendido do ponto;

7. Cancelar pedido: permite ao cliente informar o número do pedido e cancelá-lo
(o pedido é removido da fila do ponto juntamente com os seus itens);

8. Relatórios:
o Pontos: lista todos os pontos, a quantidade de pedidos feitos e o valor
total vendido até o momento;
o Pedidos: lista todos os pedidos um ponto, juntamente com os itens do
pedido;
o Pedido: permite que o usuário informe um número de pedido e o
sistema exibe todos os detalhes daquele pedido.

9. Gerar dados: como temos muitos dados para cadastrar, essa opção no menu
permitirá gerar dados randomizados para o sistema utilizando o comando;

random e as regras abaixo:
* Gerar entre 3 e 7 pontos de cachorro quente;
* Gerar entre 5 e 15 pedidos para cada ponto;
* Gerar entre 1 e 5 itens para cada pedido, sendo:
 Item: pode ter a descrição padrão “cachorro quente”;
 Quantidade: sortear aleatoriamente entre 1 e 5;
 Valor unitário: sortear aleatoriamente entre R$ 10,00 e R$
15,00.

Orientações:

• O projeto deverá ser realizado em grupos de 3 a 4 alunos (desde que seja possível
interagirem de forma remota).

• Itens que serão avaliados:
* Utilização nomes de variáveis significativas;
* Endentação do código;
* Organização do código em funções para facilitar a organização e o
entendimento;
* Comentários: não há necessidade de comentar cada linha, porém, o código
deve ter comentários suficientes para o entendimento do raciocínio;
* Atendimento aos requisitos definidos neste documento;
* Funcionamento do sistema;
* Cumprimento das etapas de entrega;
* Apresentação.
• Etapas e entregas: criar um diretório chamado projeto no escaninho de um dos alunos
do grupo (a ser definido pela professora na aula de 04/05). Para cada etapa do projeto criar
um diretório específico como o nome da etapa (ex: etapa1) e adicionar os códigos fonte
do desenvolvimento até o momento. A ideia é que a cada etapa o código seja incrementado
com as novas funcionalidades implementadas.
* Etapa 1: data limite de entrega 10/05/2020 às 23h59
 Criar as bibliotecas: itens do pedido e pedido. Cada uma deve ser uma
biblioteca independente (itens 2 e 3).
* Etapa 2: data limite de entrega 17/05/2020 às 23h59
 Criar a biblioteca pontos (item 1).
 Criar o programa principal e permitir cadastrar um ponto (item 4).
* Etapa 3: data limite de entrega 24/05/2020 às 23h59
 Cadastrar pedido (item 5);
 Atender pedido (item 6);
 Cancelar pedido (item 7).
* Etapa 4: data limite de entrega 31/05/2020 às 23h59
 Gerar dados (item 9).
* Etapa 5: data limite de entrega 07/06/2020 às 23h59
 Relatórios (item 8).
* Apresentação: data e forma a serem definidas.
