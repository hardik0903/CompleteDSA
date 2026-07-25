#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int f(int ind1, int ind2){

        if(ind1==0 && ind2==0) return 1;
        if(ind1<0 || ind2<0) return 0;

        int up = f(ind1-1, ind2);
        int left = f(ind1, ind2-1);

        return up+left;
    }

    int uniquePaths(int m, int n){
        return f(m-1, n-1);
    }
};

int main(){
    int m,n;
    cin>>m>>n;

    Solution sol;
    int ans = sol.uniquePaths(m, n);
    cout<<ans;
}