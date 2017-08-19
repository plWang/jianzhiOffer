#include <iostream>
#include <string>
#include <vector>
#include "string.h"

using namespace std;

bool backtrack(char* matrix, int rows, int cols, int i, int j, char* str, vector<vector<int> >& used, int k) {
    int index = i*cols + j;
    if (i<0 || i>=rows || j<0 || j>=cols || used[i][j] == 1 || matrix[index] != str[k]) return false;
    if (k == strlen(str)-1) return true;

    used[i][j] = 1;
    bool res = backtrack(matrix, rows, cols, i-1,j, str, used, k+1) || backtrack(matrix, rows, cols, i+1,j, str, used, k+1) || backtrack(matrix, rows, cols, i,j-1, str, used, k+1) || backtrack(matrix, rows, cols, i,j+1, str, used, k+1);
    if (res) return true;
    used[i][j] = 0;

    return false;
}


bool hasPath(char* matrix, int rows, int cols, char* str) {
    vector<vector<int> > used(rows, vector<int>(cols, 0));
    for (int i=0; i<rows; i++) 
        for (int j=0; j<cols; j++) {
            if (backtrack(matrix, rows, cols, i, j, str, used, 0))
                return true;
        }
    
    return false;
}

int main() {
    char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    int rows = 5, cols=8;
    char* str = "SLHECCEIDEJFGGFIE";
    if (hasPath(matrix, rows, cols, str))
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
}