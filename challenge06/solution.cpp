// Challenge 06: Repeated DNA sequences
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

void DNAsequences(string s) {
    unordered_map<string, int> dnamap;
    vector<string> DNA;
    if (s.size() < 9) {
cout << "-1" << endl;
        return;
    }
    for (size_t i = 0; i <= s.size() - 9; i++) {
        string substring = s.substr(i, 9);
        dnamap[substring]++;
        if (dnamap[substring] == 2) DNA.push_back(substring);
        
    }
    if(DNA.empty()){
        printf("-1\n");
    }else{
    sort(DNA.begin(), DNA.end());
    for (const string& seq : DNA) {
            cout << seq << endl;
        }
        printf("-1\n");
    }
        
    
}

int main(int argc, char *argv[]) {
    string s;
    while (getline(cin, s)) {
        DNAsequences(s);
    }
    return 0;
}
