#include <iostream>

using namespace std;

// int NumberOf1(int n) {
//     int res = 0;
//     while (n != 0) {
//         if (n & 1 == 1) res++;
//         n >>= 1;
//     }

//     return res;
// }

int NumberOf1(int n) {
    int res = 0;
    while (n) {
        n = (n-1) & n;
        res++;
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    int res = NumberOf1(n);
    cout << res << endl;
}