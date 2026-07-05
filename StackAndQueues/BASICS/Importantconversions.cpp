#include <bits/stdc++.h>

using namespace std;

int priority(char ch){

    if(ch=='^') return 3;

    else if(ch=='*' || ch=='/') return 2;

    else if(ch=='+' || ch=='-') return 1;

    else return -1;
}

string reverseString(string s){
    reverse(s.begin(),s.end());
    
    for(char &ch:s){
        if(ch==')') ch='(';
        else if(ch=='(') ch=')';
    }

    return s;
}

// Infix to Prefix
string infixtoPrefix(string a){
    string s=reverseString(a);

    int i=0;
    string ans="";
    stack<char> st;
    int n=s.size();

    while(i<n){

        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }

        else if(s[i]=='('){
            st.push(s[i]);
        }

        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }

        else{

            if(s[i]=='^'){
                while(!st.empty() && priority(s[i])<=priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }

            else{
                while(!st.empty() && priority(s[i])<priority(st.top())){
                    ans+=st.top();
                    st.pop();
                } 
                st.push(s[i]);      
            }
        }
        i++;
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());

    return ans;
}

//Infix to Postfix
string infixtoPostfix(string s){
    int i=0;
    stack<char> st;
    string ans="";
    int n=s.size();

    while(i<n){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }

        else if(s[i]=='('){
            st.push(s[i]);
        }

        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            while(!st.empty() && priority(s[i])<=priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    return ans;
}

//Postfix to Infix
string postfixtoInfix(string s){

    int i=0;
    stack<string> st;
    int n=s.size();

    while(i<n){

        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1,s[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string ans='('+t2+s[i]+t1+')';
            st.push(ans);
        }
        i++;
    }

    return st.top();
}

//Prefix to Infix
string prefixtoInfix(string s){

    stack<string> st;
    int n=s.size();
    int i=n-1;

    while(i>=0){

        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1,s[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string ans='('+t1+s[i]+t2+')';
            st.push(ans);
        }
        i--;
    }

    return st.top();
}

//Postfix to Prefix
string postfixtoPrefix(string s){

    int i=0;
    stack<string> st;
    int n=s.size();

    while(i<n){

        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1,s[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string ans=s[i]+t2+t1;
            st.push(ans);
        }
        i++;
    }

    return st.top();
}

//Prefix to Postfix
string prefixtoPostfix(string s){

    stack<string> st;
    int n=s.size();
    int i=n-1;

    while(i>=0){

        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1,s[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string ans=t1+t2+s[i];
            st.push(ans);
        }
        i--;
    }

    return st.top();
}

int main(){

    string s1="a+b*(c^d-e)";
    string s2="(A+B)*C-D+F";

    string postofs=infixtoPostfix(s1);
    string preofs=infixtoPrefix(s2);

    string inofpost=postfixtoInfix(postofs);
    string inofpre=prefixtoInfix(preofs);

    string preofpost=postfixtoPrefix(postofs);
    string postofpre=prefixtoPostfix(preofs);

    cout<<"Postfix expression of string s: "<<s1<<" is: "<<postofs<<endl;
    cout<<"Prefix expression of string s: "<<s2<<" is: "<<preofs<<endl;

    cout<<"Infix expression of string s: "<<postofs<<" is: "<<inofpost<<endl;
    cout<<"Infix expression of string s: "<<preofs<<" is: "<<inofpre<<endl;
    
    cout<<"Prefix expression of string s: "<<postofs<<" is: "<<preofpost<<endl;
    cout<<"Postfix expression of string s: "<<preofs<<" is: "<<postofpre<<endl;

return 0;
}