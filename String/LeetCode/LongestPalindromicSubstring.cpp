#include <bits/stdc++.h>

using namespace std;

// BRUTE-FORCE APPROACH
//  bool isPalindrome(string s){
//      int left=0;
//      int right=s.length()-1;

//     while(left<right){
//         if(s[left]==s[right]){
//             left++;
//             right--;
//         }
//         else{
//             return false;
//         }
//     }
//     return true;
// }

// string longestPalindrome(string s){
//     if(s.length()<=1){
//         return s;
//     }

//     int max_len=1;
//     string max_str=s.substr(0,1);

//     for(int i=0;i<s.size();i++){
//         for(int j=i+max_len;j<s.size();j++){

//             if(j-i>max_len && isPalindrome(s.substr(i,j-i))){
//                 max_len=j-i;
//                 max_str=s.substr(i,j-i);
//             }
//         }
//     }

//     return max_str;
// }

// Two-Pointers Approach
// int expandAround(string s, int left, int right)
// {

//     while (left >= 0 && right < s.size() && s[left] == s[right])
//     {
//         left--;
//         right++;
//     }

//     return right - left - 1;
// }
// string longestPalindrome(string s)
// {
//     if (s == "")
//     {
//         return "";
//     }

//     int start = 0;
//     int end = 0;

//     for (int i = 0; i < s.size(); i++)
//     {
//         int odd = expandAround(s, i, i);
//         int even = expandAround(s, i, i + 1);
//         int max_len = max(odd, even);

//         if (max_len > (end - start))
//         {
//             start = (i - (max_len - 1) / 2);
//             end = (i + (max_len / 2));
//         }
//     }
//     return s.substr(start, end - start + 1);
// }

// Manacher's Algorithm
vector<int> manacher(string t)
{
    int n = t.size();
    vector<int> p(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
            p[i] = min(r - i, p[l + r - i]);

        while (l + p[i] < n && i - p[i] >= 0 && t[i - p[i]] == t[i + p[i]])
        {
            p[i]++;
        }

        if (i + p[i] > r)
        {
            l = i - p[i];
            r = i + p[i];
        }
    }
    return p;
}
string longestPalindrome(string s)
{
    string t = "#";
    for (int i = 0; i < s.size(); i++)
    {
        t += s[i];
        t += '#';
    }

    vector<int> man = manacher(t);

    int n = man.size();
    int ans = 0, k;

    for (int i = 0; i < n; i++)
    {
        if (man[i] > ans)
        {
            ans = man[i] - 1;
            k = i;
        }
    }

    int l = k - ans;
    int r = k + ans;

    string result;

    for (int j = l; j <= r; j++)
    {
        if (t[j] != '#')
        {
            result += t[j];
        }
    }
    return result;
}

int main()
{
    int t;
    cout << "Enter No. of TestCases: ";
    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++)
    {
        string s;
        cout << "Enter String: ";
        getline(cin, s);

        string ans = longestPalindrome(s);

        cout << "Your Longest Palindrome is: " << ans << endl;
    }

    return 0;
}