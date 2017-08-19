#include <iostream>
#include <vector>

using namespace std;

int Merge(vector<int>& data, int lo, int mid, int hi, vector<int>& assist) {
    int i = mid, j = hi;
    int count = 0;
    for (int k=hi; k>=lo; k--) {
        if (i < lo) assist[k] = data[j--];
        else if (j <= mid) assist[k] = data[i--];
        else if (data[i] <= data[j]) {
            assist[k] = data[j--];
        }
        else {
            count += (j-mid);out
            assist[k] = data[i--];
            if (count >= 1000000007)
                count = count%1000000007;
        }
    }

    for (int i=lo; i<=hi; i++)
        data[i] = assist[i];
    return count;
}

int InversePairsHelp(vector<int>& data, int lo, int hi, vector<int>& assist) {
    int count = 0;
    if (lo >= hi) return 0;

    int mid = lo + (hi-lo)/2;
    count += (InversePairsHelp(data, lo, mid, assist)%1000000007);
    count += (InversePairsHelp(data, mid+1, hi, assist)%1000000007);
    count += (Merge(data, lo, mid, hi, assist)%1000000007);

    return count%1000000007;
}


int InversePairs(vector<int>& data) {
    vector<int> assist(data.size(), 0); //避免在递归中创建数组，造成超时
    return InversePairsHelp(data, 0, data.size()-1, assist);
}

int main() {
    int arr[] = {2,4,3,6,1,2,7,5};
    vector<int> data(arr, arr+sizeof(arr)/sizeof(int));
    int count = InversePairs(data);

    cout << count << endl;
}