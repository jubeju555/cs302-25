// Challenge 01: Rotating Arrays; null solution
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <array>
using namespace std;

int storearray(){
    
    return 0;

}

// rotate the array, by d elements, in the direction d
int rotatearray(vector<int> arr, int d){
    int n = arr.size();

if (char direct = 'L') {
    d = n - d;

}
if (char direct = 'R')
{
    d = n - d;

}

    int d = d % n;
    vector<int> temp(d);

    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    return 0;
}

int printarray(){
    int n;
    vector<int> arr(n);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

int readarray(){
    int n;
    vector<int> arr(n);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return 0;
}
int main(int argc, char *argv[]) {
    int n;
    vector<int> arr(n);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return 0;
}
// int main(int argc, char *argv[]) {
//     int n;
//     vector<int> arr(n);
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     return 0;
// }

