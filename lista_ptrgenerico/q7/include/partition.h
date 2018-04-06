#ifndef PARTITION_H
#define PARTITION_H
#include <iostream>
#include <cstring>

namespace graal 
{
	using byte = unsigned char;
	using Predicate = bool (*) (void *);
	void * partition(void * first, void * last, size_t size, Predicate p);
}
#endif
