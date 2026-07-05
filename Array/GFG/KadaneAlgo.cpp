#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int kadaneAlgorithm(vector<int>& arr){
    int n=arr.size();
    int current_sum=arr[0];
    int max_sum=arr[0];

    for(int i=1;i<n;i++){
        current_sum=max(arr[i],current_sum+arr[i]);
        max_sum=max(current_sum,max_sum);
    }
    return max_sum;
}

int main(){
    vector<int> arr={-2,-3,4,-1,-2,1,5,-3};
    int ans=kadaneAlgorithm(arr);

    cout<<"Calculated Answer is: "<<ans<<" Whereas Real Answer is: 7";
return 0;
}