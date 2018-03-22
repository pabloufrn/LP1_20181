#include <iostream>
#include <iterator>

using namespace std;
// declara um namespace para evitar ambiguidade.
namespace ranges{
	bool lsearch(int *first, int *last, int value )
	{
		while(first < last){
			if(*first == value)
				return true;
			first++;
		}
		return false;
	}

	/// implements a function to eliminate rapeated elements. 
	/*!
	 * \param first Pointer to first element,
	 * \param last Pointer to the last element.
	 * \return new last. 
	 */
	int* unique(int* first, int* last){
		int *slow = first, *fast = first;
		while(fast < last){
			// search for reapeated element
			if(!lsearch(first, fast, *fast)){
				// position after last not repeated element
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
	int v[] = {1, -2, 3, 6, -3, 0, 3, 4, 7, 9, 1, 1};
	int *last = end(v);
	// print vector
	cout << "Vector: ";
	copy(v, last, ostream_iterator<int>(cout, " "));
	cout << endl;
	last = ranges::unique(begin(v), last);
	// print result
	cout << "Result vector: ";
	copy(v, last, ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}
