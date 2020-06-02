#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/*Desenvolvedores:

Derek Freire Quaresma   Ra:18706986
Lucas Cicconi                     Ra:17121393

Descrição:
    Programa funciona conforme os requerimentos passados,fazendo matricula de professores alunos e disciplinas no sistema, matricula e desmatricula de alunos em disciplinas e matricula e desmatricula de um professores em uma disciplina.
nao foram feitas algumas verificaçoes de entrada, por exemplo: caso o usuario digite uma letra onde deveria digitarum numero, o programa nao funcionara da forma prevista.
*/
struct ALUNO {
    char nome[50];
    int Ra;
};
typedef struct ALUNO elemento_A;
struct PROFESSOR {
    char nome[50];
    int registro;
};
typedef struct PROFESSOR elemento_P;

struct DISCIPLINA {

    char nome[50];

    int codigo;
    int Ra_Aluno[50];
    int qtdd_ja_cadastrada;
    int primeiro_cadastro;// como nao  da pra zerar qtdd ja cadastrada usei essa variavel;
    char Reg_Prof[50];
};
typedef struct DISCIPLINA elemento_D;

struct no_A {

    elemento_A info;

    struct no_A* link;

};
typedef struct no_A no_A;

struct no_P {

    elemento_P info;

    struct no_P* link;



};
typedef struct no_P no_P;

struct no_D {



    elemento_D info;

    struct no_D* link;



};
typedef struct no_D no_D;

/////////////////////////////////////////////////////////////////////////////////
//Funçao para mudar cor de texto.
void mudacor(int cor)
{

    /*
    0 = Preto        8 = Cinza
    1 = Azul        9 = Azul Claro
    2 = Verde        10 = Verde Claro
    3 = Verde-Agua    11= Verde-Agua Claro
    4 = Vermelho    12 = Vermelho Claro
    5 = Roxo        13 = Lilas
    6 = Amarelo        14 = Amarelo Claro
    7 = Branco        15 = Branco Brilhante
    */
    HANDLE Saida;
    Saida = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Saida, cor);

}

int Menu_principal(); //ok

void inserir_final_A(no_A** pri, elemento_A x);//ok

void inserir_final_P(no_P** pri, elemento_P x);//ok

void inserir_final_D(no_D** pri, elemento_D x);//ok

void incluir_Aluno(no_A** Lista);//OK

void incluir_Disciplina(no_D** Lista);//ok

void incluir_Professor(no_P** Lista);//ok

void Cadastrar_Aluno_Disciplina(no_D* Lista_D);//ok

void Desmatricular_Aluno(no_D* Lista_D);

void Cadastrar_Professor_Disciplina(no_D* Lista_D);//ok

void Desvincular_Professor(no_D* Lista_D);

void imprimirDisciAluno(no_D* Lista_D);

void imprimir_A(no_A* Lista);

void imprimir_D(no_D* Lista);

void imprimir_P(no_P* Lista);

void imprimirAlunoDisci(no_D* Lista_D, no_A* Lista_A);
void impProfDisci(no_D* Lista_D);
void impDisciProf(no_D* Lista_D);

