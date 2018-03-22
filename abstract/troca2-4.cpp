#include <iostream>
#include <iterator>
#include <cstring>
using namespace std;
using byte = unsigned char;
void troca(void *a, size_t size){
	byte * temp = new byte[size];
	byte *f = static_cast<byte*>(a);
	//*temp = f[size*2];
	memcpy(temp, f+(2*size), size);
	//WARNIG, NAO FUNCIONA, f[size*2] = f[size*4];
	memcpy(f+(2*size), f+(4*size), size);
	//WARNING, NAO FUNCIONA, f[size*4] = *temp;
	memcpy(f+(4*size), temp, size);
	delete [] temp;
}
int main(){
	size_t size = 5;
	string s[] = {"um", "dois", "tres", "quadro", "cinco"};
	int i[] = {1, 2, 3, 4, 5};
	char c[] = {'1', '2', '3', '4', '5'};	
	cout << "s : ";
	copy(s, end(s), ostream_iterator<string>(cout, " "));
        cout << endl;	
	cout << "i : ";
	copy(i, end(i), ostream_iterator<int>(cout, " "));
        cout << endl;	
	cout << "c : ";
	copy(c, end(c), ostream_iterator<char>(cout, " "));
        cout << endl;
	troca(s, sizeof(string));	
	troca(i, sizeof(int));	
	troca(c, sizeof(char));	

	cout << "s : ";
	copy(s, s+size, ostream_iterator<string>(cout, " "));
        cout << endl;	
	cout << "i : ";
	copy(i, i+size, ostream_iterator<int>(cout, " "));
        cout << endl;	
	cout << "c : ";
	copy(c, c+size, ostream_iterator<char>(cout, " "));
        cout << endl;
}
