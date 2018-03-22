#include <iostream>
#include <iterator>

using namespace std;
// declara um namespace para evitar ambiguidade.
namespace ranges{
	/// implements a function to find the first occurrence to the minimum value in the range. 
	/*!
	 * \param first Pointer to first element,
	 * \param last Pointer to the last element.
	 * \return poiter to the first occurrence of minimum value. 
	 */
	const int* min(const int* first, const int* last){
		// save minimum value
		int* min = (int*) first;
		int* aux = min;
		while(aux < last){
			if(*aux < *min)
				min = aux;
			aux++;
		}
		return min;
	}
}
// driver function
int main(void){
	int v[] = {1, -2, 3, 6, -3, 0, -3, 4};
	// print vector
	cout << "Input: ";
	copy(v, end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
	auto result = ranges::min(begin(v), end(v));
	// print result
	cout << "Result (position): ";
	cout << result-v;
	cout << endl;
	return 0;
}