int main() {


    no_A* Lista_A = NULL;
    no_P* Lista_P = NULL;
    no_D* Lista_D = NULL;

    //Lista_D->info.qtdd_ja_cadastrada = 0;

    int escolha;
    int escolha_m_c = 0;//escolhe entre matricular e desmatricular

    escolha = Menu_principal();

    while (escolha != 14) {
        switch (escolha) {

        case 1: //CADASTRAR ALUNOS
            incluir_Aluno(&Lista_A);

            system("pause");
            system("cls");
            break;

        case 2: //CADASTRAR DISCIPLINAS
            incluir_Disciplina(&Lista_D);

            system("pause");
            system("cls");
            break;


        case 3: //CADASTRAR PROFESSORES
            incluir_Professor(&Lista_P);

            system("pause");
            system("cls");
            break;

        case 4: //MATRICULAR / CANCELAR MATRICULA

            do {
                printf("1-Matricular\t2-Cancelar matricula:");
                scanf("%d", &escolha_m_c);
                system("cls");
            } while (escolha_m_c != 1 && escolha_m_c != 2);

            if (escolha_m_c == 1) {
                Cadastrar_Aluno_Disciplina(Lista_D);
            }
            else {
                Desmatricular_Aluno(Lista_D);
            }

            system("pause");
            system("cls");
            break;

        case 5: //VINCULAR / DESVINCULAR PROFESSOR A DISCIPLINA
            do {
                printf("1-Vincular\t2-Desvincular:");
                scanf("%d", &escolha_m_c);
                system("cls");
            } while (escolha_m_c != 1 && escolha_m_c != 2);

            if (escolha_m_c == 1) {
                Cadastrar_Professor_Disciplina(Lista_D);
            }
            else {
                Desvincular_Professor(Lista_D);
            }

            system("pause");
            system("cls");
            break;

        case 6: //IMPRIMIR INFORMAÇÕES
            imprimir_A(Lista_A);
            system("pause");
            system("cls");
            break;


        case 7:
            imprimir_D(Lista_D);
            system("pause");
            system("cls");
            break;

        case 8:
            imprimir_P(Lista_P);
            system("pause");
            system("cls");
            break;

        case 9:
            imprimirDisciAluno(Lista_D);
            system("pause");
            system("cls");
            break;


        case 10:
            imprimirAlunoDisci(Lista_D, Lista_A);
            system("pause");
            system("cls");
            break;

        case 11:
            impDisciProf(Lista_D);
            system("pause");
            system("cls");
            break;

        case 12:
            impProfDisci(Lista_D);
            system("pause");
            system("cls");
            break;


        case 13: //SAIR;

            return 0;
            break;

        }
        escolha = Menu_principal();
    }
}

int Menu_principal()
{
    int escolha_1;
    do
    {
        escolha_1 = 0;
        mudacor(15);
        printf("\n");
        printf("\t\t\t\t|--------------|\n");
        printf("\t\t\t\t|Menu Principal|\n");
        printf("\t\t\t\t|--------------|\n");
        printf("\n\n\n");
        printf("\t 1 =  CADASTRAR ALUNOS\n");
        printf("\t 2 =  CADASTRAR DISCIPLINAS\n");
        printf("\t 3 =  CADASTRAR PROFESSORES\n");
        printf("\t 4 =  MATRICULAR / CANCELAR MATRICULA\n");
        printf("\t 5 =  VINCULAR / DESVINCULAR PROFESSOR A DISCIPLINA\n");
        printf("\t 6 =  Imprimir todos os alunos\n");
        printf("\t 7 =  Imprimir todas as disciplinas\n");
        printf("\t 8 =  Imprimir todos os professores\n");
        printf("\t 9 =  Imprimir disciplinas de um aluno\n");
        printf("\t 10 = Imprimir alunos em uma disciplina\n");
        printf("\t 11 = Imprimir disciplinas ministradas pelo professor\n");
        printf("\t 12 = Imprimir professores em uma disciplina\n");
        printf("\t 13 = SAIR\n");
        printf("\n\n\t :");
        scanf("%d", &escolha_1);

        if (escolha_1 < 1 || escolha_1 > 13)
        {
            MessageBox(NULL, "  Opcao invalida  ", " << ERRO >>", MB_ICONEXCLAMATION);
            fflush(stdin);
        }
    } while (escolha_1 < 1 || escolha_1 > 13);
    system("cls");
    return escolha_1;
}

no_A* novo_noA()
{

    no_A* novo;

    novo = (no_A*)malloc(sizeof(no_A));

    if (novo == NULL)

    {

        printf("\n Erro Alocacao Novo No\n");

        exit(1);

    }
    return novo;

}

no_D* novo_noD()
{

    no_D* novo;

    novo = (no_D*)malloc(sizeof(no_D));

    if (novo == NULL)

    {

        printf("\n Erro Alocacao Novo No\n");

        exit(1);
    }

    return novo;
}

no_P* novo_noP()
{
    no_P* novo;

    novo = (no_P*)malloc(sizeof(no_P));

    if (novo == NULL)

    {
        printf("\n Erro Alocacao Novo No\n");

        exit(1);
    }

    return novo;
}

