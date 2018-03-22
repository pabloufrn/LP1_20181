#include <iostream>
#include <iterator>

int* insertion(int* first, int* last, int value){
	int* aux = last--;
	while(first < last && value <= *aux){
		*aux = *(aux-1);
		aux--;
	}
	*aux = value;
	return last+1;

}
void print_array(int* first, int* last){
	std::cout << "Array: [";
	std::copy(first, last, std::ostream_iterator<int>(std::cout, "" ));
	std::cout << "], size = " << std::distance(first, last) << std::endl;
}
int main(){
	const size_t N(10);
	int A[N];
	int* first = std::end(A);
	int* last(std::begin(A)+1);
	print_array(std::begin(A), std::end(A));
	for(auto i(0); i < 10; ++i){
		last = insertion(std::begin(A),  last, (i+1)*10);
		print_array(first, std::end(A));
	}
	return 0;
}
