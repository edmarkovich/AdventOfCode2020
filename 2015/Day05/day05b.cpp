#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int is_nice(const string &s) {
	bool cond1 = false;
	bool cond2 = false;
	for (int i=0; i< s.length()-2; ++i) {
		if (s[i] == s[i+2] && s[i] != s[i+1]) cond2 = true;
		
		string tgt("");
		tgt += s[i];
		tgt += s[i+1];

		if (s.find(tgt, i+2) != string::npos) cond1 = true;
	}
	return cond1 && cond2;
}


int main() {
	
	ifstream input("input.txt");
	
	string s;
	int nice =0;
	while (input >> s) {
		nice += is_nice(s);
	}
	cout << nice << endl;
	
}