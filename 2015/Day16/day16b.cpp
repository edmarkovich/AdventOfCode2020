#include <iostream>
#include <unordered_set>
#include <fstream>
#include <string>
using namespace std;


int main()
{
    unordered_set<int> aunts;
    for (int i = 1; i <= 500; ++i) {
        aunts.insert(i);
    }
    
    // Sue 1: goldfish: 6, trees: 9, akitas: 0
    string s;
    ifstream infile("input.txt");
    
    string sue_num;
    infile >> s;
    bool done = false;
    while (infile >> sue_num) {
        sue_num.pop_back();
        
        
        string attr = "!";
        infile >> attr;
        while (attr != "Sue") {
                        
                                  
            attr.pop_back();

            string count;
            infile >> count;
            
            if (!(infile >> s)) {
                done = true;
            }

            if (!done && s != "Sue") {
                count.pop_back();
            }

            int countn = stoi(count);
            
            //cout << sue_num << "/" << attr << "/" << count << endl;

            if ((attr == "children" && countn != 3) ||
                (attr == "cats" && countn <= 7) ||
                (attr == "samoyeds" && countn != 2) ||
                (attr == "pomeranians" && countn >= 3) ||
                (attr == "akitas" && countn != 0) ||
                (attr == "vizslas" && countn != 0) ||
                (attr == "goldfish" && countn >= 5) ||
                (attr == "trees" && countn <= 3) ||
                (attr == "cars" && countn != 2) ||
                (attr == "perfumes" && countn != 1)) {
                int sn = stoi(sue_num);
                aunts.erase(sn);
            }

            attr = s;
            if (done) {

                cout << aunts.size() << ":" << *aunts.begin() << endl;
                break;
            }
        }

    }


}
