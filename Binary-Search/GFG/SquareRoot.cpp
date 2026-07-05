#include <iostream>

using namespace std;

int sqaureRoot(int n){
    int low=1;
    int high=n;
    int ans=0;

    while(low<=high){
        int mid=(low+high)/2;

        if((mid*mid)>n){
            high=mid-1;
        }
        else if((mid*mid)<=n){
            ans=mid;
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    int n=28;
    int answer=sqaureRoot(n);
    cout<<"Calculated Answer is: "<<answer<<" Whereas Real Answer is: 5 for n="<<n<<endl;
return 0;
}