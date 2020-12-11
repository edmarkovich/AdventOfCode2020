#include <string>
#include <iostream>
#include <regex>
#include <fstream>
using namespace std;



int parse_string(const char **s) {
	assert(**s=='\"');
	++(*s);
	
	if ((*s)[0]=='r' && (*s)[1]=='e' && 
		(*s)[2]=='d' && (*s)[3]=='\"') {
			(*s)+=4;
			return 1;
		}	
		
		while(**s!='\"') {
			++(*s);
		}
		++(*s);
		return 0;
}
	
int parse_number(const char **s) {
	int sum=0;
	int sign=1;
	
	if (**s=='-') {
		sign = -1;
		++(*s);
	}
	
	while(**s>='0' && **s<='9') {

		sum *= 10;
		sum += (**s - '0');
		++(*s);
	}
	
	return sign*sum;
}

int parse_array(const char**s); //fwd decl.
int parse_json(const char **s) {
	int out = 0;
	int red = 0;
	
	assert(**s=='{');
	++(*s);
	
	while(**s!='}') {
		parse_string(s);
		assert(**s==':');
		++(*s);

		switch (**s) {
			case '[' : out+=parse_array(s);  break;
			case '{' : out+=parse_json(s);   break;
			case '\"': red+=parse_string(s); break; 
			default  : out+=parse_number(s); break;
		}
		assert(**s==',' || **s=='}');
		if (**s=='}') break;
		++(*s);
	}
	++(*s);
	
	return (red)?0:out;
	
}


int parse_array(const char **s) {
	int out = 0;
	assert(**s=='[');
	++(*s);
	
	while (**s!= ']') {
		switch (**s) {
			case '[' : out+=parse_array(s);  break;
			case '{' : out+=parse_json(s);   break;
			case '\"': parse_string(s); break; 
			default   : out+=parse_number(s); break;
		}
		assert(**s==',' || **s==']');
		if(**s==']') break;
		++(*s);
	}
	++(*s);
	return out;
}

int main() {
	ifstream infile("input.txt");
	string s;
	while (infile>>s) {
		const char *x = s.c_str();
		cout << parse_array(&x) << endl;
		cout << x[0] << endl;
	}
	return 0;
}