void inserir_final_A(no_A** pri, elemento_A x) {

    no_A* p, * novo;

    novo = novo_noA();

    novo->info = x;

    novo->link = NULL;

    p = *pri;

    while (p != NULL && p->link != NULL)

        p = p->link;

    if (p == NULL) *pri = novo;

    else p->link = novo;



}

void inserir_final_D(no_D** pri, elemento_D x) {

    no_D* p, * novo;

    novo = novo_noD();

    novo->info = x;

    novo->link = NULL;

    p = *pri;

    while (p != NULL && p->link != NULL)

        p = p->link;

    if (p == NULL) *pri = novo;

    else p->link = novo;



}

void inserir_final_P(no_P** pri, elemento_P x) {

    no_P* p, * novo;

    novo = novo_noP();

    novo->info = x;

    novo->link = NULL;

    p = *pri;

    while (p != NULL && p->link != NULL)

        p = p->link;

    if (p == NULL) *pri = novo;

    else p->link = novo;



}

void incluir_Aluno(no_A** Lista) {

    int qtdd, i;

    printf("Quantos alunos deseja cadastrar? :");
    scanf("%d", &qtdd);
    system("cls");

    for (i = 0; i < qtdd; i++) {

        elemento_A Novo;

        printf("digite os dados do Aluno [%d] : \n", i + 1);

        printf("\nnome = ");

        getchar();

        scanf("%[^\n]", Novo.nome);

        printf("\nRa = ");

        scanf("%d", &Novo.Ra);

        inserir_final_A(Lista, Novo);

        system("cls");
    }
    printf("\nAluno(s) cadastrado(s).\n");

}

void incluir_Disciplina(no_D** Lista) {

    int i, qtdd = 0;

    printf("Quantas disciplinas deseja cadastrar? : ");
    scanf("%d", &qtdd);
    system("cls");

    for (i = 0; i < qtdd; i++) {


        elemento_D Novo;

        printf("digite os dados da Disciplina [%d]: \n", i + 1);

        printf("\nnome = ");

        getchar();

        scanf("%[^\n]", Novo.nome);

        printf("\nCodigo = ");

        scanf("%d", &Novo.codigo);

        inserir_final_D(Lista, Novo);
        system("cls");
    }
    printf("\nDisciplina(s) cadastrada(s).\n");
}

void incluir_Professor(no_P** Lista) {

    int i, qtdd = 0;

    printf("Quantos professores deseja cadastrar? :");
    scanf("%d", &qtdd);
    system("cls");

    for (i = 0; i < qtdd; i++) {

        elemento_P Novo;

        printf("digite os dados do Professor a ser cadastrado: \n");

        printf("\nnome = ");

        getchar();

        scanf("%[^\n]", Novo.nome);

        printf("\nRegistro = ");

        scanf("%d", &Novo.registro);

        inserir_final_P(Lista, Novo);
        system("cls");

    }
    printf("\nProfessor(es) cadastrado(s).\n");
}

void imprimir_A(no_A* Lista) {

    no_A* p;
    p = Lista;

    while (p != NULL) {

        if (p->info.nome != 0) {

            printf("\n nome: %s\n", p->info.nome);
            printf("Ra: %d\n", p->info.Ra);

        }

        p = p->link;

    }

}

void imprimir_D(no_D* Lista) {

    no_D* p;
    p = Lista;

    while (p != NULL) {

        if (p->info.nome != 0) {

            printf("\n\nnome: %s\n", p->info.nome);
            printf("Registro: %d\n", p->info.codigo);

        }

        p = p->link;

    }

}

void imprimir_P(no_P* Lista) {

    no_P* p;
    p = Lista;

    while (p != NULL) {

        if (p->info.nome != 0) {

            printf("\n\nnome: %s\n", p->info.nome);
            printf("Registro: %d\n", p->info.registro);

        }

        p = p->link;

    }

}

