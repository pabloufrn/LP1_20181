#include <iostream>
#include <cstring>

// definições
using Compare = int(const void*, const void*);
using byte = unsigned char;
using namespace std;
// assinaturas
void sort_bubble_2(const void * first , const void* last , size_t size , Compare * cmp );
// funcao de comparacao
int cmp_int(const void* a, const void* b)
{
	int *ia = (int*) a, *ib = (int*) b;
	if(*ia > *ib)return 1;
	else if(*ia < *ib)return -1;
	return 0;
}
// funcao principal
int main(void)
{
	int A[] = {5, 3, 4, 9};
	sort_bubble_2(begin(A), end(A), sizeof(int), cmp_int);
	cout << "array = ";
	for(int i = 0; i < 4; i++)
		cout << A[i] << " ";
	cout << "\n";
}
// bubble sort generico
void sort_bubble_2(const void * first , const void* last , size_t size , Compare * cmp )
{
	auto bfirst = (byte*) first; // byte para first
	byte* aux; // iterador
	byte tmp[4]; // auxiliar de troca
	auto blast = (byte*) last; // byte para last
	bool stop; // condição de parada
	do 
	{
		aux = bfirst; // seta o iterador para o inicio do vetor
		stop = true;
		while(aux < blast - size) // borbulha para cima
		{
			if(cmp(aux, aux+size) == 1) // verifica se o elemento eh maior que o proximo
			{
				stop = false;
				// faz o swap entre os elementos
				memcpy(tmp, aux, size);
				memcpy(aux, aux+size, size);
				memcpy(aux+size, aux, size);
				
			}
			aux+=size;
		}
		// para se ja estiver ordenado
		if(stop)break;
		aux = blast - size;
		while(aux > first) // borbulha para baixo
		{
			if(cmp(aux, aux-size) == -1) // verifica se o elemento eh menor que o proximo (elemento com indice menor)
			{
				stop = false; // nao esta ordenado
				// faz o swap
				memcpy(tmp, aux, size);
				memcpy(aux, aux-size, size);
				memcpy(aux-size, aux, size);
			}
			aux-=size;
		}
	}while(stop == false);	
}
