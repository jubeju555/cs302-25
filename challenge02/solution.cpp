// Challenge 02: Closest Numbers
// Name:  xxxxx

// Brief description:

// This code solves yyyy based on the following idea/implementation...

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// Main Execution

int findclosest(){
    int n;
    cin >>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

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
            cout << arr[i] << " " << arr[i+1];
        }
    }
return 0;
}

int main(int argc, char *argv[]) {
    int n;
        findclosest();
    

    return EXIT_SUCCESS;
}
