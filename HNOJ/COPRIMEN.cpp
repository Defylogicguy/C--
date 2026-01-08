#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,lzcnt,popcnt,fma")
/*************************
  Author: Defy logic guy
  11:19:40 - 17/05/2025
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
#define endl '\n'
#define NAME "COPRIMEN"

vector<pair<int, int>> masks;

vector<int> get(int n)
{
    vector<int> p;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
        {
            p.pb(i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        p.pb(n);
    return p;
}

void pre(const vector<int> &p)
{
    int m = p.size();
    for (int mask = 1; mask < (1 << m); ++mask)
    {
        int lcm = 1;
        bool flow = false;
        int bit = __builtin_popcount(mask);
        for (int i = 0; i < m; ++i)
            if (mask & (1 << i))
            {
                if (lcm > LLONG_MAX / p[i])
                {
                    flow = true;
                    break;
                }
                lcm *= p[i];
            }
        if (!flow)
        {
            int sign = (bit % 2 == 1) ? 1 : -1;
            masks.emplace_back(lcm, sign);
        }
    }
}

int cnt(int x)
{
    int res = x;
    for (auto &[a, b] : masks)
        res -= b * (x / a);
    return res;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> p = get(n);
    pre(p);

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << cnt(r) - cnt(l - 1) << endl;
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
