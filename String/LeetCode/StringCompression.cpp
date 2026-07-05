#include <iostream>
#include <vector>
#include <string>

using namespace std;

int compress(vector<char>& chars){
    int i=0;
    int ansIndex=0;
    int n=chars.size();

    while(i<n){

        int j=i+1;

        while(j<n && chars[i]==chars[j]){
            j++;
        }

        chars[ansIndex++]=chars[i];

        int count=j-i;

        if(count>1){
            string str=to_string(count);
            for(char ch: str){
                chars[ansIndex++]=ch;
            }
        }

        i=j;
    }

    return ansIndex;
}   

int main(){
    vector<char> ch={'a','a','b','b','c','c','c','c','d'};
    int ans=compress(ch);

    cout<<"Real Answer is: 7, Whereas Calculated Answer is: "<<ans<<endl;

    return 0;
}
