/*************************
  Author: Defy logic guy
  23:04:36 - 04/09/2025
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
#define NAME "1036C"

vector<int> v;

void dfs(int pos, int cnt, int cur)
{
    if (pos == 18)
    {
        v.pb(cur);
        return;
    }
    dfs(pos + 1, cnt, cur * 10);
    if (cnt < 3)
        for (int i = 1; i < 10; i++)
            dfs(pos + 1, cnt + 1, cur * 10 + i);
}

void pre()
{
    dfs(0, 0, 0);
    v.pb((int)1e18);
}

void solve()
{
    int l, r;
    cin >> l >> r;
    cout << upper_bound(all(v), r) - lower_bound(all(v), l) << '\n';
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

    pre();

    int tt = 1;
    cin >> tt;

    while (tt--)
        solve();

    return 0;
}
