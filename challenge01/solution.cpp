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

int rotatearray(vector<int> arr, int d){
   int n = arr.size();

    int d = d % n;

    vector<int> temp(d);

    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }
    
    return 0;
}

int printarray(){
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
    return 0;
}

