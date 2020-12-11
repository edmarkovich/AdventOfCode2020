#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string, int> the_map;
unordered_set<string>      cities;

void save_dist(string a, string b, int d) { 
	the_map[a+":"+b] = d;
	the_map[b+":"+a] = d;
	cities.insert(a);
	cities.insert(b);
}

int get_dist(string a, string b) {
	return the_map[a+":"+b];
}

vector < vector<string> > make_permutations(vector<string> so_far, vector<string> rest) {
	
	vector < vector<string> > out;
	
	if (rest.size() == 0) {
		out.push_back(so_far);
		return out;
	}
	
	for (vector<string>::iterator it = rest.begin(); it != rest.end(); ++it) {
		vector<string> s1 = so_far;
		s1.push_back(*it);
		vector<string> s2(rest);
		s2.erase( find(s2.begin(), s2.end(), *it));
		
		vector< vector<string> > perm = make_permutations(s1, s2);
		out.insert(out.end(), perm.begin(), perm.end());
	}
	
	return out;
}

int score(vector<string> perm) {
	int sum=0;
	for (int i=0; i<perm.size()-1; i++) {
		sum += get_dist(perm[i], perm[i+1]);
	}
	return sum;
}

void permute(unordered_set<string> cities) {
	vector<string> blank;
	vector<string> rest(cities.begin(), cities.end());
	
	vector < vector < string > > perms = make_permutations(blank, rest);
	
	
	int best = score(perms[0]);
	for (int i =1 ; i < perms.size(); ++i) {
		int tmp = score(perms[i]);
		if (tmp > best) {
			best = tmp;
			cout << best << endl;
		}
	}
	
}

int main() {
	
	ifstream infile("input.txt");
	string from, to, s;
	int len;
	
	while (infile>>from) {
		infile >> s;
		infile >> to;
		infile >> s;
		infile >> len;
		save_dist(from, to, len);
	}
	permute(cities);
	return 0;
}