/*************************
  Author: Defy logic guy
  20:41:57 - 18/07/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "DPDIGIT_XORLE"

int x, l, r, s;
map<tuple<int, int, int, int>, int> mp;
int dfs(int pos, bool tl, bool tr, bool ts)
{
    if (pos < 0)
        return 1;
    auto f = make_tuple(pos, tl, tr, ts);
    if (mp.count(f))
        return mp[f];
    int ans = 0;
    int xb = (x >> pos) & 1, lb = (l >> pos) & 1, rb = (r >> pos) & 1, sb = (s >> pos) & 1;
    for (int i = 0; i <= 1; i++)
    {
        int t = i ^ xb;
        if (ts && t > sb)
            continue;
        if (tl && i < lb)
            continue;
        if (tr && i > rb)
            continue;
        bool ntl = tl && (i == lb), ntr = tr && (i == rb), nts = ts && (t == sb);
        ans += dfs(pos - 1, ntl, ntr, nts);
    }
    return mp[f] = ans;
}
void solve()
{
    cin >> x >> l >> r >> s;
    cout << dfs(60, true, true, true);
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
