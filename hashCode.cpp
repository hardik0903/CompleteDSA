#include <iostream>
#include <string>

using namespace std;

int main() {
    int m=8;
    int BASE=1000000;
    string source="abcdabcdabcd";
    string target="cdabcdab";
    int targetCode=746308;
    int power=37441;
    int hashCode = 0;
        for(int i = 0;i<source.size();i++){
            hashCode = (hashCode*31 + source[i])%BASE;
            cout<<"After "<<i<<" operations hashCode is: "<<hashCode<<endl;
            
            if(i<m-1) continue;
            if(i>=m){
                hashCode = (hashCode-source[i-m]*power)%BASE;
                cout<<"     After "<<i<<" operations new hasCode is: "<<hashCode<<endl;
            }
            if(hashCode<0){
                cout<<"     Ohh no hashCode becomes less than 0"<<endl;
                hashCode+=BASE;
                cout<<"     Making Our new hashCode as 1000000 (equal to BASE)"<<endl;
                cout<<"Our hashCode is: "<<hashCode<<endl;
            }
            if(hashCode == targetCode){
        
                cout<<"     Hehehe a Match Occurs Our targetCode is: "<<targetCode<<" And Our hashCode is: "<<hashCode<<endl;
                if(source.substr(i-m+1,m) == target)
                    cout<<"Hell, yes Match is a Success"<<endl;
                    cout<<"And Our Answer is i-m+1: "<<i-m+1<<endl;
                    break;
            }
        }

    return 0;
}