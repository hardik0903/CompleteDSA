#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

//!BRUTE FORCE APPROACH
// vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals){

//     int n=intervals.size();
//     sort(intervals.begin(),intervals.end());
//     vector<vector<int>> ans;

//     for(int i=0;i<n;i++){
//         int start=intervals[i][0];
//         int end=intervals[i][1];

//         if(!ans.empty() && end<=ans.back()[1]){
//             continue;
//         }
//         for(int j=i+1;j<n;j++){
//             if(end>=intervals[j][0]){
//                 end=max(end,intervals[j][1]);
//             }
//             else{
//                 break;
//             }
//         }
//         ans.push_back({start,end});
//     }
//     return ans;
// }

//!OPTIMAL APPROACH
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals){
    int n=intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        if(ans.empty() || intervals[i][0]>ans.back()[1]){
            ans.push_back(intervals[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }
    }
    return ans;
}


int main(){
    vector<vector<int>> arr1={{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};
    vector<vector<int>> answer=mergeIntervals(arr1);

    cout<<"Calculated Answer is: "<<endl;
    for (const auto& row : answer) {
        for (const auto& element : row) {
            cout << element << " ";
        }
        cout << "\n";
    }

    cout<<"Whereas Real Answer is: (1,6),(8,11),(15,18)";

return 0;
}