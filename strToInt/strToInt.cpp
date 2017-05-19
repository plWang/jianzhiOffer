#include <iostream>
#include <string>

using namespace std;

int g_Invlaid = 0;

int StrToIntCore(string& str, int lo, int hi) {
    long long res = 0;
    for (int i=lo; i<=hi; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            res = res*10 + str[i]-'0';
        }
        else return 0;
    }

    return res;
}

int StrToInt(string str) {
    if (str.size() == 0) {
        g_Invlaid = 1;   // invalid input
        return 0;
    }

    int i = 0;
    int numflag = 0;
    bool minus = false;
    long long result = 0;
    for (int i=0; i<str.size(); i++) {
        if (numflag == 0) {
            if (str[i] == ' ') continue;
            else if (str[i] == '+') numflag=1;
            else if (str[i] == '-') {
                numflag = 1;
                minus = true;
            }
            else if (str[i] >= '0' && str[i] <= '9') {
                result = StrToIntCore(str, i, str.size()-1);
                break;
            }
            else {
                g_Invlaid = 1; // other character, invalid input
                return 0;
            }
        }
        else {
            if (str[i] >= '0' && str[i] <= '9') {
                result = StrToIntCore(str, i, str.size()-i);
                break;
            }
            else {
                g_Invlaid = 1;
                return 0;
            }
        }
    }

    if ((minus && result < INT_MIN) || (!minus && result > INT_MAX)) {
        g_Invlaid = 1;
        return 0;
    }
    else {
        int res = minus?-result:result;
        return res;
    }
}

int main() {
    string str;
    cin >> str;
    int num = StrToInt(str);
    if (g_Invlaid) 
        cout << "Invalid Input" << endl;
    else 
        cout << num << endl;
}

///测试用例
// 1. 空指针
// 2. 空字符串 “”
// 3. 只包含空格
// 4. 包含+， -号
// 5. 数字越界