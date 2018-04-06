#include <iostream>
#include <vector>
using namespace std;

/// Implements a function that prints pascal triangle.
/*!
 * \param n any non negative integer.
 * \return a vector with the last line of pascal triangle. 
 */
vector<int> pascal(int height)
{
	vector<int> result(height);
	if(height == 1){
		cout << "1\n";
		result[0] = 1;
		return result;
	}
	vector<int> vect = pascal(height-1);
	result[0] = 1;
	cout << "1 ";
	for(int i = 1; i < height-1; ++i){
		result[i] = vect[i-1] + vect[i];
		cout << result[i] << " ";
	}
	result[height-1] = 1;
	cout << "1\n";
	return result;
}
// driver function
int main(){
	int n;
	cout << "Digite n: ";
	cin >> n;
	pascal(n);
}
