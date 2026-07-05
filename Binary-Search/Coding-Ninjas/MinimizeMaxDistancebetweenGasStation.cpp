#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool check(double dist, vector<int>& arr,int k){
	int n=arr.size();
	int cnt=0;

	for(int i=0;i<n-1;i++){
		cnt+=(arr[i+1]-arr[i])/dist;
	}

	return cnt>k;
}

double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.	
	int n=arr.size();
	int maxi=0;

	for(int i=0;i<n-1;i++){
		maxi=max(maxi,(arr[i+1]-arr[i]));
	}

	double low=0;
	double high=maxi;

	double diff=1e-6;

	while(high-low>diff){
		double mid=(low+high)/(2.0);

		if(check(mid,arr,k)){
			low=mid;
		}
		else{
			high=mid;
		}
	}

	return high;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    double ans=minimiseMaxDistance(arr,4);

    cout<<"Calculated Answer is: "<<ans<<" Whereas Real Answer is: 0.5";
return 0;
}