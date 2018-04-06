#include <iostream>
#include <iterator>
#include "find_if.h"
using namespace std;

/// Execute a defined predicate.
/* /param a void poiter to be converted on a integer
 * /return true if the number os negative; or false if its a positive integer.
 */
bool pred(const void* a)
{
	int ia = *reinterpret_cast<int*>(const_cast<void*>(a));
	if(ia < 0)
		return true;
	return false;
}
int main(void)
{
	int A[] = {2, 4, 5, 7, 4, -2, 5, 6};
	cout << "Array: [ ";
	copy(A, end(A), ostream_iterator<int>(cout, " "));
	cout << "] ";

	int *result = static_cast<int*>(const_cast<void*>(graal::find_if(A, end(A), sizeof(int), &pred)));	
	if(result != end(A))
		cout << "result = " << *result << endl;
	else
		cout << "result = last" << endl;
}
