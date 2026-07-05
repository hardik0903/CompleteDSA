#include <bits/stdc++.h>

using namespace std;

class Solution{

public:

    //!NAIVE APPROACH
    // vector<int> findNGE2(vector<int> arr){

    // int n=arr.size();
    // vector<int> nge(n);
    
    // for(int i=0;i<n;i++){
    //     bool found=false;

    //     for(int j=i+1;j<n;j++){

    //         if(arr[j]>arr[i]){
    //             nge[i]=arr[j];
    //             found=true;
    //             break;
    //         }
            
    //     }

    //     if(!found){
    //         for(int j=0;j<i;j++){

    //             if(arr[j]>arr[i]){
    //                 nge[i]=arr[j];
    //                 found=true;
    //                 break;
    //             }
    //         }
    //     }

    //     if(!found){
    //         nge[i]=-1;
    //     }        
    // }

    // return nge;
    // }

    //!BETTER APPROACH
    // vector<int> findNGE2(vector<int> arr){
    //     int n=arr.size();
    //     vector<int> nge(n);

    //     for(int i=0;i<n;i++){
    //         nge[i]=-1;
    //         for(int j=i+1;j<i+n-1;j++){
    //             int ind=j%n;
    //             if(arr[ind]>arr[i]){
    //                 nge[i]=arr[ind];
    //                 break;
    //             }
    //         }
    //     }

    //     return nge;
    // }

    //!OPTIMAL APPROACH
    vector<int> findNGE2(vector<int>& arr) {
        
        stack<int> st;
        int n=arr.size();

        vector<int> nge(n);

        for(int i=2*n-1;i>=0;i--){

            while(!st.empty() && st.top()<=arr[i%n]){
                st.pop();
            }

            if(i<n){
                nge[i]=st.empty() ? -1:st.top();
            }

            st.push(arr[i%n]);
        }

        return nge;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = {2,10,12,1,11};
    cout << "Original Array 1: ";
    for (int x : arr1) {
        cout << x << " ";
    }
    cout << endl;
    vector<int> nge1 = sol.findNGE2(arr1);
    cout << "Next Greater Elements 1: ";
    for (int x : nge1) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Expected: 10 12 -1 11 12" << endl;
    cout << "---------------------------------------" << endl;

}