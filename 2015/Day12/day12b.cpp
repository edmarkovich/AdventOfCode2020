#include <string>
#include <iostream>
#include <regex>
#include <fstream>
using namespace std;

int sumString(const string &str) {

	int sum = 0;
	
	regex r("-?([0-9]+)");
	smatch m;

	string::const_iterator ss ( str.cbegin() );
	while( regex_search (ss, str.cend(), m, r)) {
		//cout << m[0] << endl;
		sum += stoi(m[0]);
		ss = m.suffix().first;
	}	
	return sum;
}

int main() {
	ifstream infile("input.txt");
	string s;
	while (infile>>s) {
		cout << sumString(s) << endl;
	}
	return 0;
}


