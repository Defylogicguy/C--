/*************************
  Author: Defy logic guy
  15:30:03 - 31/01/2026
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
#define NAME "LUYENDE2025_CONTEST2_B4"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vector<int> idx(n);
    for (int i = 0; i < n; i++)
        idx[i] = i + 1;
    sort(all(idx), [&](const int &i, const int &j)
         { return (a[i] * b[j] != a[j] * b[i] ? a[i] * b[j] > a[j] * b[i] : i < j); });
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = idx[i - 1];
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++)
        pos[s[i]] = i;
    vector<int> pfa(n + 1, 0), pfb(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pfa[i] = pfa[i - 1] + a[s[i]];
        pfb[i] = pfb[i - 1] + b[s[i]];
    }
    int sum = 0, cur = 0;
    for (int i = 1; i <= n; i++)
    {
        cur += b[s[i]];
        sum += a[s[i]] * cur;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        int r = pos[x], l = pos[y];
        if (r < l)
        {
            cout << sum << '\n';
            continue;
        }
        int suma = pfa[r - 1] - pfa[l - 1];
        int sumb = pfb[r - 1] - pfb[l - 1];
        int suma1 = pfa[r] - pfa[l];
        int sumb1 = pfb[r] - pfb[l];
        int da = b[x] * suma - a[x] * sumb;
        int db = a[y] * sumb1 - b[y] * suma1;
        cout << (sum + min(da, db)) << '\n';
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
