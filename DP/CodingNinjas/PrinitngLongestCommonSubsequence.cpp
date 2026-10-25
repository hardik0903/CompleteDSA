#include <bits/stdc++.h>
using namespace std;

/// int longestCommonSubsequence(string s1, string s2){

// 	int n = s1.size();
// 	int m = s2.size();

// 	vector<vector<int>> dp(n, vector<int>(m, 0));

// 	for(int i=1;i<=n;i++){
// 		for(int j=1;j<=m;j++){

// 			if(s1[i-1]==s2[j-1]){
// 				dp[i][j] = 1 + dp[i-1][j-1];
// 			}
// 			else{
// 				dp[i-1][j-1] = max(dp[i-1][j], dp[i][j-1]);
// 			}
// 		}
// 	}
// 	return dp[n][m];
// }

string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.	

	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){

			if(s1[i-1]==s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	int len = dp[n][m];
	// cout<<len<<endl;

	string s = "";
	for(int i=0;i<len;i++) s+='$';

	int index = len-1;
	int i=n, j=m;

	while(i>0 && j>0){

		if(s1[i-1]==s2[j-1]){
			s[index] = s1[i-1];
			index--;
			i--;
			j--;
		}

		else if(dp[i-1][j] > dp[i][j-1]){
			i--;
		}
		else{
			j--;
		}
	}

	return s;
}

int main(){
    int n;
    int m;
    string s1, s2;

    cout<<"Enter First String: ";
    cin>>s1;
    cout<<"Enter Second String: ";
    cin>>s2;

    n = s1.size();
    m = s2.size();

    string ans = findLCS(n, m, s1, s2);
    cout<<ans<<endl;
}