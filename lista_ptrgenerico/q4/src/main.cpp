#include <iostream>
#include <iterator>
#include "find.h"

using namespace std;

/// Execute a defined predicate.
/*! 
 * \param a void poiter to be converted on a integer
 * \param b void poiter to be converted on a integer
 * \return true if a and b have the same value; or false otherwise.
 */
bool eq(const void* a, const void* b)
{
	int ia = *reinterpret_cast<int*>(const_cast<void*>(a));
	int ib = *reinterpret_cast<int*>(const_cast<void*>(b));
	if(ia == ib)
		return true;
	return false;
}
int main(void)
{
	int A[] = {2, 4, 5, 7, 4, -2, 5, 6};
	cout << "Array: [ ";
	copy(A, end(A), ostream_iterator<int>(cout, " "));
	cout << "] ";

	int *result = static_cast<int*>(const_cast<void*>(graal::find(A, end(A), sizeof(int), A+3, &eq)));	
	if(result != end(A))
		cout << "result = " << *result << endl;
	else
		cout << "result = last" << endl;
}
