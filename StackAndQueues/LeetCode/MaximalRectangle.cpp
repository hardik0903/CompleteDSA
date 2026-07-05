#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
    
class Solution {
public:

    //!OPTIMAL APPROACH
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int maxArea=0;
        vector<vector<int>> pSum(n,vector<int>(m, 0));

        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(matrix[j][i]=='1') sum+=1;
                if(matrix[j][i]=='0') sum=0;
                pSum[j][i]=sum;
            }
        }

        for(int i=0;i<n;i++){
            maxArea=max(maxArea,largestRectangleArea(pSum[i]));
        }

        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> matrix = {
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}
};

    int result = sol.maximalRectangle(matrix);
    cout << result << endl;
    return 0;
}
