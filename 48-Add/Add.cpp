int Add(int num1, int num2) {
    //int ans;
    // 先进行异或
    int res = num1 ^ num2;
    // 使用位与计算进位
    int carry = num1 & num2;
    while (carry) {
        carry <<= 1;
        int tmp = carry ^ res;
        carry = carry & res;
        res = tmp;
    }

    return res;
}