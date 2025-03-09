// Challenge 06: Repeated DNA sequences
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

void DNAsequences(string s) {
    unordered_map<string, int> dnamap;
    vector<string> DNA;
    for (int i = 0; i <= s.size(); i++) {
        string substring = s.substr(i, 9);
        if (dnamap[substring] == 1) {
            DNA.push_back(substring);
        }
        dnamap[substring]++;
    }
    for (const string& seq : DNA) {
        if (dnamap[seq] == 2)
        {
            cout << seq;
        }
      if(cin.eof())cout << endl;
    }
    cout << "-1" << endl;
}

int main(int argc, char *argv[]) {
    string s;
    while (getline(cin, s)) {
        DNAsequences(s);
    }
    return 0;
}