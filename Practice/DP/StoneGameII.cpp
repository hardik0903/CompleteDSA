#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> suffixSum;
    // dp[i][M] = max stones the current player can get starting at pile i with reach M
    int stoneGameII(vector<int>& piles, vector<vector<int>>& dp) {
        n = piles.size();

        // suffix sums: suffixSum[i] = total stones from index i to the end
        suffixSum.assign(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // M can range from 1 to n, so size dp accordingly (index 0 unused for M)
        // dp.assign(n + 1, vector<int>(n + 1, -1));

        return f(0, 1, dp);
    }

    int f(int i, int M, vector<vector<int>>& dp) {
        // Base case: no piles left
        if (i >= n) return 0;

        // Base case: can take everything remaining
        if (n - i <= 2 * M) return suffixSum[i];

        // Cap M for indexing safety (M can't usefully exceed n)
        int Mcap = min(M, n);
        if (dp[i][Mcap] != -1) return dp[i][Mcap];

        int best = 0;
        for (int x = 1; x <= 2 * M; x++) {
            if (i + x > n) break;
            int opponentBest = f(i + x, max(M, x), dp);
            int candidate = suffixSum[i] - opponentBest;
            best = max(best, candidate);
        }

        return dp[i][Mcap] = best;
    }
};

int main() {
    vector<int> piles = {2, 7, 9, 4, 4};
    int n=5;
    Solution sol;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    cout << "Alice's max stones: " << sol.stoneGameII(piles, dp) << endl; // Expected: 10
    
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[i].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}