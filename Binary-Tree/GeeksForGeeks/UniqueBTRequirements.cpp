#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool isPossible(int a, int b) {
        if(a==2 && b==2) return false;
        if(a==2 || b==2) return true;
        
        return false;
    }
};

int main(){
    int a,b;
    cout<<"Enter a Value: ";
    cin>>a;

    cout<<"Enter b Value: ";
    cin>>b;
    Solution s;
    if(s.isPossible(a,b)){
        cout<<"The Building of Unique Binary Tree is Possible";
    }
    else{
        cout<<"Not Possible Building a Unique Binary Tree";
    }
}