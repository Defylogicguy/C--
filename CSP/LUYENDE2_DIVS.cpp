/*************************
  Author: Defy logic guy
  14:28:57 - 14/03/2026
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
#define NAME "DIVS"

const int maxn = 4e4 + 5;
int d[maxn];
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            d[j]++;
    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(d[i]);
    vector<int> a(all(st));
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int dj : a)
        {
            int t = dj * d[i] * k;
            if (t % i != 0)
                continue;
            int j = t / i;
            if (j < i or j > n)
                continue;
            ans += (dj == d[j]);
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
