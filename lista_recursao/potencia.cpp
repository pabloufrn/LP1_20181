#include <iostream>
using namespace std;
int raiseToPower(int n, int k){
	if(k == 0)
		return 1;
	return n * raiseToPower(n, k-1);
}
int main(){
	int n, k;
	cout << "Digite n: ";
	cin >> n;
	cout << "Digite k: ";
	cin >> k;
	int r = raiseToPower(n, k);
	cout << "O resultado eh: " << r << "\n";

}
