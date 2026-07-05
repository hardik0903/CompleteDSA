#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:

    //!NAIVE APPROACH
    // vector<int> findNSE(vector<int> arr) {
    //     int n = arr.size();
    //     vector<int> nse(n);
    //     stack<int> st;

    //     for (int i = n - 1; i >= 0; i--) {
    //         while (!st.empty() && arr[st.top()] >= arr[i]) {
    //             st.pop();
    //         }
    //         nse[i] = st.empty() ? n : st.top();
    //         st.push(i);
    //     }
    //     return nse;
    // }

    // vector<int> findPSE(vector<int> arr) {
    //     int n = arr.size();
    //     vector<int> pse(n);
    //     stack<int> st;

    //     for (int i = 0; i < n; i++) {
    //         while (!st.empty() && arr[st.top()] > arr[i]) {
    //             st.pop();
    //         }
    //         pse[i] = st.empty() ? -1 : st.top();
    //         st.push(i);
    //     }
    //     return pse;
    // }

    // int largestRectangleArea(vector<int>& heights){

    //     vector<int> nse=findNSE(heights);
    //     vector<int> pse=findPSE(heights);
    //     int n=heights.size();
    //     int maxi=0;

    //     for(int i=0;i<n;i++){
    //         maxi=max(maxi,heights[i]*(nse[i]-pse[i]-1));
    //     }

    //     return maxi;
    // }

    //!OPTIMAL SOLUTION
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxValue=0; 
        int n=heights.size();

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int elements=heights[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxValue=max(maxValue,(elements*(nse-pse-1)));
            }
            st.push(i);
        }

        while(!st.empty()){
            int elements=heights[st.top()];
            st.pop();
            int nse=n;
            int pse=st.empty()?-1:st.top();
            maxValue=max(maxValue,(elements*(nse-pse-1)));
        }

        return maxValue;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {3,2,10,11,5,10,6,3};
    int result = sol.largestRectangleArea(heights);
    cout << result << endl;
    return 0;
}
