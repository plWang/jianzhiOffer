#include <iostream>
#include <vector>

using namespace std;

int rectCover(int number) {
    if (number <= 0) return 0;
    if (number == 1 || number == 2) return number;
    int a = 1, b = 2;
    int c;
    for (int i=3; i <=number; i++) {
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int number;
    cin >> number;
    int res = rectCover(number);
    cout << res << endl;;
    return 0;
}