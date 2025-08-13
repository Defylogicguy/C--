/*************************
  Author: Defy logic guy
  22:58:50 - 12/08/2025
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
#define NAME "2102D"

void solve()
{
    auto gp = [&](vector<int> &v)
    {
        int n = v.size();
        vector<int> c = v;
        sort(c.begin(), c.end());
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
            m[c[i]] = i;

        vector<int> f(n + 1);
        int r = 0;
        auto up = [&](int i)
        {
            i++;
            for (; i <= n; i += i & -i)
                f[i]++;
        };
        auto qr = [&](int i)
        {
            int s = 0;
            i++;
            for (; i > 0; i -= i & -i)
                s += f[i];
            return s;
        };

        for (int i = n - 1; i >= 0; i--)
        {
            int x = m[v[i]];
            r ^= (qr(x - 1) & 1);
            up(x);
        }
        return r;
    };

    auto bd = [&](vector<int> &x, vector<int> &y)
    {
        int n = x.size() + y.size();
        vector<int> r(n);
        int ix = 0, iy = 0;
        for (int i = 0; i < n; i++)
            r[i] = (i % 2 == 0 ? x[ix++] : y[iy++]);
        return r;
    };

    int n;
    cin >> n;
    vector<int> a(n), e, o;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        (i % 2 ? o : e).push_back(a[i]);
    }

    auto se = e, so = o;
    sort(se.begin(), se.end()), sort(so.begin(), so.end());

    int pe = gp(e), po = gp(o);

    vector<int> ans;
    if (pe == po)
        ans = bd(se, so);
    else
    {
        auto e1 = se;
        if (e1.size() > 1)
            swap(e1[e1.size() - 1], e1[e1.size() - 2]);
        auto o1 = so;
        if (o1.size() > 1)
            swap(o1[o1.size() - 1], o1[o1.size() - 2]);
        auto c1 = bd(e1, so);
        auto c2 = bd(se, o1);
        ans = c1 < c2 ? c1 : c2;
    }

    for (int x : ans)
        cout << x << ' ';
    cout << '\n';
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
    cin >> tt;

    while (tt--)
        solve();
    return 0;
}
