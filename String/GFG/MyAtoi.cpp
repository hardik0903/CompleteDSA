#include <iostream>
#include <climits>
#include <cctype>

using namespace std;

int myAtoi(char *s) {
    int sign = 1, res = 0, i = 0;
    
    // Skip any leading whitespace
    while(s[i] && isspace(s[i])){
        i++;
    }
    
    // Check for sign (+/-)
    if(s[i] && (s[i]=='-' || s[i]=='+')){
        if(s[i]=='-'){
            sign = -1;
        }
        i++;
    }
    
    // Process the digits and build the result, checking for overflow
    while(s[i] && s[i]>='0' && s[i]<='9'){
        int newNum = s[i]-'0';
        if(res > INT_MAX/10 || (res == INT_MAX/10 && newNum > 7)){
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        
        res = res * 10 + newNum;
        i++;
    }
    
    return res * sign;
}

int main(){
    // Sample case
    // Example input: -123
    char s[100];
    cout << "Enter a string: ";
    cin.getline(s, 100);
    
    int result = myAtoi(s);
    cout << "Converted integer: " << result << endl;
    
    return 0;
}
