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
	void partition(int* first, int* last, int *pivot){
		swap(*pivot, *(last-1));
		pivot = last-1;
		int *slow = first, *fast = first;
		while(fast < last){
			if(*fast < *pivot){
				swap(*slow, *fast);
				slow++;
			}
			fast++; 
		}
		swap(*slow, *pivot);
	}
}
// driver function
int main(void){
	int v[] = {1, 7, 3, 6, -3, 7, 6, 5, 4, 3, 2, 6, 4, 5, 8, 9, 6};
	int *last = end(v);
	int *pivot = &v[3];
	cout << "Pivot: " << *pivot << endl;
	// print vector
	cout << "Original vector: ";
	copy(v, last, ostream_iterator<int>(cout, " "));
	cout << endl;
	ranges::partition(v, last, pivot);
	// print result
	cout << "Resultant Vector: ";
	copy(v, last, ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}
