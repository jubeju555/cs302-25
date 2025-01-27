// Challenge 03: Palindrome Permutation
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool is_palindrome_permutation(const string &s) {
  // using a map to store and check how oftern char repetition happens
  unordered_map<char, int> num_char;
  for (char c : s)
  {
    num_char[c]++;
  }
  int odd_count = 0;
  for ( auto it = num_char.begin(); it != num_char.end(); it++)
  {
    if (it->second % 2 != 0)
    {
      odd_count++;
    }
  }
  if (odd_count <= 1)
  {
    return (true);
  }
  
  
  return (false);
}



int main(int argc, char *argv[]) {
  string s;
  while (cin >> s)
  {
    if (is_palindrome_permutation(s)) {
    cout << "\"" <<  s << "\"" << " is a palindrome permutation." << endl;
  } else {
    cout << "\"" <<  s << "\"" << "is not a palindrome permutation." << endl;
  }
  }
   
  
  return (0);
}

