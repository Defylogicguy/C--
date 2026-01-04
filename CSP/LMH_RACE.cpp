/*************************
  Author: Defy logic guy
  14:54:56 - 20/12/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &os, const string &s)
{
    os.write(s.data(), s.size());
    return os;
}
template <typename a, typename b>
ostream &operator<<(ostream &os, const pair<a, b> &p) { return os << "" << p.first << " " << p.second << ""; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> typename enable_if<!is_same<T, string>::value, decltype(c.begin(), c.end(), os)>::type
{
    for (auto it = c.begin(); it != c.end(); it++)
        os << (it == c.begin() ? "" : "\n") << *it;
    return os << "";
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
#define NAME "LMH_RACE"

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; a[i].second = i + 1, i++)
        cin >> a[i].first;
    for (int i = 0; i < n; b[i].second = i + 1, i++)
        cin >> b[i].first;

    sort(all(a)), sort(all(b));

    int la = 0, ra = n - 1;
    int lb = 0, rb = n - 1;

    while (la <= ra)
        if (a[ra].first > b[rb].first)
            cout << a[ra--].second << ' ' << b[rb--].second << '\n';
        else if (a[la].first > b[lb].first)
            cout << a[la++].second << ' ' << b[lb++].second << '\n';
        else
            cout << a[la++].second << ' ' << b[rb--].second << '\n';
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
