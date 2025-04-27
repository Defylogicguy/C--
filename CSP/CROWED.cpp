/*************************
  Author: Defy logic guy
  15:21:16 - 26/04/2025
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
#define NAME "CROWED"

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(all(a));
    vector<int> x(n), h(n), l(n), r(n);
    for (int i = 0; i < n; i++)
        x[i] = a[i].first, h[i] = a[i].second;
    heap<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({h[max(0ll, i - 1)], max(0ll, i - 1)});
        while (pq.size() and x[pq.top().second] < x[i] - d)
            pq.pop();
        l[i] = pq.size() ? pq.top().first : 0;
    }

    while (pq.size())
        pq.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        pq.push({h[i + 1], i + 1});
        while (pq.size() and x[pq.top().second] > x[i] + d)
            pq.pop();
        r[i] = pq.size() ? pq.top().first : 0;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (l[i] >= 2 * h[i] and r[i] >= 2 * h[i])
            ans++;
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
