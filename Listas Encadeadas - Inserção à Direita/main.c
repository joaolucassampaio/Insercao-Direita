#include <stdio.h>
#include <stdlib.h>

// Lista Simplesmente Encadeada - Inser��o no final

// Cria��o da estrutura node, um tipo de dado
struct node {
	int info;
	struct node *next;
};

int main(int argc, char *argv[]) {
	//Ponteiros Auxiliares p/ struct node
	struct node *lista, *p, *q;
	//Definindo lista inicialmente vazia
	lista = NULL;
	//Vari�vel para armazenar escolha do usu�rio
	int choice;
	
	do{
		//Cria��o de um novo elemento
		p = malloc(sizeof(struct node));
		printf("Qual dado deseja adicionar? ");
		//Adicionando a informa��o no campo info do novo elemento criado
		scanf("%i", &p->info);
		
		//Caso a lista estiver vazia, faremos uma inser��o � esquerda
		if(lista == NULL) {
			p->next = lista;
			lista = p;
			
		//Caso a lista estiver com um ou mais elementos, faremos um inser��o � direita
		} else {
			p->next = NULL; // Garantindo que o novo elemento a ser adicionado apontar� para NULL (ser o �ltimo)
			q = lista; // Aloca��o de um novo ponteiro para o in�cio da lista
			
			// Faz com que o ponteiro "q" encontre o fim da fila
			// Basicamente ele ir� percorrer todos elementos at� encontrar aquele que est� apontando para NULL (o �ltimo elemento)
			while(q->next != NULL) {
				//Garante o avan�o de "q" ao longo dos elementos da lista
				q = q->next;
			}
			
			//Quando o interpretador chegar nessa linha de c�digo, significa que "q" j� est� apontando para NULL
			//Ou seja, "q" j� � o �ltimo elemento
			// q->next = p "puxa" o novo n� "p" para o final da lista
			// com p->next = NULL j� definido antes, garantimos que esse novo elemento realmente � o �ltimo do encadeamento
			q->next = p;
		}
		
		// Ao sair do la�o, verifica se o usu�rio quer continuar adicionando elementos � lista
		printf("Deseja adicionar algum dado ao fim da lista? 0-nao, 1-sim ");
		scanf("%i", &choice);
	}while(choice != 0);
	
	printf("\n\n");
	//Atualiza "p" com o encadeamento da lista completa
	p = lista;
	// Enquanto o ponteiro "p" n�o apontar para o �ltimo elemento da lista, continuar o la�o
	while(p != NULL) {
		// Na primeira repeti��o exibe a informa��o do primeiro elemento, na segunda exibe a do segundo e assim sucessivamente
		printf("%i ", p->info);
		// Avan�a um elemento da lista
		p = p->next;
	}
	return 0;
}
