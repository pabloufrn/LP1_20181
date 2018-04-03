#include <iostream>
#include <iterator>

using Pred = bool (*) (const void *);
using byte = unsigned char;
using namespace std;
bool pred(const void* a)
{
	int ia = *reinterpret_cast<int*>(const_cast<void*>(a));
	if(ia < 0)
		return true;
	return false;
}
bool any_of(const void * first , const void * last, size_t size, Pred p )
{
	byte* bfirst = reinterpret_cast<byte*>(const_cast<void*>(first));
	while(bfirst < last)
	{
		if(p(reinterpret_cast<void*>(bfirst)))
			return true;
		bfirst+=size;
	}
	return false;
}
bool all_of(const void * first , const void * last, size_t size, Pred p )
{
	byte* bfirst = reinterpret_cast<byte*>(const_cast<void*>(first));
	while(bfirst < last)
	{
		if(!p(reinterpret_cast<void*>(bfirst)))
			return false;
		bfirst+=size;
	}
	return true;
}
bool none_of(const void * first , const void * last, size_t size, Pred p )
{
	if(any_of(first, last, size, p))
		return false;
	return true;
}
int main(void)
{
	int A[] = {2, 4, -5, 7, -4, -2, -5, -6};
	cout << "Array: [ ";
	copy(A, end(A), ostream_iterator<int>(cout, " "));
	cout << "] \n";
	cout << "any of = ";
	cout <<  any_of(A, end(A), sizeof(int), &pred) <<  endl;
	cout << "all of = ";
	cout <<  all_of(A, end(A), sizeof(int), &pred) << endl;
	cout << "none of = ";
	cout <<  none_of(A, end(A), sizeof(int), &pred) << endl;
}

