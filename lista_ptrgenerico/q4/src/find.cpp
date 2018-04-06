#include <iostream>
#include <iterator>
#include "find.h"

/*!
 * \param first Pointer to the first element in range.
 * \param last Pointer to the position after last element in range.
 * \param size Size of each element.
 * \param Equal A predicate that performs a equal comparation.
 */
void * graal::find(const void * first , const void * last, size_t size, const void * value, Equal p )
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


