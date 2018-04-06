#ifndef FIND_H 
#define FIND_H
#include <iostream>

namespace graal{
    using Equal = bool (*) (const void *, const void *);
    using byte = unsigned char;
	void * find(const void * first , const void * last, size_t size, const void * value, Equal p);
}
#endif
