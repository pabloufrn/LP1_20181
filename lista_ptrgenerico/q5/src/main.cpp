#include <iostream>
#include <iterator>
#include "range_prop.h"

using namespace std;

/// Execute a defined predicate.
/*! 
 * \param a void poiter to be converted on a integer
 * \param b void poiter to be converted on a integer
 * \return true if a and b have the same value; or false otherwise.
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
	int A[] = {2, 4,- 5, 7, -4, 2, -5, 6};
    // print array
	cout << "Array: [ ";
	copy(A, end(A), ostream_iterator<int>(cout, " "));
	cout << "] \n";
    // print result
	cout << "any of = ";
	cout <<  graal::any_of(A, end(A), sizeof(int), &pred) <<  endl;
	cout << "all of = ";
	cout <<  graal::all_of(A, end(A), sizeof(int), &pred) << endl;
	cout << "none of = ";
	cout <<  graal::none_of(A, end(A), sizeof(int), &pred) << endl;
}
