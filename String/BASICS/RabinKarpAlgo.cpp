#include <bits/stdc++.h>

using namespace std;

// BRUTE FORCE APPROACH
// vector<int> basicApproach(string text,string pattern){

//     vector<int> matches;
//     int n=text.size();
//     int m=pattern.size();

//     for(int i=0;i<=n-m;i++){
//         int j=0;
//         while(j<m && text[i+j]==pattern[j]){
//             j++;
//         }

//         if(j==m){
//             matches.push_back(i);
//         }
//     }

//     return matches;

// }

// Rabin Karp Algo
vector<int> Rabin_Karp(string source, string target)
{
    vector<int> matches;
    int n = source.size();
    int m = target.size();
    int BASE = 1000000;

    if (source == "" or target == "")
        return matches;

    int power = 1;
    for (int i = 0; i < m; i++)
    {
        power = (power * 31) % BASE;
    }

    int targetCode = 0;
    for (int i = 0; i < m; i++)
    {
        targetCode = (targetCode * 31 + target[i]) % BASE;
    }

    int hashCode = 0;
    for (int i = 0; i < n; i++)
    {
        hashCode = (hashCode * 31 + source[i]) % BASE;

        if (i < m - 1)
            continue;
        if (i >= m)
        {
            hashCode = (hashCode - source[i - m] * power) % BASE;
            if (hashCode < 0)
            {
                hashCode += BASE;
            }
        }
        if (hashCode == targetCode)
        {
            if (source.substr(i - m + 1, m) == target)
            {
                matches.push_back(i - m + 2);
            }
        }
    }

    return matches;
}

int main()
{

    string text = "geeksforgeeks";
    string pattern = "geek";

    vector<int> ans = Rabin_Karp(text, pattern);

    cout << "Calculated Answer is: ";
    for (int count : ans)
    {
        cout << count << " ";
    }
    cout << " Whereas Real Answer is: 1,9";
    return 0;
}