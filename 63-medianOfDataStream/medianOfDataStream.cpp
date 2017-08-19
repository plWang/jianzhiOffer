#include <iostream>
#include <vector>

using namespace std;

bool invaild = false;

class Heap {
//private:
 //    bool isMaxHeap;
public:
    bool isMaxHeap;
    vector<int> heap;

    Heap(bool isMax):isMaxHeap(isMax) {}  // constructor

    int size() {
        return heap.size();
    }

    bool isempty() {
        return heap.size() == 0;
    }

    int top() {
        if (!isempty())
            return heap[0];
        else {
            invaild = true;
            return 0;
        }
    }

    void push_back(int num) {
        heap.push_back(num);
        int j = heap.size()-1;
        swim(j);
    }

    int pop() {
        int tmp = top();
        int i = heap.size()-1;
        heap[0] = heap[i];
        heap.pop_back();
        sink(0);

        return tmp;
    }

    void printHeap() {
        for (int i=0; i<heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void sink(int i) { // 最大堆的向下调整方法
        int j =2*i+1;
        while (j < heap.size()) {
            if (isMaxHeap) {
                if (j+1 < heap.size() && heap[j] < heap[j+1]) j++;
                swap(heap[i], heap[j]);
            }
            else {
                if (j+1 < heap.size() && heap[j] > heap[j+1]) j++;
                swap(heap[i], heap[j]);
            }
            i = j;
            j = 2*i+1;
        }
    }

    void swim(int j) { //最大堆的向上调整方法
        int i = (j-1)/2; 
        while (i >= 0) {
            if (isMaxHeap) {
                if (heap[i] < heap[j]) {
                    swap(heap[i], heap[j]);
                    j = i;
                    i = (j-1)/2;
                }
                else break;
            }
            else {
                if (heap[i] > heap[j]) {
                    swap(heap[i], heap[j]);
                    j = i;
                    i = (j-1)/2;
                }
                else break;
            }
        }
    }
};

class Solution {
public:
    bool isMax = true;
    bool isMin = false;
    Heap maxHeap = Heap(isMax);
    Heap minHeap = Heap(isMin);
    int size = 0;

    void Insert(int num) {
        if (size%2 == 0) { // 目前总数为偶数时，插入最大堆
            if (minHeap.size()>0 && num > minHeap.top()) {//如果当前数比最小堆中最小元素大，那么把最小元素取出，插入最大堆中
                int tmp = minHeap.top();
                maxHeap.push_back(tmp);
                //sink();                  //调整最大堆
                minHeap.heap[0] = num;
                minHeap.swim(0);                  //调整最小堆
            }
            else {                      //如果当前数比最小堆中最小元素小，那么直接将该数插入最大堆
                maxHeap.push_back(num);
                //sink();
            }
        }
        else {
            if (maxHeap.size()>0 && num < maxHeap.top()) {
                int tmp = maxHeap.top();
                minHeap.push_back(tmp);
                //swim();
                maxHeap.heap[0] = num;
                maxHeap.sink(0);
            }
            else {
                minHeap.push_back(num);
                //swim();
            }
        }
        size++;
    }

    double GetMedian() { 
        if (size%2 == 0) return (minHeap.top()+maxHeap.top())/2.0;
        else return (double)maxHeap.top();
    }

};


int main() {
    

    int num;
    Solution sol = Solution(); 
    while (cin >> num) {
        sol.Insert(num);
        cout << "maxHeap: ";
        sol.maxHeap.printHeap();
        cout << "minHeap: ";
        sol.minHeap.printHeap();
    }

    return 0;
}