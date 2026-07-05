#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//!BRUTE-FORCE APPROACH
// double findMedian(vector<int>& a,vector<int>& b){
//     int n1=a.size();
//     int n2=b.size();
//     int n=n1+n2;
//     vector<int> ans(n);
//     int i=0, j=0;
//     int index=0;
//     while(i<n1 && j<n2){
//         if(a[i]>b[j]){
//             ans[index++]=b[j++];
//         }
//         else{
//             ans[index++]=a[i++];
//         }
//     }

//     while(i<n1){
//         ans[index++]=a[i++];
//     }

//     while(j<n2){
//         ans[index++]=b[j++];
//     }

//     if(n%2==1){
//         return (double)ans[n/2];
//     }

//     else{
//         return (double)(ans[n/2]+(ans[n/2-1]))/2.0;
//     }

//     return 0;
// }

//!BETTER APPROACH
// double findMedian(vector<int>& a, vector<int>& b){
//     int n1=a.size();
//     int n2=b.size();
//     int n=n1+n2;
//     int i=0;
//     int j=0;
//     int ind2=n/2;
//     int ind1=ind2-1;
//     int cnt=0;

//     int indexEl1=-1, indexEl2=-1;

//     while(i<n1 && j<n2){
//         if(a[i]<b[j]){
//             if(cnt==ind1){
//                 indexEl1=a[i];
//             }
//             else if(cnt==ind2){
//                 indexEl2=a[i];
//             }
//             cnt++;
//             i++;
//         }
//         else{
//             if(cnt==ind1){
//                 indexEl1=b[j];
//             }
//             else if(cnt==ind2){
//                 indexEl2=b[j];
//             }
//             cnt++;
//             j++;
//         }
//     }

//     while(i<n1){
//         if(cnt==ind1){
//             indexEl1=a[i];
//         }
//         else if(cnt==ind2){
//             indexEl2=a[i];
//         }
//         cnt++;
//         i++;
//     }

//     while(j<n2){
//         if(cnt==ind1){
//             indexEl1=b[j];
//         }
//         else if(cnt==ind2){
//             indexEl2=b[j];
//         }
//         cnt++;
//         j++;
//     }

//     if(n%2==1){
//         return (double)indexEl1;
//     }
//     else{
//         return (double)((double)(indexEl1+indexEl2)/2.0);
//     }
//     return 0;
// }

//!OPTIMAL APPROACH
double findMedian(vector<int>& a, vector<int>& b){
    int n1=a.size();
    int n2=b.size();
    int n=n1+n2;

    if(n1>n2) return findMedian(b,a);
    int left=(n1+n2+1)/2;
    int low=0;
    int high=n1;

    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=left-mid1;
        int l1=INT_MIN, l2=INT_MIN;
        int r1=INT_MAX, r2=INT_MAX;

        if(mid1<n1){
            r1=a[mid1];
        }
        if(mid2<n2){
            r2=b[mid2];
        }
        if(mid1-1>=0){
            l1=a[mid1-1];
        }
        if(mid2-1>=0){
            l2=b[mid2-1];
        }
        
        if(l1<r2 && l2<r1){
            if(n%2==1){
                return (double)max(l1,l2);
            }
            else{
                return (double)(max(l1,l2)+min(r1,r2))/2.0;
            }
        }

        if(l1>r2){
            high=mid1-1;
        }

        else{
            low=mid1+1;
        }
    }

    return 0;
}

int main(){
    vector<int> arr1={1,3,4,7,10,12};
    vector<int> arr2={2,3,6,15};

    double ans=findMedian(arr1,arr2);

    cout<<"Calculated Answer is: "<<ans<<" Whereas Rel Answer is 5";
return 0;
}