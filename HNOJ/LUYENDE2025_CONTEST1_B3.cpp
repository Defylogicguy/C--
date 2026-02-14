/*************************
  Author: Defy logic guy
  14:47:12 - 24/01/2026
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
#define NAME "LUYENDE2025_CONTEST1_B3"

void solve()
{
    int m, n;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    vector<int> pf(n + 1, 0);
    partial_sum(all(a), pf.begin() + 1);
    int ans = LLONG_MAX;
    for (int i = m; i <= n; i++)
    {
        int plus = 0, minus = 0;
        int mid = (pf[i] - pf[i - m]) / m;
        for (int j = i - m; j < i; j++)
            if (a[j] > mid)
                plus += a[j] - mid;
            else if (a[j] < mid)
                minus += mid - a[j];
        if (mid * m <= pf[n])
            ans = min(ans, max(plus, minus));
        plus = 0, minus = 0, mid++;
        for (int j = i - m; j < i; j++)
            if (a[j] > mid)
                plus += a[j] - mid;
            else if (a[j] < mid)
                minus += mid - a[j];
        if (mid * m <= pf[n])
            ans = min(ans, max(plus, minus));
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
