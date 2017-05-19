#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

static bool myCompare(const string& a, const string& b) {
    string x = a+b;
    string y = b+a;
    if (strcmp(x.c_str(), y.c_str()) < 0 ) return true;
    else return false;
}

string intToString(int a) {
    string str = "";
    while (a != 0) {
        char tmp = a%10;
        str.insert(0, 1, tmp+'0');
        a /= 10;
    }

    return str;
}

string PrintMinNumber(vector<int>& numbers) {
    vector<string> strs;
    for (int i=0; i<numbers.size(); i++) {
        strs.push_back(intToString(numbers[i]));
    }
    sort(strs.begin(), strs.end(), compare);

    string result;
    for (int i=0; i<strs.size(); i++)
        result += strs[i];

    return result;
}

int main() {
    int arr[] = {3, 32, 321};
    vector<int> numbers(arr, arr+sizeof(arr)/sizeof(int));
    string result = PrintMinNumber(numbers);
    cout << result << endl;
    return 0;
}