void Cadastrar_Aluno_Disciplina(no_D* Lista_D) {


    no_D* Lista_Disciplinas;


    Lista_Disciplinas = Lista_D;

    int i = 0, j = 0, qtdd_al, qtdd_disc;
    int* RAs;
    char Nome_disci[50];

    printf("Quantos alunos deseja cadastrar a(s) disciplina(s)? :");
    scanf("%d", &qtdd_al);
    system("cls");
    RAs = (int*)malloc(qtdd_al * sizeof(int));//Tamanho para a qtdd de Ras alocado dinamicamente

    for (i = 0; i < qtdd_al; i++) {
        printf("Digite o Ra do aluno [%d]:", i + 1);
        scanf("%d", &RAs[i]);
        system("cls");
    }

    //ja_cadastrados = Lista_Disciplinas->info.qtdd_ja_cadastrada;//Mudar para variavel atravez de parametro

    printf("Em quantas disciplinas deseja cadastrar o(s) aluno(s)? :");
    scanf("%d", &qtdd_disc);
    system("cls");
    for (i = 0; i < qtdd_disc; i++)
    {
        printf("\nDigite o Nome da(s) disciplina(s):");
        getchar();
        gets(Nome_disci);
        system("cls");
        //Roda até a lista estar vazia, quanto encontrar o nome da disciplina entra no for, o for faz com que
        // o Ra do aluno entre no vetor de cadastro da struct, onde ja_cadastrado recebe a quantidade de informaçao
        //já existente no vetor e o vetor RAs armazena temporiramente o ra dos alunos a serem mandados para o vetor
        //Ra_Aluno da struc, após o cadastro a varavel ja cadastrados é atualizada.

        while (Lista_Disciplinas != NULL)
        {
            if (Lista_Disciplinas->info.primeiro_cadastro != 1)
            {
                Lista_Disciplinas->info.primeiro_cadastro = 1;
                Lista_Disciplinas->info.qtdd_ja_cadastrada = 0;
            }

            if (strcmp(Nome_disci, Lista_Disciplinas->info.nome) == 0)
            {
                for (j = 0; j < qtdd_al; j++)
                {
                    Lista_Disciplinas->info.Ra_Aluno[Lista_Disciplinas->info.qtdd_ja_cadastrada] = RAs[j];
                    Lista_Disciplinas->info.qtdd_ja_cadastrada++;
                }
            }
            Lista_Disciplinas = Lista_Disciplinas->link;
        }
    }
}

void Cadastrar_Professor_Disciplina(no_D* Lista_D) {
    no_D* Lista_Disciplinas;
    Lista_Disciplinas = Lista_D;

    char Professor[50], Disciplina[50];

    printf("Digite o nome do Professor que deseja vincular a uma disciplina: ");
    getchar();
    gets(Professor);
    system("cls");

    printf("Digite o nome da Disciplina :");
    gets(Disciplina);

    while (Lista_Disciplinas != NULL)
    {
        if (strcmp(Disciplina, Lista_Disciplinas->info.nome) == 0)
        {

            strcpy(Lista_Disciplinas->info.Reg_Prof, Professor);
            printf("\nProfessor cadastrado\n");
        }
        Lista_Disciplinas = Lista_Disciplinas->link;
    }

}

