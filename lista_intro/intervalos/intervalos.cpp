#include <iostream>

using namespace std;
int main(void){
	int intervalos[] = {0, 25, 50, 75, 100};
	int contadores[] = {0, 0, 0, 0};
	int n, i, total = 0;
	cout << "Entre com valores inteiros ( Ctrl + d p / encerrar ): " << endl ;
	while(cin >> n){
		for(i = 0; i < 4; i++){
			if(n >= intervalos[i] && n < intervalos[i+1])
				break;
		}
		if(i != 4 || (n == 100 && --i)){
			contadores[i]++;
			total++;
		}
		if(total > 0)
			for(i = 0; i < 4; ++i)
				cout << "numeros no intervalo [" << intervalos[i] << ", " << intervalos[i+1] << ((i == 3) ? "]":")") << ": " << ((float) contadores[i]/total*100) << "%.\n";
	}
	return 0;
}
