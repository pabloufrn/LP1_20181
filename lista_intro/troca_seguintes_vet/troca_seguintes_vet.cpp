#include <iostream> 
using namespace std;
int main(void){
        int vet[20], imp[20], size_imp = 0, i, j, aux;
        cout << "Entre com 20 valores inteiros: " << endl;
        for(i = 0; i < 20; ++i){
		cin >> vet[i];  
        }
	for(i = 0; i < 20; ++i){
		cout << vet[i] << " ";  
        }
	cout << "\n";
	for(i = 0; i < 20; ++i) // procura um par
		if(vet[i] % 2 == 0){
			if(size_imp > 0)
				vet[i-size_imp] = vet[i];
			for(j = 0; j < size_imp; j++)
				vet[i-size_imp+1+j] = imp[j];
			size_imp = 0;
		}
		else
			imp[size_imp++] = vet[i]; 
	for(i = 0; i < 20; ++i)
		cout << vet[i] << " ";  
	cout << "\n";
        return 0;
 }           
