/*************************
  Author: Defy logic guy
  14:28:50 - 07/02/2026
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
#define NAME "LUYENDE2025_CONTEST3_B3"

void solve()
{
    int n, m;
    cin >> m >> n;
    vector<pair<int, int>> pos(m * n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            pos[x] = {i, j};
        }
    auto f = [&](int mid) -> bool
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < mid; i++)
            v.pb(pos[i]);
        sort(all(v));
        int lst = 1;
        for (auto [i, j] : v)
        {
            if (j < lst)
                return false;
            lst = j;
        }
        return true;
    };
    int l = 0, r = n + m - 1;
    int ans = 0;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (f(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    cout << ans << '\n';
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
    cin >> tt;

    while (tt--)
        solve();

    return 0;
}
