int Sum_Solution(int n) {
    int ans = n;
    ans && (ans += Sum_Solution(n-1)); //利用短路原理终止递归
    return ans;
}