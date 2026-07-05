#include <bits/stdc++.h> 
using namespace std;

// Function to prepare cleaned, lowercase-only alphanumeric string
// string prepared(string s) {
//     string cleaned;
//     for (char ch : s) {
//         if (isalnum(static_cast<unsigned char>(ch))) {
//             if (ch >= 'A' && ch <= 'Z') {
//                 cleaned.push_back(ch - 'A' + 'a');
//             } else {
//                 cleaned.push_back(ch);
//             }
//         }
//     }
//     return cleaned;
// }

// // Function to check palindrome
// bool checkPalindrome(string s) {
//     s = prepared(s);  // clean and lowercase the entire string first

//     int st = 0;
//     int e = s.size() - 1;

//     while (st < e) {  // ✅ correct comparison
//         if (s[st] != s[e]) {
//             return false;
//         }
//         st++;
//         e--;
//     }
//     return true;
// }

void toLowerCase(string &s)
{	
    for (int i = 0; i < s.length(); i++){
        char ch = s[i];
        if (ch <= 'Z' && ch >= 'A'){
            ch = ch - ('A' - 'a');
            s[i] = ch;
        }
    }
}

bool checkPalindrome(string s){	
    toLowerCase(s);
        int i = 0;
        int j = s.length() - 1;
    while (i < j){
        if (isalnum(s[i]) == 0){
            ++i;
        }
        else if (isalnum(s[j]) == 0){
            --j;
        }
        else if (s[i] == s[j]){
            ++i, --j;
        }
        else{
            return false;
        }
    }
    
    return true;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    if (checkPalindrome(str)) {
        cout << "Is a Palindrome \n";
    } else {
        cout << "Not a Palindrome \n";
    }
}
