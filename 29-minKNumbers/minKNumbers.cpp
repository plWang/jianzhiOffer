#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}


// Solution 1: partition based method
// int partition(vector<int>& nums, int lo, int hi) {
//     int i=lo, j=hi+1;
//     int key = nums[lo];
//     while (true) {
//         while (nums[++i] <= key) if (i==hi) break;
//         while (nums[--j] >= key) if (j == lo) break;
//         if (i>=j) break;
//         swap(nums, i, j);
//     }
//     swap(nums, lo, j);

//     return j;

// }

// vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
//     vector<int> result;
//     if (input.size() == 0 || k== 0 || k > input.size()) return result;
//     if (k == input.size()) return input;

//     int lo = 0, hi = input.size()-1;
//     int index = partition(input, lo, hi);
//     while (index != k) {
//         if (index < k) {
//             lo = index+1;
//         }
//         else hi = index-1;
//         index = partition(input, lo, hi);
//     }

//     return vector<int>(input.begin(), input.begin()+k);
// }


//Solution2: heap method
void sink(vector<int>& nums, int i, int k) {
    while (2*i+1 < k) {
        int j=2*i+1;
        if (j < k-1 && nums[j+1] > nums[j]) j=j+1;
        if (nums[i] < nums[j]) {
            swap(nums, i, j);
            i = j;
        }
        else break;

    }
}

void buildHeap(vector<int>& nums, int k) {
    int i=k/2 - 1; // first node with child
    for(int i=k/2-1; i>=0; i--)
        sink(nums, i, k);

}

vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
    vector<int> result;
    if (input.size() == 0 || k== 0 || k > input.size()) return result;
    if (k == input.size()) return input; 

    buildHeap(input, k);
    for (int i=k; i<input.size(); i++) {
        if (input[i] < input[0]) {
            swap(input, i, 0);
            sink(input, 0, k);
        }
    }

    return vector<int>(input.begin(), input.begin()+k);

}


int main() {
    int arr[] = {2,4,3,6,1, 2,7,5};
    vector<int> input(arr, arr+sizeof(arr)/sizeof(int));
    
    int k;
    cin >> k;
    vector<int> result =  GetLeastNumbers_Solution(input, k);
    //int k = input.size();
    //buildHeap(input, k);

    for (int i=0; i < k; i++)
        cout << result[i] << " ";
    cout << endl;
}