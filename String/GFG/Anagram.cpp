#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool areAnagrams(const string &s1, const string &s2) {
    // If lengths are different, they cannot be anagrams
    if (s1.size() != s2.size())
        return false;
    
    // Frequency array for 26 letters initialized to 0
    vector<int> freq(26, 0);
    
    // Count frequency in s1 and s2
    for (char ch : s1) {
        freq[ch - 'a']++;
    }
    
    for (char ch : s2) {
        freq[ch - 'a']--;
    }
    
    // Check if all frequencies are zero
    for (int count : freq) {
        if (count != 0)
            return false;
    }
    
    return true;
}

int main() {
    // Example 1
    string s1 = "geeks", s2 = "kseeg";
    cout << "Are \"" << s1 << "\" and \"" << s2 << "\" anagrams? " 
         << (areAnagrams(s1, s2) ? "true" : "false") << "\n";

    // Example 2
    s1 = "allergy", s2 = "allergic";
    cout << "Are \"" << s1 << "\" and \"" << s2 << "\" anagrams? " 
         << (areAnagrams(s1, s2) ? "true" : "false") << "\n";

    // Example 3
    s1 = "g", s2 = "g";
    cout << "Are \"" << s1 << "\" and \"" << s2 << "\" anagrams? " 
         << (areAnagrams(s1, s2) ? "true" : "false") << "\n";
    
    return 0;
}
