#include <iostream>
#include <iterator>

using namespace std;
// declara um namespace para evitar ambiguidade.
namespace ranges{
	/// implements a function to find the first occurrence to the minimum value in the range. 
	/*!
	 * \param first Pointer to first element,
	 * \param last Pointer to the last element.
	 * \return new last. 
	 */
	int* compact(int* first, int* last){
		int *slow = first, *fast = first;
		while(fast < last){
			if(*fast > 0){
				*slow = *fast;
				slow++;
			}
			fast++; 
		}
		return slow;
	}
}
// driver function
int main(void){
	int v[] = {1, -2, 3, 6, -3, 0, -3, 4};;
	int *last = end(v);
	// print vector
	cout << "Original vector: ";
	copy(v, last, ostream_iterator<int>(cout, " "));
	cout << endl;
	last = ranges::compact(v, last);
	// print result
	cout << "Resultant Vector: ";
	copy(v, last, ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}
