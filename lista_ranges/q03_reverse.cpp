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
	void reverse(int* first, int* last){
		last--;
		while(first < last){
			swap(*first, *last); // swaps the range limits 
			first++; // decrease range size
			last--;
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
	ranges::reverse(v, end(v));
	// print result
	cout << "Resultant Vector: ";
	copy(v, end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}
