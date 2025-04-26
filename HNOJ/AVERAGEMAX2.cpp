/*************************
  Author: Defy logic guy
  11:05:21 - 26/04/2025
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
#define NAME "AVERAGEMAX2"

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<float> a(n);
    float mn = 1e18, mx = -1e18;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    float lo = mn, hi = mx;
    const float eps = 1e-5;
    vector<float> pf(n + 1);

    auto f = [&](float mid)
    {
        pf[0] = 0;
        for (int i = 1; i <= n; i++)
            pf[i] = pf[i - 1] + (a[i - 1] - mid);
        deque<int> dq;
        for (int v = l; v <= n; v++)
        {
            int u = v - l;
            while (dq.size() and pf[dq.back()] >= pf[u])
                dq.pop_back();
            dq.pb(u);
            int id = v - r;
            while (dq.size() and dq.front() < id)
                dq.pop_front();
            if (dq.size() and pf[v] - pf[dq.front()] >= 0)
                return true;
        }
        return false;
    };

    while (hi - lo > eps)
    {
        float mid = (lo + hi) / 2;
        if (f(mid))
            lo = mid;
        else
            hi = mid;
    }

    cout << fixed << setprecision(4) << lo;
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
