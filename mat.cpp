#include "mat.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>

//algorithm from https://codegolf.stackexchange.com/questions/241219/mat-printing-matrix
//answer by Jonah

using namespace std;
string ariel::mat(int col, int row, char c1, char c2){

    //checking invalid input
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

    //creating 2 vector matrix
    vector<vector<int>> mat1(row, vector<int>(col));
    vector<vector<int>> mat2(row, vector<int>(col));
    string ans;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            //applying values to the matrices
            mat1.at(i).at(j) = min(i, j); 
            mat2.at(i).at(j) = min(col - 1 - j, row - 1 - i);
            //choosing the minmum value between the two matrices applying it to the 1st matrix to save storage
            //also doing everything in the same loop to lower runtime complexity
            mat1.at(i).at(j) = min(mat1.at(i).at(j), mat2.at(i).at(j)); 
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            //applying the symbols to the string by modulu 2 of the value in the matrix
            if (mat1.at(i).at(j) % 2 == 0){
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