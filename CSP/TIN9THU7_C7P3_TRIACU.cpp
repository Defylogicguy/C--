/*************************
  Author: Defy logic guy
  15:42:28 - 18/04/2026
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
#define NAME "TIN9THU7_C7P3_TRIACU"

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> a(n), sq(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(all(v));
    for (int i = 0; i < n; i++)
    {
        a[i] = v[i].first;
        sq[i] = a[i] * a[i];
    }
    vector<int> pf(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pf[i] = pf[i - 1] + v[i - 1].second;
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int t1 = lower_bound(all(a), a[i] + a[j]) - a.begin() - 1;
            if (t1 <= j)
                continue;
            int tmp = sq[i] + sq[j];
            int t = lower_bound(sq.begin() + j + 1, sq.begin() + t1 + 1, tmp) - sq.begin();
            if (t > j + 1)
                ans += (pf[t] - pf[j + 1]) * v[i].second * v[j].second;
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
