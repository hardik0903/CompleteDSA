#include <iostream>
#include <string>

using namespace std;

string replaceSpaces(string& s){
    string result;

    for(char ch: s){
        if(ch==' '){
            result+="@40";
        }
        else{
            result.push_back(ch);
        }
    }
    return result;
}

int main(){

    int t;
    cout<<"Enter Number of TestCases: ";
    cin>>t;
    cin.ignore();

    for(int i=0;i<t;i++){
        string s;
        cout<<"Enter a String: ";
        getline(cin,s);
        string ans=replaceSpaces(s);
        cout<<"Calculated Answer is: "<<ans<<endl;
    }
    return 0;
}