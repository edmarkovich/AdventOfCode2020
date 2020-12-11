#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

const int numIngr = 4;


int score(vector<int> ing) {

	int out = 1;

	short props[4][5] = {
		{ 4, -2, 0, 0, 5},
		{ 0, 5, -1, 0, 8},
		{-1, 0,  5, 0, 6},
		{ 0, 0, -2, 2, 1} };

	//Calories check
	int catsum = 0;
	for (int i = 0; i < 4; ++i) {
		catsum += ing[i] * props[i][4];
	}
	if (catsum != 500) return 0;

	for (int cat = 0; cat < 4; cat++) {
		int catsum = 0;
		for (int i = 0; i < 4; ++i) {
			catsum += ing[i] * props[i][cat];
		}
		if (catsum <= 0) return 0;
		out *= catsum;
	}
	return out;
}

int permute(vector<int> so_far) {
	int sum = accumulate(so_far.begin(), so_far.end(), 0);
	
	if (sum == 100) {		
		so_far.resize(4, 0);
		return score(so_far);
	}

	if (so_far.size() == 3) {
		so_far.push_back(100 - sum);
		return score(so_far);
	}

	so_far.push_back(0);
	int best_score = -1;
	for (int i = 0; i <= 100 - sum; ++i) {
		so_far[so_far.size() - 1] = i;
		int score = permute(so_far);
		best_score = max(score, best_score);
	}

	return best_score;
}

int main() {

	vector<int> v;
	cout << permute(v) << endl;

}
