#include <iostream>
#include <iterator>

using namespace std;
// declara um namespace para evitar ambiguidade.
namespace ranges{
	/*!
	 * \param first Pointer to first element,
	 * \param last Pointer to the last element. 
	 */
	void negate(int* first, int* last){
		/// negate all elements from first to last.
		while(first < last){
			*first = -*first;
			first++;
		}
		return;
	}
}
// driver function
int main(void){
	int v[] = {1, -2, 3};
	// print original vector
	cout << "Input: ";
	copy(v, end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
	ranges::negate(begin(v), end(v));
	// print post-negate vector
	cout << "Result: ";
	copy(v, end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}
