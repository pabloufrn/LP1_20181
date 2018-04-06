#include "range_prop.h"

/*!
 * \param first Poiter to the first element.
 * \param last Pointer to the position after last element.
 * \param size Size of each element.
 * \param p Predicate to to used in the elements.
 * \return true if p is valid at some element in the range; or false otherwise.
 */
bool graal::any_of(const void * first , const void * last, size_t size, Pred p )
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
/*!
 * \param first Poiter to the first element.
 * \param last Pointer to the position after last element.
 * \param size Size of each element.
 * \param p Predicate to to used in the elements.
 * \return true if p is valid at all range; or false otherwise.
 */
bool graal::all_of(const void * first , const void * last, size_t size, Pred p )
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
/*!
 * \param first Poiter to the first element.
 * \param last Pointer to the position after last element.
 * \param size Size of each element.
 * \param p Predicate to to used in the elements.
 * \return true if p is false for all elements; or false otherwise.
 */
bool graal::none_of(const void * first , const void * last, size_t size, Pred p )
{
	return !any_of(first, last, size, p);

}


