#include <iostream>
#include <iterator>
#include "clone.h"

using namespace std;
int main(void)
{
	string A[] = {"um", "dois", "tres", "quatro", "cinco"};

	cout << "----- Before Reverse -----\n";
	cout << "Array A: [ ";
	copy(begin(A), end(A), ostream_iterator<string>(cout, " "));
	cout << "]\n";
	// Clone Array in range [1, 3]
	string *B = reinterpret_cast<string*>(graal::clone(begin(A)+1, end(A)-1));
	// -------------
	cout << "------ Copied Array ------\n";
	cout << "Array B: [ ";
	copy(B, B+(end(A)-begin(A)-2), ostream_iterator<string>(cout, " "));
	cout << "]\n";
}
