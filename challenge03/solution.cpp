/*
judah benjamin
challenge 03
thie program reads in a string of chars and checks if it is a palindrome permutation
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

bool is_palindrome_permutation(const string &readline) {
    unordered_map<char, int> num_char;
    
    // count how many chars read
    for (string::const_iterator it = readline.begin(); it != readline.end(); ++it) {
      // looked up how to only look at letters, used site programiz, for info on isalpha
        if (isalpha(*it)) {  
            char c = tolower(*it);  
            num_char[c]++;
        }
    }
    
    // check if more then 1 char has an odd count 
    int permcount = 0;
    for (unordered_map<char, int>::const_iterator it = num_char.begin(); it != num_char.end(); ++it) {
        if (it->second % 2 != 0) {
            permcount++;
        }
        if (permcount > 1) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    string readline;
    while (getline(cin, readline)) {
        if (is_palindrome_permutation(readline)) {
            cout << "\"" << readline << "\"" << " is a palindrome permutation" << endl;
        } else {
            cout << "\"" << readline << "\"" << " is not a palindrome permutation" << endl;
        }
    }
    return 0;
}