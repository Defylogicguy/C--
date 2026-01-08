/*************************
  Author: Defy logic guy
  11:44:34 - 20/07/2025
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
#define NAME "2118C"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += __builtin_popcountll(a[i]);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int c = (~x & (x + 1ll));
        pq.push({c, i});
    }
    int r = k;
    while (pq.size())
    {
        auto [c, i] = pq.top();
        if (c > r)
            break;
        pq.pop();
        r -= c;
        ans++;
        a[i] += c;
        int x = a[i];
        int nw = (~x & (x + 1ll));
        pq.push({nw, i});
    }
    cout << ans << '\n';
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
