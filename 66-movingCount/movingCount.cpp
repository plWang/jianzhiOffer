#include <iostream>
#include <vector>

using namespace std;


bool ifReach(int i, int j, int threshold) {
    int sum = 0;
    while (i>0) {
        sum += (i%10);
        i /= 10;
    }

    while (j>0) {
        sum += (j%10);
        j /= 10;
    }

    if (sum <= threshold) return true;
    else return false;
}

int backtrack(vector<vector<int> >& visit, int rows, int cols, int i, int j, int threshold) {
    // 判断当前点是否可以计算，有几个限制条件
    // 1. 在矩阵范围内
    // 2. 没有被访问过
    // 3. 没有超过threshold
    if (i<0 || i>=rows || j<0 || j>=cols || visit[i][j]==1 || !ifReach(i, j, threshold))
        return 0;

    visit[i][j] = 1;
    return backtrack(visit, rows, cols, i-1, j, threshold) + backtrack(visit, rows, cols, i+1, j, threshold) + backtrack(visit, rows, cols, i, j-1, threshold) + backtrack(visit, rows, cols, i, j+1, threshold) + 1;
}


int movingCount(int threshold, int rows, int cols) {
    vector<vector<int> > visit(rows, vector<int>(cols, 0));
    return backtrack(visit, rows, cols, 0, 0, threshold);
}

int main() {
    int threshold = 3;
    int rows = 4, cols = 4;
    int count = movingCount(threshold, rows, cols);
    cout << count << endl;
    return 0;
}