/*************************
  Author: Defy logic guy
  20:22:59 - 30/05/2025
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
#define endl '\n'
#define NAME "ABC094B"

void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    map<int,bool> mp;
    for (int i = 0; i < m;i++)
    {
        int x;
        cin >> x;
        mp[x] = true;
    }

    int ans = 0;
    for (int i = x; i > 0; i--)
        ans += mp[i];
    int cur = 0;
    for (int i = x + 1; i <= n; i++)
        cur += mp[i];
    cout << min(ans, cur) << endl;
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
