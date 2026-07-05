#include <iostream>
#include <cmath>

using namespace std;

//!WITHOUT BUILT-IN FUNCTION
// int intPow(int mid, int n){
//     int result=1;

//     for(int i=0;i<n;i++){
//         result*=mid;
//     }
//     return result; 
// }

// int NthRoot(int n,int m){

//     if(n==1) return m;

//     int low=1;
//     int high=m;

//     while(low<=high){
//         int mid=(low+high)/2;

//         int power=intPow(mid,n);

//         if(power>m){
//             high=mid-1;
//         }
//         else if(power<m){
//             low=mid+1;
//         }
//         else if(power==m){
//             return mid;
//         }
//     }
//     return -1;
// }

//!WITH BUILT-IN FUCNTION
int NthRoot(int n,int m){

    if(n==1) return m;

    int low=1;
    int high=m;

    while(low<=high){
        int mid=(low+high)/2;

        int power=pow(mid,n);

        if(power>m){
            high=mid-1;
        }
        else if(power<m){
            low=mid+1;
        }
        else if(power==m){
            return mid;
        }
    }
    return -1;
}
int main(){
    int n=3;
    int m=9;
    int answer=NthRoot(n,m);

    cout<<"Calculated Answer is: "<<answer<<" Whereas Real Answer is: -1 for n="<<n<<" and m="<<m<<endl;
return 0;
}