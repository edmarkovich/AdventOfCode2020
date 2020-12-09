#include <string>
#include <iostream>
using namespace std;


string look_say(const string in, int iterations) {
	
	string out;
	char current=in[0];
	int run = 1;
	
	for (int i=1; i<in.length(); ++i) {
		if (in[i] == current) { run++; }
		else {
			out += to_string(run);
			out += current;
			current = in[i];
			run =1;
		}
	}
	out += to_string(run);
	out += current;	
	
	if (iterations == 1) return out;
	else return( look_say(out, iterations-1));
}


int main() {
	cout << look_say("1113222113", 50).length() << endl;
	return 0;
}
	
	