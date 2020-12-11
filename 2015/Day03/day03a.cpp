#include <utility> //for pair
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int locX = 0;
int locY = 0;
set< pair<int,int> > locations;

void move(char c) {
	switch (c) {
		case '^': locY--; break;
		case 'v': locY++; break;
		case '<': locX--; break;
		case '>': locX++; break;
	}
	
	pair<int, int> loc(locX, locY);
	locations.insert(loc);
	
}

int main() {
	
	ifstream infile("input.txt");
	
	char c;
	while (infile >> c) {
		move(c);
	}
	cout << locations.size() << endl;
}