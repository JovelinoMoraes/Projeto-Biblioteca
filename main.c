// Importação das bibliotecas necessárias para o funcionamento do programa
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


// Constante que define o tamanho do acervo
#define TAMANHO_ACERVO 20

// Declaração da Struct (estrutura dos livros)
struct Livro {
    char titulo[50];
    char autor[30];
    char area[30];
    int codigo;
    int ano;
    char editora[30];
};

// Assinatura das Funções ( Serve para que o compilador leia e saiba que dentro da função main essas funções existam e quais parâmetros elas exigem para funcionar
void cadastrarLivro(struct Livro acervo[], int *quantidade);
void imprimirLivros(struct Livro acervo[], int quantidade);
void pesquisarLivro(struct Livro acervo[], int quantidade, int codigoBusca);
void ordenarLivros(struct Livro acervo[], int quantidade);

//Função principal do programa
int main() {
	setlocale(LC_ALL, "portuguese");
    struct Livro acervo[TAMANHO_ACERVO]; // criação do vetor de structs, onde serão guardados os livros.

	
    int opcao; // variável para salvar o numero digitado no menu
    int codigoBusca; // variável para o usuario informar qual livro ele quer procurar
    int quantidade = 0; // variável que armazena a quantidade de livros já cadastrados no vetor de livros

    do {
        printf("\n ------ MENU -----\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Imprimir todos os livros\n");
        printf("3 - Pesquisar livro por codigo\n");
        printf("4 - Ordenar livros por ano de publicacao\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: "); // pede para o usuario escolher uma opção do menu
        scanf("%d", &opcao);
        fflush(stdin);
		system("cls");
		
		
		// a escolha do usuario faz cair em um dos cases a baixo, chamando suas respectivas funções.
        switch (opcao) {
            case 1:
                cadastrarLivro(acervo, &quantidade);
                break;

            case 2:
                imprimirLivros(acervo, quantidade);
                break;

            case 3:
                pesquisarLivro(acervo, quantidade, codigoBusca);
                break;

            case 4:
               	ordenarLivros(acervo, quantidade);
                break;

            case 5:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}
// Função para Cadastrar Livro novo.
void cadastrarLivro(struct Livro acervo[], int *quantidade) {
    char palavra[10]; // variável que recebe a palavra Livro ou Livros, para apresentar quantos livros tem cadastrado

	if (*quantidade >= TAMANHO_ACERVO) {
        printf("Acervo cheio! Nao e possível cadastrar mais livros.\n");
        return;
    }

    int i = *quantidade; // a variável i vai receber a posição onde o novo livro será armazenado
	
    strcpy(palavra, (*quantidade == 1) ? "livro" : "livros"); // compara se tem 1 livro cadastrado, se sim , adiciona a string "Livro" a variavel palavra, se não , adiciona a string "Livros" \ operator ternário

    printf("Atualmente temos %d %s na biblioteca.\n", *quantidade, palavra);

    printf("Digite o Titulo do livro: ");

    scanf(" %49[^\n]", acervo[i].titulo);
    fflush(stdin);

    printf("Digite o Autor do livro: ");
    scanf(" %29[^\n]", acervo[i].autor);
    fflush(stdin);

    printf("Digite a Area do livro: ");
    scanf(" %29[^\n]", acervo[i].area);
    fflush(stdin);

    printf("Digite o Codigo do livro: ");
    scanf("%d", &acervo[i].codigo);
    fflush(stdin);

    printf("Digite o ano do livro: ");
    scanf("%d", &acervo[i].ano);
    fflush(stdin);

    printf("Digite a Editora do livro: ");
    scanf(" %29[^\n]", acervo[i].editora);
    fflush(stdin);

    (*quantidade)++;  // incrementa o número total de livros cadastrados

    printf("\nLivro cadastrado com sucesso!\n");

}

// Função para imprimir livros já cadastrados.
void imprimirLivros(struct Livro acervo[], int quantidade) {
	// verifica se não tem livros cadastrados, e imprime a mensagem informando isso.
    if (quantidade == 0) {
        printf("\n Nenhum livro cadastrado no acervo \n");
    }
    // percorre o array acervo imprimindo na tela todos os livros cadastrados.
    for (int i = 0; i < quantidade; i++) {
        printf("-----------------------\n");
        printf("Livro: %d \n", i+1);
        printf("Titulo: %s\n", acervo[i].titulo);
        printf("Autor: %s\n", acervo[i].autor);
        printf("Acervo: %s\n", acervo[i].area);
        printf("Editora: %s\n", acervo[i].editora);
        printf("Codigo:  %d\n", acervo[i].codigo);
        printf("Ano: %d\n", acervo[i].ano);
        printf("-----------------------\n");
    }

}

//Função para pesquisar livro pelo código
void pesquisarLivro(struct Livro acervo[], int quantidade, int codigoBusca) {
    // solicita ao usuário o código do livro a ser pesquisado.
    printf("Digite o codigo do livro: ");
    scanf("%d", &codigoBusca);
    fflush(stdin);

    // Se o código for encontrado, exibe as informações do livro.
    // Se não, mostre uma mensagem de "Livro não encontrado"
    for (int i = 0; i < quantidade; i++) {
        if (acervo[i].codigo == codigoBusca) {
            printf("-----------------------\n");
            printf("Titulo: %s\n", acervo[i].titulo);
            printf("Autor: %s\n", acervo[i].autor);
            printf("Acervo: %s\n", acervo[i].area);
            printf("Editora: %s\n", acervo[i].editora);
            printf("Codigo:  %d\n", acervo[i].codigo);
            printf("Ano: %d\n", acervo[i].ano);
            printf("-----------------------\n");
        }
    }
}

// Função para ordenar os livros por ano de publicação , utilizando BubbleSortz 
void ordenarLivros(struct Livro acervo[], int quantidade){
	struct Livro troca; // struct que serve de troca para fazer a ordenação dos livros.
		// verifica se não tem livros cadastrados, e imprime a mensagem informando isso.
    if (quantidade == 0) {
        printf("\n Nenhum livro cadastrado no acervo \n");
    }else{
    	printf("Livros ordenados com sucesso!"); // caso tenha mais que 1 livro, aprensenta uma mensagem informando ao usuario que os livros foram ordenados
	}
	int i, j;
	// Percorre todo vetor de livros verificando se o proximo tem o "ano" maior que o atual, se sim troca as posições para que o livro que tiver ano menor fique sempre nas primeiras posições
	for (i = 0; i <= quantidade - 1; i++){
		for(j = 0; j <= quantidade - 2; j++){
			if(acervo[j].ano > acervo[j+1].ano){
				
				troca = acervo[j+1];
				acervo[j+1] = acervo[j];
				acervo[j] = troca;
			}
		}
	}
	
}