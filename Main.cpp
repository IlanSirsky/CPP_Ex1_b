#include "mat.hpp"
#include <iostream>

using namespace std;

int main(){
    int col, row;
    char c1, c2;
    cout << "Enter 2 positive numbers" << endl;
    cin >> col >> row;
    cout << "Enter 2 symbols" << endl;
    cin >> c1 >> c2;
    ariel::mat(col, row, c1, c2);
    return 1;
}