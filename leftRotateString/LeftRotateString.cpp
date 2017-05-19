// 思路：
// XYZabcdef,左移3位 --> abcdefXYZ
// 利用翻转字符串的方法
// 先将前3位翻转， 然后将其余位翻转， 得到 ZYXfedcba
// 然后翻转整个字符串， 就得到 abcdefXYZ

string reverseString(string str) {
    string result = "";
    for (int i=str.size()-1; i>=0; i--)
        result.append(1, str[i])

    return result;
}

string LeftRotateString(string str, int n) {
    if (str.size() < n) return "";
    string a = reverseString(str.substr(0, n));
    string b = reverseString(str.substr(n, str.size()-n));
    return reverseString(a+b);

}