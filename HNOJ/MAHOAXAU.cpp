/*
 Author: Defy logic guy
 22:27:04 - 30/12/2024
*/
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
#define NAME "Skibidi"

void solve()
{
    string s;
    int k;
    cin >> s >> k;
    string a, b;
    cin >> a >> b;
    unordered_map<char, char> mp;
    for (int i = 0; i < a.size(); i++)
        mp[a[i]] = b[i];
    vector<vector<char>> c(26);
    for (int i = 0; i < 26; i++)
    {
        char need = 'a' + i;
        c[i].pb(need);
        char cur = mp[need];
        while (cur != need)
        {
            c[i].pb(cur);
            cur = mp[cur];
        }
    }
    unordered_map<char, char> ans(26);
    for (int i = 0; i < 26; i++)
    {
        int mod = k % c[i].size();
        ans['a' + i] = c[i][mod];
    }
    for (char c : s)
        cout << ans[c];
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
