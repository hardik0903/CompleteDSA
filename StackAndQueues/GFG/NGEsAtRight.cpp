#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    
    int countNGE(vector<int> arr, int ind){
        int curr = arr[ind];
        int count = 0;
        
        for (int end = arr.size() - 1; end > ind; --end) {
            if (arr[end] > curr) {
                ++count;
            }
        }
        
        return count;
    }

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        vector<int> ans(indices.size());
        for (int i = 0; i < (int)indices.size(); ++i) {
            ans[i] = countNGE(arr, indices[i]);
        }
        return ans;
    }
};

int main() {
    // Hardcoded example:
    // arr[] = {3, 4, 2, 7, 5, 8, 10, 6}
    // queries = 2
    // indices[] = {0, 5}
    vector<int> arr = {3, 4, 2, 7, 5, 8, 10, 6};
    int n = arr.size();

    vector<int> indices = {0, 5};
    int queries = indices.size();

    Solution sol;
    vector<int> result = sol.count_NGE(n, arr, queries, indices);

    // Print the result in the format [6, 1]
    cout << "[";
    for (int i = 0; i < queries; ++i) {
        cout << result[i];
        if (i + 1 < queries) cout << ", ";
    }
    cout << "]\n";

    return 0;
}
