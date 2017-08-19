#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
    deque<int> q;
    vector<int> res;
    for (int i=0; i<num.size(); i++) {
        if (q.size() && num[i] > num[q.front()]) {
            while (!q.empty())  //当前数字比队列开头元素大，则清空队列
                q.pop_back();
        }
        else if (q.size() && num[i] > num[q.back()]) { //否则，扔掉队列中比当前数字小的元素
            while (!q.empty() && num[i] > num[q.back()]) q.pop_back();
        }
        q.push_back(i);  //插入当前数字
        if (i-q.front()+1 > size) q.pop_front();   //滑动窗口的最大值总是在队列开头
        if (i >= size-1) res.push_back(num[q.front()]);
    }

    return res;
}

int main() {
    int arr[] = {16,14,12,10,8,6,4};
    vector<int> num(arr, arr+sizeof(arr)/sizeof(int));
    int size = 5;
    vector<int> result = maxInWindows(num, size);
    for (int i=0; i<result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
}