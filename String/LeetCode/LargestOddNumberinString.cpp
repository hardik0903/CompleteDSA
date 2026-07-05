#include <bits/stdc++.h>

using namespace std;

//APPROACH MAY RESULT IN MEMORY LIMIT EXCEEDED
// string largestOddNumber(string s){
//     string ans="";

//     for(int i=0;i<s.size();i++){
//         int digit=s[i]-'0';
//         if(digit%2!=0){
//             ans=s.substr(0,i+1);
//         }
//     }
//     return ans;
// }

string largestOddNumber(string s){
    for(int i=s.size();i>=0;i--){
        if((s[i]-'0')%2!=0){
            return s.substr(0,i+1);
        }
    }
    return "";
}

int main(){
    int t;
    cout<<"Enter Number of TestCases: ";
    cin>>t;
    cin.ignore();

    for(int i=0;i<t;i++){
        string s;
        cout<<"Enter a String: ";
        getline(cin,s);
        string ans=largestOddNumber(s);
        cout<<"Your Answer is: "<<ans<<endl;
    }
    return 0;
}