#include <iostream>
using namespace std;

bool match(char* str, char* pattern) {
    if (*str == '\0' && *pattern == '\0') return true;

    if (*str != '\0' && *pattern == '\0') return false;


    if (*(pattern+1) != '*') { //下一个字符不为*时，如果str与pattern对应字符相等，则继续匹配，否则return false
        if ((*pattern == '.' && *str != '\0') || *str == *pattern) {
            return match(str+1, pattern+1);
        }
        else return false;
    }
    //下一个字符为*时，
    // 如果str与pattern不相等，那么pattern后移两位，str不动
    // 如果str与pattern相等，有以下匹配方式：
    // 1. str后移一位，pattern后移两位，继续匹配
    // 2. str后移一位，pattern不动，因为x*可以重复
    // 3. str不动, pattern后移两位，因为x*可以忽略
    else {
        if (*pattern == *str || (*pattern == '.' && *str != '\0'))
            return match(str+1, pattern+2) || match(str+1, pattern) || match(str, pattern+2);
        else 
            return match(str, pattern+2);
    }
}

int main()