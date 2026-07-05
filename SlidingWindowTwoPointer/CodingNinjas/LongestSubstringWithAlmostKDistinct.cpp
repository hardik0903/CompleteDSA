#include <string>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int kDistinctChars(int k, string &s)
{
    // Write your code here
    int maxlen=0, l=0, r=0;
    map<char, int> mpp;

    while(r<s.size()){
        mpp[s[r]]++;

        if(mpp.size()>k){
            mpp[s[l]]--;
            if(mpp[s[l]]==0){
                mpp.erase(s[l]);
            }
            l++;
        }

        if(mpp.size()<=k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;

    }
    return maxlen;
}

int main(){
    int k=2;
    string s="aaabbccd";
    int ans=kDistinctChars(k,s);

    cout<<"Correct Answer is: 5, Whereas Calculated Answer is: "<<ans<<endl;
}
