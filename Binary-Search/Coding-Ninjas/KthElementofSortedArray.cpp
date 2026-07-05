#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int kthElement(vector<int> &a, vector<int>& b, int n1, int n2, int k){
    // Write your code here
    int n=n1+n2;

    if(n1>n2) return kthElement(b,a,n2,n1,k);
    int left=k;
    int low=max(0,k-n2);
    int high=min(k,n1);

    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=left-mid1;
        int l1=INT_MIN, l2=INT_MIN;
        int r1=INT_MAX, r2=INT_MAX;

        if(mid1<n1){
            r1=a[mid1];
        }
        if(mid2<n2){
            r2=b[mid2];
        }
        if(mid1-1>=0){
            l1=a[mid1-1];
        }
        if(mid2-1>=0){
            l2=b[mid2-1];
        }
        
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }

        if(l1>r2){
            high=mid1-1;
        }

        else{
            low=mid1+1;
        }
    }

    return 0;
}

int main(){
    vector<int> arr1={2,3,6,7,9};
    vector<int> arr2={1,4,8,10};

    int ans=kthElement(arr1,arr2,5,4,4);

    cout<<"Calculated Answer is: "<<ans<<" Whereas Real Answer is: 4";
return 0;
}