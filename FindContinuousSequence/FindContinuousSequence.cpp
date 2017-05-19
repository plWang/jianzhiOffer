#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) {
    int i=1, j=1;
    vector<int> tempsol;
    vector<vector<int> > result;
    int curSum = 1;
    tempsol.push_back(j);
    while (j < sum && tempsol.size() > 0) {
        if (curSum == sum) {
            result.push_back(tempsol);
            j++;
            curSum += j;
            tempsol.push_back(j);
        }
        else if (curSum < sum) {
            tempsol.push_back(++j);
            curSum += j;
        }
        else {
            int tmp = tempsol.front();
            tempsol.erase(tempsol.begin());
            curSum -= tmp;
            i++;
        }
    }

    return result;
}

int main() {
    int sum;
    cin >> sum;
    vector<vector<int> > result = FindContinuousSequence(sum);

    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}