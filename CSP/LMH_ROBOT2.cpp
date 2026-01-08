/*************************
  Author: Defy logic guy
  15:16:52 - 06/12/2025
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
#define NAME "ROBOT"

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    string s;
    cin >> s;

    sort(all(a)), sort(all(b));

    vector<int> pfa(n + 1), pfb(n + 1);
    for (int i = 0; i < n; i++)
    {
        pfa[i + 1] = pfa[i] + a[i];
        pfb[i + 1] = pfb[i] + b[i];
    }

    auto f = [&](const vector<int> &v, const vector<int> &pf, int idx)
    {
        int t = lower_bound(all(v), idx) - v.begin();
        return idx * t - pf[t] + (pf[n] - pf[t]) - idx * (n - t);
    };

    int x = 0, y = 0;

    int cx = f(a, pfa, x);
    int cy = f(b, pfb, y);

    for (char c : s)
    {
        if (c == 'E')
            x++;
        else if (c == 'W')
            x--;
        else if (c == 'N')
            y++;
        else if (c == 'S')
            y--;

        cx = f(a, pfa, x);
        cy = f(b, pfb, y);

        cout << cx + cy << '\n';
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
