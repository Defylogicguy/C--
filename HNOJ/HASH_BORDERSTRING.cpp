/*************************
  Author: Defy logic guy
  08:47:40 - 22/02/2025
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
#define NAME "HASH_BORDERSTRING"

void solve()
{
    string s;
    cin >> s;
    vector<int> hash(s.size() + 1, 0);
    for (int i = 1; i <= s.size(); i++)
        hash[i] = (hash[i - 1] * 31 + (s[i - 1] - 'a')) % MOD;

    int cur = 1;
    for (int sz = 1; sz < s.size(); sz++)
    {
        cur = (cur * 31) % MOD;
        int one = hash[sz];
        int two = (hash[s.size()] - (hash[s.size() - sz] * cur) % MOD + MOD) % MOD;
        if (one == two)
            cout << sz << ' ';
    }
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
