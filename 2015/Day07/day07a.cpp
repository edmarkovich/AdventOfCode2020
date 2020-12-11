/* 
	Parsing:                    ->	Tokens
	[a]         -> [target]		2	3
	[a] AND [b] -> [target]    	4	5
	[a] OR  [b] -> [target]		4	5
	[a] LS  [b] -> [target]		4	5
	[a] RS  [b] -> [target]		4	5
	NOT [a]     -> [target]		3	4
*/

#include <fstream>
#include <iostream>
#include <string>
#include "wire_value.h"

int main() {
	ifstream infile("input.txt");	
	string s1, s2, s3, s4, s5;
	while (infile >> s1) {
		infile >> s2;
		infile >> s3;
		
		if (s2 == "->") {
			// assignment case
			//cout << s1 << endl;
			
			if (isdigit(s1[0])) the_map[s3] = new IntValue (stoi(s1));
			else                the_map[s3] = new GateValue(ASSIGN, s1, "");
			continue;
		}
		
		infile >> s4;
		if (s3 == "->") {
			the_map[s4] = new GateValue(NOT, s2, "");
			continue;
		}
		
		infile >> s5;
		// Operator case
		the_map[s5] = new GateValue( s2gt(s2), s1, s3);
		
	}
	
	
	cout << stringToValue("a") << endl;
	return 0;
}
