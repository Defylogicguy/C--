/*************************
  Author: Defy logic guy
  12:31:15 - 27/06/2026
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
#define NAME "MED2"

void solve()
{
    int n, k;
    cin >> n >> k;
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
            int mn = INT_MAX;
            for (int i = k; i <= n; i++)
            {
                mn = min(mn, pf[i - k]);
                if (pf[i] - mn > 0)
                    return true;
            }
            return false;
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
