/*************************
  Author: Defy logic guy
  14:41:54 - 12/04/2025
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
#define NAME "CSPHN_QHD_FRACTION"

struct frac
{
    int a, b;
    bool operator<(const frac &other) const
    {
        return a * other.b < b * other.a;
    }
};


int lis(vector<frac> v)
{
    vector<frac> lis;
    for (const auto &f : v)
    {
        auto it = lower_bound(all(lis), f);
        if (it == lis.end())
            lis.pb(f);
        else
            *it = f;
    }
    return lis.size();
}

void solve()
{
    int n, w;
    cin >> n >> w;
    vector<frac> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].a >> v[i].b;

    if (w == 0)
        cout << lis(v) << endl;
    else
    {
        // backtrack(0, v, {});
        vector<frac> idk;
        for (int i = 0; i < n; i++)
        {
            frac f = v[i];
            frac f1 = {f.b, f.a};
            if (f < f1)
            {
                idk.pb(f1);
                idk.pb(f);
            }
            else
            {
                idk.pb(f);
                idk.pb(f1);
            }
        }
        cout << lis(idk) << endl;
    }
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
