#include <iostream> // std::cout
#include <cstring> // std::memcpy()
#include <utility> // std::pair
#include <iterator> // std:ostream::iterator

// definições
using Compare = int(const void*, const void*); // funcao de compraracao
using byte = unsigned char;
using namespace std;
using UnaryPredicate = bool ( const int * );
// asinaturas
std::pair <int*, int*> array_selected(const int* first , const int* last, UnaryPredicate * p);
/*! 
 * \param value recebe o valor a ser comparado
 * \return true, se o numero fo negativo; ou false, caso contrario
 */
bool pred(const int* value)
{
	if(*value < 0)
		return true;
	return false;
}
/// driver function
int main(void)
{
	int A[] = {5, 3, 4, -1, -6, -4, 9};
	std::pair<int*,int*> par = array_selected(begin(A), end(A), pred);
	cout << "Array result: [ ";
		copy(get<0>(par), get<1>(par), ostream_iterator<int>(cout, " "));
	cout << "] \n";
}
/*!
 * \param first ponteiro para o inicio do intervalo
 * \param first ponteiro para o final do intervalo
 * \param p predicado que sera utilizado
 * \return par que define o intervalo do vetor resultante
 */
std::pair <int*, int*> array_selected(const int* first , const int* last, UnaryPredicate * p)
{
	int *fast = (int*) first; // iterador
	int n_size = 0; // quantidade de elementos que satisfazem o predicado
	// calcula a quantidade de elementos 
	while(fast < last)
	{
		if(p(fast))
			n_size++;
		fast++;
	}
	// aloca novo vetor
	int *result = new int[n_size];
	// (re)inicializa iteradores
	int *rfirst = result;
	int *slow = result;
	fast = (int*) first;
	// preenche o vetor resultante
	while(fast < last)
	{
		if(p(fast))
			*slow++ = *fast;
		fast++;
	}
	return std::make_pair(rfirst, slow);
}
