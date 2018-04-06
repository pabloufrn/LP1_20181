#include "find_if.h"
// ==================== Functions ==================== 

void * graal::find_if(const void * first , const void * last, size_t size, Predicate p )
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
