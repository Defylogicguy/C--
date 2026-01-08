/*************************
  Author: Defy logic guy
  16:20:12 - 05/07/2025
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
#define NAME "LMH_LMINMAX"

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    deque<int> mx, mn;
    int l = 0, ans = 0;

    for (int r = 0; r < n; r++)
    {
        while (mx.size() and a[r] > a[mx.back()])
            mx.pop_back();
        mx.pb(r);

        while (mn.size() and a[r] < a[mn.back()])
            mn.pop_back();
        mn.pb(r);

        while (a[mx.front()] - a[mn.front()] > d)
        {
            if (mx.front() == l)
                mx.pop_front();
            if (mn.front() == l)
                mn.pop_front();
            l++;
        }

        ans = max(ans, r - l + 1);
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
