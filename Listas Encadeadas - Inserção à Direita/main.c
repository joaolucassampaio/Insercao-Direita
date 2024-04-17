#include <stdio.h>
#include <stdlib.h>

// Lista Simplesmente Encadeada - Inserção no final

// Criação da estrutura node, um tipo de dado
struct node {
	int info;
	struct node *next;
};

int main(int argc, char *argv[]) {
	//Ponteiros Auxiliares p/ struct node
	struct node *lista, *p, *q;
	//Definindo lista inicialmente vazia
	lista = NULL;
	//Variável para armazenar escolha do usuário
	int choice;
	
	do{
		//Criação de um novo elemento
		p = malloc(sizeof(struct node));
		printf("Qual dado deseja adicionar? ");
		//Adicionando a informação no campo info do novo elemento criado
		scanf("%i", &p->info);
		
		//Caso a lista estiver vazia, faremos uma inserção à esquerda
		if(lista == NULL) {
			p->next = lista;
			lista = p;
			
		//Caso a lista estiver com um ou mais elementos, faremos um inserção à direita
		} else {
			p->next = NULL; // Garantindo que o novo elemento a ser adicionado apontará para NULL (ser o último)
			q = lista; // Alocação de um novo ponteiro para o início da lista
			
			// Faz com que o ponteiro "q" encontre o fim da fila
			// Basicamente ele irá percorrer todos elementos até encontrar aquele que está apontando para NULL (o último elemento)
			while(q->next != NULL) {
				//Garante o avanço de "q" ao longo dos elementos da lista
				q = q->next;
			}
			
			//Quando o interpretador chegar nessa linha de código, significa que "q" já está apontando para NULL
			//Ou seja, "q" já é o último elemento
			// q->next = p "puxa" o novo nó "p" para o final da lista
			// com p->next = NULL já definido antes, garantimos que esse novo elemento realmente é o último do encadeamento
			q->next = p;
		}
		
		// Ao sair do laço, verifica se o usuário quer continuar adicionando elementos à lista
		printf("Deseja adicionar algum dado ao fim da lista? 0-nao, 1-sim ");
		scanf("%i", &choice);
	}while(choice != 0);
	
	printf("\n\n");
	//Atualiza "p" com o encadeamento da lista completa
	p = lista;
	// Enquanto o ponteiro "p" não apontar para o último elemento da lista, continuar o laço
	while(p != NULL) {
		// Na primeira repetição exibe a informação do primeiro elemento, na segunda exibe a do segundo e assim sucessivamente
		printf("%i ", p->info);
		// Avança um elemento da lista
		p = p->next;
	}
	return 0;
}
