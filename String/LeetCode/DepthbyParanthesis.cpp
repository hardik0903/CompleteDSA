#include <bits/stdc++.h>

using namespace std;

int maxDepth(string s) {
        int depth=INT_MIN;
        int x=0;
        for(char ch:s){
            if(ch=='('){
                x++;
            }
            depth=max(depth,x);
            if(ch==')'){
                x--;
            }   
        }
        return depth;
    }

int main()
{

    string s = "(1+(2*3)+((8)/4))+1";
    int ans = maxDepth(s);
    cout << "Calculated answer is:3, Whereas Real Answer is: " << ans << endl;

    return 0;
}