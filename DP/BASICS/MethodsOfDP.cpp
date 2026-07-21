#include <bits/stdc++.h>
using namespace std;

class Solution{

public: 
    //!BASIC APPROACH: RECURSION
    int fibonacci(int n){
        if(n==0) return 0;
        if(n==1) return 1;

        return fibonacci(n-1)+fibonacci(n-2);
    }
};

int main(){
    Solution sol;
    int number;
    cin>>number;

    int ans = sol.fibonacci(number);
    cout<<ans;

}