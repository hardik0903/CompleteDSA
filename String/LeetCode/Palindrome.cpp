#include <bits/stdc++.h>

using namespace std;

// void toLowerCase(string& s){

//     for(int i=0;i<s.size();i++){
//         char ch=s[i];
//         if(ch>='A' && ch<='Z'){
//             ch=ch-('A'-'a');
//             s[i]=ch;
//         }
//     }
// }

// bool checkPalindrome(string s){
//     toLowerCase(s);
//     int i=0;
//     int j=s.size()-1;

//     while(i<j){
//         if(isalnum(s[i])==0){
//             i++;
//         }

//         else if(isalnum(s[j])==0){
//             j--;
//         }

//         else if(s[i]==s[j]){
//             i++;
//             j--;
//         }
//         else{
//             return false;
//         }
//     }
//     return true;
// }

bool checkCharacter(char ch){
    if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
        return true;
    }
    else{
        return false;
    }
}

char toLowerCase(char ch){
    if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
        return ch;
    }
    else{
        char temp;
        temp=ch-'A'+'a';
        return temp;
    }
}

bool checkPalindrome(string s){
    int st=0;
    int e=s.size()-1;

    while(st<=e){
        if(s[st]!=s[e]){
            return false;
        }
        else{
            st++;
            e--;
        }
    }
    return true;
}

bool isPalindrome(string s){
    int i=0;
    string temp="";

    for(int j=0;j<s.size();j++){
        if(checkCharacter(s[j])){
            temp.push_back(s[j]);
        }
    }

    for(int j=0;j<temp.size();j++){
        temp[j]=toLowerCase(temp[j]);
    }

    return checkPalindrome(temp);
}

int main(){
    int t;
    cout<<"Number of TestCases: ";
    cin>>t;
    cin.ignore();

    for(int i=0;i<t;i++){
        string s;
        cout<<"Enter a String to Check is it Palindrome: ";
        getline(cin, s);

        if(isPalindrome(s)){
            cout<<"Yes it is Palindrome"<<endl;
        }
        else{
            cout<<"It is Not Palindrome"<<endl;
        }
    }
    return 0;
}