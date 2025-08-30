/*************************
  Author: Defy logic guy
  21:56:11 - 28/08/2025
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
#define NAME "2136C"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> p(n + 1);
    vector<int> mx(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int v = a[i];
        p[v].pb(i);
        int t = -1;
        if (p[v].size() >= v)
            t = mx[p[v][p[v].size() - v] - 1] + v;
        mx[i] = max(mx[i - 1], (t == -1 ? mx[i - 1] : t));
    }
    cout << mx[n] << '\n';
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