void Desvincular_Professor(no_D* Lista_D) {
    no_D* Lista_Disciplinas;
    Lista_Disciplinas = Lista_D;

    char Professor[50], Disciplina[50];

    printf("Digite o nome do Professor que deseja desvincular de uma disciplina: ");
    getchar();
    gets(Professor);
    system("cls");

    printf("Digite o nome da Disciplina :");
    gets(Disciplina);

    while (Lista_Disciplinas != NULL)
    {
        if (strcmp(Disciplina, Lista_Disciplinas->info.nome) == 0)
        {
            Lista_Disciplinas->info.Reg_Prof[0] = '\0';
            printf("\nProfessor desvinculado\n");
        }
        Lista_Disciplinas = Lista_Disciplinas->link;
    }
}
void Desmatricular_Aluno(no_D* Lista_D) {
    no_D* Lista_Disciplinas;

    Lista_Disciplinas = Lista_D;

    int i, j, qtdd_al, qtdd_disc;
    int* RAs;
    char Nome_disci[50];

    printf("Quantos alunos deseja desmatricular?:");
    scanf("%d", &qtdd_al);
    system("cls");

    RAs = (int*)malloc(qtdd_al * sizeof(int));

    for (i = 0; i < qtdd_al; i++)
    {

        printf("\nDigite o Ra do aluno que deseja desmatricular :");
        scanf("%d", &RAs[i]);
        system("cls");
    }

    printf("Digite quantas disciplinas deseja mexer:\n");
    scanf("%d", &qtdd_disc);
    system("cls");
    for (i = 0; i < qtdd_disc; i++)
    {
        printf("Digite o nome da disciplina que deseja retirar o aluno:\n");
        getchar();
        gets(Nome_disci);
        system("cls");
        while (Lista_Disciplinas != NULL)
        {

            if (strcmp(Nome_disci, Lista_Disciplinas->info.nome) == 0)
            {
                for (j = 0; j < Lista_Disciplinas->info.qtdd_ja_cadastrada; j++)
                {
                    if (Lista_Disciplinas->info.Ra_Aluno[i] == RAs[j])
                    {
                        Lista_Disciplinas->info.Ra_Aluno[i] = -1;
                        printf("Aluno desmatriculado\n");
                    }
                }
            }
            Lista_Disciplinas = Lista_Disciplinas->link;
        }
    }
}

void imprimirDisciAluno(no_D* Lista_D) {

    no_D* p;
    p = Lista_D;
    int Ra, i;

    printf("Digite o Ra do aluno que deseja saber as disciplinas:");
    scanf("%d", &Ra);
    system("cls");
    printf("\n--Aluno cadastrado na(s) Disciplina(s)--\n");
    while (p != NULL)
    {

        for (i = 0; i < p->info.qtdd_ja_cadastrada; i++)
        {
            if (Ra == p->info.Ra_Aluno[i] && p->info.Ra_Aluno[i] != -1)
            {
                printf("%s\n", p->info.nome);
            }
        }
        p = p->link;
    }

}

void imprimirAlunoDisci(no_D* Lista_D, no_A* Lista_A) {





    no_D* p;
    no_A* pA;
    p = Lista_D;
    pA = Lista_A;
    int i, j;
    int* RAs;

    char nomeDisci[50];


    printf("Digite o nome da disciplinas:");
    getchar();
    gets(nomeDisci);
    system("cls");
    printf("\n---Alunos cadastrados na Disciplina---\n");

    while (p != NULL)
    {
        if (strcmp(nomeDisci, p->info.nome) == 0)
        {
            j = p->info.qtdd_ja_cadastrada;
            RAs = (int*)malloc(p->info.qtdd_ja_cadastrada * sizeof(int));
            for (i = 0; i < p->info.qtdd_ja_cadastrada; i++)
            {
                RAs[i] = p->info.Ra_Aluno[i];
            }

        }
        p = p->link;
    }

    while (pA != NULL)
    {
        for (i = 0; i < j; i++)
        {
            if (RAs[i] == pA->info.Ra)
            {
                printf("Nome=%s\tRa:%d\n", pA->info.nome, pA->info.Ra);
            }
        }
        pA = pA->link;
    }

}
void impProfDisci(no_D* Lista_D) {
    no_D* p;
    p = Lista_D;
    char nomeDisci[50];

    printf("Digite o nome da disciplina :");
    getchar();
    gets(nomeDisci);

    printf("---Professor ministrando a Disciplina---\n");
    while (p != NULL)
    {
        if (strcmp(nomeDisci, p->info.nome) == 0)
        {
            if (p->info.Reg_Prof[0] == '\0')
            {
                printf("Nenhum");
            }
            printf("\t%s\n", p->info.Reg_Prof);
        }
        p = p->link;
    }
}

void impDisciProf(no_D* Lista_D) {
    no_D* p;
    p = Lista_D;
    char nomeProf[50];
    printf("Digite o nome do Professor:");
    getchar();
    gets(nomeProf);
    printf("---Disciplinas ministradas pelo professor---");
    while (p != NULL) {
        if (strcmp(nomeProf, p->info.Reg_Prof) == 0)
        {
            printf("\n\t%s\n", p->info.nome);
        }
        p = p->link;
    }
}
