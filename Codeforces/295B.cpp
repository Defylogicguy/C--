/*************************
  Author: Defy logic guy
  20:50:03 - 18/07/2026
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
#define NAME "295B"

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> d(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> d[i][j];
    vector<int> a(n);
    vector<bool> check(n + 1, false);
    for (int i = 0; i < n; i++)
        cin >> a[i], check[a[i]] = true;
    reverse(all(a));
    vector<int> ans;
    for (int x : a)
    {
        check[x] = false;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][x] + d[x][j]);
        int sum = 0;
        for (int i = 1; i <= n; i++)
            if (!check[i])
                for (int j = 1; j <= n; j++)
                    if (!check[j])
                        sum += d[i][j];
        ans.pb(sum);
    }
    for (int i = n - 1; i >= 0; i --)
        cout << ans[i] << ' ';
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
