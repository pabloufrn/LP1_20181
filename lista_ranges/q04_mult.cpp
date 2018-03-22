#include <iostream>
#include <iterator>

using namespace std;
// declara um namespace para evitar ambiguidade.
namespace ranges{
	/// implements a function to find the first occurrence to the minimum value in the range. 
	/*!
	 * \param first Pointer to first element,
	 * \param last Pointer to the last element.
	 */
	void scalar_multiplication(int* first, int* last, int scalar){
		while(first < last){
			*first *= scalar;
			first++;
		}
		return;
	}
}
// driver function
int main(void){
	int v[] = {1, -2, 3, 6, -3, 0, -3, 4};
	// print vector
	cout << "Original vector: ";
	copy(v, end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
	int scalar = 4;
	ranges::scalar_multiplication(begin(v), end(v), scalar);
	// print result
	cout << "Resultant vector: ";
	copy(v, end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}
