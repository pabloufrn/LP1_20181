#include <iostream>
#include <iterator>

using namespace std;
// declara um namespace para evitar ambiguidade.
namespace ranges{
	/// implements a function to return dot product of a and b. 
	/*!
	 * \param a_first Pointer to first element of a.
	 * \param a_last Pointer to the last element of a. 
	 * \param b_first Pointer to the first element of a. 
	 * \return dot_product of a and b
	 */
	int dot_product(const int* a_first, const int* a_last, int *b_first){
		int result = 0;
		int d = distance((int*) a_first, (int*) a_last);
		for(int i = 0; i < d; i++){
			result += a_first[i]*b_first[i];
		}
		return result;
	}
}
// driver function
int main(void){
	int A[] = {2, 4, 3};
	int B[] = {1, 2, 3};
	// print vectors
	cout << "Original vector A: ";
	copy(A, end(A), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "Original vector B: ";
	copy(B, end(B), ostream_iterator<int>(cout, " "));
	cout << endl;
	int result = ranges::dot_product(begin(A), end(A), begin(B));
	// print result
	cout << "Result: ";
	cout << result;
	cout << endl;
	return 0;
}
