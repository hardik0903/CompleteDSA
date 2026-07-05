#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int getMinDiff(vector<int> &arr, int k) {
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int ans=arr[n-1]-arr[0];
    if(ans==0) return 0;
    int largest=arr[n-1]-k;
    int smallest=arr[0]+k;
    int mi,ma;
    
    for(int i=1;i<n;i++){
        int mi=min(smallest,arr[i]-k);
        int ma=max(largest,arr[i-1]+k);
        if(mi<0) continue;
        ans=min(ans,ma-mi);
    }
    return ans;
}

int main(){
    vector<int> arr={2,4,3,9,9,10,9,7,1,2};
    int ans=getMinDiff(arr,4);
    cout<<"Calculated Answer is:"<<ans<<" Whereas Real Answer is: 5";
return 0;
}

