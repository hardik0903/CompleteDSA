#include <bits/stdc++.h>

using namespace std;

//EXTRA SPACE STACK APPROACH
// string removeOuterMostParenthesis(string s){
//     stack<int> st;
//     string ans;

//     for(char ch:s){
//         if(st.empty()){
//             st.push(ch);
//         }
//         else{
//             if(ch=='('){
//                 st.push(ch);
//                 ans.push_back(ch);
//             }
//             else{
//                 st.pop();
//                 if(!st.empty()){
//                     ans.push_back(ch);
//                 }
//             }
//         }
//     }
//     return ans;
// }

//OPTIMAL APPROACH
string removeOuterMostParenthesis(string s){
    int cnt=0;
    string ans;

    for(char ch:s){
        if(ch==')'){
            cnt--;
        }

        if(cnt!=0){
            ans.push_back(ch);
        }

        if(ch=='('){
            cnt++;
        }
    }

    return ans;
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
        string ans=removeOuterMostParenthesis(s);
        cout<<"Your Answer is: "<<ans<<endl;
    }
    return 0;
}