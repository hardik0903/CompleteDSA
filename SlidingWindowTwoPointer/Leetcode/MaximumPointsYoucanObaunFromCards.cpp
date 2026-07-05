#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0,rsum=0,maxsum=0;
        
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        maxsum=lsum;
        int n=cardPoints.size();
        int rindex=n-1;
        for(int i=k-1;i>=0;i--){
            lsum=lsum-cardPoints[i];
            rsum=rsum+cardPoints[rindex];
            maxsum=max(maxsum,lsum+rsum);
            rindex--;
        }
        return maxsum;
    }
};

int main(){
    vector<int> arr={6,2,3,4,7,2,1,7,1};
    int k=4;

    Solution sol;
    int ans=sol.maxScore(arr,k);
    cout<<"Calculated Answer is: "<<ans<<" Whereas Real Answer is: 16"<<endl;
return 0;
}