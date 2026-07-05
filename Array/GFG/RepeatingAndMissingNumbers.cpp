#include <iostream>
#include <climits>
#include <vector>

using namespace std;

//!BRUTE FORCE CODE
// vector<int> findTwoElement(vector<int> &arr)
// {
//     int n = arr.size();
//     int repeating = -1;
//     int missing = -1;

//     for (int i = 1; i <= n; i++)
//     {
//         int cnt = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[j] == i)
//             {
//                 cnt++;
//             }
//         }
//         if (cnt == 0)
//         {
//             missing = i;
//         }
//         if (cnt == 2)
//         {
//             repeating = i;
//         }
//         if (repeating != -1 && missing != -1)
//             break;
//     }
//     return {repeating, missing};
// }

//!BETTER APPROACH
// vector<int> findTwoElement(vector<int>& arr){
//     int n=arr.size();
//     int hash[n+1]={0};
//     int repeating=-1,missing=-1;

//     for(int i=0;i<n;i++){
//         hash[arr[i]]++;
//     }

//     for(int i=1;i<=n;i++){
//         if(hash[i]==2) repeating=i;
//         else if(hash[i]==0) missing=i;
//         if(repeating!=-1 && repeating!=-1){
//             break;
//         }
//     }
//     return {repeating,missing};
// }

//!First OPTIMAL APPROACH USING MATHEMATICAL LOGIC
vector<int> findTwoElement(vector<int>& arr){
    long long n=arr.size();
    long long sn=(n*(n+1))/2;
    long long s2n=(n*(n+1)*(2*n+1))/6;
    long long s=0,s2=0;
    for(int i=0;i<n;i++){
        s+=(long long)arr[i];
        s2+=(long long)arr[i]*(long long)arr[i];
    }

    long long val1=s-sn;
    long long val2=s2-s2n;
    val2=val2/val1;

    long long x=(val1+val2)/2;
    long long y=(x-val1);

    return {(int)x, (int)y};
    
}


//!Second OPTIMAL APPROACH USING XOR IDEA
// vector<int> findTwoElement(vector<int>& arr){

//     long long n=arr.size();
//     int xr=0;

//     for(int i=0;i<n;i++){
//         xr=xr^arr[i];
//         xr=xr^(i+1);
//     }

//     int bitNo=0;
//     while(1){
//         if(xr & (1<<bitNo)!=0){
//             break;
//         }
//         bitNo++;
//     }

//     int zero=0;
//     int one=0;

//     for(int i=0;i<n;i++){
//         if((arr[i] & (1<<bitNo))!=0){
//             one=one^arr[i];
//         }
//         else{
//             zero=zero^arr[i];
//         }
//     }

//     for(int i=1;i<=n;i++){
//         if((i & (1<<bitNo))!=0){
//             one=one^i;
//         }
//         else{
//             zero=zero^i;
//         }
//     }

//     int cnt=0;

//     for(int i=0;i<n;i++){
//         if(arr[i]==zero){
//             cnt++;
//         }
//         if(cnt==2) return {zero,one};
//     }
//     return {one,zero};
// }

int main()
{

    vector<int> arr1 = {5,1,6,2,4,6};
    vector<int> ans1 = findTwoElement(arr1);

    cout << "Answer is: ";
    for (int i = 0; i < 2; i++)
    {
        cout << ans1[i] << " ";
    }
    cout << "Whereas Real Answer is: 6,3";

    return 0;
}