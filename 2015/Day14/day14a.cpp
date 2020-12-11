#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

int traveled(int speed, int burst, int rest, int snapshot) {
	
	int cycle = burst + rest;
	int cycles = snapshot / cycle;
	
	return speed * ((cycles * burst) + min(snapshot%cycle,burst));
}


int main() {
	
	//Dancer can fly 27 km/s for 5 seconds, but then must rest for 132 seconds.

	string trash;
	int speed, burst, rest;
	ifstream infile("input.txt");
	while (infile >> trash) {
		infile >> trash; infile >> trash;
		infile >> speed >> trash >> trash
			>> burst >> trash >> trash >> trash >> trash >> trash >> trash
				>> rest >> trash;
			
		//cout << speed << ":" << burst << ":" << rest << endl;
		cout << traveled(speed,burst,rest,2503) << endl;
	}
	
	
	
	
	return 0;
}