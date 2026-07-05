#include <bits/stdc++.h>

using namespace std;

//!BRUTE-FORCE APPROACH
// class StockSpanner {
// public:
//     vector<int> arr;
//     int ind = -1;

//     StockSpanner() {
//         while(!arr.empty()){
//             arr.pop_back();
//         }
//     }
    
//     int next(int price) {
//         arr.push_back(price);
//         int cnt=1;
//         for(int i=arr.size()-2;i>=0;i--){
//             if(arr[i]<=price) cnt++;
//             else break;
//         }
//         return cnt;
//     }
// };

//!OPTIMAL APPROACH
class StockSpanner {
public:
    stack<pair<int,int>> st;
    int ind = -1;

    StockSpanner() {
        ind = -1;
    }
    
    int next(int price) {
        ind++;
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int ans = ind - (st.empty() ? -1 : st.top().second);
        st.push({price, ind});
        return ans;
    }
};

int main() {
    StockSpanner* obj = new StockSpanner();
    vector<int> prices = {7, 2, 1, 3, 3, 1, 8};

    for (int price : prices) {
        int result = obj->next(price);
        cout << result << " ";
    }
    cout << endl;

    delete obj; // clean up
    return 0;
}
