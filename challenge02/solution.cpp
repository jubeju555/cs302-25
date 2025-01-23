// Challenge 02: Closest Numbers
/*
judah benjamin
challenge02
takes a list of numbers and finds the closest numbers in the list
*/
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool first = true;
    sort(arr.begin(), arr.end());
    int smalldiff = INT_MAX;

    // as you sort the array, the smallest difference will be between adjacent elements
    for (int i = 0; i < n-1; i++)
    {
        smalldiff = min(smalldiff, arr[i+1]-arr[i]);
    }
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i+1]-arr[i] == smalldiff){
            cout << arr[i] << " " << arr[i+1] << " ";
        }
    }
    cout << endl;
    }
    return 0;
}
