/*************************
  Author: Defy logic guy
  15:27:01 - 24/01/2026
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
#define NAME "LUYENDE2025_CONTEST1_B4"

void solve()
{
    int n;
    cin >> n;

    vector<int> ans(n);
    vector<pair<int, int>> plus, minus;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x > 0)
            plus.emplace_back(x, i);
        else if (x < 0)
            minus.emplace_back(-x, i);
    }

    auto floordiv = [&](int a, int b)
    {
        if (a >= 0)
            return a / b;
        return -((-a + b - 1) / b);
    };

    for (auto [a, i] : plus)co
        for (auto [b, j] : minus)
        {
            int x = 2 * min(a, b) - (j - i);
            int cnt = floordiv(x, n) + (i < j);
            if (cnt > 0)
                ans[i] += cnt, ans[j] += cnt;
        }

    for (int i : ans)
        cout << i << '\n';
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
