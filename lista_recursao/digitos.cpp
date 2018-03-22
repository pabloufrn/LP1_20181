#include <iostream>
using namespace std;
int digitSum(int n){
	if(n / 10  < 1)
		return n;
	return n % 10 + digitSum(n % 10);
}
int main(){
	int n;
	cout << "Digite n: ";
	cin >> n;
	int r = digitSum(n);
	cout << "O resultado eh: " << r << "\n";

}
