#include <iostream>
#include <vector>

using namespace std;

int myMin(int a, int b, int c) {
    int x = (a<b)?a:b;
    return (x<c)?x:c;
}


int GetUglyNumber_Solution(int index) {
    if (i < 1) return 0;
    vector<int> uglyNumber(index, 0);
    uglyNumber[0] = 1;
    int t2 = 0, t3 = 0, t5 = 0;
    int u2, u3, u5;
    for (int i=1; i<index; i++) {
        for (int j=t2; j<i; j++) {  // find first 2*uglynumber[before] bigger than uglyNumber[i-1]
            u2 = 2*uglyNumber[j];
            if (u2 > uglyNumber[i-1]) {
                t2 = j;
                break;
            }
        }

        for (int j=t3; j<i; j++) {
            u3 = 3*uglyNumber[j];
            if (u3 > uglyNumber[i-1]) {
                t3 = j;
                break;
            }
        }

        for (int j=t5; j<i; j++) {
            u5 = 5*uglyNumber[j];
            if (u5 > uglyNumber[i-1]) {
                t5 = j;
                break;
            }
        }

        uglyNumber[i] = myMin(u2, u3, u5);
    }

    return uglyNumber[index-1];

}

int main() {
    int k;
    cin >> k;
    cout << GetUglyNumber_Solution(k) << endl;
}