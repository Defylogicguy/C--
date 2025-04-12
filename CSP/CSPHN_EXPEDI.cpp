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
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x >> mp[x];
    }

    int l, p;
    cin >> l >> p;
    heap<int> pq;
    int cnt = 0;
    int nxt = l - p;
    while (l > 0)
    {
        if (l < nxt)
            break;
        l--;
        if (mp[l])
            pq.push(mp[l]);
        if (l == nxt)
        {
            cnt++;
            nxt -= p;
        }
    }
    cout << cnt;
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
