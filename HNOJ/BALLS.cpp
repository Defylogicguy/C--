/*************************
  Author: Defy logic guy
  19:19:28 - 14/11/2025
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
    for (auto it = c.begin(); it != c.end(); ++it)
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
#define NAME "BALLS"

const int maxn = 1e5 + 7, NEG = LLONG_MIN;
int best[maxn], c[maxn], v[maxn];
void solve()
{
    int n, q;
    cin >> n >> q;
    // vector<int> v(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        for (int i = 1; i <= n; i++)
            best[i] = NEG;
        int m1 = NEG, m2 = NEG, id1 = 0, id2 = 0, ans = NEG;
        for (int i = 0; i < n; i++)
        {
            int same = (best[c[i]] == NEG ? NEG : best[c[i]] + v[i] * a);
            int diff = ((id1 != c[i] ? m1 : m2) == NEG ? NEG : (id1 != c[i] ? m1 : m2) + v[i] * b);
            int t = v[i] * b;
            t = max({t, same, diff});
            best[c[i]] = max(best[c[i]], t);
            if (best[c[i]] >= m1 and id1 != c[i])
                m2 = m1, id2 = id1, m1 = best[c[i]], id1 = c[i];
            else if (best[c[i]] > m1 and id1 == c[i])
                m1 = best[c[i]];
            else if (best[c[i]] > m2 and id1 != c[i])
                m2 = best[c[i]], id2 = c[i];
            ans = max(ans, best[c[i]]);
        }
        cout << max(ans, 0ll) << '\n';
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
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
