#include <iostream>
#include <vector>

using namespace std;

vector<int> hash(256, 0);
string str;
void Insert(char ch)
{
    hash[ch]++;
    str.push_back(ch);
}
//return the first appearence once char in current stringstream
char FirstAppearingOnce() {
    for (int i=0; i<str.size(); i++) {
        if (hash[str[i]] == 1) return str[i];
    }

    return '#';
}

int main() {
    cout << "" << endl;
    return 0;
}