
#include <iostream>
#include <iterator>

using namespace std;
// declara um namespace para evitar ambiguidade.
namespace ranges{
	/// implements a function to copy a vector 
	/*!
	 * \param first Pointer to first element of source.
	 * \param last Pointer to the last element of source. 
	 * \param d_first Pointer to the first element of dest. 
	 * \return last
	 */
	int* copy(const int* first, const int* last, int *d_first){
		int d = distance(first, last);
		for(int i = 0; i < d; i++){
			d_first[i] = first[i];
		}
		return d_first+d; // new last
	}
}
// driver function
int main(void){
	int A[] = {2, 4, 3};
	int B[] = {1, 2, 3, 4};
	int* b_last = end(B);
	// print vectors
	cout << "Original vector A: ";
	copy(A, end(A), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "Original vector B: ";
	copy(B, b_last, ostream_iterator<int>(cout, " "));
	cout << endl;
	b_last = ranges::copy(begin(A), end(A), begin(B));
	// print result
	cout << "Resultant vector B: ";
	copy(B, b_last, ostream_iterator<int>(cout, " "));
	cout << endl;
	b_last = ranges::copy(begin(A), end(A), begin(B));
	return 0;
}
