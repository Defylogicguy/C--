/*************************
  Author: Defy logic guy
  19:54:18 - 17/02/2025
*************************/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "SHIFTSTRING"

int booth(const string &s)
{
    int n = s.size();
    string s2 = s + s;
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n)
        if (s2[i + k] == s2[j + k])
            k++;
        else
        {
            if (s2[i + k] > s2[j + k])
                i = i + k + 1;
            else
                j = j + k + 1;
            if (i == j)
                j++;
            k = 0;
        }
    return min(i, j);
}

void solve()
{
    string s;
    cin >> s;
    int pos = booth(s);
    string res = s.substr(pos) + s.substr(0, pos);
    cout << res;
}

signed main()
{
    if (fopen(NAME ".INP", "r"))
    {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
