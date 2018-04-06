#include <iostream>
using namespace std;
/// Implements greatest common divisor calculator.
/*!
 * \param x any integer.
 * \param y any integer.
 * \return greatest common divisor of x and y. 
 */
int gcd(int x, int y){
	if(x % y == 0)
		return y;
	return gcd(y, x % y);
}
// driver function
int main(){
	int x, y;
	cout << "Digite x: ";
	cin >> x;
	cout << "Digite y: ";
	cin >> y;
	int r = gcd(x, y);
	cout << "O resultado eh: " << r << "\n";

}
