#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lMax = 0, rMax = 0, total = 0;
        int l = 0, r = n - 1;

        while (l < r) {
            if (height[l] <= height[r]) {
                if (lMax > height[l]) {
                    total += lMax - height[l];
                } else {
                    lMax = height[l];
                }
                l++;
            } else {
                if (rMax > height[r]) {
                    total += rMax - height[r];
                } else {
                    rMax = height[r];
                }
                r--;
            }
        }
        return total;
    }
};

int main() {

    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    

    Solution sol;
    int trapped = sol.trap(height);

    cout <<"Total Water Trapped is: "<< trapped <<" Whereas Correct answer is 6";
    return 0;
}
