/*************************
  Author: Defy logic guy
  15:37:37 - 06/09/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> decltype(c.begin(), c.end(), os)
{
    for (auto it = c.begin(); it != c.end(); ++it)
        os << (it == c.begin() ? "{" : ", ") << *it;
    return os << "}";
}
#define dbg(x) cerr << #x << " = " << (x) << '\n';
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "CSPHN_SCHEDULE"

struct node
{
    int a, c, id;
    bool operator<(const node &o) const { return (c == o.c ? c > o.c : a < o.a); }
};

int n, d, s;
void solve()
{
    cin >> n >> d;
    int x = 0, y = 0;
    vector<node> a(n + 1);
    vector<int> b(n + 1), res(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].a >> a[i].c, a[i].id = i, x += a[i].a, y += a[i].c, res[i] = b[i] = a[i].c;
    s = y;
    if (y < d or x > d)
    {
        cout << -1;
        return;
    }
    auto f = [&](int x) -> bool
    {
        int o = 0;
        for (int i = 1; i <= n; i++)
            if (a[i].c >= x)
                o += max(x, a[i].a);
            else
                o += a[i].c;
        if (o <= d)
            return true;
        s = o;
        for (int i = 1; i <= n; i++)
            if (a[i].c >= x)
                b[a[i].id] = max(a[i].a, x);
            else
                b[a[i].id] = a[i].c;
        return false;
    };
    int l = 0, r = 1e9;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (f(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    int ans = r + 1;
    if (s - d)
    {
        auto ff = [&](int x) -> bool
        {
            int r = s - d;
            for (int i = 1; i <= n; i++)
            {
                c[a[i].id] = b[a[i].id];
                if (c[i] > x)
                {
                    int o = min({r, c[a[i].id] - x, c[i] - a[i].a});
                    c[a[i].id] -= o;
                    r -= o;
                }
            }
            if (!r)
            {
                for (int i = 1; i <= n; i++)
                    res[i] = c[i];
                return true;
            }
            return false;
        };
        l = 0, r = ans;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (ff(mid))
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
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
