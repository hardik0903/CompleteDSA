#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; 
        int n = asteroids.size();

        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0 || st.empty()) {
                st.push_back(asteroids[i]);
            }
            else {
                while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
                    st.pop_back();
                }

                if (!st.empty() && st.back() == abs(asteroids[i])) {
                    st.pop_back();
                }
                else if (st.empty() || st.back() < 0) {
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};

int main() {
    Solution sol;
    vector<int> asteroids = {4, 7, 1, 1, 2, -3, -7, 17, 15, -16};

    vector<int> result = sol.asteroidCollision(asteroids);

    cout << "Result after collisions: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
