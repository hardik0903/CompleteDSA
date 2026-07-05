#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int MaxProfitCalculation(vector<int>& prices){
    int n=prices.size();
    int maxProfit=0;

    for(int i=0;i<n-1;i++){
        if(prices[i]<prices[i+1]){
            maxProfit+=prices[i+1]-prices[i];
        }
    }
    return maxProfit;
}

int main(){
    vector<int> arr={1,5,3,100};
    int answer=MaxProfitCalculation(arr);

    cout<<"Calculated Answer is: "<<answer<<" Whereas Real Answer is: 101";
return 0;
}