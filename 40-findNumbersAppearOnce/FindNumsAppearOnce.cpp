#include <iostream>
#include <vector>

using namespace std;

bool isBit1(int num, int bit1) {
    num >>= bit1;
    return (num&1) == 1;
}

void FindNumsAppearOnce(vector<int>& data,int* num1,int *num2) {
    int xors = 0;
    for (int i=0; i<data.size(); i++) {
        xors ^= data[i];
    }

    int bit1 = 0;
    if (xors == 0) return;
    while ((xors&1) == 0) {
        xors >>= 1;
        bit1++;
    }

    num1[0] = num2[0] = 0;
    for (int i=0; i<data.size(); i++) {
        if (isBit1(data[i], bit1)) 
            *num1 ^= data[i];
        else 
            *num2 ^= data[i];
    }

}

int main() {
    int arr[] = {2,4,3,6,3,2,5,5};
    vector<int> data(arr, arr+sizeof(arr)/sizeof(int));
    int num1[1];
    int num2[1];
    FindNumsAppearOnce(data, num1, num2);
    cout << *num1 << " " << *num2 << endl;
}