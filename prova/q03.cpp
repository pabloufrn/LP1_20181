#include <iostream> 	// std::cout
#include <cstring> 	// std::string 
#include <iterator>	// std:ostream_iterator
#include <fstream>	// std::ifstream
#include <sstream>	// std::stringstream
#include <vector>	// std::vector
// definições
using Compare = int(const void*, const void*);
using namespace std;

int percorrer(vector<int>::iterator first, vector<int>::iterator last);
int main(void)
{
	// abre o arquivo
	ifstream file;
	file.open("input.dat");
	std::vector<int> vet; // vetor do caminho
	
	// obtem uma linha do arquivo
	std::string line;
	while(std::getline(file, line))
	{
	    std::stringstream ss(line);
	    int i; // valor a set 
	    while( ss >> i ) 
	       vet.push_back(i);
	    // gera a saida
	   int saida = percorrer(begin(vet), end(vet));
	   vet.clear(); // limpa o vetor de caminho
	   cout << "bateria minima = " << saida << "\n";
	}
}

int percorrer(vector<int>::iterator first, vector<int>::iterator last)
{
	int bateria = 0;
	int min = 0; 
	int max = 0;
	first++;
	while(first < last)
	{
		bateria -= *first - *(first-1);
		if(bateria > max)
			max = bateria;
		else if(bateria < min)
			min = bateria;
		first++;
	}
	return max - min;
}
