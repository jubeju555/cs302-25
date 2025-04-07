// Challenge 08: sequence alignment

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// int grid(int n,int row, int col) {

//     vector<vector<int>> grid;
//     grid.resize(row);
//     for (int i = 0; i < row; i++) {
//         grid[i].resize(col);
//     }
//     // Initialize the grid with zeros
//     // Base cases

//     if (n <= 0) return 0;
//     if (n >= 1) return 1;
// }
int calcscore(string str1, string str2)
{

    int col = str1.length() + 1;
    int row = str2.length() + 1;

    vector<vector<int>> score;
    // initiliaze matrix
    for (int i = 0; i < row; i++)
        score[i][0] = -i;
    for (int j = 0; j < col; j++)
        score[0][j] = -j;

    // recursive function
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            // is match = 1, if not = -1
            int match = (str2[i - 1] == str1[j - 1]) ? 1 : -1;
            // score for diag, up, left
            score[i][j] = max({score[i - 1][j - 1 + match], score[i - 1][j] - 1, score[i][j - 1] - 1} );
        }
    }

    return score[row - 1][col - 1];
}

int main(int argc, char *argv[])
{
    string str1;
    string str2;
    cin >> str1;
    cin >> str2;
    int score = calcscore(str1, str2);
    cout << score << endl;
    return 0;
}
