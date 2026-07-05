#include <iostream>
#include <string>

using namespace std;

string removeDuplicates(string s){
    for(int i=0;i<s.length();i++){
        if(i>0 && s[i]==s[i-1]){
            s.erase(s.begin()+(i-1),s.begin()+(i-1)+2);
            i-=2;
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
        cout<<"Enter String: ";
        getline(cin,s);

        string ans=removeDuplicates(s);
        cout<<"Calculated Answer is: "<<ans<<endl;
    }

    return 0;
}