/*************************
  Author: Defy logic guy
  23:03:34 - 12/08/2025
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
#define NAME "2119B"

void solve()
{
    int n;
    cin >> n;
    int x, y, u, v;
    cin >> x >> y >> u >> v;
    vector<double> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a.push_back(sqrt((x - u) * (x - u) + (y - v) * (y - v)));
    sort(a.begin(), a.end());
    double t = a.back();
    for (int i = n - 1; i >= 0; i--)
        t -= a[i];
    cout << (t <= 0 ? "YES\n" : "NO\n");
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
