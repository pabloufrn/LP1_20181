#include <iostream>
#include <iterator>

using Predicate = bool (*) (const void *);
using byte = unsigned char;
using namespace std;
bool pred(const void* a)
{
	int ia = *reinterpret_cast<int*>(const_cast<void*>(a));
	if(ia < 0)
		return true;
	return false;
}

void * find_if(const void * first , const void * last, size_t size, Predicate p )
{
	byte* bfirst = reinterpret_cast<byte*>(const_cast<void*>(first));
	while(bfirst < last)
	{
		if(p(reinterpret_cast<void*>(bfirst)))
			return bfirst;
		bfirst+=size;
	}
	return const_cast<void*>(last);
}
int main(void)
{
	int A[] = {2, 4, 5, 7, 4, -2, 5, 6};
	cout << "Array: [ ";
	copy(A, end(A), ostream_iterator<int>(cout, " "));
	cout << "] ";

	int *result = static_cast<int*>(const_cast<void*>(find_if(A, end(A), sizeof(int), &pred)));	
	if(result != end(A))
		cout << "result = " << *result << endl;
	else
		cout << "result = last" << endl;
}

