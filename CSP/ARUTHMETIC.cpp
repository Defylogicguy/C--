/*************************
  Author: Defy logic guy
  15:26:52 - 28/03/2026
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
#define NAME "idk3"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<map<int, vector<int>>> dp(n);
    vector<int> res(n + 1, 0);
    res[1] = n, res[2] = n * (n - 1) / 2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            int d = a[i] - a[j];
            if (!dp[i].count(d))
                dp[i][d] = vector<int>(n + 1, 0);
            dp[i][d][2] += 1;
            if (dp[j].count(d))
            {
                vector<int> &v = dp[j][d];
                for (int k = 2; k <= n; k++)
                {
                    if (!v[k])
                        continue;
                    dp[i][d][k + 1] += v[k];
                    res[k + 1] += v[k];
                }
            }
        }
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
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
