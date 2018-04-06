#include <iostream>
using namespace std;

/// Implements a recursive sum of digits of n.
/*!
 * \param n any non negative integer.
 * \return sum of digits of n. 
 */
int digitSum(int n)
{
	if(n < 10)
		return n;
	return n % 10 + digitSum(n/10);
}
// driver function
int main()
{
	int n;
	cout << "Digite n: ";
	cin >> n;
	cout << "Resultado: " << digitSum(n) << endl;
}
