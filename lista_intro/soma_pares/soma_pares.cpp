#include <iostream> 
using namespace std;
int main(void){ 
         int m, n, soma = 0;
         cout << "Entre com pares de valores inteiros ( Ctrl + d p / encerrar ): " << endl ;
         while(cin >> m >> n){
		cout << "lista de valores: "; 
                for(n+=m, soma = 0; m < n; m++){
			soma+=m;
                	cout << " " << m;
                }
                cout << " = " << soma << "\n";
          }
          return 0;
 }           
