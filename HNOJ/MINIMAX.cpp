/*************************
  Author: Defy logic guy
  14:06:36 - 27/06/2026
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
#define NAME "MINIMAX"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 1, r = maxall(a), ans = 0;
    while (l <= r)
    {
        int mm = l + r >> 1;
        auto f = [&](int x) -> bool
        {
            vector<int> b = a;
            int cur = 0;
            for (int i = 0; i < n and cur < m; i++)
                if (b[cur] > x)
                    b[cur] -= x;
                else
                    cur++;
            return (cur == m);
        };
        if (f(mm))
            ans = mm, r = mm - 1;
        else
            l = mm + 1;
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
