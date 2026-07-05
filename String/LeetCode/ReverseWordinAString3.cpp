#include <bits/stdc++.h>

using namespace std;

string reverseAString(string s){
    int i=0;
    int j=0;
    int n=s.size();

    while(i<n){
        while(i<n && s[i]==' '){
            i++;
        }
        j=i;
        while(j<n && s[j]!=' '){
            j++;
        }
        reverse(s.begin()+i,s.begin()+j);

        i=j;
    }
    return s;
}


int main(){
    int t;

    cout<<"Number of TestCases: ";
    cin>>t;
    cin.ignore();

    for(int i=0;i<t;i++){
        string s;
        cout<<"Enter a String: ";
        getline(cin,s);
        string ans=reverseAString(s);
        cout<<"Reverse of the Input String is: "<<ans<<endl;
    }
    return 0;
}