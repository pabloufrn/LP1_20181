#include <iostream> 
using namespace std;
int main(void){
        int vet[20], i, menor;
        cout << "Entre com 20 valores inteiros: " << endl;
        for(i = 0; i < 20; ++i){
		cin >> vet[i];  
        }
	for(i = 0; i < 20; ++i){
		cout << vet[i] << " ";  
        }
	cout << endl;
	menor = 0;
	for(i = 1; i < 20; ++i){
		if(vet[i] < vet[menor])
			menor = i;
        }
	cout << "O menor elemento da lista eh " << vet[menor] << ", na posicao " << menor << endl;
        return 0;
 }           
