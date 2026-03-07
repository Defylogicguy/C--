/*************************
  Author: Defy logic guy
  14:10:23 - 28/02/2026
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
#define NAME "CSPHN_LIGHTBALL"

void solve()
{
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n), b(m), c(p);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < p; i++)
        cin >> c[i];
    sort(all(a)), sort(all(b)), sort(all(c));
    function<int(vector<int>, vector<int>, vector<int>)> f = [&](const vector<int> &a, const vector<int> &b, const vector<int> &c)
    {
        int ans = LLONG_MAX;
        for (int x : a)
        {
            auto itb = lower_bound(all(b), x);
            auto itc = upper_bound(all(c), x);
            if (itb == b.end() or itc == c.begin())
                continue;
            itc--;
            ans = min(ans, (x - *itb) * (x - *itb) + (*itb - *itc) * (*itb - *itc) + (*itc - x) * (*itc - x));
        }
        return ans;
    };
    int ans = LLONG_MAX;
    vector<vector<int>> v = {a, b, c};
    vector<int> vv = {0, 1, 2};
    do
        ans = min(ans, f(v[vv[0]], v[vv[1]], v[vv[2]]));
    while (next_permutation(all(vv)));
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
