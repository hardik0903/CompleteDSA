#include <iostream>
#include <string>
#include <vector>
using namespace std;

char firstNonRepeatingCharacter(const string &s) {
    // Create a frequency array for 26 lowercase english letters
    vector<int> freq(26, 0);
    
    // Count frequency of each character
    for (char ch : s) {
        freq[ch - 'a']++;
    }
    
    // Find and return the first non-repeating character
    for (char ch : s) {
        if (freq[ch - 'a'] == 1)
            return ch;
    }
    
    // If no non-repeating character, return '$'
    return '$';
}

int main() {
    string s;
    cout<<"Enter String: ";
    cin >> s;
    
    char result = firstNonRepeatingCharacter(s);
    
    // if result is '$', then we output -1 according to the problem note
    if (result == '$') {
        cout << -1;
    } else {
        cout << result;
    }
    
    return 0;
}
