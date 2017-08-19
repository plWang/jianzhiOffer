#include <iostream>
#include "memory.h"
using namespace std;

int jumpFloorII(int number) {
    int res = 0;
    int arr[number+1];
    memset(arr, 0, sizeof(arr));
    arr[1] = 1;
    arr[2] = 2;
    if (number < 3) return arr[number];
    else {
        for (int i=3; i<=number; i++) {
            arr[i] += 1;
            for (int j=1;j<i; j++)
                arr[i] += arr[j];
        }
        return arr[number];
    }
}


int main() {
    int number;
    cin >> number;
    int res = jumpFloorII(number);
    cout << res << endl;
    return 0;
}