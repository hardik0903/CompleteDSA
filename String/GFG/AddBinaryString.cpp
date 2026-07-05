#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to add two binary strings
string addBinary(string& a, string& b) {
    string res = "";
    int carry = 0;

    // Reverse the strings to start from the least significant bit
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int n = max(a.size(), b.size());

    // Iterate through both strings and add corresponding bits
    for (int i = 0; i < n; i++) {
        int digitA = (i < a.size()) ? a[i] - '0' : 0;
        int digitB = (i < b.size()) ? b[i] - '0' : 0;

        int total = digitA + digitB + carry;
        res += (total % 2) + '0'; // Append the result bit
        carry = total / 2; // Update carry for next iteration
    }

    // If carry remains, add '1' to result
    if (carry) {
        res += '1';
    }

    // Reverse the result string to correct the order
    reverse(res.begin(), res.end());

    // Remove leading zeros if any
    int pos = res.find_first_not_of('0');
    if (pos != string::npos) {
        res = res.substr(pos);
    } else {
        res = "0";
    }

    return res;
}

int main() {
    // Test case
    string a = "1101"; // Binary representation of 13
    string b = "1011"; // Binary representation of 11

    // Call the addBinary function and print the result
    cout << "Sum of " << a << " and " << b << " is: " << addBinary(a, b) << endl;
    
    return 0;
}
