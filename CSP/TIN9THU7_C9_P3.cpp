/*************************
  Author: Defy logic guy
  14:38:00 - 09/05/2026
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
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "TIN9THU7_C9_P3"

struct node
{
    int t, x, a;
    node(int t = 0, int x = 0, int a = 0) : t(t), a(a), x(x) {}
    bool operator<(const node &o) const { return t < o.t; }
};
void solve()
{
    int n;
    cin >> n;
    vector<node> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].t >> a[i].x >> a[i].a;
    sort(all(a));
    vector<int> dp(5, LLONG_MIN);
    dp[0] = 0;
    int lst = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> ndp(5, LLONG_MIN);
        int dt = a[i].t - lst;
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                if (abs(j - k) <= dt)
                    ndp[j] = max(ndp[j], dp[k]);
        if (ndp[a[i].x] != LLONG_MIN)
            ndp[a[i].x] += a[i].a;
        dp = ndp, lst = a[i].t;
    }
    cout << maxall(dp);
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
