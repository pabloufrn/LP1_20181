#ifndef FIND_IF_H 
#define FIND_IF_H
#include <iostream>
#include <cstring>
namespace graal{
	// ============== Structs and definitions ============
	using Predicate = bool (*) (const void *);
	using byte = unsigned char;
	void * find_if(const void * first , const void * last, size_t size, Predicate p );
}
#endif
