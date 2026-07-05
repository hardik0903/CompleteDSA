#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findNSE(vector<int> arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSEE(vector<int> arr){
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    int sumSubarrayMins(vector<int>& arr) {
        long long total = 0;
        int mod = (int)(1e9 + 7);

        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        for(int i = 0; i < arr.size(); i++){
            int left = i - psee[i];
            int right = nse[i] - i;

            total = (total + ((left) * right *1LL * arr[i]) % mod) % mod;
        }
        return total;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {3,1,2,4};

    int result = sol.sumSubarrayMins(arr);

    cout << "The sum of minimums of all subarrays is: " << result << endl;

    return 0;
}
