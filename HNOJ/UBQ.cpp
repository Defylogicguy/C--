/*************************
  Author: Defy logic guy
  19:48:59 - 12/09/2025
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
#define NAME "UBQ"

const int maxn = 2e5 + 5;
vector<int> v[maxn + 1];
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v[a[i]].pb(i);
    }

    vector<vector<int>> mul(maxn + 1);
    for (int i = 1; i <= maxn; i++)
    {
        for (int j = i; j <= maxn; j += i)
        {
            if (v[j].empty())
                continue;
            for (int idx : v[j])
                mul[i].pb(idx);
        }
        if (mul[i].size())
            sort(all(mul[i]));
    }

    auto f = [](const vector<int> &v, int l, int r) -> int
    {
        if (v.empty())
            return 0;
        return upper_bound(all(v), r) - lower_bound(all(v), l);
    };

    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        int ans = f(mul[x], l, r);
        int sx = sqrt(x);
        for (int d = 1; d <= sx; d++)
        {
            if (x % d)
                continue;
            int d1 = d;
            int d2 = x / d;
            if (d1 <= maxn and d1 != x)
                ans += f(v[d1], l, r);
            if (d2 != d1 and d2 <= maxn and d2 != x)
                ans += f(v[d2], l, r);
        }
        cout << ans << '\n';
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
