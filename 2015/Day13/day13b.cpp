#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;


unordered_map<string, unordered_map<string, int> > the_map;
vector<string> names;

void get_input() {
	ifstream infile("input.txt");
	string a,b,c,d, tmp;
	while (infile>>a) {
		infile >> tmp;
		infile >> b;
		infile >> c;
		infile >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp;
		infile >> d;
		d.pop_back();
		
		int gain = stoi(c);
		if (b=="lose") gain *= -1;
		
		the_map[a][d]=gain;
	}
	
	for (auto element: the_map) {
		names.push_back(element.first);
		the_map["me"][element.first] = 0;
		the_map[element.first]["me"] = 0;
	}
}

int score(int me, int left, int right) {
	return the_map[names[me]][names[left]] + 
		   the_map[names[me]][names[right]];
	
}

int score(const vector<int> &perm) {
	int sum = 0;
	for (int i=1; i< perm.size()-1; i++) {
		sum +=score(perm[i], perm[i-1], perm[i+1]);
	}
	
	sum += score(perm[0], perm[1], perm[perm.size()-1]);
	sum += score(perm[perm.size()-1], perm[0], perm[perm.size()-2]);
		
	return sum;
}

int permute() {
	int best_score = -99999;
	
	vector<int> perm={0,1,2,3,4,5,6,7,8};
	do {
		int sc = score(perm);
		if (sc>best_score) {
			best_score = sc;
			cout << "!" << sc << endl;
		} 
		
	} while (next_permutation(perm.begin(), perm.end()));
	
	
	return best_score;
}



int main( ) {
	
	get_input();
	cout << permute() << endl;
	return 0;
	
	vector<string> test = {"aaa", "bbb", "ccc", "000"};
	
	do {
		
		cout << test[0] << endl;
	} while (next_permutation(test.begin(), test.end()));
	
	
	return 0;
}