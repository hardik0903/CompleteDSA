#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int digitA = (i >= 0) ? num1[i] - '0' : 0;
            int digitB = (j >= 0) ? num2[j] - '0' : 0;
            int sum = digitA + digitB + carry;
            res += (sum % 10) + '0';
            carry = sum / 10;
            i--;
            j--;
        }

        reverse(res.begin(), res.end());
        return res;
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
        string ans = sol.addStrings(s1, s2);
        cout << "Sum: " << ans << endl;
    }

    return 0;
}
