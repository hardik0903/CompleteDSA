#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string conversion(string s){
        stack<char> st;
        string ans;
        for(char& ch: s){
            if(ch=='('){
                st.push(ch);
            }

            if(ch==')'){
                while(st.top()=='('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }

            if(ch=='^'){
                st.push(ch);
            }

            if(ch=='*' || ch=='/'){
                if(st.top()=='+' || st.top()=='-'){
                    st.push(ch);
                }
                while(!st.empty() || st.top()!='+' || st.top()!='-'){
                    ans+=st.top();
                    st.pop();
                }
                if(st.top()=='+' || st.top()=='-'){
                    st.push(ch);
                }
            }

            if(ch=='+' || ch=='-'){
                if(st.empty()){
                    st.push(ch);
                }
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
                if(st.empty()){
                    st.push(ch);
                }
            }
        }

        while(st.empty()){
            ans+=st.top();
            st.pop();
        }

        return ans;
    }
};

int main(){

    string s = "a+b*c+d";
    Solution sol;
    string ans = sol.conversion(s);
    cout<<ans<<endl;
}