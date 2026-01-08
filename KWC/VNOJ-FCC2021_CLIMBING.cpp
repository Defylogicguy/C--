/*************************
  Author: Defy logic guy
  20:53:23 - 05/08/2025
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
#define NAME "VNOJ-FCC2021_CLIMBING"

void solve()
{
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> ans;
    deque<int> mx, mn;
    for (int i = 0; i < n; i++)
    {
        if (mx.size() && mx.front() <= i - m)
            mx.pop_front();
        if (mn.size() && mn.front() <= i - m)
            mn.pop_front();

        while (mx.size() && a[mx.back()] <= a[i])
            mx.pop_back();
        while (mn.size() && a[mn.back()] >= a[i])
            mn.pop_back();

        mx.pb(i);
        mn.pb(i);

        if (i >= m - 1)
        {
            int mxx = a[mx.front()];
            int mnn = a[mn.front()];
            if (mxx - mnn <= c)
                ans.pb(i - m + 2);
        }
    }
    if (ans.empty())
        cout << "NONE";
    else
        for (int i : ans)
            cout << i << '\n';
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
