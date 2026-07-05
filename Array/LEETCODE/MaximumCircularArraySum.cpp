#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int MaximumCircularArraySum(vector<int>& arr){
    int n=arr.size();
    int array_sum=0;
    int min_array_sum=INT_MAX;
    int max_array_sum=INT_MIN;
    int temp_max=0;
    int temp_min=0;

    for(int i=0;i<n;i++){
        array_sum+=arr[i];
        temp_max+=arr[i];
        temp_min+=arr[i];

        if(temp_min>0){
            temp_min=0;
        }

        if(temp_max<0){
            temp_max=0;
        }

        min_array_sum=min(min_array_sum,temp_min);
        max_array_sum=max(max_array_sum,temp_max);
    }

    if(array_sum==min_array_sum){
        return max_array_sum;
    }

    return max(max_array_sum,array_sum-min_array_sum);
}


int main(){
    vector<int> arr={-5,3,2,6,-1,4};
    int ans=MaximumCircularArraySum(arr);

    vector<int> arr2={ 8,-8,9,-9,10,-11,12};
    int ans2=MaximumCircularArraySum(arr2);

    vector<int> arr3={-3,-2,-3};
    int ans3=MaximumCircularArraySum(arr3);

    cout<<"Calculated Answer is: "<<ans<<" Whereas Real Answer is: 14"<<endl;
    cout<<"Calculated Answer is: "<<ans2<<" Whereas Real Answer is: 22"<<endl;
    cout<<"Calculated Answer is: "<<ans3<<" Whereas Real Answer is: -2"<<endl;

return 0;
}