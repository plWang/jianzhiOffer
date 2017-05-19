#include <iostream>
#include <string>

using namespace std;

// void swap(string& str, int lo, int hi) {
//     char tmp = str[lo];
//     str[lo] = str[hi];
//     str[hi] = tmp;
// }

void reverseString(string& str, int lo, int hi) {
    while (lo < hi) {
        swap(str[lo++], str[hi--]);
    }
}

// 思路： 先翻转整个句子，然后翻转每个单词
string ReverseSentence(string str) {
    // string result = str;
    reverseString(str, 0, str.size()-1);
    int start = 0;
    for (int i=0; i<=str.size(); i++) {
        if (str[i] == ' ' || i == str.size()) {
            reverseString(str, start, i-1);
            start = i+1;
        }
    }

    return str;
}

int main() {
    string str = "he am a student";
    cout << ReverseSentence(str) << endl;
    return 0;
}