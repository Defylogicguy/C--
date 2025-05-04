/*************************
  Author: Defy logic guy
  21:11:32 - 29/04/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "CSPHN_BALANCE1"

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a, b;
    vector<pair<int, int>> pos;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x + 1 <= m)
            a.pb(x + 1);
        if (y + 1 <= m)
            b.pb(y + 1);
        pos.pb({x, y});
    }

    sort(all(a));
    sort(all(b));
    a.erase(unique(all(a)), a.end());
    b.erase(unique(all(b)), b.end());

    int ans = n;
    for (int i : a)
        for (int j : b)
        {
            int one = 0, two = 0, tri = 0, fur = 0;
            for (auto [x, y] : pos)
            {
                if (x < i and y < j)
                    one++;
                else if (x < i and y > j)
                    two++;
                else if (x > i and y > j)
                    tri++;
                else if (x > i and y < j)
                    fur++;
            }

            ans = min(ans, max({one, two, tri, fur}));
        }

    cout << ans << endl;
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
