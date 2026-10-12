#include <bits/stdc++.h>

using namespace std;

class Solution{
public:

    // Recursion
    int f(int ind, int weight, vector<int>& wt, vector<int>& val){

        //Base case
        if(ind==0){

            //Condition 1: Check whether it is a take 
            if(wt[0]<=weight){
                return val[0];
            } 
            //Condition 2: Not take
            else{
                return 0;
            }
        }

        //BASIC PICK AND NOTPICK LOGIC

        int notTake = 0 + f(ind-1, weight, wt, val);
        int take = INT_MIN;
        // Check whether take can be performed or not
        if(wt[ind] <= weight){
            take = val[ind] + f(ind-1, weight-wt[ind], wt, val);
        }

        return max(notTake, take);
    }
    int knapsack(int W, vector<int>& wt, vector<int>& val){
        int n = wt.size();

        return f(n-1, W, wt, val);
    }
};


int main(){

    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> wt(n);
    vector<int> val(n);

    int W;
    cout<<"Please enter capacity of bag: ";
    cin>>W;

    for(int i=0;i<n;i++){
        int n1, n2;
        cout<<"Enter weight at index "<<i<<": ";
        cin>>n1;
        cout<<"Enter value at index "<<i<<": ";
        cin>>n2;
        wt[i] = n1;
        val[i] = n2;
    }

    Solution sol;
    int ans = sol.knapsack(W, wt, val);
    cout<<ans<<endl;


}