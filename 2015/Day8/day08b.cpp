#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int lit_eng(const char* s){
	int len = 2; // Open and close quote`
	int ptr = 0;
	
	while(s[ptr] != 0) {
		if (s[ptr] == '\\' || s[ptr] == '"')  { ++len; } // these count as 2
		++len;
		++ptr;
	}
	
	
	return len;
}

int main() {
	
	string s;
	
	ifstream infile("input.txt");
	
	int sum = 0;
	
	while (infile >> s) {
		//cout << s << ":" << mem_size(s.c_str()) << endl;
		sum -= s.length();
		sum += lit_eng(s.c_str());
	}
	
	cout << sum << endl;
	
	
	return 0;
}