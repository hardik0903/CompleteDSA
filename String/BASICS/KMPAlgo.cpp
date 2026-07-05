#include <bits/stdc++.h>

using namespace std;

// BRUTE FORCE APPROACH
// vector<int> basicApproach(string text,string pattern){

//     vector<int> matches;
//     int n=text.size();
//     int m=pattern.size();

//     for(int i=0;i<=n-m;i++){
//         int j=0;
//         while(j<m && text[i+j]==pattern[j]){
//             j++;
//         }
//         if(j==m){
//             matches.push_back(i);
//         }
//     }

//     return matches;

// }

vector<int> computeLPS(string& pat){
        int m=pat.size();
        vector<int> lps(m,0);
        
        int len=0;
        int i=1;
        
        while(i<m){
            if(pat[i]==pat[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
    }
    vector<int> KMPAlgo(string& txt, string& pat) {
        // code here
        int m=pat.size();
        int n=txt.size();
        
        vector<int> matches;
        if(m==0 || n<m){
            return matches;
        }
        
        vector<int> lps=computeLPS(pat);
        int i=0;
        int j=0;
        
        while(i<n){
            if(txt[i]==pat[j]){
                i++;j++;
                if(j==m){
                    matches.push_back(i-m);
                    j=lps[j-1];
                }
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        
    return matches;
        
}

int main(){

    string text="ababcdabcd";
    string pattern="abcd";

    vector<int> ans=KMPAlgo(text,pattern);

    cout<<"Calculated Answer is: ";
    for(int count:ans){
        cout<<count<<" ";
    }
    cout<<" Whereas Real Answer is: 2, 6";
return 0;
}