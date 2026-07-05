#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:

    //!BASIC APROACH
    // stack<pair<int,int>> st;

    // MinStack() {
        
    // }
    
    // void push(int val) {
    //     if(st.empty()){
    //         st.push({val,val});
    //     }
    //     else{
    //         st.push({val,min(val,st.top().second)});
    //     }
    // }
    
    // void pop() {

    //     st.pop();
        
    // }
    
    // int top() {
    //     return st.top().first;
    // }
    
    // int getMin() {
    //     return st.top().second;
    // }

    //!OPTIMAL APPROACH
    stack<long long> st;
    long long int mini;

    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            mini=val;
            st.push(val);
        }
        else{
            if(mini<val){
                st.push(val);
            }
            else{
                st.push((long long)2*val-mini);
                mini=val;
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }

        long long x=st.top();
        st.pop();
        if(mini>x){
            mini=2*mini-x;
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }

        long long x=st.top();
        if(x<mini){
            return mini;
        }
        return x;
    }
    
    int getMin() {
        
        return mini;
    }

};

int main(){

    MinStack obj;
    obj.push(12);
    obj.push(15);
    obj.push(10);
    int min=obj.getMin();
    obj.pop();
    int top=obj.top();
    min=obj.getMin();

    cout<<"Min Value is: "<<min<<" Whereas Minimum Should be 12"<<endl;

}

