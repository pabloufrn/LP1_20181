#include <iostream>
using namespace std;
/// Implements a recursive sum of digits of n.
/*!
 * \param n any non negative integer.
 * \return sum of digits of n. 
 */
long int digitSum(unsigned long int n)
{
	if(n < 10)
		return n;
	return n % 10 + digitSum(n/10);
}
/// Implements a recursive digital root of n.
/*!
 * \param n any non negative integer.
 * \return digital root of n. 
 */
int digital_root(unsigned long int n)
{
	n = digitSum(n);
	if(n > 9)
		return digital_root(n);
	else
		return n;

}
// driver function
int main(){
	unsigned long int n; // input integer
	cout << "Digite n: ";
	cin >> n;
	cout << "Resultado: " << digital_root(n) << endl; // print result 
}
