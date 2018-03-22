#include <iostream>
#include <iterator>
#include <cstring>
using namespace std;
using byte = unsigned char;
void troca(void *a, size_t count, size_t size){
	byte *temp = new byte[size];
	byte *f = static_cast<byte*>(a);
	for(int i = 0; i < (int) count/2; i++){
		memcpy(temp, f+(i*size), size);
		memcpy(f+(i*size), f+((count-1-i)*size), size);
		memcpy(f+((count-1-i)*size), temp, size);
	}
	delete [] temp;
}
int main(){
	size_t size = 5;
	string s[] = {"um", "dois", "tres", "quatro", "cinco"};
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
	troca(s, size, sizeof(string));	
	troca(i, size, sizeof(int));	
	troca(c, size, sizeof(char));	
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
