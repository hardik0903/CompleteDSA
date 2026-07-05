#include <iostream>
#include <string>

using namespace std;

char getMaxOccurence(string s){

    int arr[26]={0};

    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch>='a' && ch<='z'){
            int n=ch-'a';
            arr[n]++;
        }
    }

    int maxi=-1;
    int ans=-1;

    for(int i=0;i<26;i++){
        if(arr[i]>maxi){
            maxi=arr[i];
            ans=i;
        }
    }

    char finalAns='a'+ans;

    return finalAns;
}

int main(){

    int t;
    cout<<"Number of TestCases: ";
    cin>>t;
    cin.ignore();

    for(int i=0;i<t;i++){
        string s;
        cout<<"Enter String: ";
        getline(cin,s);

        char ans=getMaxOccurence(s);
        cout<<"Calculated Answer is: "<<ans<<endl;
    }

    return 0;
}