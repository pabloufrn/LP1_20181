#include <iostream>
using namespace std;
void digital_root(int n){
	if(n < 10){
		cout << n;
		return;
	}
	digital_root(n/10);
	cout << " + "<< n % 10; 
	//cout << endl;
	//digital_root(n/10);
}
int main(){
	int n;
	cout << "Digite n: ";
	cin >> n;
	digital_root(n);
}
