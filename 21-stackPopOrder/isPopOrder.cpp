#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isPopOrder(vector<int>& pushV, vector<int>& popV) {
    if (pushV.size() == 0 && popV.size() == 0) return true;
    else if (pushV.size() == 0 || popV.size() == 0 || pushV.size() != popV.size()) return false;
    stack<int> s;
    int n = pushV.size();
    int i=0, j=0;
    while (i<=n && j<n) {
        if (i == n) {
            if (s.top() == popV[j]) {
                s.pop();
                j++;
            }
            else return false;
        }
        else {
            if (s.empty()) 
                s.push(pushV[i++]);
            else {
                if (popV[j] == pushV[i]) {
                    i++;
                    j++;
                }
                else if (s.top() == popV[j]){
                    s.pop();
                    j++;
                }
                else {
                    if (i<n)
                        s.push(pushV[i++]);
                    else 
                        return false;
                }
            }
        }
    }

    return true;

}

int main() {
    int Push[] = {1, 2, 3, 4, 5};
    int Pop[] = {4, 3, 5, 1, 2};
    vector<int> pushV(Push, Push+sizeof(Push)/sizeof(int));
    vector<int> popV(Pop, Pop+sizeof(Pop)/sizeof(int));
    if (isPopOrder(pushV, popV))
        cout << "True" << endl;
    else 
        cout << "False" << endl;
    return 0;
}