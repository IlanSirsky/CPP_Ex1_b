#include "mat.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>

using namespace std;
string ariel::mat(int row, int col, char c1, char c2){
    if (row % 2 == 0 || col % 2 == 0){
        throw invalid_argument("Row or column must be an odd number");
    }
    if (row <= 0 || col <= 0){
        throw invalid_argument("Row or column mustn't be a negative number");
    }
    const int minChar = 33;
    const int maxChar = 126;
    if (c1 < minChar || c2 < minChar || c1 > maxChar || c2 > maxChar){
        throw invalid_argument("Invalid symbol");
    }
    vector<vector<int>> mat1(row, vector<int>(col));
    vector<vector<int>> mat2(row, vector<int>(col));
    string ans;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat1[i][j] = min(i, j);
            mat2[i][j] = min(col - 1 - j, row - 1 - i);
            mat1[i][j] = min(mat1[i][j], mat2[i][j]);
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat1[i][j] % 2 == 0){
                ans += c1;
                ans += " ";
            }
            else {
                ans += c2;
                ans += " ";
            }
        }
        if (i != row - 1){
            ans += "\n";
        }
    }
    cout << ans << endl;
    return ans;
}