#include <iostream>
#include <string>

using namespace std;

bool checkEqual(int a[26], int b[26]){
    for(int i=0;i<26;i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1,string s2){
    int count1[26]={0};

    for(int i=0;i<s1.length();i++){
        int index=s1[i]-'a';
        count1[index]++;
    }

    int i=0;
    int windowSize=s1.length();
    int count2[26]={0};

    while(i<windowSize && i<s2.length()){
        int index=s2[i]-'a';
        count2[index]++;
        i++;
    }

    if(checkEqual(count1,count2)){
        return true;
    }

    while(i<s2.length())
    {
        char newChar=s2[i];
        int index=newChar-'a';
        count2[index]++;

        char oldChar=s2[i-windowSize];
        index=oldChar-'a';
        count2[index]--;

        i++;

        if(checkEqual(count1,count2)){
            return true;
        }
    }

    return false;

}

int main(){
    int t;
    cout<<"Number of TestCases: ";
    cin>>t;
    cin.ignore();

    for(int i=0;i<t;i++){
        string s1;
        string s2;

        cout<<"Enter String s1: ";
        getline(cin,s1);

        cout<<"Enter String s2: ";
        getline(cin,s2);

        bool ans=checkInclusion(s1,s2);
        cout<<"Calculated Answer is: "<<ans<<endl;
    }

    return 0;
}