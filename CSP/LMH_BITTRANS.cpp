/*************************
  Author: Defy logic guy
  13:04:10 - 22/02/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "LMH_BITTRANS"

void solve()
{
    int x, n, k;
    cin >> x >> n >> k;

    if (x == 0)
    {
        cout << 0 << endl;
        return;
    }

    int m = __builtin_popcountll(x);

    if (k + m > n)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> ones;
    for (int i = 0; i < 32; i++)
        if (x & (1LL << i))
            ones.pb(i);

    int ans = 0;
    for (int i = 0; i < ones.size(); i++)
    {
        int x = k + i;
        if (ones[i] < x)
            ans += (x - ones[i]);
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    if (fopen(NAME ".INP", "r"))
    {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }

    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
