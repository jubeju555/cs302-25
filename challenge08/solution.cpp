// Challenge 08: sequence alignment

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

map<int, int> memo;


int fib(int n,int row, int col) {

    int grid[row][col];
    // Base cases
    if (n < 0) return 0;   
    if (n >= 1) return 1;    
    

    if (memo.find(n) != memo.end()) return memo[n];


    int result = 0;


    return memo[n];
}


int main(int argc, char *argv[]) {
    string str1;
    string str2;
    cin >> str1;
    cin >> str2;
    return 0;
}


