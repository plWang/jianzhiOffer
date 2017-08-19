#include <iostream>
#include <vector>

using namespace std;

int count(int n, int k) {
    vector<vector<int> > dp(n, vector<int>(k+1, 0));
    dp[0][0] = 1;
    for (int i=1; i<n; i++)
        for (int j=0; j<=k; j++)
            for (int l=0; l<=k; l++)
                dp[i][j] += dp[i-1][l];

    cout << dp[n-1][k] << endl;
    return dp[n-1][k];
}

int main() {
    int n, k;
    cin >> n >> k;
    int c = count(n, k);
}