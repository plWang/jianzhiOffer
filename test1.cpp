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
            count += (j-mid);
            assist[k] = data[i--];
            if (count >= 10000)
                count = count%10000;
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
    count += (InversePairsHelp(data, lo, mid, assist)%10000);
    count += (InversePairsHelp(data, mid+1, hi, assist)%10000);
    count += (Merge(data, lo, mid, hi, assist)%10000);

    return count%10000;
}


int InversePairs(vector<int> data) {
    vector<int> assist(data.size(), 0); //避免在递归中创建数组，造成超时
    return InversePairsHelp(data, 0, data.size()-1, assist);
}

// permute
void backtrack(vector<int>& candidates, vector<int>& tempsol, int& count, vector<int>& taken, int k) {
    if (tempsol.size() == candidates.size()) {
        if (InversePairs(tempsol) == k) 
            count++;
        return;
    }

    if (InversePairs(tempsol) > k) return;

    for (int i=0; i<candidates.size(); i++) {
        if (taken[i] != 1) {
            tempsol.push_back(candidates[i]);
            taken[i] = 1;
            backtrack(candidates, tempsol, count, taken, k);
            tempsol.pop_back();
            taken[i] = 0;
        }
    }
}

int permute(int n, int k) {
    vector<int> tempsol;
    vector<int> nums;
    vector<int> taken(n, 0);
    for (int i=1; i<=n; i++)
        nums.push_back(i);
    int count = 0;
    backtrack(nums, tempsol, count, taken, k);
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    for (int i=0; i<n; i++) {
        nums.push_back(i+1);
    }
    
    int count = permute(n, k);

    cout << count << endl;


}