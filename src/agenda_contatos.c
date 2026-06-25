/* ===================================================================
   Trabalho Final - Agenda de Contatos
   Disciplina: Fundamentos de Programacao
   Linguagem : C ANSI

   Este programa implementa APENAS os itens que valem os 7,0 pontos
   base do trabalho:
     - Programa compilando e executando corretamente
     - Menu principal funcionando
     - Inclusao de contatos
     - Listagem de contatos
     - Consulta de contato pelo nome
     - Exclusao de contato

   Conteudos utilizados (todos obrigatorios da disciplina):
     variaveis, entrada/saida de dados, operadores, estrutura
     condicional, estrutura de selecao (switch), estruturas de
     repeticao, vetores, funcoes e strings simples com vetores
     de caracteres.

   Nao sao utilizados recursos de bonus (string.h, typedef struct,
   windows.h/gotoxy, gravacao em arquivo, etc).
   =================================================================== */

#include <stdio.h>

#define MAX_CONTATOS 100 
#define TAM_NOME     50
#define TAM_TELEFONE 20

/* ---------- Prototipos das funcoes ---------- */
void exibirMenu(void);
void limparBufferEntrada(void); 
void removerQuebraLinha(char texto[]);
void copiarString(char destino[], char origem[], int tamanho);
int  compararNomes(char nome1[], char nome2[]);

void incluirContato(char nomes[][TAM_NOME], char telefones[][TAM_TELEFONE], int *total);
void listarContatos(char nomes[][TAM_NOME], char telefones[][TAM_TELEFONE], int total);
void consultarContato(char nomes[][TAM_NOME], char telefones[][TAM_TELEFONE], int total);
void excluirContato(char nomes[][TAM_NOME], char telefones[][TAM_TELEFONE], int *total);

/* ---------- Funcao principal ---------- */
int main(void)
{
    char nomes[MAX_CONTATOS][TAM_NOME];
    char telefones[MAX_CONTATOS][TAM_TELEFONE];
    int total = 0;
    int opcao;

    do
    {
        exibirMenu();
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1)
        {
            opcao = 0;
        }
        limparBufferEntrada();

        switch (opcao)
        {
            case 1:
                incluirContato(nomes, telefones, &total);
                break;
            case 2:
                listarContatos(nomes, telefones, total);
                break;
            case 3:
                consultarContato(nomes, telefones, total);
                break;
            case 4:
                excluirContato(nomes, telefones, &total);
                break;
            case 5:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

        printf("\n");

    } while (opcao != 5);

    return 0;
}

/* ---------- Exibe o menu principal ---------- */
void exibirMenu(void)
{
    printf("\n===== AGENDA DE CONTATOS =====\n");
    printf("1 - Incluir contato\n");
    printf("2 - Listar contatos\n");
    printf("3 - Consultar contato pelo nome\n");
    printf("4 - Excluir contato\n");
    printf("5 - Sair\n");
    printf("===============================\n");
}

/* ---------- Limpa o buffer de entrada apos o scanf ---------- */
void limparBufferEntrada(void)
{
    char c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        /* descarta caracteres restantes */
    }
}

/* ---------- Remove o '\n' deixado pelo fgets ---------- */
void removerQuebraLinha(char texto[])
{
    int i = 0;

    while (texto[i] != '\0')
    {
        if (texto[i] == '\n')
        {
            texto[i] = '\0';
        }
        i++;
    }
}

/* ---------- Copia uma string manualmente (sem string.h) ---------- */
void copiarString(char destino[], char origem[], int tamanho)
{
    int i = 0;

    while (origem[i] != '\0' && i < tamanho - 1)
    {
        destino[i] = origem[i];
        i++;
    }

    destino[i] = '\0';
}

/* ---------- Compara duas strings manualmente (sem string.h) ----------
   Retorna 1 se forem iguais, 0 se forem diferentes.                 */
int compararNomes(char nome1[], char nome2[])
{
    int i = 0;

    while (nome1[i] != '\0' && nome2[i] != '\0')
    {
        if (nome1[i] != nome2[i])
        {
            return 0;
        }
        i++;
    }

    if (nome1[i] == '\0' && nome2[i] == '\0')
    {
        return 1;
    }

    return 0;
}

/* ---------- Inclui um novo contato ---------- */
void incluirContato(char nomes[][TAM_NOME], char telefones[][TAM_TELEFONE], int *total)
{
    if (*total >= MAX_CONTATOS)
    {
        printf("\nAgenda cheia! Nao e possivel incluir novos contatos.\n");
        return;
    }

    printf("\n--- Incluir novo contato ---\n");

    printf("Nome: ");
    fgets(nomes[*total], TAM_NOME, stdin);
    removerQuebraLinha(nomes[*total]);

    printf("Telefone: ");
    fgets(telefones[*total], TAM_TELEFONE, stdin);
    removerQuebraLinha(telefones[*total]);

    (*total)++;

    printf("\nContato cadastrado com sucesso!\n");
}

/* ---------- Lista todos os contatos cadastrados ---------- */
void listarContatos(char nomes[][TAM_NOME], char telefones[][TAM_TELEFONE], int total)
{
    int i;

    if (total == 0)
    {
        printf("\nNenhum contato cadastrado.\n");
        return;
    }

    printf("\n--- Lista de contatos (%d) ---\n", total);
    for (i = 0; i < total; i++)
    {
        printf("%d) Nome: %-30s Telefone: %s\n", i + 1, nomes[i], telefones[i]);
    }
}

/* ---------- Consulta um contato pelo nome ---------- */
void consultarContato(char nomes[][TAM_NOME], char telefones[][TAM_TELEFONE], int total)
{
    char nomeBusca[TAM_NOME];
    int i;
    int encontrado = 0;

    if (total == 0)
    {
        printf("\nNenhum contato cadastrado.\n");
        return;
    }

    printf("\n--- Consultar contato ---\n");
    printf("Digite o nome a ser consultado: ");
    fgets(nomeBusca, TAM_NOME, stdin);
    removerQuebraLinha(nomeBusca);

    for (i = 0; i < total; i++)
    {
        if (compararNomes(nomes[i], nomeBusca) == 1)
        {
            printf("\nContato encontrado!\n");
            printf("Nome: %s\n", nomes[i]);
            printf("Telefone: %s\n", telefones[i]);
            encontrado = 1;
        }
    }

    if (encontrado == 0)
    {
        printf("\nContato nao encontrado.\n");
    }
}

/* ---------- Exclui um contato pelo nome ---------- */
void excluirContato(char nomes[][TAM_NOME], char telefones[][TAM_TELEFONE], int *total)
{
    char nomeBusca[TAM_NOME];
    int i, j, posicao = -1;

    if (*total == 0)
    {
        printf("\nNenhum contato cadastrado.\n");
        return;
    }

    printf("\n--- Excluir contato ---\n");
    printf("Digite o nome do contato a ser excluido: ");
    fgets(nomeBusca, TAM_NOME, stdin);
    removerQuebraLinha(nomeBusca);

    for (i = 0; i < *total; i++)
    {
        if (compararNomes(nomes[i], nomeBusca) == 1) 
        {
            posicao = i;
            break;
        }
    }

    if (posicao == -1)
    {
        printf("\nContato nao encontrado.\n");
        return;
    }

    /* Desloca os contatos seguintes uma posicao para tras */
    for (j = posicao; j < (*total) - 1; j++)
    {
        copiarString(nomes[j], nomes[j + 1], TAM_NOME);
        copiarString(telefones[j], telefones[j + 1], TAM_TELEFONE);
    }

    (*total)--;

    printf("\nContato excluido com sucesso!\n");
}
