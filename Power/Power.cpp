#include <iostream>
#include <math.h>

using namespace std;

bool equal(double x, double y) {
    double thresh = 0.000000001;
    if (fabs(x - y) < thresh) return true;
    else return false;
}

double Power(double base, int exponent) {
    if (equal(base, 0.0) && exponent == 0) return 0;
    if (equal(base, 0.0) && exponent < 0) return -1; // invalid input
    if (exponent == 0) return 1.0;
    int flag=0;
    if (exponent < 0) {
        flag = 1;
        exponent = -exponent;
    }
    double result = 1;
    for (int i=0; i<exponent; i++) {
        result *= base;
    }

    if (flag) return 1/result;

    else return result;
}

int main() {
    int exponent;
    double base;
    cin >> base >> exponent;
    double res = Power(base , exponent);

    cout << res << endl;
}