/*************************
  Author: Defy logic guy
  21:08:14 - 28/06/2026
*************************/
#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &os, const string &s)
{
    os.write(s.data(), s.size());
    return os;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> typename enable_if<!is_same<T, string>::value, decltype(c.begin(), c.end(), os)>::type
{
    for (auto it = c.begin(); it != c.end(); it++)
        os << (it == c.begin() ? "{" : ", ") << *it;
    return os << "}";
}
#define dbg(x) cerr << #x << " = " << (x) << '\n';
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "MEDIANNN"

class Fenwick
{
    int n;
    vector<int> a;

public:
    Fenwick(int n = 0) : n(n) { a.assign(n + 1, 0); }
    void upd(int idx, int x)
    {
        while (idx <= n)
            a[idx] += x, idx += idx & -idx;
    }
    int get(int idx)
    {
        int ans = 0;
        while (idx > 0)
            ans += a[idx], idx -= idx & -idx;
        return ans;
    }
};

void solve()
{
    int n;
    cin >> n;
    const int T = (n * (n + 1) / 2) / 2 + 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = minall(a), r = maxall(a), ans = 0;
    while (l <= r)
    {
        int m = l + r >> 1;
        auto f = [&](int x) -> bool
        {
            vector<int> b(n);
            for (int i = 0; i < n; i++)
                b[i] = (a[i] >= x ? 1 : -1);
            vector<int> pf(n + 1, 0);
            partial_sum(all(b), pf.begin() + 1);
            Fenwick fw(2 * n + 5);
            fw.upd(n + 1, 1);
            int cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                cnt += fw.get(pf[i] + n + 1);
                fw.upd(pf[i] + n + 1, 1);
            }
            return cnt >= T;
        };
        if (f(m))
            ans = m, l = m + 1;
        else
            r = m - 1;
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

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
