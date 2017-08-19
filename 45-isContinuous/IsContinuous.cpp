#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsContinuous(vector<int>& numbers) {
    if (numbers.size() == 0) return false;
    if (numbers.size() == 1) return true;
    sort(numbers.begin(), numbers.end());
    int count0 = 0;
    int gap = 0;
    for (int i=0; i<numbers.size(); i++) {
        if (numbers[i] == 0) count0++;
        else {
            if (i>0 && numbers[i-1] != 0) {
                if (numbers[i] == numbers[i-1]) return false;
                gap += numbers[i]-numbers[i-1]-1;
            }
        }
    }

    if (gap > count0) return false;
    else return true;
}

int main() {
    int arr[] = {2, 0 ,3,4,6};
    vector<int> numbers(arr, arr+sizeof(arr)/sizeof(int));
    if (IsContinuous(numbers))
        cout << "true" << endl;
    else 
        cout << "false" << endl;
}