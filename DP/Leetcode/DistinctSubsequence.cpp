#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int i, int j, string s, string t){
        
        if(j<0) return 1;
        if(i<0) return 0;

        int notPick = f(i-1, j, s, t);
        int pick = 0;

        if(s[i]==t[j]){
            pick = f(i-1, j-1, s, t);
        }

        return (pick+notPick);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        int ans = f(n-1, m-1, s, t);

        return ans;
    }
};

int main(){

    string s, t;

    cout<<"First String: ";
    cin>>s;
    cout<<"Second String: ";
    cin>>t;

    Solution sol;
    int ans = sol.numDistinct(s, t);
    cout<<ans<<endl;
}