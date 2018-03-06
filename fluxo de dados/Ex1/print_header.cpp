#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
using namespace std ;
/* *!
   7
 * Print the table ’s header to the terminal ( std :: cout ).
 8
 * @param fields_ Reference to the list of header fields to be printed .
 9
 */
void printHeader(const std::vector<std::string> &fields_)
{
	ostringstream header, border;
	border << '*';
	header << '|';
	for(string field : fields_){
		border << setw(field.length()+1) << setfill('-') << '+';
		header << field << '|';
	}
	cout << border.str() << endl << header.str() << endl << border.str() << endl;
	
}
int main (void) 
{
	std::vector <std::string> fieldNames = { " ITEM " , " QUANTIDADE " , " VALOR UNITARIO " };
	printHeader(fieldNames);
	return EXIT_SUCCESS ;
}
