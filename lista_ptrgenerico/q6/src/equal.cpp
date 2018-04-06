#include "equal.h"

/*!
 * \param first Poiter to the first element of the first range.
 * \param last Pointer to the position after last element of first range.
 * \param first Poiter to the first element of the second range.
 * \param p Predicate that performs a equal verification.
 * \return true if the first range is equal to the range [first2;first2+(last1-first1)[; or false otherwise.
 */
bool graal::equal(void * first, void * last, void * first2, Predicate eq)
{
	byte * bfirst = reinterpret_cast<byte*>(first);
	byte * bfirst2 = reinterpret_cast<byte*>(first2);
	while(bfirst < last)
	{
		if(!eq(bfirst, bfirst2))
			return false;
		bfirst++;
		bfirst2++;
	}
	return true;
}
/*!
 * \param first Poiter to the first element of the first range.
 * \param last Pointer to the position after last element of first range.
 * \param first Poiter to the first element of the second range.
 * \param last Pointer to the position after last element of second range.
 * \param p Predicate that performs a equal verification.
 * \return true if the first range is equal to the second range; or false otherwise.
 */
bool graal::equal(void * first, void * last, void * first2, void * last2, Predicate eq)
{
	byte * bfirst = reinterpret_cast<byte*>(first);
	byte * bfirst2 = reinterpret_cast<byte*>(first2);
	while(bfirst < last && bfirst2 < last2)
	{
		if(!eq(bfirst, bfirst2))
			return false;
		bfirst++;
		bfirst2++;
	}
	return true;
}
