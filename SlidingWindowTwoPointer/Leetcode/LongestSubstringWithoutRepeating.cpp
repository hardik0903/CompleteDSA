#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // vector<int> hash(256,-1);
        if(s.size()==0) return 0;
        map<char,int> mpp;
        int l=0;
        int r=0;
        int n=s.size();
        int max_len=1;

        while(r<n){
            if(mpp.find(s[r])!=mpp.end() && mpp[s[r]]>=l){
                l=mpp[s[r]]+1;
            }
            max_len=max(max_len,r-l+1);
            mpp[s[r]]=r;
            r++;
        }

        return max_len;

    }
};

int main(){

    string s="cadbzabcd";

    Solution sol;

    int ans=sol.lengthOfLongestSubstring(s);

    cout<<"Calculated answer is: "<<ans<<" Whereas Real answer is: 5";
return 0;
}