#include <fstream>
#include <string>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;


int compute_ribbon(int l, int w, int h) {
	int extra = min(w+w+h+h, w+w+l+l);
	extra = min(extra, h+h+l+l);

	return extra + (l*w*h);
}



int main() {
	int sum = 0;
	ifstream infile("input.txt");
	
	char s[20];
	while (infile >> s) {
		
		char *token1 = strtok(s,"x");
		char *token2 = strtok(NULL,"x");
		char *token3 = strtok(NULL,"x");
		
		sum += compute_ribbon(atoi(token1), atoi(token2), atoi(token3));
		
	}
	cout << sum << endl;
}