<div align="center">

##  Agenda de Contatos em C ANSI

### Contact Management System in ANSI C

Sistema desenvolvido para a disciplina de **Fundamentos de Programação** utilizando **C ANSI**, estruturas de repetição, vetores, funções e manipulação manual de strings.

<img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c">
<img src="https://img.shields.io/badge/Compiler-GCC-darkgreen?style=for-the-badge">
<img src="https://img.shields.io/badge/Paradigm-Structured%20Programming-orange?style=for-the-badge">
<img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge">
<img src="https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge">

</div>

---

<div align="center">

 ANSI C • Console Application • Structured Programming 

</div>

---

##  Overview | Visão Geral

| Português 🇧🇷                                                                         | English 🇺🇸                                                              |
| -------------------------------------------------------------------------------------- | ------------------------------------------------------------------------- |
| Sistema de gerenciamento de contatos desenvolvido em C ANSI para execução em terminal. | Contact management system developed in ANSI C for terminal execution.     |
| O projeto aplica os principais conceitos estudados em Fundamentos de Programação.      | The project applies core concepts studied in Fundamentals of Programming. |
| O sistema utiliza vetores bidimensionais para armazenamento dos dados em memória.      | The system uses bidimensional arrays for in-memory data storage.          |

---

##  Funcionalidades | Features

| Funcionalidade                | Status |
| ----------------------------- | ------ |
| Inclusão de contatos          | sim      |
| Consulta por nome             | sim      |
| Exclusão de contatos          | sim      |
| Listagem de contatos          | sim      |
| Menu interativo               | sim      |
| Manipulação manual de strings | sim      |

---

##  Tecnologias Utilizadas | Technologies Used

| Tecnologia          | Descrição                 |
| ------------------- | ------------------------- |
| ANSI C              | Linguagem principal       |
| GCC                 | Compilador                |
| Git                 | Controle de versão        |
| GitHub              | Hospedagem do repositório |
| Console Application | Execução via terminal     |

---

## Estrutura do Projeto | Project Structure

```txt id="n5k7p2"
agenda-contatos-c/
│
├── src/
│   └── agenda_contatos.c
│
├── docs/
│   ├── relatorio.docx
│   └── screenshots/
│       ├── menu.png
│       ├── cadastro.png
│       ├── consulta.png
│       ├── exclusao.png
│       └── lista.png
│
├── exemplos/
│   └── exemplo_execucao.txt
│
├── video/
│   └── demonstracao.mp4
│
├── README.md
├── LICENSE
└── .gitignore
```

---

##  Arquitetura do Sistema | System Architecture

```txt id="z8g2x6"
User
  ↓
Menu Controller
  ↓
Function Dispatcher
  ↓
CRUD Operations
  ↓
Memory Arrays
```

---

##  Estruturas de Dados | Data Structures

## Vetor de nomes | Names Array

```c id="s6f9m1"
char nomes[MAX_CONTATOS][TAM_NOME];
```

## Vetor de telefones | Phone Numbers Array

```c id="d4t8k5"
char telefones[MAX_CONTATOS][TAM_TELEFONE];
```

| Português 🇧🇷                                           | English 🇺🇸                                      |
| -------------------------------------------------------- | ------------------------------------------------- |
| Cada índice representa um contato armazenado em memória. | Each index represents a contact stored in memory. |
| Os vetores trabalham de forma sincronizada.              | Arrays operate synchronously.                     |

---

## Explicação das Funções | Function Breakdown

---

## `main()`

| Português 🇧🇷                                                    | English 🇺🇸                                                |
| ----------------------------------------------------------------- | ----------------------------------------------------------- |
| Responsável pelo fluxo principal do sistema.                      | Responsible for the application's main flow.                |
| Controla o menu, entrada de dados e execução das funcionalidades. | Controls menu navigation, user input and feature execution. |

---

## `exibirMenu()`

| Português 🇧🇷                      | English 🇺🇸                            |
| ----------------------------------- | --------------------------------------- |
| Exibe o menu principal no terminal. | Displays the main menu in the terminal. |

---

## `limparBufferEntrada()`

| Português 🇧🇷                                      | English 🇺🇸                                                     |
| --------------------------------------------------- | ---------------------------------------------------------------- |
| Remove caracteres residuais do buffer após `scanf`. | Removes residual characters from the input buffer after `scanf`. |

---

## `removerQuebraLinha()`

| Português 🇧🇷                               | English 🇺🇸                                        |
| -------------------------------------------- | --------------------------------------------------- |
| Remove o caractere `\n` gerado pelo `fgets`. | Removes the newline character generated by `fgets`. |

---

## `copiarString()`

| Português 🇧🇷                                                | English 🇺🇸                                             |
| ------------------------------------------------------------- | -------------------------------------------------------- |
| Realiza cópia manual de strings sem utilização de `string.h`. | Performs manual string copying without using `string.h`. |

---

## `compararNomes()`

