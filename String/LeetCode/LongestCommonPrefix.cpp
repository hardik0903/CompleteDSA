#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string>& strs){

    sort(strs.begin(),strs.end());

    int n=strs.size();

    string first=strs[0];
    string last=strs[n-1];
    string ans;

    for(int i=0;i<last.size();i++){
        if(first[i]==last[i]){
            ans.push_back(first[i]);
        }
        else{
            break;
        }
    }

    return ans;
}

int main(){

    int t;
    cout<<"Enter Number of TestCases: ";
    cin>>t;
    cin.ignore();

    for(int i=0;i<t;i++){
        vector<string> s;
        int j;
        cout<<"Enter Number of Strings for array: ";
        cin>>j;
        cin.ignore();
        for(int k=0;k<j;k++){
            string str;
            cout<<"Enter String: ";
            getline(cin,str);
            s.push_back(str);
        }
        string ans=longestCommonPrefix(s);
        cout<<"Your Calculated Answer is: "<<ans<<endl;
    }

    return 0;
}
