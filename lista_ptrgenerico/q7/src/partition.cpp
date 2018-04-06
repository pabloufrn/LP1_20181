#include "partition.h"

/*!
 * \param first Poiter to the first element in the range.
 * \param last Pointer to the position after last element in the range.
 * \param size Size of each element.
 * \param p Some predicate that can be applied at elements.
 */
void * graal::partition(void * first, void * last, size_t size, Predicate p)
{
	byte * bslow = reinterpret_cast<byte*>(first), * bfast = bslow;
	byte * tmp = new byte(size);
	while(bfast < last)
	{
		if(p(bfast))
		{
			std::memcpy(tmp, bslow, size);
			std::memcpy(bslow, bfast, size);
			std::memcpy(bfast, tmp, size);
			bslow += size;
		}
		bfast += size;
	}
	return bslow;
}
