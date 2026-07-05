#include <bits/stdc++.h>

using namespace std;

string reverseAString(string s, int k){
    int n=s.size();

    for(int i=0;i<n;i+=2*k){
        int j=min(i+k-1,n-1);
        int start=i;
        int end=j;
        
        while(start<end){
            swap(s[start++],s[end--]);
        }
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
        int k;
        cout<<"Enter Value of k: ";
        cin>>k;
        string ans=reverseAString(s,k);
        cout<<"Reverse of the Input String is: "<<ans<<endl;
    }
    return 0;
}