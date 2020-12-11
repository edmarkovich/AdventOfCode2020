#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


vector<int> containers;


int min_soln(int start_from, int capacity_so_far) {
	if (capacity_so_far == 150) return 0;
	if (capacity_so_far > 150)  return -1;
	if (start_from == containers.size()) return -1;

	
	int a = min_soln(start_from + 1, capacity_so_far);
	int b = min_soln(start_from + 1, capacity_so_far + containers[start_from]);

	if (a < 0 && b < 0) return -1;
	else if (a >= 0 && b < 0) return a;
	else if (a < 0 && b >= 0) return b +1;
	else return min(a, b+1);
}



int solve(int start_from, int capacity_so_far, int used) {
	if (capacity_so_far == 150) return (used == 4);
	if (capacity_so_far > 150)  return 0;
	if (start_from == containers.size()) return 0;

	return
		solve(start_from + 1, capacity_so_far, used) +
		solve(start_from + 1, capacity_so_far + containers[start_from], used + 1);

}

int main() {
	ifstream infile("input.txt");
	int cont;
	while(infile>>cont){
		containers.push_back(cont);		
	}

	cout << min_soln(0,0) << endl;  //6
	cout << solve(0, 0, 0) << endl;  //6

}