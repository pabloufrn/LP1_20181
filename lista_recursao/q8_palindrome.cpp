#include <iostream>

using namespace std;

/// Implements a palidrome string  checker.
/*!
 * \param str a string.
 * \return true, if str is a palindrime; or false, if str is not a palindrome. 
 */
bool palindrome(string str){
	if(str.size() <= 1)
		return true;
	if(str[0] != str[str.size()-1])
		return false;
	return palindrome(str.substr(1, str.size()-2));
}
// diver function
int main(){
	string str;
	cout << "Digite a palavra: ";
	cin >> str;
	bool r = palindrome(str);
	if(r)
		cout << "A palavra digitada eh um palindromo.\n";
	else
		cout << "A palavra digitada nao eh um palindromo.\n";
}
