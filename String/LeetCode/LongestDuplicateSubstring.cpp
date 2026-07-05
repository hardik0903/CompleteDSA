#include <bits/stdc++.h>

using namespace std;

string help(string &s, int m)
{
    int pri = 1e9 + 7;
    int d = 256;
    int n = s.size();

    long long h = 1;
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % pri;
    }

    long long hash = 0;
    for (int i = 0; i < m; i++)
    {
        hash = (hash * d + s[i]) % pri;
    }

    unordered_map<long long, vector<int>> mp;
    mp[hash] = {0};

    for (int i = 1; i <= n - m; i++)
    {
        hash = ((hash - s[i - 1] * h % pri) * d + s[i + m - 1]) % pri;
        if (hash < 0)
        {
            hash += pri;
        }
        if (mp.find(hash) != mp.end())
        {
            for (auto j : mp[hash])
            {
                if (s.substr(j, m) == s.substr(i, m))
                {
                    return s.substr(i, m);
                }
            }
        }
        mp[hash].push_back(i);
    }
    return "";
}
string longestDupSubstring(string s)
{
    int l = 1;
    int r = s.size() - 1;
    string ans;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        string t = help(s, mid);

        if (!(t.empty()))
        {
            if (ans.size() < t.size())
            {
                ans = t;
            }
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

int main(){

    int t;
    cout<<"Enter Number of TestCases: ";
    cin>>t;
    cin.ignore();

    for(int i=0;i<t;i++){
        string s;
        cout<<"Enter a string: ";
        getline(cin,s);
        string ans=longestDupSubstring(s);
        cout<<"Your Answer is: "<<ans<<endl;
    }
return 0;
}