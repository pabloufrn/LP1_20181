#include <iostream>
int main(){
	int n, i, aux = 0;
	for(int i = 0; i < 5; i++){
		std::cout << "digite um numero: \n";
		std::cin >> n;
		if(n < 0)
			aux++;
	}
	std::cout << "quantidade de numeros negativos: " << aux << std::endl;

}
