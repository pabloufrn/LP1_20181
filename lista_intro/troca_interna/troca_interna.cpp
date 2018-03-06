#include <iostream> 
using namespace std;
int main(void){
        int vet[20], i, aux;
        cout << "Entre com 20 valores inteiros: " << endl;
        for(i = 0; i < 20; ++i){
		cin >> vet[i];  
        }
	for(i = 0; i < 20; ++i){
		cout << vet[i] << " ";  
        }
	cout << "\n";
	for(i = 0; i < 10; ++i){
		aux = vet[i];
		vet[i] = vet[19-i];
		cout << vet[i] << " ";
		vet[19-i] = aux;
        }
	for(i = 10; i < 20; ++i){
		cout << vet[i] << " ";  
        }
	cout << "\n";
        return 0;
 }           
