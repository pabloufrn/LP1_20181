#include <iostream>

using namespace std;
int main(void){
	int n, n1 = 1, n2 = 1, r;
	cout << "Digite um numero: ";
	cin >> n;
	if(n < 2)
		return 1;
	cout << "1 ";
	for(r = 1; r < n; r = n1 + n2){
		n2 = n1;
		n1 = r;
		cout << " " << r; 
		
	}
	cout << endl;
	return 0;
}
