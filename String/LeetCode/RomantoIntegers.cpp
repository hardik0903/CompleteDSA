#include <bits/stdc++.h>

using namespace std;

int char2Num(char a)
{
    switch (a)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}
int romanToInt(string s)
{
    int result = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (i + 1 < s.size() && char2Num(s[i]) < char2Num(s[i + 1]))
        {
            result -= char2Num(s[i]);
        }
        else
        {
            result += char2Num(s[i]);
        }
    }
    return result;
}

int main()
{

    string s = "MCMXCIV";
    int ans = romanToInt(s);
    cout << "Calculated answer is:1994, Whereas Real Answer is: " << ans << endl;

    return 0;
}