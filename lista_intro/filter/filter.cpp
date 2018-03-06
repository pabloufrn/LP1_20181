#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct item Item;
typedef struct item* Lista;
struct item{
	int val;
	Item* ant;
	Item* prox;
};

Item &filtra(Item*& first, Item* last){
	Item *aux = first, *auxfree;
	Item *nlast;
	while(aux != last){
		if(aux->val < 1){
			if(aux == first){
				first = aux->prox;
				aux = first;
				continue;
			}
			aux->ant->prox = aux->prox;
			aux->prox->ant = aux->ant;
			auxfree = aux;
			free(auxfree);
			aux = aux->prox;
			continue;
		}
		aux = aux->prox;
		nlast = aux;
	}
	return *nlast;
}
int main(void){
	Lista *vet;
	Item *aux, *last;
	int size = 0, v = 0;
	cout << "Digite o tamanho do vetor: ";
	cin >> size;
	cout << "Digite os elementos do vetor: ";
	vet = (Lista*) malloc(sizeof(Lista));
	aux = (Item*) malloc(sizeof(Item));
	*vet = aux;
	for(int i = 0; i < size; i++){
		cin >> v;
		if(aux == *vet){
			aux->ant = NULL;
			aux->val = v;
			aux->prox = (Item*) malloc(sizeof(Item));
			aux->prox->ant = aux;
			aux = aux->prox;
			continue;
		}
		aux->val = v;
		aux->prox = (Item*) malloc(sizeof(Item));
		aux->prox->ant = aux;
		aux = aux->prox;
	}
	last = aux;
	aux = *vet;
	while(aux != last){
		cout << aux->val << " ";
		aux = aux->prox;
	}
	cout << endl;
	*last = filtra(*vet, last);
	aux = *vet;
	while(aux != last){
		cout << aux->val << " ";
		aux = aux->prox;
	}	
	cout << endl;
}
