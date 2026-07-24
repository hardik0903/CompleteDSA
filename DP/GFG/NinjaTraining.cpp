#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    int ninjaTraining(vector<vector<int>>& arr){
        int n=arr.size();

        vector<vector<int>> dp(n, vector<int>(4, -1));

        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
        int maxi=0;
        for(int day=1;day<n;day++){
            for(int last=0;last<4;last++){
                for(int task=0;task<3;task++){
                    int point = 0;
                    if(task!=last){
                        point = dp[day-1][task] + arr[day][task];
                        dp[day][last] = max(maxi, point);
                    }   
                }
            }
        }
        return dp[n-1][3];
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(3));

    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];  
    }

    Solution sol;
    int ans = sol.ninjaTraining(arr);

    cout<<ans<<endl;
}