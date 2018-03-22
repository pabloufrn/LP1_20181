#include <iostream>
#include <iterator>

using namespace std;
// declara um namespace para evitar ambiguidade.

enum ball_t{B, W}; 
namespace ranges{
	// implements separe black and write marbles. 
	/*!
	 * \param first Pointer to first element,
	 * \param last Pointer to the last element.
	 * \return write's start position. 
	 */
	ball_t* sort_marbles(ball_t* first, ball_t* last){
		ball_t *slow = first, *fast = first;
		while(fast < last){
			if(*fast == B){
				swap(*slow, *fast);
				slow++;
			}
			fast++; 
		}
		return slow;
	}
}
// driver function
int main(void){
	ball_t v[] = {W, W, B, W, B, B, B};
	// print vector
	cout << "Vector: ";
	copy(v, end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
	auto result = ranges::sort_marbles(begin(v), end(v));
	// print result
	cout << "Last of Writes (index): " << (result - begin(v));
	cout << "\nResult vector: ";
	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}
