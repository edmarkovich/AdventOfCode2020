#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <cstring>
#include <sstream>
using namespace std;


enum actionTypes {on, off, toggle};
typedef pair<int,int> Coords;

bool lights[1000][1000];

Coords parseCoords (const string &s) {

	stringstream ss(s);
	string tmp1, tmp2;
	getline(ss, tmp1, ','); 
	getline(ss, tmp2, ',');

	return Coords(stoi(tmp1),stoi(tmp2));
}

void doIt(actionTypes action, Coords from, Coords to) {
	
	
	for (int i=from.first; i<=to.first; ++i) {
		for (int j=from.second; j<=to.second; j++) {
				switch (action) {
					case on: lights[i][j] = true; break;
					case off: lights[i][j] = false; break;
					case toggle: lights[i][j] = !lights[i][j];
				}
		}
	}
}

int count() {
	int sum = 0;
	for (int i=0; i<1000; ++i) {
		for (int j=0; j<1000; j++) {
			sum += lights[i][j];
		}
	}
	return sum;
}

int main() {
	ifstream infile("input.txt");
	
	string verb;
	actionTypes action;
	string coords1, coords2;
	
	while(infile >> verb) {
		if (verb == "turn") {
			infile >> verb;
			action = (verb=="on")?on:off;
		} else {
			action = toggle;
		}
		
		infile >> coords1;
		infile >> verb; //consume the "through"
		infile >> coords2;
		
		doIt(action, parseCoords(coords1), parseCoords(coords2));
	}
	
	cout << count() << endl;
}