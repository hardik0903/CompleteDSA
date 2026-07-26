#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePaths2(vector<vector<int>> &arr)
    {
        int m = arr.size();
        int n = arr[0].size();
        long long MOD = LLONG_MAX;
        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else if (arr[i][j] == 1)
                    dp[i][j] = 0;
                else
                {
                    long long up = 0, left = 0;

                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];

                    dp[i][j] = (up + left) % MOD;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    int n, m;
    cin >> m >> n;

    vector<vector<int>> arr(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    Solution sol;
    int ans = sol.uniquePaths2(arr);
    cout << ans << endl;
}