#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int smallestPositive(vector<int>& arr){
    int n=arr.size();
    int x=1;

    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(x==arr[i]){
            x++;
        }
        else if(arr[i]>x){
            break;
        }
    }

    return x;
}

int main(){

    vector<int> arr={2,-3,4,1,1,7};
    int ans=smallestPositive(arr);

    cout<<"Calculated Answer is: "<<ans<<" Whereas Real Answer is: 3";
return 0;
}