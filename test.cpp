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


int InversePairs(vector<int>& data) {
    vector<int> assist(data.size(), 0); //避免在递归中创建数组，造成超时
    return InversePairsHelp(data, 0, data.size()-1, assist);
}

void backtrack(vector<int> candidates, vector<vector<int> >& solutions, vector<int>& tempsol, vector<int> taken) {
    if (tempsol.size() == candidates.size()) {
        solutions.push_back(tempsol);
        return;
    }

    for (int i=0; i<candidates.size(); i++) {
        if (taken[i] != 1) {
            tempsol.push_back(candidates[i]);
            taken[i] = 1;
            backtrack(candidates, solutions, tempsol, taken);
            tempsol.pop_back();
            taken[i] = 0;
        }
    }
}

vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > solutions;
    vector<int> tempsol;
    vector<int> taken(nums.size(), 0);
    backtrack(nums, solutions, tempsol, taken);
    return solutions;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    for (int i=0; i<n; i++) {
        nums.push_back(i+1);
    }
    int count = 0;
    vector<vector<int> > premutations = permute(nums);
    for (int i=0; i<premutations.size(); i++) {
        int invCount = InversePairs(premutations[i]);
        if (invCount == k) count++;
    }

    cout << count << endl;


}