/*************************
  Author: Defy logic guy
  14:54:08 - 08/02/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "CSPHN_POOL"

int f(int mid, vector<int> a)
{
    heap<int, vector<int>, greater<int>> pq;
    int cur = 0;
    for (int i = 0; i < mid; i++)
        pq.push(a[i]), cur = max(cur, a[i]);

    for (int i = mid; i < a.size(); i++)
    {
        int x = pq.top();
        pq.pop();
        int idk = x + a[i];
        cur = max(cur, idk);
        pq.push(idk);
    }

    return cur;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int t = *max_element(all(a));
    int l = 1, r = n;
    int ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int idk;
        idk = f(mid, a);

        if (idk <= m)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
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
