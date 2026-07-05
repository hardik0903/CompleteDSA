#include <bits/stdc++.h>

using namespace std;

string minWindow(string S, string T)
{
	// Write your Code here
	string minWin="";
	int j=0, min=S.size()+1;

	for(int i=0;i<S.size();i++){
		if(S[i]==T[j]){
			j++;

			if(j>=T.size()){
				int end=i+1;
				j--;

				while(j>=0){
					if(T[j]==S[i]){
						j--;
					}
					i--;
				}
				i++;
				j++;

				if(end-i <min){
					min=end-i;
					minWin=S.substr(i,min);
				}
			}
		}
	}
	return minWin;
}

int main(){

    string S="XAYMBAZBDCE";
    string T="ABE";

    string ans=minWindow(S,T);

    cout<<"Correct Answer is: AZBDCE, Whereas Calculated Answer is: "<<ans<<endl;
}