#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int MaxProfitCalculation(vector<int>& prices){
    int n=prices.size();
    int maxProfit=0;
    int mini=prices[0];

    for(int i=0;i<n;i++){
        int cost=prices[i]-mini;
        maxProfit=max(maxProfit,cost);
        mini=min(mini,prices[i]);
    }
    return maxProfit;
}

int main(){
    vector<int> arr={1,5,3,100};
    int answer=MaxProfitCalculation(arr);

    cout<<"Calculated Answer is: "<<answer<<" Whereas Real Answer is: 99";
return 0;
}