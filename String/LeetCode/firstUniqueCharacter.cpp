#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int firstUnique(string s){

    unordered_map<char,int> mpp;

    for(auto ch:s){
        mpp[ch]++;
    }

    for(int i=0;i<s.size();i++){
        if(mpp[s[i]]==1){
            return i;
        }
    }
    return -1;
}

int main(){

    string s="loveleetcode";
    int ans=firstUnique(s);

    cout<<"Answer is: 2 Because v is first unique character, Whereas Calculated Answer is: "<<ans;

return 0;
}