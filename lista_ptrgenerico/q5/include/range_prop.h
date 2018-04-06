#ifndef RANGE_PROP_H 
#define RANGE_PROP_H
#include <iostream>

namespace graal{
    using Pred = bool (*) (const void *);
    using byte = unsigned char;
	bool any_of(const void * first , const void * last, size_t size, Pred p );
    bool all_of(const void * first , const void * last, size_t size, Pred p );
    bool none_of(const void * first , const void * last, size_t size, Pred p );
}
#endif
