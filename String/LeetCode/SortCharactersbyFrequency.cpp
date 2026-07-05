#include <bits/stdc++.h>

using namespace std;

string sortCharacters(string s)
{
    unordered_map<char, int> mpp;

    for (char ch : s)
    {
        mpp[ch]++;
    }

    priority_queue<pair<int, char>> pq;

    for (auto &it : mpp)
    {
        pq.push({it.second, it.first});
    }

    string result;

    while (!(pq.empty()))
    {
        pair < int, char > top = pq.top();
        pq.pop();
        result.append(top.first, top.second);
    }

    return result;
}

int main()
{
    string s = "tree";

    string ans = sortCharacters(s);

    cout << "Calculated Answer is: " << ans << " Whereas Real Answer is: eert";

    return 0;
}