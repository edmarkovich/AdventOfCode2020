#include <string>
#include <iostream>
using namespace std;

unsigned long long pass2int(const string &s) {
	unsigned long long pow = 1;
	unsigned long long val = 0;
	
	for (int i=7; i>=0; --i) {
		unsigned long long incr = (s[i]-'a')*pow;
		val += incr;
		pow *= 26;
	}

	return val;
};

string int2pass(unsigned long long in) {
	string out;
	while (in>0) {
		string blank(":");
		out = (char)((in % 26)+'a') + out;
		in /= 26;
	}
	return out;
}



int main() {
	

	unsigned long long count=0;
	while(true) {
		++count;
		string x = int2pass(count);
		unsigned long long int    y = pass2int(x);
		
		if (count % 1000000000 == 0) cout << (count*100)/208827064550 << ":" << y-count ;
	}
	
	
	cout << pass2int("hepxcrrq") << endl;
	cout << int2pass(57647112526) << endl;
	
	return 0;
}