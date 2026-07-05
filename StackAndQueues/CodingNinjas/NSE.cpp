#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> nse(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]<=st.top()){
            st.pop();
        }
        if(st.empty()){
            nse[i]=-1;
        }
        else{
            nse[i]=st.top();
        }
        st.push(arr[i]);
    }
    return nse;
}

int main() {
    vector<int> arr1 = {4, 5, 2, 10, 8};
    int n1 = arr1.size();
    vector<int> result1 = nextSmallerElement(arr1, n1);

    cout << "Original Array 1: ";
    for (int x : arr1) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Next Smaller Elements 1: ";
    for (int x : result1) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Expected: 2 2 -1 8 -1" << endl;
    cout << "---------------------------------------" << endl;

    return 0;
}