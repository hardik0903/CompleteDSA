#include <bits/stdc++.h>

using namespace std;

int beautySum(string s) {
        int ans=0;

        int n=s.size();

        for(int i=0;i<n;i++){

            multiset<int> st;
            map<char,int> mpp;

            for(int j=i;j<n;j++){

                if(mpp.find(s[j])!=mpp.end()){
                    st.erase(st.find(mpp[s[j]]));
                }

                mpp[s[j]]++;

                st.insert(mpp[s[j]]);

                ans+=(*st.rbegin() - *st.begin());
            }

            st.clear();
            mpp.clear();
        }
        return ans;
}

int main(){

    int t;
    cout << "Enter No. of TestCases: ";
    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++)
    {
        string s;
        cout << "Enter String: ";
        getline(cin, s);

        int ans = beautySum(s);

        cout << "Your Longest Palindrome is: " << ans << endl;
    }

    return 0;

}