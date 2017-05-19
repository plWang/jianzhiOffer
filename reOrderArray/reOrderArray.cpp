#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reOrderArray(vector<int> &array) {
    int lo = 0, hi=array.size()-1;
    while (lo <= hi) {
        while (lo <= hi && array[lo] % 2 != 0) lo++;
        while (lo <= hi && array[hi] % 2 == 0) hi--;
        if (lo < hi) {
            int tmp = array[lo];
            array[lo] = array[hi];
            array[hi] = tmp;
        }
    }
    cout << "lo: " << lo << endl;
    cout << "hi: " << hi << endl;
    sort(array.begin(), array.begin()+hi+1);
    sort(array.begin()+lo, array.end());
}

int main() {
    vector<int> array;
    for (int i=0; i<1; i++) array.push_back(i);

    reOrderArray(array);
    for (int i=0; i<array.size(); i++)
        cout << array[i] << " ";
    cout << endl;
}