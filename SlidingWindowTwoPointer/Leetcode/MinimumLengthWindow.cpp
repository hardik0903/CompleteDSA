#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int l=0, r=0, cnt=0, sIndex=-1, minLen=1e9, n=s.size(), m=t.size();

        if(m>n) return "";
        vector<int> mpp(256 , 0);

        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }

        while(r<n){
            if(mpp[s[r]]>0) cnt++;
            mpp[s[r]]--;

            while(cnt==m){

                if(r-l+1<minLen){
                    minLen=r-l+1;
                    sIndex=l;
                }

                mpp[s[l]]++;
                if(mpp[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }

        return sIndex==-1 ? "":s.substr(sIndex,minLen);
    }
};

int main(){

    string s="ddaaabbca";
    string t="abc";

    Solution sol;
    string ans=sol.minWindow(s,t);
    cout<<"Correct answer is: bca Whereas Calculated Answer is: "<<ans<<endl;
}