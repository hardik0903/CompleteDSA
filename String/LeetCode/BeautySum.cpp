int beautySum(string s) {
        int ans=0;
        int n=s.size();

        for(int i=0;i<n;i++){
            multiset<int> st;
            map<char,int> mpp;

            for(int j=0;j<n;j++){
                st.erase(st.find(mpp[s[j]]));
                mpp[s[j]]++;
                st.insert(mpp[s[j]]);
                ans+=(*st.rbegin() - *st.begin());
            }
        }

        return ans;

    }