#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


vector<int> containers;


int solve(int start_from, int capacity_so_far) {
	if (capacity_so_far == 150) return 1;
	if (capacity_so_far > 150)  return 0;
	if (start_from == containers.size()) return 0;

	return
		solve(start_from + 1, capacity_so_far) +
		solve(start_from + 1, capacity_so_far + containers[start_from]);

}

int main() {
	ifstream infile("input.txt");
	int cont;
	while(infile>>cont){
		containers.push_back(cont);		
	}

	cout << solve(0,0) << endl;

}