#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int is_nice(const char* s) {
	char last = 0;
	int curr = 0;
	
	int vowels =0;
	bool double_letter = false;
	
	while (s[curr]) {
		switch(s[curr]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u': vowels++; break;
			case 'b': if (last=='a') return 0; break;
			case 'd': if (last=='c') return 0; break;
			case 'q': if (last=='p') return 0; break;
			case 'y': if (last=='x') return 0; break;
		}
		if (s[curr] == last) double_letter = true;
		last = s[curr];
		curr++;
	}
	return vowels > 2 && double_letter;
}


int main() {
	
	ifstream input("input.txt");
	
	string s;
	int nice =0;
	while (input >> s) {
		nice += is_nice(s.c_str());
	}
	cout << nice << endl;
	
}