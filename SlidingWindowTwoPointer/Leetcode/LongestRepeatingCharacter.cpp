#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int characterReplacement(string s, int k){
        int l=0,n=s.size(),maxlen=0,maxCount=0;
        int cnt[26]={0};

        for(int r=0;r<n;r++){

            int ind=s[r]-'A';
            cnt[ind]++;
            maxCount=max(maxCount,cnt[ind]);
            int windowSize=r-l+1;
            int need=windowSize-maxCount;

            if(need>k){
                int index=s[l]-'A';
                cnt[index]--;
                l++;
            }

            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};

int main(){
    string s="AABABBA";
    int k=2;

    Solution sol;
    int ans=sol.characterReplacement(s,k);

    cout<<"Calculated Answer is: "<<ans<<" Whereas Real Answer is: 5"<<endl;
return 0;
}