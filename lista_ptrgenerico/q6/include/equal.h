#ifndef EQUAL_H
#define EQUAL_H
#include <iostream>

namespace graal 
{
	using byte = unsigned char;
	using Predicate = bool (*) (void *, void *);
	bool equal(void * first, void * last, void * first2, Predicate eq);
	bool equal(void * first, void * last, void * first1, void * first2, Predicate eq);
}
#endif
