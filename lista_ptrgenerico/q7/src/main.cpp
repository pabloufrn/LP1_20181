#include <iostream>
#include <iterator>
#include "partition.h"

using namespace std;

bool pred(void * a)
{
	int * ia = reinterpret_cast<int*>(a);
	if(*ia < 0)
		return true;
	return false;
}

int main()
{
	int A[] = {5, 3, -3, 6, -7, -4, 3, 2, -1};

	//	print array
	cout << "Array A: [ ";
	copy(A, end(A), ostream_iterator<int>(cout, " "));
	cout << "] \n";
	// print result
	int * r = static_cast<int*>(graal::partition(begin(A), end(A), sizeof(int),  &pred));
	cout << "Array A partitioned: [ ";
	copy(begin(A), r, ostream_iterator<int>(cout, " "));
	cout << "] [ ";
	copy(r, end(A), ostream_iterator<int>(cout, " "));
	cout << "]\n";
}
