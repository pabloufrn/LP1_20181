#include "clone.h"

/// copy sequecial memory block
/* \param first pointer to the first element.
 * \param last pointer to the post-last element.
 */
void* graal::clone(void* first , void* last)
{
	// convert the range edges to a type we can operate
	byte* bfirst = reinterpret_cast<byte*>(first);
	byte* blast = reinterpret_cast<byte*>(last);
	// we need to ensure we have sufficient memory to store resultant range.
	byte* copy = new byte(blast-bfirst);
	memcpy(copy, bfirst, blast-bfirst);
	return copy;
}
