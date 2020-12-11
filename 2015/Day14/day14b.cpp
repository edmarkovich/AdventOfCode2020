#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int traveled(int speed, int burst, int rest, int snapshot) {
	
	int cycle = burst + rest;
	int cycles = snapshot / cycle;
	
	return speed * ((cycles * burst) + min(snapshot%cycle,burst));
}


int deer[9][4];

void race() {
	
	for (int i=1; i<=2503; i++) {
		int best_score =0;
		int best_deer  =0;
		
		for (int j=0; j<9; ++j) {
			int sc= traveled(deer[j][0],deer[j][1],deer[j][2],i);
			if (sc>best_score) {
				best_score = sc;
			}
		}
		
		for (int j=0; j<9; ++j) {
			int sc= traveled(deer[j][0],deer[j][1],deer[j][2],i);
			if (sc==best_score) {
				deer[j][3]++;
			}
		}
		
		
		
	}
	
	for (int j=0; j<9; ++j) {
		cout << deer[j][3] << endl;
	}
	
}

int main() {
	
	//Dancer can fly 27 km/s for 5 seconds, but then must rest for 132 seconds.

	string trash;
	int speed, burst, rest;
	ifstream infile("input.txt");
	int count = 0;
	while (infile >> trash) {
		infile >> trash; infile >> trash;
		infile >> speed >> trash >> trash
			>> burst >> trash >> trash >> trash >> trash >> trash >> trash
				>> rest >> trash;
			
		//cout << count << ":" <<  speed << ":" << burst << ":" << rest << endl;
		//cout << traveled(speed,burst,rest,2503) << endl;
		deer[count][0] = speed;
		deer[count][1] = burst;
		deer[count][2] = rest;
		deer[count][3] = 0;
		count++;
	}
	race();
	
	
	
	return 0;
}