#include <iostream>
#include <iterator>
#include "reverse.h"

using namespace std;
int main(void)
{
	int A[] = {1, 2, 3, 4, 5};

	cout << "----- Before Reverse -----\n";
	cout << "Array A: [";
	copy(begin(A), end(A), ostream_iterator<int>(cout, " "));
	cout << "]\n";

	// Apply Reverse
	graal::reverse(begin(A), end(A), sizeof(int));
	// -------------
	cout << "----- After Reverse ------\n";
	cout << "Array A: [";
	copy(begin(A), end(A), ostream_iterator<int>(cout, " "));
	cout << "]\n";
}
