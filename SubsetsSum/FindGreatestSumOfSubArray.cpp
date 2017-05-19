int FindGreatestSumOfSubArray(vector<int> array) {
    int maxSum = -10000;
    int n = array.size();
    vector<int> dp(n, 0);
    dp[0] = array[0];
    for (int i=1; i<n; i++) {
        dp[i] = (dp[i-1]>0)?(dp[i-1]+array[i]):array[i];
        maxSum = max(dp[i], maxSum);
    }

    return maxSum;
}