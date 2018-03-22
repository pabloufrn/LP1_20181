#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int main(){
	vector<int> vet;
	int val;
	ifstream ifs("input.txt");
	while(ifs >> val)
		vet.push_back(val);

}
