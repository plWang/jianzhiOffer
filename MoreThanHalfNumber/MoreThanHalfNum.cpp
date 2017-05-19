#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& nums, int lo, int hi) {
    int tmp = nums[lo];
    nums[lo] = nums[hi];
    nums[hi] = tmp;
}

int partition(vector<int>& nums, int lo, int hi) {
    int i=lo, j=hi+1;
    int key = nums[lo];
    while (true) {
        while (nums[++i] <= key) if (i == hi) break;
        while (nums[--j] >= key) if (j == lo) break;
        if (i >= j) break;
        swap(nums, i, j);
    }
    swap(nums, lo, j);

    return j;
}


bool isMoreThanHalf(vector<int>& numbers, int target) {
    int count = 0;
    for (int i=0; i<numbers.size(); i++) {
        if (numbers[i] == target) count++;
    }
    if (count*2 <= numbers.size())
        return false;
    else 
        return true;
}

// int MoreThanHalfNum_Solution(vector<int>& numbers) {
//     if (numbers.size() == 0) return 0;
//     int lo=0, hi=numbers.size()-1;
//     int middle = numbers.size()/2;
//     int k = partition(numbers, lo, hi);
//     while (k != middle) {
//         if (k < middle)
//             lo = k+1;
//         else 
//             hi = k-1;
//         k = partition(numbers, lo, hi);
//     }

//     if (isMoreThanHalf(numbers, numbers[middle]))
//         return numbers[middle];
//     else 
//         return 0;
// }


//Solution 2
int MoreThanHalfNum_Solution(vector<int>& numbers) {
    if (numbers.size() == 0) return 0;
    int key, count = 0;
    for (int i=0; i<numbers.size(); i++) {
        if (count == 0) {
            key = numbers[i];
            count++;
        }
        else {
            if (numbers[i] == key) count++;
            else count--;
        }
    }

    if (isMoreThanHalf(numbers, key))
        return key;
    else 
        return 0;
}

int main() {
    int arr[] = {1, 2, 3, 2, 2, 2, 5, 4 ,2};
    vector<int> numbers(arr, arr+sizeof(arr)/sizeof(int));
    int res = MoreThanHalfNum_Solution(numbers);
    cout << res << endl;

    return 0;
}