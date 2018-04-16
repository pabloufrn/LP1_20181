#include "reverse.h"

/// iterative function to reverse all elements in range [first, last)
/* \param first pointer to the first element.
 * \param last pointer to the post-last element.
 * \param size size of each element.
 */
void graal::reverse(void* first , void* last, size_t size)
{
	// convert the range edges to a type we can operate
	byte* bfirst = reinterpret_cast<byte*>(first);
	byte* blast = reinterpret_cast<byte*>(last) - size;
	/// get the middle-left element.
	byte* bmiddle = bfirst + (std::distance(bfirst, blast)/2) - size;
	// we need to ensure we have sufficient memory to operate (size bytes).
	byte aux[size]; 
	while(bfirst < bmiddle)
	{
		// generic swap
		memcpy(aux, bfirst, size);
		memcpy(bfirst, blast, size);
		memcpy(blast, aux, size);
		// decrease interval
		bfirst += size;
		blast -= size;
	}
}
