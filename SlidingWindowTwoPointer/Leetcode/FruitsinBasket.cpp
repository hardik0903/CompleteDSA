#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    //!BRUTE-FORCE ANSWER
    // int totalFruit(vector<int>& fruits) {
    //     int maxlen=0;
    //     int n=fruits.size();
    //     for(int i=0;i<n;i++){
    //         set<int> st;
    //         for(int j=i;j<n;j++){
    //             st.insert(fruits[j]);

    //             if(st.size()<=2){
    //                 maxlen=max(maxlen,j-i+1);
    //             }

    //             else{
    //                 break;
    //             }
    //         }
    //     }
    //     return maxlen;
    // }

    //! BETTER ANSWER
    // int totalFruit(vector<int>& fruits) {
    //     int l=0,r=0,maxlen=0,n=fruits.size();
    //     map<int,int> mpp;
    //     int k=2;

    //     while(r<n){
    //         mpp[fruits[r]]++;

    //         while(mpp.size()>k){
    //             mpp[fruits[l]]--;
    //             if(mpp[fruits[l]]==0){
    //                 mpp.erase(fruits[l]);
    //             }
    //             l++;
    //         }

    //         if(mpp.size()<=k){
    //             maxlen=max(maxlen,r-l+1);
    //         }
    //         r++;
    //     }
    //     return maxlen;
    // }

    //!OPTIMAL ANSWER
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,maxlen=0,n=fruits.size();
        map<int,int> mpp;
        int k=2;

        while(r<n){
            mpp[fruits[r]]++;

            if(mpp.size()>k){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }

            if(mpp.size()<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};

int main(){

    vector<int> arr={3,3,3,3,1,2,1,1,2,3,3,4};
    Solution sol;

    int ans=sol.totalFruit(arr);

    cout<<"Calculcated Answer is: "<<ans<<" Whereas Real Answer is: 5"<<endl;
    return 0;
}