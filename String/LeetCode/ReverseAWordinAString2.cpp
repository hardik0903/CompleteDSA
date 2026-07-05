#include <bits/stdc++.h>

using namespace std;

string reverseAString(string s){
    int i=0;
    int j=0;
    int n=s.size();

    while(j<n && s[j]==' '){
        j++;
    }

    for(;j<n;j++){
        if(s[j]==' ' && i>0 && s[i-1]==' '){
            continue;
        }
        s[i++]=s[j];
    }

    if(i>0 && s[i-1]==' '){
        i--;
    }
    s.resize(i);

    reverse(s.begin(),s.end());

    int start=0;
    for(int end=0;end<=i;end++){
        if(end==i || s[end]==' '){
            reverse(s.begin()+start,s.begin()+end);
            start=end+1;
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
        string ans=reverseAString(s);
        cout<<"Reverse of the Input String is: "<<ans<<endl;
    }
    return 0;
}