#include <iostream>
#include "math.h"
using namespace std;

int NumberOf1Between1AndN_Solution(int n) {
    int dvs = 1;
    int count = 0;
    int i=1;
    while (n/dvs > 0) {
        cout << "----------------" << endl;
        int cur = (n/dvs)%10;  //当前位数字
        int high = n/(dvs*10);  //高位数字
        int low = n%dvs; //低位数字
        cout << "cur: " << cur << endl;
        cout << "high: " << high << endl;
        cout << "low: " << low << endl;
        int a = high * pow(10, i-1);
        if (cur > 1) {
            a += pow(10, i-1);
        }
        else if (cur == 1)
            a += low+1;

        cout << "a: " << a << endl;
        count += a;
        dvs *= 10;
        i++;
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    int count = NumberOf1Between1AndN_Solution(n);
}