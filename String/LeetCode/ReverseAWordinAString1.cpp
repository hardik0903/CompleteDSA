#include <iostream>
#include <string>


using namespace std;

string reverseAString(string s){
    string result="";
    int i=0;
    int j=0;

    while(i<s.size()){
        while(i<s.size() && s[i]==' '){
            i++;
        }
        if(i>=s.size()) break;
        j=i+1;

        while(j<s.size() && s[j]!=' '){
            j++;
        }

        string w=s.substr(i,j-i);

        if(result.empty()){
            result=w;
        }
        else if(!result.empty()){
            result=w+' '+result;
        }
        i=j+1;
    }
    return result;
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