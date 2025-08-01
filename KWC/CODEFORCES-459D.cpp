/*************************
  Author: Defy logic guy
  20:54:59 - 29/07/2025
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
#define NAME "CODEFORCES-459D"

struct Fenwreck
{
    vector<int> a;
    int n;

    Fenwreck(int _n)
    {
        n = _n + 2;
        a.assign(n, 0);
    }

    void upd(int i, int v)
    {
        while (i < n)
        {
            a[i] += v;
            i += (i & -i);
        }
    }

    int get(int i)
    {
        int res = 0;
        while (i > 0)
        {
            res += a[i];
            i -= i & -i;
        }
        return res;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<int, int> mp;
    for (auto x : a)
        mp[x];
    int id = 1;
    for (auto &[_, v] : mp)
        v = id++;

    for (int i = 0; i < n; i++)
        a[i] = mp[a[i]];

    unordered_map<int, int> mpl, mpr;
    vector<int> l(n), r(n);

    for (int i = 0; i < n; i++)
        l[i] = ++mpl[a[i]];

    for (int i = n - 1; i >= 0; i--)
        r[i] = ++mpr[a[i]];

    Fenwreck f(maxall(l) + 2);

    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ans += f.get(l[i] - 1);
        f.upd(r[i], 1);
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
    // cin >> tt;

    while (tt--)
        solve();
    return 0;
}
