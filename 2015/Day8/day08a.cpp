#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int mem_size(const char* s){
	int len = 0;
	int ptr = 0;
	
	while(s[ptr] != 0) {
		if (s[ptr] == '\\' && s[ptr+1] == '\\') { ++len; ptr +=2; continue; }
		if (s[ptr] == '\\' && s[ptr+1] == '"')  { ++len; ptr +=2; continue; }
		if (s[ptr] == '\\' && s[ptr+1] == 'x' ) { ++len; ptr +=4; continue; }
		if (s[ptr] == '\"'                    ) {        ptr +=1; continue; }
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
		sum += s.length();
		sum -= mem_size(s.c_str());
	}
	
	cout << sum << endl;
	
	
	return 0;
}