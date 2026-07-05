#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto it:s){
            if(it=='(' || it=='[' || it=='{'){
                st.push(it);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char ch=st.top();
                st.pop();

                if((it==')' && ch=='(')||(it=='}' && ch=='{')||(it==']' && ch=='[')){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main(){

    string s1="()[{}()]";
    string s2="{()[(])}";

    Solution obj;

    bool obj1=obj.isValid(s1);
    if(obj1==1){
        cout<<"S1 is a Valid Parenthesis and is a Correct Answer"<<endl;
    }
    else{
        cout<<"S1 is Not a Valid Parenthesis and is Not a Correct Answer"<<endl;
    }

    bool obj2=obj.isValid(s2);
    if(obj2==1){
        cout<<"S1 is a Valid Parenthesis and is Not a Correct Answer"<<endl;
    }
    else{
        cout<<"S1 is Not a Valid Parenthesis and is a Correct Answer"<<endl;
    }

    return 0;

}