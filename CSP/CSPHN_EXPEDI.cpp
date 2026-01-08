/*************************
  Author: Defy logic guy
  16:04:12 - 12/04/2025
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
#define NAME "CSPHN_EXPEDI"

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    int l, p;
    cin >> l >> p;
    l -= p;
    sort(rall(a));
    a.insert(a.begin(), {0, 0});
    heap<int> pq;
    int ans = 0, j = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        if (a[i].first == a[i - 1].first)
            continue;
        while (l > a[i].first)
        {
            while (j <= i and  l <= a[j].first)
            {
                pq.push(a[j].second);
                j++;
            }
            if (pq.empty())
            {
                cout << -1;
                return;
            }

            ans++;
            l -= pq.top();
            pq.pop();
        }
    }
    cout << ans;
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
