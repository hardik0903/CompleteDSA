#include <iostream>

using namespace std;

int main() {
    int m=8;
    int BASE=1000000;
    int power = 1;
    for(int i = 0;i<m;i++){
        power = (power*31)%BASE;
        cout<<"After "<<i<<" operations power is: "<<power<<endl;
    }
    
    cout<<"Final Value of Power is: "<<power;
    

    return 0;
}