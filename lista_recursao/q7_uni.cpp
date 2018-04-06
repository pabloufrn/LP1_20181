#include <iostream>
#include <iterator>

using namespace std;
// declara um namespace para evitar ambiguidade.
namespace rec{
	bool lsearch(int *first, int *last, int value )
	{
		while(first < last){
			if(*first == value)
				return true;
			first++;
		}
		return false;
	}
    /// implements to shift left non reapeted elements. 
	/*!
	 * \param first Pointer to first element,
	 * \param last Pointer to the last element.
     * \param slow new slow pointer.
     * \param fast new fast pointer.
	 * \return new last. 
	 */
	int* exe_unique(int* first, int* last, int* slow, int* fast)
	{
		if(fast == last)
			return slow;
		if(!lsearch(first, fast, *fast)){
			// position after last not repeated element
			*slow = *fast;
			slow++;
		}
		fast++;
		return exe_unique(first, last, slow, fast);	
	}
	/// implements a function to eliminate rapeated elements. 
	/*!
	 * \param first Pointer to first element,
	 * \param last Pointer to the last element.
	 * \return new last. 
	 */
	int* unique(int* first, int* last){
		return exe_unique(first, last, first, first);
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
	last = rec::unique(begin(v), last);
	// print result
	cout << "Result vector: ";
	copy(v, last, ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}
