#include <iostream>
#include <string>

using namespace std;

int main() {
    int BASE=1000000;
    int m=8;
    string target="cdabcdab";
    int targetCode = 0;
        for(int i = 0;i<m;i++){
            targetCode = (targetCode*31+target[i])%BASE;
            cout<<"After "<<i<<" operations targetCode is: "<<targetCode<<endl;
        }
        
        cout<<"Final Value of targetCode is: "<<targetCode<<endl;

    return 0;
}