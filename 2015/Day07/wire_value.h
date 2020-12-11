#include <unordered_map>
#include <iostream>
#include <unordered_map>

using namespace std;
enum GateType {AND, OR, LSHIFT, RSHIFT, NOT, ASSIGN};
GateType s2gt(const string &gt) {
		if (gt == "AND") return AND;
		else if (gt == "OR")  return OR;
		else if (gt == "RSHIFT") return RSHIFT;
		else if (gt == "LSHIFT") return LSHIFT;
		else cout << "Oper error: " << gt << endl;
		return AND;
}



class WireValue {
	public:	virtual unsigned short getValue() =0;
};

unordered_map<string, WireValue*> the_map;


unordered_map<string, unsigned short> cache;

unsigned short stringToValue(const string &s) {
		
	if (cache.find(s) != cache.end()) {
		return cache[s];
	} 
	
	unsigned short out;
	if (isdigit(s[0])) out = stoi(s);
	else out = the_map[s]->getValue();
	cache[s] = out;
	return out;
}


class IntValue : public WireValue {
	unsigned short val;
	
	public:
	IntValue(int x) : val(x) {};
	unsigned short getValue() {
		return val; 
	};
};

class GateValue : public WireValue {
	const string inputA, inputB;
	GateType gateType;
	
	public:
	GateValue(GateType gt, const string &a, const string &b) : gateType(gt), inputA(a), inputB(b) {}

	unsigned short getValue() {
		//printSpaces(depth);
		//cout << "Gate: " << gateType << " " << inputA << " " << inputB << endl;
		
		switch(gateType) {
			case AND:    return stringToValue(inputA) & stringToValue(inputB); 
			case OR:     return stringToValue(inputA) | stringToValue(inputB);
			case LSHIFT: return stringToValue(inputA) << stringToValue(inputB);
			case RSHIFT: return stringToValue(inputA) >> stringToValue(inputB);
			case NOT:    return ~stringToValue(inputA);
			case ASSIGN: return stringToValue(inputA);
		}
		cout << "Error" << endl;
		return -1;
	}
};