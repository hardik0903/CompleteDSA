#include <iostream>
#include <string>

using namespace std;

string removeOccurences(string s, string part){
    while(s.length()!=0 && s.find(part)<s.length())
    {
        s.erase(s.find(part),part.length());
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
        string part;
        
        cout<<"Enter String: ";
        getline(cin,s);

        cout<<"Enter part: ";
        getline(cin,part);

        string ans=removeOccurences(s,part);
        cout<<"Calculated Answer is: "<<ans<<endl;
    }

    return 0;
}