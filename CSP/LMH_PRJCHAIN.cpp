/*************************
  Author: Defy logic guy
  14:19:38 - 06/09/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &i) { return os << "(" << i.first << ", " << i.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> decltype(c.begin(), c.end(), os)
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
#define NAME "LMH_PRJCHAIN"

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; cin >> a[i++])
        ;
    for (int i = 0; i < n; cin >> b[i++])
        ;

    vector<pair<int, int>> one, two;
    for (int i = 0; i < n; i++)
        if (a[i] <= b[i])
            one.pb({a[i], i});
        else
            two.pb({b[i], i});

    sort(all(one));
    sort(rall(two));

    dbg(one);
    dbg(two);

    int t = 0, res = 0;
    for (int i = 0; i < one.size(); i++)
        if (t < one[i].first)
        {
            res += one[i].first - t;
            t = b[one[i].second];
        }
        else
            t += b[one[i].second] - one[i].first;
    for (int i = 0; i < two.size(); i++)
        if (t < a[two[i].second])
        {
            res += a[two[i].second] - t;
            t = two[i].first;
        }
        else
            t += two[i].first - a[two[i].second];
    cout << res << "\n";
    for (auto i : one)
        cout << i.second + 1 << ' ';
    for (auto i : two)
        cout << i.second + 1 << ' ';
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
