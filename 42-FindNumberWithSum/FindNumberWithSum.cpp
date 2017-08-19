#include <iostream>
#include <vector>

using namespace std;

vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    vector<int> result;
    if (array.size() == 0 || array.size() == 1)
        return result;

    int lo=0, hi = array.size()-1;
    while (lo < hi) {
        if (array[lo] + array[hi] == sum) {
            result.push_back(array[lo]);
            result.push_back(array[hi]);
            break;
        }
        else if (array[lo] + array[hi] < sum) {
            lo++;
        }
        else 
            hi--;
    }

    return result;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5,,};

}