| Português 🇧🇷                                   | English 🇺🇸                                     |
| ------------------------------------------------ | ------------------------------------------------ |
| Compara dois nomes caractere por caractere.      | Compares two names character by character.       |
| Retorna `1` para igualdade e `0` para diferença. | Returns `1` for equality and `0` for difference. |

---

## `incluirContato()`

| Português 🇧🇷                      | English 🇺🇸                        |
| ----------------------------------- | ----------------------------------- |
| Realiza cadastro de novos contatos. | Handles insertion of new contacts.  |
| Valida limite máximo da agenda.     | Validates maximum storage capacity. |

---

## `listarContatos()`

| Português 🇧🇷                                              | English 🇺🇸                                         |
| ----------------------------------------------------------- | ---------------------------------------------------- |
| Percorre os vetores exibindo todos os contatos cadastrados. | Traverses arrays displaying all registered contacts. |

---

## `consultarContato()`

| Português 🇧🇷                                      | English 🇺🇸                                           |
| --------------------------------------------------- | ------------------------------------------------------ |
| Executa busca sequencial baseada no nome informado. | Performs sequential search based on the provided name. |

---

## `excluirContato()`

| Português 🇧🇷                                             | English 🇺🇸                                    |
| ---------------------------------------------------------- | ----------------------------------------------- |
| Remove contatos da memória.                                | Removes contacts from memory.                   |
| Desloca elementos subsequentes para evitar espaços vazios. | Shifts subsequent elements to avoid empty gaps. |

---

## Fluxo de Execução | Execution Flow

```txt id="r5g8v1"
Program Initialization
        ↓
Memory Allocation
        ↓
Menu Rendering
        ↓
User Input
        ↓
Feature Execution
        ↓
Return to Main Menu
        ↓
Program Termination
```

---

## Complexidade Computacional | Computational Complexity

| Operação | Complexidade |
| -------- | ------------ |
| Inclusão | O(1)         |
| Consulta | O(n)         |
| Exclusão | O(n)         |
| Listagem | O(n)         |

---

## Build & Run

## Linux / macOS

```bash id="x1m9k7"
gcc src/agenda_contatos.c -o agenda

./agenda
```

## Windows

```bash id="f6t2p8"
gcc src/agenda_contatos.c -o agenda.exe

agenda.exe
```

---

## Screenshots

<table align="center">
<tr>

<td align="center">
<img src="docs/screenshots/menu.png" width="400">

###  Main Menu

Interface principal do sistema responsável pela navegação entre as funcionalidades disponíveis.

Main interface responsible for navigating through the available system functionalities.

</td>

<td align="center">
<img src="docs/screenshots/cadastro.png" width="400">

###  Contact Registration

Tela de cadastro utilizada para inserção de novos contatos na agenda.

Registration screen used to insert new contacts into the system.

</td>

</tr>

<tr>

<td align="center">
<img src="docs/screenshots/consulta.png" width="400">

###  Search Operation

Funcionalidade responsável pela busca sequencial de contatos utilizando o nome informado pelo usuário.

Feature responsible for sequential contact lookup using the provided name.

</td>

<td align="center">
<img src="docs/screenshots/exclusao.png" width="400">

###  Contact Removal

Processo de exclusão de contatos com reorganização dos vetores para evitar espaços vazios.

Contact removal process with array reorganization to prevent empty gaps.

</td>

</tr>

</table>

---

<table align="center">

<tr>

<td align="center">
<img src="docs/screenshots/lista.png" width="500">

###  Contact Listing

Listagem completa dos contatos armazenados na memória durante a execução do sistema.

Complete listing of contacts stored in memory during system execution.

</td>

</tr>

</table>

---

## Demonstration

<p align="center">

[ Watch Demonstration](video/demonstracao.mp4)

</p>

---

## Conceitos Aplicados | Applied Concepts

| Português 🇧🇷            | English 🇺🇸            |
| ------------------------- | ----------------------- |
| Programação estruturada   | Structured programming  |
| Vetores bidimensionais    | Bidimensional arrays    |
| Manipulação de strings    | String manipulation     |
| Estruturas condicionais   | Conditional structures  |
| Estruturas de repetição   | Iteration structures    |
| Busca sequencial          | Sequential search       |
| Modularização com funções | Function modularization |

---

## Melhorias Futuras | Future Improvements

| Português 🇧🇷           | English 🇺🇸            |
| ------------------------ | ----------------------- |
| Persistência em arquivos | File persistence        |
| Uso de `struct`          | `struct` implementation |
| Ordenação alfabética     | Alphabetical sorting    |
| Pesquisa parcial         | Partial search          |
| Interface gráfica        | Graphical interface     |
| Banco de dados           | Database integration    |

---

## Autor | Author

**Rafael Rodrigues**

---

## Disciplina | Course

Fundamentos de Programação
Fundamentals of Programming

---

## Licença | License

Distributed under the MIT License.
