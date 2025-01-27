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
  for (string :: const_iterator it = s.begin(); it != s.end(); it++)
  {
    if (num_char[*it] % 2 != 0)
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
  while (getline(cin, s))
  {
    if (is_palindrome_permutation(s) == true) {
    cout << "\"" <<  s << "\"" << " is a palindrome permutation" << endl;
  } else {
    cout << "\"" <<  s << "\"" << " is not a palindrome permutation" << endl;
  }
  }
  return (0);
}

