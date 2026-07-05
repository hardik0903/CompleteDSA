#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> computeLPS(string& s){
        int m=s.size();
        vector<int> lps(m,0);

        int i=1;
        int len=0;

        while(i<m){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
    }

    vector<int> search(string& pat, string& str){
        int n=str.size();
        int m=pat.size();

        vector<int> matches;

        if(m==0 || n<m){
            return matches;
        }

        vector<int> lps=computeLPS(pat);
        int i=0;
        int j=0;

        while(i<n){
            if(pat[j]==str[i]){
                i++;j++;
                if(j==m){
                    matches.push_back(i-m);
                    j=lps[j-1];
                }
            }
            else{
                if(j==0){
                    i++;
                }
                else{
                    j=lps[j-1];
                }
            }
        }
        return matches;
    }
};

int main() {
    int t;
    cout << "Number of TestCases: ";
    cin >> t;
    cin.ignore();  // to handle newlines after test case count

    for (int i = 0; i < t; i++) {
        string txt, pat;
        cout << "\nEnter the Text: ";
        getline(cin, txt);
        cout << "Enter the Pattern: ";
        getline(cin, pat);

        Solution sol;
        vector<int> ans = sol.search(pat, txt);

        cout << "Pattern found at indices: ";
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (int idx : ans) {
                cout << idx << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
