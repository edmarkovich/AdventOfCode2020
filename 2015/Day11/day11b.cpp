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


bool ok_password(const char *s) {
	bool straight=false;
	char pair1=0;
	char pair2=0;

	for (int i =0; i < strlen(s); ++i) {
		if (s[i]=='i' || s[i]=='o' || s[i]=='l') return false;
		if (i>1 && s[i-1] == s[i]-1 && s[i-2] == s[i]-2) straight = true;
		if (!pair1 && i>0 && s[i] == s[i-1]) pair1 = s[i];		
		if (pair1 && !pair2 && s[i] == s[i-1] && s[i] != pair1) pair2 = s[i];
	}
	return straight && pair1 && pair2;
}


int main() {

	unsigned long long count=pass2int("hepxxyzz");
	while(true) {
		++count;
		string x = int2pass(count);
		if (ok_password(x.c_str())) {
				cout << x  << endl;
				return 1;
		}
	}
	
	return 0;
}
