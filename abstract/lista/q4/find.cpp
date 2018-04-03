#include <iostream>
#include <iterator>

using Equal = bool (*) (const void *, const void *);
using byte = unsigned char;
using namespace std;
bool eq(const void* a, const void* b)
{
	int ia = *reinterpret_cast<int*>(const_cast<void*>(a));
	int ib = *reinterpret_cast<int*>(const_cast<void*>(b));
	if(ia == ib)
		return true;
	return false;
}

void * find(const void * first , const void * last, size_t size, const void * value, Equal p )
{
	byte* bfirst = reinterpret_cast<byte*>(const_cast<void*>(first));
	while(bfirst < last)
	{
		if(p(reinterpret_cast<void*>(bfirst), value))
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

	int *result = static_cast<int*>(const_cast<void*>(find(A, end(A), sizeof(int), A+3, &eq)));	
	if(result != end(A))
		cout << "result = " << *result << endl;
	else
		cout << "result = last" << endl;
}

