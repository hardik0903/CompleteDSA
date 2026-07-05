#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size();
        int m = num2.size();
        vector<int> result(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j;
                int p2 = i + j + 1;
                int sum = mul + result[p2];
                result[p2] = sum % 10;
                result[p1] += sum / 10;
            }
        }

        string res = "";
        for (int val : result) {
            if (!(res.empty() && val == 0)) {
                res += (val + '0');
            }
        }

        return res.empty() ? "0" : res;
    }
};

int main() {
    int t;
    cout << "Number of TestCases: ";
    cin >> t;
    cin.ignore();

    Solution sol;

    for (int i = 0; i < t; i++) {
        string s1, s2;
        cout << "Enter first number string: ";
        getline(cin, s1);
        cout << "Enter second number string: ";
        getline(cin, s2);
        string ans = sol.multiply(s1, s2);
        cout << "Product: " << ans << endl;
    }

    return 0;
}
