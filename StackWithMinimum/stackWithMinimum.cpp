#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    void push(int value) {
        s1.push(value);
        int minVal;
        if (!s2.empty())
            minVal = min()<value?min():value;
        else 
            minVal = value;
        s2.push(minVal);
    }
    void pop() {
        if (!s1.empty()) s1.pop();
        if (!s2.empty()) s2.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }

private:
    stack<int> s1;
    stack<int> s2;
};