#include <bits/stdc++.h>

using namespace std;

bool isomorphicString(string s, string t){

    if(s.size()!=t.size()){
            return false;
        }

        map<char,char> mpp;
        map<char,bool> smap;

        for(int i=0;i<t.size();i++){
            if(mpp.count(s[i])){
                if(mpp[s[i]]!=t[i]){
                    return false;
                }
            }

            else{
                if(smap[t[i]]){
                    return false;
                }

                mpp[s[i]]=t[i];
                smap[t[i]]=true;
            }
        }

        return true;
    }

int main(){

    int t;

    cout<<"Enter Number of TestCases: ";
    cin>>t;
    cin.ignore();

    for(int i=0;i<t;i++){

        string s;
        cout<<"Enter String 1: ";
        getline(cin,s);

        string t;
        cout<<"Enter String 2: ";
        getline(cin,t);

        cout<<"Is your give string Isomorphic: "<<isomorphicString(s,t)<<endl;
    }

    return 0;
}