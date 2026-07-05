#include <bits/stdc++.h>

using namespace std;


//!NAIVE APPROACH
// vector<int> findNGE(vector<int> arr){

//     int n=arr.size();
//     vector<int> nge(n);

//     for(int i=0;i<n;i++){
//         nge[i]=-1;
//         for(int j=i+1;j<n-1;j++){
//             if(arr[i]<arr[j]){
//                 nge[i]=arr[j];
//                 break;
//             }
//         }
//     }

//     return nge;
// }

//!OPTIMAL APPROACH
vector<int> findNGE(vector<int> arr){

    int n=arr.size();
    vector<int> nge(n);
    stack<int> st;

    for(int i=n-1;i>=0;i--){

        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }

        if(st.empty()){
            nge[i]=-1;
        }

        else{
            nge[i]=st.top();
        }

        st.push(arr[i]);
    }

    return nge;
}

int main() {
    vector<int> arr = {4, 5, 2, 25, 10, 8};

    cout << "Original array: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    cout << endl;

    vector<int> result = findNGE(arr);

    cout << "Calculated Anwer is Next Greater Elements: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << endl;

    cout<<"Correct Answer is Next Greater Elements: 5 25 25 -1 -1 -1 "<<endl;

    return 0;
}