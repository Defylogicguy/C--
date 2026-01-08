/*************************
  Author: Defy logic guy
  19:10:07 - 26/12/2025
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
#define NAME "PLAYOFF"

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int M = (1 << n);
    vector<int> dp((1 << (n + 1)), 0);
    for (int i = M; i < (1 << (n + 1)); i++)
        dp[i] = 1;
    vector<int> c((1 << (n + 1)), '?');
    for (int i = 1; i < M; i++)
        c[M - i] = s[i - 1];
    auto f = [&](int i) -> void
    {
        if (c[i] == '0')
            dp[i] = dp[2 * i + 1];
        else if (c[i] == '1')
            dp[i] = dp[2 * i];
        else
            dp[i] = dp[2 * i + 1] + dp[2 * i];
    };
    for (int i = M - 1; i >= 1; i--)
        f(i);
    int q;`
    cin >> q;
    while (q--)
    {
        int p;
        char ch;
        cin >> p >> ch;
        int t = M - p;
        c[t] = ch;
        while (t >= 1)
        {
            f(t);
            t >>= 1;
        }
        cout << dp[1] << '\n';
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

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
