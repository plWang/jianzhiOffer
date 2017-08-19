#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int GetNumberOfK(vector<int>& data, int k) {
    if (data.size() == 0) return 0;
    int lo=0, hi=data.size()-1;
    if (data.size()==1 && data[0] == k) return 1;

    sort(data.begin(), data.end());

    int mid;
    while (lo <= hi) {
        mid = lo + (hi-lo)/2;
        if (data[mid] == k) {
            if (data[mid-1] != data[mid]) break;
            else hi = mid-1;
        }
        else if (data[mid] < k)
            lo = mid+1;
        else 
            hi = mid-1;
    }

    if (lo > hi) return 0; // not found
    int left = mid;

    lo = 0;
    hi = data.size()-1;
    while (lo <= hi) {
        mid = lo + (hi-lo)/2;
        if (data[mid] == k) {
            if (data[mid+1] != data[mid]) break;
            else lo = mid+1;
        }
        else if (data[mid] < k)
            lo = mid+1;
        else 
            hi = mid-1;
    }
    if (lo > hi) return 0;
    int right = mid;

    return right-left+1;

}

int main() {
    int arr[] = {1,2,3,3,3,3,4,5};
    vector<int> data(arr, arr+sizeof(arr)/sizeof(int));
    int k;
    cin >> k;
    int num = GetNumberOfK(data, k);
    cout << num << endl;
    return 0;
}