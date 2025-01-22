// Challenge 01: Rotating Arrays; null solution
/*
judah benjamin 
cs302
challenge 1
this program takes an array and shifts it a certian amount left or right depending on the input*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <array>
using namespace std;

int storearray(){
    return 0;
}
// rotate the array, by d elements, in the direction d
int rotatearray(vector<int> arr, int d, char Dir){
    int n = arr.size();
if (Dir == 'R') d = n - d;
    d = d % n;
    cout << "index: " << d << endl;
 for (int i = 0; i < n; i++) {
        cout << arr[(i + d) % n] << " ";
    }

    cout << endl;
    return 0;
}
int main(int argc, char *argv[]) {
    int n, d; 
    char Dir;
    while (cin >> n >> d >> Dir) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
 
            cin >> arr[i];
        }
       rotatearray(arr, d, Dir);
    }
    return 0;
}