#include <fstream>
#include <iostream>
#include "md5.h"
using namespace std;


bool tryHash(int x) {
		string s("yzbqklnj");
		s+=	to_string(x);
		
	
		s=md5(s);
		return  s[0] == '0' && 
				s[1] == '0' &&  
				s[2] == '0' &&  
				s[3] == '0' &&
				s[4] == '0' &&				
				s[5] == '0';		
}


int main() {

	for (int i=1; i; i++) {
		if (tryHash(i)) {
			cout << "Answer: " << i << endl;
			return -1;
		}
		
		if (i % 10000 == 0) cout << ".";
		if (i % 100000 == 0) cout << "o";
	}
}