/*************************
  Author: Defy logic guy
  21:35:20 - 28/08/2025
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
#define NAME "2136A"

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    auto f = [](int a, int b)
    {
        if (a < 0 or b < 0)
            return false;
        int mx = max(a, b), mn = min(a, b);
        return mx <= 2 * (mn + 1);
    };
    cout << (f(a, b) and f(c - a, d - b) ? "YES\n" : "NO\n");
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
    cin >> tt;

    while (tt--)
        solve();

    return 0;
}
