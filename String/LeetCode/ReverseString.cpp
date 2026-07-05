#include <bits/stdc++.h>

using namespace std;

void reverseAString(vector<char>& ch){
    int st=0;
    int e=ch.size()-1;

    while(st<=e){
        swap(ch[st++],ch[e--]);
    }
}


int main(){
    int t;

    cout << "Number of TestCases: ";
    cin >> t;
    cin.ignore(); 

    for (int i = 0; i < t; i++) {
        string s;
        cout << "Enter a String: ";
        getline(cin, s); 

        vector<char> ch(s.begin(), s.end()); 

        reverseAString(ch); 

        cout << "Reverse of the Input String is: ";
        for (char c : ch) {
            cout << c; 
        }
        cout << endl;
    }
    return 0;
}