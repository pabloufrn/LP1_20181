#include <iostream>
#include <iterator>
#include "equal.h"

using namespace std;
using byte = unsigned char;

bool equal(void * a, void * b)
{
	byte * ba = reinterpret_cast<byte*>(a);
	byte * bb = reinterpret_cast<byte*>(b);
	if(*bb == *ba)
		return true;
	return false;
}

int main()
{
	int A[] = {5, 3, -3, 6, 7};
	int B[] = {5, 3, -3, 6};

	//	print array
	cout << "Array A: [ ";
	copy(A, end(A), ostream_iterator<int>(cout, " "));
	cout << "] \n";
	cout << "Array B: [ ";
	copy(B, end(B), ostream_iterator<int>(cout, " "));
	cout << "] \n";
	// print result
	cout << "Result 1 = ";
	cout <<  graal::equal(begin(A), end(A), begin(B),  &equal) <<  endl;
	cout << "Result 2 = ";
	cout <<  graal::equal(A, end(A), B, end(B), &equal) <<  endl;
}
