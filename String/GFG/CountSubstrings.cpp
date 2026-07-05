#include <bits/stdc++.h>

using namespace std;

int countSubstring(string s){

    int hashMap[3]={0};
    int l=0,r=0,cnt=0;

    while(r<s.size()){

        hashMap[s[r]-'a']=1;

        if(hashMap[0]+hashMap[1]+hashMap[2]==3){
            cnt+=s.size()-r;
            l++;
            r=l;
            hashMap[0]=hashMap[1]=hashMap[2]=0;
        }

        else{
            r++;
        }
    }

    return cnt;
}

int main(){

    int t;

    cout<<"Enter TestCases: ";
    cin>>t;
    cin.ignore();

    for(int i=0;i<t;i++){
        string s;
        cout<<"Enter a String: ";
        getline(cin,s);

        int ans=countSubstring(s);

        cout<<"Calculated Answer is: "<<ans<<endl;
    }

    return 0;
}