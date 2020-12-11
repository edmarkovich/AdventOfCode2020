#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


vector<string> state;

int count_neighn(int row, int col) {

	int top = max(0, row - 1);
	int bot = min(99, row + 1);
	int lef = max(0, col - 1);
	int rig = min(99, col + 1);

	int on = 0;
	for (int i = top; i <= bot; ++i)
		for (int j = lef; j <= rig; ++j)
			if (i == row && j == col) continue;
			else if (state[i][j] == '#') ++on;
	
	return on;
}

vector<string> new_state() {

	vector<string> out;

	for (int i = 0; i < 100; ++i) {
		out.push_back("");
		for (int j = 0; j < 100; ++j) {

			if ((i == 0 || i == 99) && (j == 0 || j = 99)) {
				out[i].push_back('#');
				continue;
			}

			int ns = count_neighn(i, j);
			if (state[i][j] == '#')
				if (ns == 2 || ns == 3) out[i].push_back('#'); else out[i].push_back('.');
			else
				if (ns == 3) out[i].push_back('#'); else out[i].push_back('.');
		}
	}
	
	return out;

}

int main() {
	ifstream infile("input.txt");
	string s;

	while (infile >> s) {
		state.push_back(s);
	}

	for (int i = 0; i < 100; ++i) {
		cout << i << endl;
		state = new_state();
	}

	int count = 0;
	for (int i = 0; i < 100; ++i) 
		for (int j = 0; j < 100; ++j) 
			if (state[i][j] == '#') count++;
	cout << count << endl;
}


