#include <iostream>
using namespace std;
int cannonball(int height){
	if(height <= 0)
		return 0;
	return (height * height) + cannonball(height-1);
}
int main(){
	int h;
	cout << "Digite a altura da pilha: ";
	cin >> h;
	int n = cannonball(h);
	if(n > 0)
		cout << "A pilha tem " << n << " Balls\n";
	else
		cout << "Altura da pilha invalida\n";	

}
