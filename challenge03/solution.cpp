// Challenge 03: Palindrome Permutation
/*
judah benjamin
this code checks whether a string is a palindrom permutation*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// use unordered map to store num of chars in each sequaence, then mod by 2 to check if palindrome
bool is_palindrome_permutation(const string &readline)
{
    int permcount = 0;
  
  unordered_map<char, int> num_char;
  for (char c : readline)
  {
    num_char[c]++;
  }
// if num of chars is odd, increment permcount
  for (string ::const_iterator it = readline.begin(); it != readline.end(); it++)
  {

    if (num_char[*it] % 2 != 0)
    {
      permcount++;
    }
    if (permcount < 1)
    {
      return (true);
    }
  }
  return (false);
}
int main(int argc, char *argv[])
{
  string readline;
  while (getline(cin, readline))
  {
    if (is_palindrome_permutation(readline) == true)
    {
      cout << "\"" << readline << "\"" << " is a palindrome permutation" << endl;
    }
    else
    {
      cout << "\"" << readline << "\"" << " is not a palindrome permutation" << endl;
    }
  }
  return (0);
}
