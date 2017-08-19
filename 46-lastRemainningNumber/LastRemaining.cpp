#include <iostream>
#include <vector>

using namespace std;

// 两种思路：
// Solution 1: 用数组模拟环
int LastRemaining_Solution(int n, int m) {
    vector<int> mark(n, 0);
    int count = n, step=0, i=0;
    while (count > 0) {
        for (int i=0; i<n; i++) {
            if (mark[i] == 0) {
                step++;
            }

            if (step == m) {
                mark[i] = 1;
                count--;
                if (count == 0) return i;
                step = 0;
            }
        }
    }

    return i;
}

// Solution 2: 递推公式
int LastRemaining_Solution(int n, int m) {
    if (n == 0 || m == 0) return -1;
    int last = 0;
    for (int i=2; i<=n; i++) {
        last = (last + m)%i;
    }

    return last;
}

int main() {
    int n, m;
    cin >> n >> m;
    int last = LastRemaining_Solution(n, m);
    cout << last << endl;
}