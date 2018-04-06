#include <iostream>
using namespace std;
/// Implements a recursive raise to power function.
/*!
 * \param n any integer base.
 * \param k a non negative expoent.
 * \return n raised to power k. 
 */
int raiseToPower(int n, int k){
	if(k == 0)
		return 1;
	return n * raiseToPower(n, k-1);
}
// driver function
int main(){
	int n, k;
	cout << "Digite n: ";
	cin >> n;
	cout << "Digite k: ";
	cin >> k;
	int r = raiseToPower(n, k);
	cout << "O resultado eh: " << r << "\n";

}
