#include <stack>

class Solution
{
public:
    void push(int node) {
        s1.push(node);
    }

    int pop() {
        if (!s2.empty()) {
            int node = s2.top();
            s2.pop();
        }
        else {
            while (!s1.empty()) {
                int tmp = s1.top();
                s1.pop();
                s2.push(tmp);
            }
            int node = s2.top();
            s2.pop();
        }
        return node;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};