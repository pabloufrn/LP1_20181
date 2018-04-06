#ifndef CLONE_H
#define CLONE_H
#include <iostream>
#include <cstring>
namespace graal{
	using byte = unsigned char;
	void* clone(void* first , void* last);
}
#endif
