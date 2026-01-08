/*************************
  Author: Defy logic guy
  20:08:17 - 08/02/2025
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
#define NAME "ABC_098B"

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int _max = 0;
    for (int i = 1; i < n - 1; i++)
    {
        string one = s.substr(0, i);
        string two = s.substr(i, n - i);
        map<char, bool> mp1, mp2;
        for (char c : one)
            mp1[c] = 1;
        for (char c : two)
            mp2[c] = 1;
        int cnt = 0;
        for (auto it : mp1)
            if (mp2[it.first] == 1)
                cnt++;
        _max = max(_max, cnt);
    }

    cout << _max << endl;
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
