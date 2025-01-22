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

int storearray()
{
    return 0;
}
// rotate the array, by d elements, in the direction d
int rotatearray(vector<int> arr, int index, char Dir)
{
    int size= arr.size();
    if (Dir == 'R')
       index= size-index;
    if (index < 5)
    {
       index+= 5;
    }

   index = index % size;
    // cout << "index: " << d << endl;
    for (int i = 0; i < size - 1; i++)
    {
        cout << arr[(i + index) % size] << " ";
    }
    cout << arr[(size - 1 + index) % size];
    cout << endl;
    return 0;
}
int main(int argc, char *argv[])
{
    int size, index;
    char Dir;
    while (cin >> size >> index >> Dir)
    {
        vector<int> arr(size);
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        rotatearray(arr, index, Dir);
    }
    return 0;
}