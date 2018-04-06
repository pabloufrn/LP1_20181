#include <iostream>
using namespace std;
/// Implements a stack pyramid elements calculator..
/*!
 * \param height height of pyramid.
 * \return number of elements in the pyramid. 
 */
int cannonball(int height){
	if(height <= 0) // base case
		return 0;
	return (height * height) + cannonball(height-1); // recursive call
}
// diver function
int main(){
    //input
	int h;
	cout << "Digite a altura da pilha: ";
	cin >> h;
	int n = cannonball(h); // call function
    // output
	if(n > 0)
		cout << "A pilha tem " << n << " Balls\n";
	else
		cout << "Altura da pilha invalida\n";	

}
