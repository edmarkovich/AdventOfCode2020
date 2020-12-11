#include <fstream>
#include <string>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;


int compute_area(int l, int w, int h) {
	int extra = min(l*w, l*h);
	extra = min(extra, w*h);

	return extra + (2*l*w) + (2*w*h) + (2*h*l);
}



int main() {
	int sum = 0;
	ifstream infile("input.txt");
	
	char s[20];
	while (infile >> s) {
		
		char *token1 = strtok(s,"x");
		char *token2 = strtok(NULL,"x");
		char *token3 = strtok(NULL,"x");
		
		sum += compute_area(atoi(token1), atoi(token2), atoi(token3));
		
	}
	cout << sum << endl;
}