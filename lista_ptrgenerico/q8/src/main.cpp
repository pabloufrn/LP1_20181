#include <iostream>
#include <iterator>
#include "quick_sort.h"

using namespace std;

int pred(const void * a, const void * b)
{
	int * ia = reinterpret_cast<int*>(const_cast<void*>(a));
	int * ib = reinterpret_cast<int*>(const_cast<void*>(b));
	if(*ia < *ib)return -1;
	if(*ia > *ib)return 1;
	else return 0;
}

int main()
{
    {
    int A[] = {4, 6, 2, 8, 7};
	//int A[] = {5, 3, -3, 6, -7, -4, 3, 2, -1, 15, 2, 5, 1, 9, 10};
	//	print array
	cout << "Array A: [ ";
	copy(A, end(A), ostream_iterator<int>(cout, " "));
	cout << "]\n";
	// print result
	graal::qsort(begin(A), end(A)-begin(A), sizeof(int),  &pred);
	cout << "Array A sorted: [ ";
	copy(A, end(A), ostream_iterator<int>(cout, " "));
	cout << "]\n";
    }
}
