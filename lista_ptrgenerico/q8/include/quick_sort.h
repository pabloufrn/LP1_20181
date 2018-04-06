#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include <iostream>
#include <cstring>

namespace graal 
{
	using Predicate = int (*) (const void *, const void *);
	using byte = unsigned char;
	void qsort (void* base, size_t num, size_t size, int (*compar)(const void*,const void*));
	void * partition(void * first, void * last, size_t size, Predicate p);
}
#endif
