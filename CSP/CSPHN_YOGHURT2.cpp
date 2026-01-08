/*************************
  Author: Defy logic guy
  16:27:36 - 12/04/2025
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
#define NAME "CSPHN_YOGHURT2"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int cur = 0;
    heap<pair<int,int>> pq;
    for (int i = 0; i < n; i++)
    {
        cur += a[i];
        if (cur >= b[i])
        {
            cur -= b[i];
            pq.push({b[i], i});
        }
        else if (pq.size() and b[i] <= pq.top().first)
        {
            cur -= b[i];
            cur += pq.top().first;
            pq.pop();
            pq.push({b[i], i});
        }
    }
    cout << pq.size() << '\n';
    vector<int> ans;
    while (pq.size())
        ans.pb(pq.top().second + 1), pq.pop();
    sort(all(ans));
    for (int i : ans)
        cout << i << ' ';
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
