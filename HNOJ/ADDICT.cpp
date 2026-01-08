/*************************
  Author: Defy logic guy
  09:34:59 - 27/11/2025
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
#define NAME "ADDICT"

struct Fenwreck
{
    int n;
    vector<int> a;
    Fenwreck(int n) : n(n), a(n + 1, LLONG_MIN) {}
    void upd(int idx, int v)
    {
        while (idx <= n)
        {
            a[idx] = max(a[idx], v);
            idx += idx & -idx;
        }
    }
    int get(int idx)
    {
        int ans = LLONG_MIN;
        while (idx)
        {
            ans = max(ans, a[idx]);
            idx -= idx & -idx;
        }
        return ans;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> pf(n + 1, 0);
    partial_sum(all(a), pf.begin() + 1);

    vector<int> c = pf;
    sort(all(c));
    c.erase(unique(all(c)), c.end());
    int m = c.size();

    auto f = [&](int x) -> int
    { return lower_bound(all(c), x) - c.begin() + 1; };

    Fenwreck pos(m), neg(m);
    vector<int> equal(m + 1, LLONG_MIN), dp(n + 1, LLONG_MIN);
    dp[0] = 0;

    int id0 = f(pf[0]);

    pos.upd(id0, 0);
    neg.upd(m - id0 + 1, 0);
    equal[id0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int id = f(pf[i]);

        int &v = dp[i];

        int t = pos.get(id - 1);
        if (t != LLONG_MIN)
            v = max(v, t + i);

        t = m - id;
        if (t >= 1)
        {
            t = neg.get(t);
            if (t != LLONG_MIN)
                v = max(v, t - i);
        }

        if (equal[id] != LLONG_MIN)
            v = max(v, equal[id]);

        pos.upd(id, dp[i] - i);
        neg.upd(m - id + 1, dp[i] + i);
        equal[id] = max(equal[id], dp[i]);
    }

    cout << dp[n];
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
