#include <iostream>
#include <iterator>

using namespace std;
// declara um namespace para evitar ambiguidade.
namespace ranges{
	/// implements a function to rotate a vector one time. 
	/*!
	 * \param first Pointer to first element,
	 * \param last Pointer to the last element.
	 */
	void rotate_once(int *first, int *last){
		// save the first value
		int first_value = *first;
		/// move one position left all elements
		while(first < last-1){
			*first = *(first+1);
			first++;
		}
		 /// move first to last element
		*(last-1) = first_value;
	}
	/// implements a function to rotate a vector. 
	/*!
	 * \param first Pointer to first element,
	 * \param last Pointer to the last element.
	 * \param elemento that will be the first.
	 */
	void rotate(int* first, int* last, int* pivot){
		int n = distance(first, pivot);
		/// rotate n times
		for(int i = 0; i < n; i++)
			rotate_once(first, last);
	}
}
// driver function
int main(void){
	int v[] = {1, -2, 3, 6, -3, 0, -3, 4};
	// print vector
	cout << "Vector: ";
	copy(v, end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
	ranges::rotate(begin(v), end(v), &v[3]);
	// print result
	cout << "Resultant Vector: ";
	copy(v, end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}
