#include "quick_sort.h"

/*!
 * \param first Poiter to the first element in the range.
 * \param last Pointer to the position after last element in the range.
 * \param size Size of each element.
 * \param p Some predicate that can be applied at elements.
 */
void * graal::partition(void * first, void * last, size_t size, Predicate p)
{
	byte * bslow = reinterpret_cast<byte*>(first), * bfast = bslow, * bpivot = reinterpret_cast<byte*>(last) - size;
	byte * tmp = new byte(size);
	while(bfast < bpivot)
	{
		if(p(bfast, bpivot) == -1)
		{
			std::memcpy(tmp, bslow, size);
			std::memcpy(bslow, bfast, size);
			std::memcpy(bfast, tmp, size);
			bslow += size;
		}
		bfast += size;
	}
	std::memcpy(tmp, bslow, size);
	std::memcpy(bslow, bpivot, size);
	std::memcpy(bpivot, tmp, size);
	delete tmp;
	return bslow;
}

void graal::qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*))
{
	if(num < 2)
		return;
	byte* blast = reinterpret_cast<byte*>(base) + num*size;
	byte* bbase = reinterpret_cast<byte*>(base);
	byte * dp = reinterpret_cast<byte*>(partition(base, blast, size, compar)); // divide point
	qsort(base, (dp-bbase)/size, size, compar);
	qsort(dp + size, (blast - (dp+size))/size, size, compar);

}
